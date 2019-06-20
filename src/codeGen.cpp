//
// Created by BossWang & ItemZheng on 2019-06-15.
//

#include "codeGen.h"
#include "node.h"
#include "type.h"

static Type* typeOf(type_var type){
    if(type == TYPE_INT){
        return Type::getInt32Ty(llvmContext);
    }
    if(type == TYPE_LONG){
        return Type::getInt64Ty(llvmContext);
    }
    if(type == TYPE_SHORT){
        return Type::getInt16Ty(llvmContext);
    }
    if(type == TYPE_DOUBLE){
        return Type::getDoubleTy(llvmContext);
    }
    if(type == TYPE_FLOAT){
        return Type::getFloatTy(llvmContext);
    }
    if(type == TYPE_CHAR){
        return Type::getInt8Ty(llvmContext);
    }
    if(type == TYPE_VOID){
        return Type::getVoidTy(llvmContext);
    }
    return NULL;
}

static Type *typeOf(const VarDeclNode& vardecl) 
{
    if(vardecl.type == ARRAY){
        return PointerType::get(typeOf(vardecl.typeVar), 0);
    }
    return typeOf(vardecl.typeVar);
}

Value * VarDeclarationNode::codeGen(CodeGenContext &context){
    int size = var_declaration_list->size();
    for(int i = 0; i < size; i++){
        Value * last = (*var_declaration_list)[i]->codeGen(context);
    }
    return last;
}

Value * VarDeclNode::codeGen(CodeGenContext &context) {
    Value * inst = NULL;
    if(type == SINGLE){
        cout << "Generating variable declaration of " << typeVar << " " << *identifier << std::endl;
        Type * llvmtype = typeOf(*this);
        inst = context.builder.CreateAlloca(llvmtype);
        context.setSymbolValue(*identifier, inst);
        context.setSymbolType(*identifier, this);
        if(assign == 1){
            Value * exp = expressionv->codeGen(context);
            context.builder.CreateStore(exp, inst);
        }
    }
    else{
        cout << "Generating array declaration of " << typeVar << " " << *(array_identifier->identifier) << std::endl;
        uint32_t array_size = array_identifier->size;
        context.setArraySize(*(array_identifier->identifier), array_size);
        Value * arraySizeValue = ConstantInt::get(Type::getInt32Ty(llvmContext), array_size, true);
        auto arrayType = ArrayType::get(typeOf(*this), array_size);
        inst = context.builder.CreateAlloca(arrayType, arraySizeValue, "arraytmp");
        context.setSymbolValue(*(array_identifier->identifier), inst);
        context.setSymbolType(*(array_identifier->identifier), this);
        if(assign == 1){
            if(array_size != this->array_init->expressionvs->size()){
                return LogErrorV("Initialize size not match");
            }
            for(auto it = this->array_init->expressionvs->begin(), int i = 0; it != this->array_init->expressionvs->end(), it++, i++){
                Value * tempvalue = it->codeGen(context);
                auto arrayPtr = context.builder.CreateLoad(inst, "arrayPtr");
                if( !arrayPtr->getType()->isArrayTy() && !arrayPtr->getType()->isPointerTy() ){
                    return LogErrorV("The variable is not array");
                }
                Value * array_index = ConstantInt::get(Type::getInt32Ty(llvmContext), i, true);
                ArrayRef<Value*> gep2_array{ ConstantInt::get(Type::getInt32Ty(llvmContext), 0), array_index };
                auto ptr = context.builder.CreateInBoundsGEP(inst, gep2_array, "elementPtr");
                context.builder.CreateAlignedStore(tempvalue, ptr, 4);
            }
        }
    }
    return inst;
}

Value * ExpressionVNode::codeGen(CodeGenContext & context){
    Value * exp = expression->codeGen(context);
    Value * last = NULL;
    if(var_list != NULL){
        for(auto it = var_list->rbegin(); it != var_list->rend(); it++){
            type_identifier temptype = it->type;
            if(temptype == SINGLE){
                Value* dst = context.getSymbolValue(*(it->identifier));
                auto dstType = context.getSymbolType(*(it->identifier));
                if( !dst ){
                    return LogErrorV("Undeclared variable");
                }
                last = context.builder.CreateStore(exp, dst);
            }
            if(temptype == ARRAY){
                auto varPtr = context.getSymbolValue(*(it->array_access->identifier));
                if( varPtr == NULL ){
                    return LogErrorV("Unknown variable name");
                }
                auto arrayPtr = context.builder.CreateLoad(varPtr, "arrayPtr");
                if( !arrayPtr->getType()->isArrayTy() && !arrayPtr->getType()->isPointerTy() ){
                    return LogErrorV("The variable is not array");
                }
                Value * array_index = ConstantInt::get(Type::getInt32Ty(llvmContext), index, true);
                ArrayRef<Value*> gep2_array{ ConstantInt::get(Type::getInt32Ty(llvmContext), 0), array_index };
                auto ptr = context.builder.CreateInBoundsGEP(varPtr, gep2_array, "elementPtr");
                last = context.builder.CreateAlignedStore(exp, ptr, 4);
            }
        }
    }
    return exp;
}

Value * ExpressionNode::codeGen(CodeGenContext & context){
    if(type == EXP_PLUS || type == EXP_MINUS || type == EXP_MUL || type == EXP_DIV ||
    type == EXP_MOD || type == EXP_LESS || type == EXP_LESS_EQUAL || type == EXP_GREATER ||
    type == EXP_GREATER_EQUAL || type == EXP_AND_AND || type == EXP_OR_OR|| type == EXP_EQUAL ||
    type == EXP_NOT_EQUAL){
        Value * L = left->codeGen(context);
        Value * R = right->codeGen(context);
        bool fp = false;
        if( (L->getType()->getTypeID() == Type::DoubleTyID) || (R->getType()->getTypeID() == Type::DoubleTyID) ){
            fp = true;
            if( (R->getType()->getTypeID() != Type::DoubleTyID) ){
                R = context.builder.CreateUIToFP(R, Type::getDoubleTy(llvmContext), "ftmp");
            }
            if( (L->getType()->getTypeID() != Type::DoubleTyID) ){
                L = context.builder.CreateUIToFP(L, Type::getDoubleTy(llvmContext), "ftmp");
            }
        }
        if(!L || !R){
            return NULL;
        }
        switch(type){
            case EXP_PLUS:
                return fp ? context.builder.CreateFAdd(L, R, "addftmp") : context.builder.CreateAdd(L, R, "addtmp");
            case EXP_MINUS:
                return fp ? context.builder.CreateFSub(L, R, "subftmp") : context.builder.CreateSub(L, R, "subtmp");
            case EXP_MUL:
                return fp ? context.builder.CreateFMul(L, R, "mulftmp") : context.builder.CreateMul(L, R, "multmp");
            case EXP_DIV:
                return fp ? context.builder.CreateFDiv(L, R, "divftmp") : context.builder.CreateSDiv(L, R, "divtmp");
            case EXP_LESS:
                return fp ? context.builder.CreateFCmpULT(L, R, "cmpftmp") : context.builder.CreateICmpULT(L, R, "cmptmp");
            case EXP_LESS_EQUAL:
                return fp ? context.builder.CreateFCmpOLE(L, R, "cmpftmp") : context.builder.CreateICmpSLE(L, R, "cmptmp");
            case EXP_GREATER_EQUAL:
                return fp ? context.builder.CreateFCmpOGE(L, R, "cmpftmp") : context.builder.CreateICmpSGE(L, R, "cmptmp");
            case EXP_GREATER:
                return fp ? context.builder.CreateFCmpOGT(L, R, "cmpftmp") : context.builder.CreateICmpSGT(L, R, "cmptmp");
            case EXP_EQUAL:
                return fp ? context.builder.CreateFCmpOEQ(L, R, "cmpftmp") : context.builder.CreateICmpEQ(L, R, "cmptmp");
            case EXP_NOT_EQUAL:
                return fp ? context.builder.CreateFCmpONE(L, R, "cmpftmp") : context.builder.CreateICmpNE(L, R, "cmptmp");
            default:
                return LogErrorV("Unknown binary operator");
        }
    }
    if(type == EXP_NOT){
        Value * L = left->codeGen(context);
        if(!L){
            return NULL;
        }
        return context.builder.CreateNot(L, "nottmp");
    }
    if(type == EXP_MINUS_SIGN){
        Value * L = left->codeGen(context);
        if(!L){
            return NULL;
        }
        return context.builder.CreateNeg(L, "negtmp");
    }
    if(type == EXP_VAR){
        return var->codeGen(context);
    }
    if(type == EXP_CONST){
        return constant->codeGen(context);
    }
    if(type == EXP_EXPV){
        return expressionv->codeGen(context);
    }
    if(type == EXP_CALL){
        return call->codeGen(context);
    }
}

Value * VarNode::codeGen(CodeGenContext & context){
    if(type == SINGLE){
        Value * value = context.getSymbolValue(*identifier);
        if( !value ){
            return LogErrorV("Unknown variable name " + *identifier);
        }
        return context.builder.CreateLoad(value, false, "");
    }
    else{
        return array_access->codeGen(context);
    }
}

Value * ArrayAccessNode::codeGen(CodeGenContext & context){
    auto varPtr = context.getSymbolValue(*identifier);
    auto type = context.getSymbolType(*identifier);
    uint32_t size = context.getArraySize(*identifier);
    if(size <= index){
        return LogErrorV("out of range");
    }
    if(!varPtr){
        return LogErrorV("Unknown variable name " + *identifier);
    }
    Value * array_index = ConstantInt::get(Type::getInt32Ty(llvmContext), index, true);
    ArrayRef<Value*> indices;
    indices = { ConstantInt::get(Type::getInt32Ty(llvmContext), 0), array_index };
    auto ptr = context.builder.CreateInBoundsGEP(varPtr, indices, "elementPtr");
    return context.builder.CreateAlignedLoad(ptr, 4);
}

Value * ConstantNode::codeGen(CodeGenContext & context){
    if(type == TYPE_INT){
        return ConstantInt::get(Type::getInt32Ty(llvmContext), integer, true);
    }
    else if(type == TYPE_DOUBLE){
        return ConstantFP::get(Type::getDoubleTy(llvmContext), double_number);
    }
    else if(type == TYPE_CHAR){
        return ConstantInt::get(Type::getInt8Ty(llvmContext), character, true);
    }
}

Value * CallNode::codeGen(CodeGenContext & context){
    Function * calleeF = context.theModule->getFunction(*identifier);
    if( !calleeF ){
        LogErrorV("Function name not found");
    }
    if( calleeF->arg_size() != args->size() ){
        LogErrorV("Function arguments size not match, calleeF=" + std::to_string(calleeF->size()) + ", this->arguments=" + std::to_string(args->size()) );
    }
    std::vector<Value*> argsv;
    for(auto it=args->begin(); it!=args->end(); it++){
        argsv.push_back(it->codeGen(context));
        if( !argsv.back() ){        
            return NULL;
        }
    }
    return context.builder.CreateCall(calleeF, argsv, "calltmp");
}
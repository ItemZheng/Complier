//
// Created by BossWang & ItemZheng on 2019-06-15.
//

#include "codeGen.h"
#include "node.h"
#include "type.h"

static Type *typeOf(type_var type) {
    if (type == TYPE_INT) {
        return Type::getInt32Ty(llvmContext);
    }
    if (type == TYPE_LONG) {
        return Type::getInt64Ty(llvmContext);
    }
    if (type == TYPE_SHORT) {
        return Type::getInt16Ty(llvmContext);
    }
    if (type == TYPE_DOUBLE) {
        return Type::getDoubleTy(llvmContext);
    }
    if (type == TYPE_FLOAT) {
        return Type::getFloatTy(llvmContext);
    }
    if (type == TYPE_CHAR) {
        return Type::getInt8Ty(llvmContext);
    }
    if (type == TYPE_VOID) {
        return Type::getVoidTy(llvmContext);
    }
    return NULL;
}

static Type *typeOf(const VarDeclNode &vardecl) {
    return typeOf(vardecl.typeVar);
}

llvm::Value *ProgramNode::codeGen(CodeGenContext &context) {
    if (declaration_list != NULL) {
        for (int i = 0; i < declaration_list->size(); i++) {
            (*declaration_list)[i]->codeGen(context);
        }
    }
    return NULL;
}

llvm::Value *DeclarationNode::codeGen(CodeGenContext &context) {
    if (varDeclarationNode != NULL) {
        varDeclarationNode->codeGen(context);
    } else if (functionDeclarationNode != NULL) {
        functionDeclarationNode->codeGen(context);
    }
    return NULL;
}

llvm::Value *FunctionDeclarationNode::codeGen(CodeGenContext &context) {
    if (functionDeclNode != NULL) {
        functionDeclNode->codeGen(context);
    } else if (functionDefinitionNode != NULL) {
        functionDefinitionNode->codeGen(context);
    }
    return NULL;
}

llvm::Value *FunctionDeclNode::codeGen(CodeGenContext &context) {
    vector<llvm::Type *> args;
    if (function_args != NULL) {
        for (int i = 0; i < function_args->size(); i++) {
            args.push_back(typeOf((*function_args)[i]->type));
        }
    }
    FunctionType *functionType = FunctionType::get(typeOf(type), args, true);
    Function *F = Function::Create(functionType, GlobalValue::ExternalLinkage, identifier, context.theModule.get());
    if (F->getName() != identifier) {
        F->eraseFromParent();
        F = context.theModule->getFunction(identifier);
    }

    // set identifier name
    int Idx = 0;
    if(function_args != NULL)
        for (Function::arg_iterator AI = F->arg_begin(); Idx != function_args->size(); ++AI, ++Idx)
            AI->setName((*function_args)[Idx]->identifier);
    return NULL;
}

llvm::Value *FunctionDefinitionNode::codeGen(CodeGenContext &context) {
    if (functionDeclNode != NULL) {
        functionDeclNode->codeGen(context);
    }
    Function *F = context.theModule->getFunction(functionDeclNode->identifier);
    // already define
    if (!F->empty()) {
        return NULL;
    }

    // define body
    BasicBlock *block = BasicBlock::Create(llvmContext, "entry", F);
    context.builder.SetInsertPoint(block); // insert instruction to end of block
    context.pushBlock(block);
    // register name values to symbol table
    if (functionDeclNode != NULL && functionDeclNode->function_args != NULL) {
        int Idx = 0;
        for (Function::arg_iterator AI = F->arg_begin(); Idx != functionDeclNode->function_args->size(); ++AI, ++Idx) {
            Value* argAlloc = (*(functionDeclNode->function_args))[Idx]->codeGen(context);
            context.builder.CreateStore(AI, argAlloc, false);
            // context.setSymbolValue( (*(functionDeclNode->function_args))[Idx]->identifier, AI);
        }
    }

    // code generete body
    if (functionBodyNode != NULL) {
        Value *ret = functionBodyNode->codeGen(context);
        context.builder.CreateRet(ret);
    }
    context.popBlock();
    return NULL;
}


llvm::Value* FunctionArgNode::codeGen(CodeGenContext &context) {
    //cout << "Generating variable declaration of " << typeVar << " " << *identifier << std::endl;
    Type *llvmtype = typeOf(type);
    Value * inst = context.builder.CreateAlloca(llvmtype);
    context.setSymbolValue(identifier, inst);
    return inst;
}

llvm::Value *FunctionBodyNode::codeGen(CodeGenContext &context) {
    if (functionStatementsNode != NULL) {
        return functionStatementsNode->codeGen(context);
    }
    return NULL;
}

llvm::Value *FunctionStatementsNode::codeGen(CodeGenContext &context) {
    if (statements != NULL) {
        for (int i = 0; i < statements->size(); i++) {
            (*statements)[i]->codeGen(context);
        }
    }
    if (returnStatementNode != NULL) {
        return returnStatementNode->codeGen(context);
    }
    return NULL;
}

llvm::Value *ReturnStatementNode::codeGen(CodeGenContext &context) {
    if (expressionVNode != NULL) {
        Value *ret = expressionVNode->codeGen(context);
        context.setCurrentReturnValue(ret);
        return ret;
    }
    return NULL;
}

llvm::Value *StatementNode::codeGen(CodeGenContext &context) {
    switch (type) {
        case TYPE_VAR_DECLARATION:
            if (varDeclarationNode != NULL) {
                varDeclarationNode->codeGen(context);
            }
            break;
        case TYPE_ITERATION:
            if (iterationStatementNode != NULL) {
                iterationStatementNode->codeGen(context);
            }
            break;
        case TYPE_SELECTION:
            if (selectionStatementNode != NULL) {
                selectionStatementNode->codeGen(context);
            }
            break;
        case TYPE_EXPRESSION:
            if (expressionStatementNode != NULL) {
                expressionStatementNode->codeGen(context);
            }
            break;
        case TYPE_JUMP:
            if (jumpStatementNode != NULL) {
                jumpStatementNode->codeGen(context);
            }
            break;
        default:
            break;
    }
    return NULL;
}

llvm::Value *ExpressionStatementNode::codeGen(CodeGenContext &context) {
    if (expressionVNode != NULL) {
        return expressionVNode->codeGen(context);
    }
    return NULL;
}

llvm::Value *IterationStatementNode::codeGen(CodeGenContext &context) {
    Function *theFunction = context.builder.GetInsertBlock()->getParent();
    // 2 basic block
    BasicBlock *block = BasicBlock::Create(llvmContext, "forloop", theFunction);
    BasicBlock *after = BasicBlock::Create(llvmContext, "forcont");

    if (type == TYPE_WHILE || type == TYPE_DO_WHILE) {
        if (type == TYPE_WHILE) {
            // compute value
            Value *condValue = expressionVNode->codeGen(context);
            condValue = CastToBoolean(context, condValue);
            context.builder.CreateCondBr(condValue, block, after);
        } else {
            context.builder.CreateBr(block);
        }
        // loop body
        context.pushBlock(block);
        context.builder.SetInsertPoint(block);

        // set break and continue
        context.setBreakBlock(after);
        context.setContinueBlock(block);

        if (loopBodyNode != NULL) {
            loopBodyNode->codeGen(context);
        } else if (compoundStatementNode != NULL) {
            compoundStatementNode->codeGen(context);
        }

        // pop
        context.popBlock();

        // execute the again or stop
        Value *condValue = expressionVNode->codeGen(context);
        condValue = CastToBoolean(context, condValue);
        context.builder.CreateCondBr(condValue, block, after);

    } else if (type == TYPE_FOR) {
        // new scope
        context.pushBlock(block);

        // execute init
        ForInitListNode *forInitListNode = forConditionNode->forInitListNode;
        ExpressionVNode *forExpression = forConditionNode->forExpression;
        vector<ExpressionVNode *> *incrementExpressionList = forConditionNode->incrementExpressionList;
        if (forInitListNode != NULL) {
            forInitListNode->codeGen(context);
        }

        // Compute Condition
        Value *condValue;
        if (forExpression == NULL) {
            // 表达式为真
            condValue = ConstantFP::get(llvmContext, APFloat(1.0));
        } else {
            condValue = forExpression->codeGen(context);
        }
        if (!condValue) {
            // error
            return NULL;
        }

        condValue = CastToBoolean(context, condValue);

        // create branch
        context.setBreakBlock(after);
        context.setContinueBlock(block);
        context.builder.CreateCondBr(condValue, block, after);

        // begin for body
        context.builder.SetInsertPoint(block);

        // codeGen
        if (loopBodyNode != NULL) {
            loopBodyNode->codeGen(context);
        }

        // do increment
        if (incrementExpressionList != NULL) {
            for (int i = 0; i < incrementExpressionList->size(); i++) {
                (*incrementExpressionList)[i]->codeGen(context);
            }
        }

        // compute value
        if (forExpression == NULL) {
            // 表达式为真
            condValue = ConstantFP::get(llvmContext, APFloat(1.0));
        } else {
            condValue = forExpression->codeGen(context);
        }
        condValue = CastToBoolean(context, condValue);
        context.builder.CreateCondBr(condValue, block, after);

        // pop
        context.popBlock();
    }
    // insert the after block
    theFunction->getBasicBlockList().push_back(after);
    context.builder.SetInsertPoint(after);
    return NULL;
}

llvm::Value *ForConditionNode::codeGen(CodeGenContext &context) {
    return NULL;
}

llvm::Value *LoopBodyNode::codeGen(CodeGenContext &context) {
    if (statementNode != NULL) {
        return statementNode->codeGen(context);
    }
    if (compoundStatementNode != NULL) {
        return compoundStatementNode->codeGen(context);
    }
    return NULL;
}

llvm::Value *CompoundStatementNode::codeGen(CodeGenContext &context) {
    context.pushBlock(NULL);
    if (statements != NULL) {
        for (int i = 0; i < statements->size(); i++) {
            (*statements)[i]->codeGen(context);
        }
    }
    context.popBlock();
    return NULL;
}


llvm::Value *ForInitListNode::codeGen(CodeGenContext &context) {
    if (forDeclarationNode != NULL) {
        forDeclarationNode->codeGen(context);
    }
    if (expressionList != NULL) {
        for (int i = 0; i < expressionList->size(); i++) {
            (*expressionList)[i]->codeGen(context);
        }
    }
    return NULL;
}

llvm::Value *ForDeclarationNode::codeGen(CodeGenContext &context) {
    if (varDeclarationList != NULL) {
        for (int i = 0; i < varDeclarationList->size(); i++) {
            VarDeclNode *varDeclNode = (*varDeclarationList)[i];
            varDeclNode->codeGen(context);
        }
    }
    return NULL;
}

llvm::Value *JumpStatementNode::codeGen(CodeGenContext &context) {
    BasicBlock *block;
    if (type == TYPE_CONTINUE) {
        block = context.continueBlock();
    } else {
        block = context.breakBlock();
    }
    if (block != NULL) {
        context.builder.CreateBr(block);
    }
    return NULL;
}

llvm::Value *SelectionStatementNode::codeGen(CodeGenContext &context) {
    if (ifStatementNode != NULL) {
        ifStatementNode->codeGen(context);
    }
    if (switchStatementNode != NULL) {
        switchStatementNode->codeGen(context);
    }
    return NULL;
}

Value *VarDeclarationNode::codeGen(CodeGenContext &context) {
    int size = var_declaration_list->size();
    Value *last = NULL;
    for (int i = 0; i < size; i++) {
        last = (*var_declaration_list)[i]->codeGen(context);
    }
    return last;
}

Value *VarDeclNode::codeGen(CodeGenContext &context) {
    Value *inst = NULL;
    if (type == SINGLE) {
        //cout << "Generating variable declaration of " << typeVar << " " << *identifier << std::endl;
        Type *llvmtype = typeOf(*this);
        if(context.isGlobal()){
            inst = new GlobalVariable(*context.theModule, llvmtype,
                   false, GlobalValue::CommonLinkage, NULL, *identifier);
        } else {
            inst = context.builder.CreateAlloca(llvmtype);
        }
        context.setSymbolValue(*identifier, inst);
        context.setSymbolType(*identifier, this);
        if (assign == 1) {
            Value *exp = expressionv->codeGen(context);
            if(!context.isGlobal())
                context.builder.CreateStore(exp, inst);
            else
                ((GlobalVariable *)inst)->setInitializer((Constant*) exp);
        }
    } else {
        //cout << "Generating array declaration of " << typeVar << " " << *(array_identifier->identifier) << std::endl;
        uint32_t array_size = array_identifier->size;
        context.setArraySize(*(array_identifier->identifier), array_size);
        Value *arraySizeValue = ConstantInt::get(Type::getInt32Ty(llvmContext), array_size, true);
        auto arrayType = ArrayType::get(typeOf(*this), array_size);
        inst = context.builder.CreateAlloca(arrayType, arraySizeValue, "arraytmp");
        context.setSymbolValue(*(array_identifier->identifier), inst);
        context.setSymbolType(*(array_identifier->identifier), this);
        if (assign == 1) {
            if (array_size != this->array_init->expressionvs->size()) {
                return LogErrorV("Initialize size not match");
            }
            int i = 0;
            for (auto it = this->array_init->expressionvs->begin();
                 it != this->array_init->expressionvs->end(); it++, i++) {
                Value *tempvalue = (*it)->codeGen(context);
                auto arrayPtr = context.builder.CreateLoad(inst, "arrayPtr");
                if (!arrayPtr->getType()->isArrayTy() && !arrayPtr->getType()->isPointerTy()) {
                    return LogErrorV("The variable is not array");
                }
                Value *array_index = ConstantInt::get(Type::getInt32Ty(llvmContext), i, true);
                ArrayRef<Value *> gep2_array{ConstantInt::get(Type::getInt32Ty(llvmContext), 0), array_index};
                auto ptr = context.builder.CreateInBoundsGEP(inst, gep2_array, "elementPtr");
                context.builder.CreateAlignedStore(tempvalue, ptr, 4);
            }
        }
    }
    return inst;
}

Value *ExpressionVNode::codeGen(CodeGenContext &context) {
    Value *exp = expression->codeGen(context);
    Value *last = NULL;
    if (var_list != NULL) {
        for (auto it = var_list->rbegin(); it != var_list->rend(); it++) {
            type_identifier temptype = (*it)->type;
            if (temptype == SINGLE) {
                Value *dst = context.getSymbolValue(*((*it)->identifier));
                auto dstType = context.getSymbolType(*((*it)->identifier));
                if (!dst) {
                    return LogErrorV("Undeclared variable");
                }
                context.builder.CreateStore(exp, dst);
            }
            if (temptype == ARRAY) {
                auto varPtr = context.getSymbolValue(*((*it)->array_access->identifier));
                if (varPtr == NULL) {
                    return LogErrorV("Unknown variable name");
                }
                auto arrayPtr = context.builder.CreateLoad(varPtr, "arrayPtr");
                if (!arrayPtr->getType()->isArrayTy() && !arrayPtr->getType()->isPointerTy()) {
                    return LogErrorV("The variable is not array");
                }
                int index = (*it)->array_access->index;
                Value *array_index = ConstantInt::get(Type::getInt32Ty(llvmContext), index, true);
                ArrayRef<Value *> gep2_array{ConstantInt::get(Type::getInt64Ty(llvmContext), 0), array_index};
                auto ptr = context.builder.CreateInBoundsGEP(varPtr, gep2_array, "elementPtr");
                context.builder.CreateAlignedStore(exp, ptr, 4);
            }
        }
    }
    return exp;
}

Value *ExpressionNode::codeGen(CodeGenContext &context) {
    if (type == EXP_PLUS || type == EXP_MINUS || type == EXP_MUL || type == EXP_DIV ||
        type == EXP_MOD || type == EXP_LESS || type == EXP_LESS_EQUAL || type == EXP_GREATER ||
        type == EXP_GREATER_EQUAL || type == EXP_AND_AND || type == EXP_OR_OR || type == EXP_EQUAL ||
        type == EXP_NOT_EQUAL) {
        Value *L = left->codeGen(context);
        Value *R = right->codeGen(context);
        bool fp = false;
        if ((L->getType()->getTypeID() == Type::DoubleTyID) || (R->getType()->getTypeID() == Type::DoubleTyID)) {
            fp = true;
            if ((R->getType()->getTypeID() != Type::DoubleTyID)) {
                R = context.builder.CreateUIToFP(R, Type::getDoubleTy(llvmContext), "ftmp");
            }
            if ((L->getType()->getTypeID() != Type::DoubleTyID)) {
                L = context.builder.CreateUIToFP(L, Type::getDoubleTy(llvmContext), "ftmp");
            }
        }
        if (!L || !R) {
            return NULL;
        }
        switch (type) {
            case EXP_PLUS:
                return fp ? context.builder.CreateFAdd(L, R, "addftmp") : context.builder.CreateAdd(L, R, "addtmp");
            case EXP_MINUS:
                return fp ? context.builder.CreateFSub(L, R, "subftmp") : context.builder.CreateSub(L, R, "subtmp");
            case EXP_MUL:
                return fp ? context.builder.CreateFMul(L, R, "mulftmp") : context.builder.CreateMul(L, R, "multmp");
            case EXP_DIV:
                return fp ? context.builder.CreateFDiv(L, R, "divftmp") : context.builder.CreateSDiv(L, R, "divtmp");
            case EXP_LESS:
                return fp ? context.builder.CreateFCmpULT(L, R, "cmpftmp") : context.builder.CreateICmpULT(L, R,
                                                                                                           "cmptmp");
            case EXP_LESS_EQUAL:
                return fp ? context.builder.CreateFCmpOLE(L, R, "cmpftmp") : context.builder.CreateICmpSLE(L, R,
                                                                                                           "cmptmp");
            case EXP_GREATER_EQUAL:
                return fp ? context.builder.CreateFCmpOGE(L, R, "cmpftmp") : context.builder.CreateICmpSGE(L, R,
                                                                                                           "cmptmp");
            case EXP_GREATER:
                return fp ? context.builder.CreateFCmpOGT(L, R, "cmpftmp") : context.builder.CreateICmpSGT(L, R,
                                                                                                           "cmptmp");
            case EXP_EQUAL:
                return fp ? context.builder.CreateFCmpOEQ(L, R, "cmpftmp") : context.builder.CreateICmpEQ(L, R,
                                                                                                          "cmptmp");
            case EXP_NOT_EQUAL:
                return fp ? context.builder.CreateFCmpONE(L, R, "cmpftmp") : context.builder.CreateICmpNE(L, R,
                                                                                                          "cmptmp");
            default:
                return LogErrorV("Unknown binary operator");
        }
    }
    if (type == EXP_NOT) {
        Value *L = left->codeGen(context);
        if (!L) {
            return NULL;
        }
        return context.builder.CreateNot(L, "nottmp");
    }
    if (type == EXP_MINUS_SIGN) {
        Value *L = left->codeGen(context);
        if (!L) {
            return NULL;
        }
        return context.builder.CreateNeg(L, "negtmp");
    }
    if (type == EXP_VAR) {
        return var->codeGen(context);
    }
    if (type == EXP_CONST) {
        return constant->codeGen(context);
    }
    if (type == EXP_EXPV) {
        return expressionv->codeGen(context);
    }
    if (type == EXP_CALL) {
        return call->codeGen(context);
    }
    return NULL;
}

Value *VarNode::codeGen(CodeGenContext &context) {
    if (type == SINGLE) {
        Value *value = context.getSymbolValue(*identifier);
        if (!value) {
            return LogErrorV("Unknown variable name " + *identifier);
        }
        return context.builder.CreateLoad(value, false, "");
    } else {
        return array_access->codeGen(context);
    }
}

llvm::Value *IfStatementNode::codeGen(CodeGenContext &context) {
    Function *theFunction = context.builder.GetInsertBlock()->getParent();      // the function where if statement is in

    // 3 basic block
    BasicBlock *ifBodyBB = BasicBlock::Create(llvmContext, "then", theFunction);
    BasicBlock *elseBody = BasicBlock::Create(llvmContext, "else");
    BasicBlock *endBB = BasicBlock::Create(llvmContext, "ifcont");

    // compute value
    Value *condValue = expressionVNode->codeGen(context);
    condValue = CastToBoolean(context, condValue);

    // if has else
    if (elseBodyNode != NULL) {
        context.builder.CreateCondBr(condValue, ifBodyBB, elseBody);
    } else {
        context.builder.CreateCondBr(condValue, ifBodyBB, endBB);
    }

    // if body block begin
    context.builder.SetInsertPoint(ifBodyBB);
    ifBodyNode->codeGen(context);
    context.builder.CreateBr(endBB);

//  Not Need ?
//    ifBodyBB = context.builder.GetInsertBlock();
//    // jump to endBB
//    if( ifBodyBB->getTerminator() == NULL ){
//        context.builder.CreateBr(endBB);
//    }

    // begin elseBody
    if (elseBodyNode != NULL) {
        theFunction->getBasicBlockList().push_back(elseBody);
        context.builder.SetInsertPoint(elseBody);
        elseBodyNode->codeGen(context);
        context.builder.CreateBr(endBB);
    }

    theFunction->getBasicBlockList().push_back(endBB);
    context.builder.SetInsertPoint(endBB);
    return NULL;
}

llvm::Value *IfBodyNode::codeGen(CodeGenContext &context) {
    if (statementNode != NULL) {
        return statementNode->codeGen(context);
    }
    if (compoundStatementNode != NULL) {
        return compoundStatementNode->codeGen(context);
    }
    return NULL;
}

llvm::Value *SwitchStatementNode::codeGen(CodeGenContext &context) {
    // get function
    Function *theFunction = context.builder.GetInsertBlock()->getParent();      // the function where if statement is in
    BasicBlock *end = BasicBlock::Create(llvmContext, "switchEnd");

    // computer value
    Value *L = expressionVNode->codeGen(context);
    context.pushBlock(NULL);
    context.setBreakBlock(end);

    // 迭代过程需要用到的2 个 basic block
    BasicBlock *matchBB = BasicBlock::Create(llvmContext, "caseMatch");
    BasicBlock *unmatchBB = BasicBlock::Create(llvmContext, "caseUnMatch");
    LabeledStatementNode *defaultLabel = NULL;

    if (labeledStatementList != NULL) {
        for (int i = 0; i < labeledStatementList->size(); i++) {
            LabeledStatementNode *labeledStatementNode = (*labeledStatementList)[i];

            // if not default
            if (labeledStatementNode->type != LabeledStatementNode::TYPE_DEFAULT) {
                // 比较值
                Value* R = labeledStatementNode->constantNode->codeGen(context);
                bool fp = false;
                if ((L->getType()->getTypeID() == Type::DoubleTyID) || (R->getType()->getTypeID() == Type::DoubleTyID)) {
                    fp = true;
                    if ((R->getType()->getTypeID() != Type::DoubleTyID)) {
                        R = context.builder.CreateUIToFP(R, Type::getDoubleTy(llvmContext), "ftmp");
                    }
                    if ((L->getType()->getTypeID() != Type::DoubleTyID)) {
                        L = context.builder.CreateUIToFP(L, Type::getDoubleTy(llvmContext), "ftmp");
                    }
                }
                Value *result = fp ? context.builder.CreateFCmpOEQ(L, R, "cmpftmp") : context.builder.CreateICmpEQ(L, R, "cmptmp");;
                result = CastToBoolean(context, result);
                context.builder.CreateCondBr(result, matchBB, unmatchBB);
            } else {
                // default
                defaultLabel = (*labeledStatementList)[i];
                context.builder.CreateBr(unmatchBB);
            }

            // matchBB
            theFunction->getBasicBlockList().push_back(matchBB);
            context.builder.SetInsertPoint(matchBB);

            labeledStatementNode->codeGen(context);
            BasicBlock *nextMatch = BasicBlock::Create(llvmContext, "caseMatch");
            context.builder.CreateBr(nextMatch);

            // unmatch
            theFunction->getBasicBlockList().push_back(unmatchBB);
            context.builder.SetInsertPoint(unmatchBB);

            matchBB = nextMatch;
            unmatchBB = BasicBlock::Create(llvmContext, "caseUnMatch");
        }
    }

    // unmatch: go default
    if (defaultLabel != NULL) {
        defaultLabel->codeGen(context);
    }
    context.builder.CreateBr(end);

    // end
    theFunction->getBasicBlockList().push_back(matchBB);
    context.builder.SetInsertPoint(matchBB);
    context.builder.CreateBr(end);

    context.popBlock();
    // end
    theFunction->getBasicBlockList().push_back(end);
    context.builder.SetInsertPoint(end);

    return NULL;
}

llvm::Value *LabeledStatementNode::codeGen(CodeGenContext &context) {
    if (statements != NULL) {
        for (int i = 0; i < statements->size(); i++) {
            (*statements)[i]->codeGen(context);
        }
    }
    return NULL;
}

Value *ArrayAccessNode::codeGen(CodeGenContext &context) {
    auto varPtr = context.getSymbolValue(*identifier);
    auto type = context.getSymbolType(*identifier);
    uint32_t size = context.getArraySize(*identifier);
    if (size <= index) {
        return LogErrorV("out of range");
    }
    if (!varPtr) {
        return LogErrorV("Unknown variable name " + *identifier);
    }
    Value *array_index = ConstantInt::get(Type::getInt32Ty(llvmContext), index, true);
    ArrayRef<Value *> indices;
    indices = {ConstantInt::get(Type::getInt32Ty(llvmContext), 0), array_index};
    auto ptr = context.builder.CreateInBoundsGEP(varPtr, indices, "elementPtr");
    return context.builder.CreateAlignedLoad(ptr, 4);
}

Value *ConstantNode::codeGen(CodeGenContext &context) {
    if (type == TYPE_INT) {
        return ConstantInt::get(Type::getInt32Ty(llvmContext), integer, true);
    } else if (type == TYPE_DOUBLE) {
        return ConstantFP::get(Type::getDoubleTy(llvmContext), double_number);
    } else if (type == TYPE_CHAR) {
        return ConstantInt::get(Type::getInt8Ty(llvmContext), character, true);
    }
    return NULL;
}

Value *CallNode::codeGen(CodeGenContext &context) {
    Function *calleeF = context.theModule->getFunction(*identifier);
    if (!calleeF) {
        LogErrorV("Function name not found");
    }
    std::vector<Value *> argsv;
    if(args != NULL){
        if (calleeF->arg_size() != args->size()) {
            LogErrorV(
                    "Function arguments size not match, calleeF=" + std::to_string(calleeF->size()) + ", this->arguments=" +
                    std::to_string(args->size()));
        }

        for (auto it = args->begin(); it != args->end(); it++) {
            argsv.push_back((*it)->codeGen(context));
            if (!argsv.back()) {
                return NULL;
            }
        }
    }
    return context.builder.CreateCall(calleeF, argsv, "calltmp");
}

void CodeGenContext::generateCode(ProgramNode &root) {
    cout << "Generating IR code" << endl;
    pushBlock(NULL);
    Value* retValue = root.codeGen(*this);
    popBlock();
    cout << "Code generate success" << endl;

    PassManager passManager;
    passManager.add(createPrintModulePass(outs()));
    passManager.run(*(this->theModule.get()));
    return;
}

void LogError(const char *str) {
    fprintf(stderr, "LogError: %s\n", str);
}

Value *LogErrorV(string str){
    return LogErrorV(str.c_str());
}

Value *LogErrorV(const char *str) {
    LogError(str);
    return NULL;
}
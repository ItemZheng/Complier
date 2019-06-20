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

llvm::Value* ProgramNode::codeGen(CodeGenContext &context) {
    if (declaration_list != NULL) {
        for (int i = 0; i < declaration_list->size(); i++) {
            (*declaration_list)[i]->codeGen(context);
        }
    }
    return NULL;
}

llvm::Value* DeclarationNode::codeGen(CodeGenContext &context) {
    if(varDeclarationNode != NULL){
        varDeclarationNode->codeGen(context);
    } else if(functionDeclarationNode != NULL){
        functionDeclarationNode->codeGen(context);
    }
    return NULL;
}

llvm::Value* FunctionDeclarationNode::codeGen(CodeGenContext &context) {
    if(functionDeclNode != NULL){
        functionDeclNode->codeGen(context);
    } else if(functionDefinitionNode != NULL){
        functionDefinitionNode->codeGen(context);
    }
    return NULL;
}

llvm::Value* FunctionDeclNode::codeGen(CodeGenContext &context) {
    vector<llvm::Type*> args;
    if(function_args != NULL){
        for(int i = 0; i < function_args->size(); i++){
            args.push_back(typeOf((*function_args)[i]->type));
        }
    }
    FunctionType *functionType = FunctionType::get(typeOf(type), args, false);
    Function *F = Function::Create(functionType, GlobalValue::ExternalLinkage, identifier, context.theModule.get());
    if( F->getName() != identifier ) {
        F->eraseFromParent();
        F = context.theModule->getFunction(identifier);
    }

    // set identifier name
    int Idx = 0;
    for (Function::arg_iterator AI = F->arg_begin(); Idx != function_args->size(); ++AI, ++Idx)
        AI->setName((*function_args)[Idx]->identifier);
    return NULL;
}

llvm::Value* FunctionDefinitionNode::codeGen(CodeGenContext &context) {
    if(functionDeclNode != NULL){
        functionDeclNode->codeGen(context);
    }
    Function *F = context.theModule->getFunction(functionDeclNode->identifier);
    // already define
    if(!F->empty()){
        return NULL;
    }

    // define body
    BasicBlock *block = BasicBlock::Create(llvmContext, "entry", F);
    context.builder.SetInsertPoint(block); // insert instruction to end of block
    context.pushBlock(block);
    // register name values to symbol table
    if(functionDeclNode != NULL && functionDeclNode->function_args != NULL){
        int Idx = 0;
        for (Function::arg_iterator AI = F->arg_begin(); Idx != functionDeclNode->function_args->size(); ++AI, ++Idx){
            context.setSymbolValue((*(functionDeclNode->function_args))[Idx]->identifier, AI);
        }
    }

    // code generete body
    if(functionBodyNode != NULL){
        Value *ret = functionBodyNode->codeGen(context);
        context.builder.CreateRet(ret);
    }
    context.popBlock();
    return NULL;
}

llvm::Value* FunctionBodyNode::codeGen(CodeGenContext &context) {
    if(functionStatementsNode != NULL){
        return functionStatementsNode->codeGen(context);
    }
    return NULL;
}

llvm::Value* FunctionStatementsNode::codeGen(CodeGenContext &context) {
    if(statements != NULL){
        for(int i = 0; i < statements->size(); i++){
            (*statements)[i]->codeGen(context);
        }
    }
    if(returnStatementNode != NULL){
        return returnStatementNode->codeGen(context);
    }
    return NULL;
}

llvm::Value* ReturnStatementNode::codeGen(CodeGenContext &context) {
    if(expressionVNode != NULL){
        Value *ret = expressionVNode->codeGen(context);
        context.setCurrentReturnValue(ret);
        return ret;
    }
    return NULL;
}

llvm::Value* StatementNode::codeGen(CodeGenContext &context) {
    switch (type){
        case TYPE_VAR_DECLARATION:
            if(varDeclarationNode != NULL){
                varDeclarationNode->codeGen(context);
            }
            break;
        case TYPE_ITERATION:
            if(iterationStatementNode != NULL){
                iterationStatementNode->codeGen(context);
            }
            break;
        case TYPE_SELECTION:
            if(selectionStatementNode != NULL){
                selectionStatementNode->codeGen(context);
            }
            break;
        case TYPE_EXPRESSION:
            if(expressionStatementNode != NULL){
                expressionStatementNode->codeGen(context);
            }
            break;
        case TYPE_JUMP:
            if(jumpStatementNode != NULL){
                jumpStatementNode->codeGen(context);
            }
            break;
        default:
            break;
    }
    return NULL;
}

llvm::Value* ExpressionStatementNode::codeGen(CodeGenContext &context) {
    if(expressionVNode != NULL){
        return expressionVNode->codeGen(context);
    }
    return NULL;
}

llvm::Value* IterationStatementNode::codeGen(CodeGenContext &context) {
    Function* theFunction = context.builder.GetInsertBlock()->getParent();
    // 2 basic block
    BasicBlock *block = BasicBlock::Create(llvmContext, "forloop", theFunction);
    BasicBlock *after = BasicBlock::Create(llvmContext, "forcont");

    if (type == TYPE_WHILE || type == TYPE_DO_WHILE) {
        if(type == TYPE_WHILE ){
            // compute value
            Value* condValue = expressionVNode->codeGen(context);
            condValue = CastToBoolean(context, condValue);
            context.builder.CreateCondBr(condValue, block, after);
        }
        // loop body
        context.pushBlock(block);
        context.builder.SetInsertPoint(block);

        // set break and continue
        context.setBreakBlock(after);
        context.setContinueBlock(block);

        if(loopBodyNode != NULL){
            loopBodyNode->codeGen(context);
        } else if(compoundStatementNode != NULL){
            compoundStatementNode->codeGen(context);
        }

        // pop
        context.popBlock();

        // execute the again or stop
        Value* condValue = expressionVNode->codeGen(context);
        condValue = CastToBoolean(context, condValue);
        context.builder.CreateCondBr(condValue, block, after);

    } else if (type == TYPE_FOR) {
        // new scope
        context.pushBlock(block);

        // execute init
        ForInitListNode *forInitListNode = forConditionNode->forInitListNode;
        ExpressionVNode *forExpression = forConditionNode->forExpression;
        vector<ExpressionVNode *> *incrementExpressionList = forConditionNode->incrementExpressionList;
        if(forInitListNode != NULL){
            forInitListNode->codeGen(context);
        }

        // Compute Condition
        Value* condValue;
        if(forExpression == NULL){
            // 表达式为真
            condValue = ConstantFP::get(llvmContext, APFloat(1.0));
        } else {
            condValue = forExpression->codeGen(context);
        }
        if(!condValue){
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
        if(loopBodyNode != NULL){
            loopBodyNode->codeGen(context);
        }

        // do increment
        if(incrementExpressionList != NULL){
            for(int i = 0; i < incrementExpressionList->size(); i++){
                (*incrementExpressionList)[i]->codeGen(context);
            }
        }

        // compute value
        if(forExpression == NULL){
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

llvm::Value* ForConditionNode::codeGen(CodeGenContext &context) {
    return NULL;
}

llvm::Value* LoopBodyNode::codeGen(CodeGenContext &context) {
    if(statementNode != NULL){
        return statementNode->codeGen(context);
    }
    if(compoundStatementNode != NULL){
        return compoundStatementNode->codeGen(context);
    }
    return NULL;
}

llvm::Value* CompoundStatementNode::codeGen(CodeGenContext &context) {
    context.pushBlock(NULL);
    if(statements != NULL){
        for(int i = 0; i < statements->size(); i++){
            (*statements)[i]->codeGen(context);
        }
    }
    context.popBlock();
    return NULL;
}


llvm::Value* ForInitListNode::codeGen(CodeGenContext &context) {
    if(forDeclarationNode != NULL){
        forDeclarationNode->codeGen(context);
    }
    if(expressionList != NULL){
        for(int i = 0; i < expressionList->size(); i++){
            (*expressionList)[i]->codeGen(context);
        }
    }
    return NULL;
}

llvm::Value* ForDeclarationNode::codeGen(CodeGenContext &context) {
    if (varDeclarationList != NULL) {
        for (int i = 0; i < varDeclarationList->size(); i++) {
            VarDeclNode *varDeclNode = (*varDeclarationList)[i];
            varDeclNode->codeGen(context);
        }
    }
    return NULL;
}

llvm::Value* JumpStatementNode::codeGen(CodeGenContext &context) {
    BasicBlock *block;
    if(type == TYPE_CONTINUE){
        block = context.continueBlock();
    } else{
        block = context.breakBlock();
    }
    if(block != NULL){
        context.builder.CreateBr(block);
    }
    return NULL;
}

llvm::Value* SelectionStatementNode::codeGen(CodeGenContext &context) {
    if(ifStatementNode != NULL){
        ifStatementNode->codeGen(context);
    }
    if(switchStatementNode != NULL){
        switchStatementNode->codeGen(context);
    }
    return NULL;
}

llvm::Value* IfStatementNode::codeGen(CodeGenContext &context) {
    Function* theFunction = context.builder.GetInsertBlock()->getParent();      // the function where if statement is in

    // 3 basic block
    BasicBlock *ifBodyBB = BasicBlock::Create(llvmContext, "then", theFunction);
    BasicBlock *elseBody = BasicBlock::Create(llvmContext, "else");
    BasicBlock *endBB = BasicBlock::Create(llvmContext, "ifcont");

    // compute value
    Value* condValue = expressionVNode->codeGen(context);
    condValue = CastToBoolean(context, condValue);

    // if has else
    if( elseBodyNode != NULL ){
        context.builder.CreateCondBr(condValue, ifBodyBB, elseBody);
    } else{
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
    if(elseBodyNode != NULL){
        theFunction->getBasicBlockList().push_back(elseBody);
        context.builder.SetInsertPoint(elseBody);
        elseBodyNode->codeGen(context);
        context.builder.CreateBr(endBB);
    }

    theFunction->getBasicBlockList().push_back(endBB);
    context.builder.SetInsertPoint(endBB);
    return NULL;
}

llvm::Value* IfBodyNode::codeGen(CodeGenContext &context) {
    if(statementNode != NULL){
        return statementNode->codeGen(context);
    }
    if(compoundStatementNode != NULL){
        return compoundStatementNode->codeGen(context);
    }
    return NULL;
}

llvm::Value* SwitchStatementNode::codeGen(CodeGenContext &context) {
    // get function
    Function* theFunction = context.builder.GetInsertBlock()->getParent();      // the function where if statement is in
    BasicBlock *end = BasicBlock::Create(llvmContext, "switchEnd");

    // computer value
    Value * value = expressionVNode->codeGen(context);
    context.pushBlock(NULL);
    context.setBreakBlock(end);

    // 迭代过程需要用到的2 个 basic block
    BasicBlock* matchBB = BasicBlock::Create(llvmContext, "caseMatch");
    BasicBlock* unmatchBB = BasicBlock::Create(llvmContext, "caseUnMatch");
    LabeledStatementNode *defaultLabel = NULL;

    if(labeledStatementList != NULL){
        for(int i = 0; i < labeledStatementList->size(); i++){
            LabeledStatementNode *labeledStatementNode = (*labeledStatementList)[i];

            // if not default
            if(labeledStatementNode->type != LabeledStatementNode::TYPE_DEFAULT){
                // 比较值
                // todo
                Value *result = NULL;
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
            BasicBlock* nextMatch = BasicBlock::Create(llvmContext, "caseMatch");
            context.builder.CreateBr(nextMatch);

            // unmatch
            theFunction->getBasicBlockList().push_back(unmatchBB);
            context.builder.SetInsertPoint(unmatchBB);

            matchBB = nextMatch;
            unmatchBB = BasicBlock::Create(llvmContext, "caseUnMatch");
        }
    }

    // end
    theFunction->getBasicBlockList().push_back(matchBB);
    context.builder.SetInsertPoint(matchBB);
    context.builder.CreateBr(end);

    // unmatch: go default
    theFunction->getBasicBlockList().push_back(unmatchBB);
    context.builder.SetInsertPoint(unmatchBB);
    if(defaultLabel != NULL){
        defaultLabel->codeGen(context);
    }
    context.builder.CreateBr(end);

    context.popBlock();
    // end
    theFunction->getBasicBlockList().push_back(end);
    context.builder.SetInsertPoint(end);

    return NULL;
}

llvm::Value* LabeledStatementNode ::codeGen(CodeGenContext &context) {
    if(statements != NULL){
        for(int i = 0; i < statements->size(); i++){
            (*statements)[i]->codeGen(context);
        }
    }
    return NULL;
}
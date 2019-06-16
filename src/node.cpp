#include "node.h"
#include<string>

using namespace std;

Node::Node() {
    this->lineno = yylineno;
    this->text = string(yytext);
}

VarDeclarationNode::VarDeclarationNode(type_var type, vector<VarDeclNode *> *vdl) {
    this->type = type;
    this->var_declaration_list = vdl;
}

void VarDeclarationNode::buildSymbolTable() {
    if(var_declaration_list != NULL){
        for(int i = 0; i < var_declaration_list->size(); i++){
            VarDeclNode *varDeclNode = (*var_declaration_list)[i];
            varDeclNode->typeVar = this->type;
            varDeclNode->buildSymbolTable();
        }
    }
}

VarDeclNode::VarDeclNode(type_identifier type, string *identifier,
                         ArrayIdentifierNode *array_identifier, int assign, ExpressionVNode *expressionv,
                         ArrayInitNode *array_init) {
    this->type = type;
    this->identifier = identifier;
    this->array_identifier = array_identifier;
    this->assign = assign;
    this->expressionv = expressionv;
    this->array_init = array_init;
}

void VarDeclNode::buildSymbolTable() {
    SymbolNode * node = NULL;
    if(type == SINGLE){
        node = new SymbolNode(lineno, *identifier, type, typeVar, symTab->getLevel());
    } else {
        node = new SymbolNode(lineno, *(array_identifier->identifier), type, typeVar, symTab->getLevel());
    }
    Error *err = symTab->sym_insert(node);
    if(err != NULL){
        err->Print();
        exit(1);
    }

    if(assign){
        if(type == SINGLE){
            if(expressionv != NULL){
                expressionv->buildSymbolTable();
            }
        } else{
            if(array_init != NULL){
                array_init->buildSymbolTable();
            }
        }
    }
}

ArrayIdentifierNode::ArrayIdentifierNode(string *identifier, int size) {
    this->identifier = identifier;
    this->size = size;
}

void ArrayIdentifierNode::buildSymbolTable() {}

ArrayAccessNode::ArrayAccessNode(string *identifier, int index) {
    this->identifier = identifier;
    this->index = index;
}

void ArrayAccessNode::buildSymbolTable() {
    SymbolNode * node = symTab->sym_look_up(*identifier);
    if(node == NULL){
        Error* err = new Error(Error::ERROR_UNDECLARED, lineno, *identifier);
        err->Print();
        exit(1);
    }
}

ArrayInitNode::ArrayInitNode(vector<ArrayInitNode *> *array_init,
                             vector<ExpressionVNode *> *expressionvs) {
    this->array_init = array_init;
    this->expressionvs = expressionvs;
}

void ArrayInitNode::buildSymbolTable() {
    if(array_init != NULL){
        for(int i = 0; i < array_init->size(); i++){
            (*array_init)[i]->buildSymbolTable();
        }
    }
    if(expressionvs != NULL){
        for(int i = 0; i < expressionvs->size(); i++){
            (*expressionvs)[i]->buildSymbolTable();
        }
    }
}

ExpressionVNode::ExpressionVNode(vector<VarNode *> *var_list, ExpressionNode *expression) {
    this->var_list = var_list;
    this->expression = expression;
}

void ExpressionVNode::buildSymbolTable() {
    if(var_list != NULL){
        for(int i = 0; i < var_list->size(); i++){
            (*var_list)[i]->buildSymbolTable();
        }
    }
    if(expression != NULL){
        expression->buildSymbolTable();
    }
}

VarNode::VarNode(type_identifier type, string *identifier, ArrayAccessNode *array_access) {
    this->type = type;
    this->identifier = identifier;
    this->array_access = array_access;
}

void VarNode::buildSymbolTable() {
    if(type == SINGLE){
        SymbolNode * node = symTab->sym_look_up(*identifier);
        if(node == NULL){
            Error* err = new Error(Error::ERROR_UNDECLARED, lineno, *identifier);
            err->Print();
            exit(1);
        }
    }
    else if(array_access != NULL){
        array_access->buildSymbolTable();
    }
}

ExpressionNode::ExpressionNode(type_expression type, ExpressionNode *left, ExpressionNode *right,
                               VarNode *var, ConstantNode *constant, CallNode *call, ExpressionVNode *expressionv) {
    this->type = type;
    this->left = left;
    this->right = right;
    this->var = var;
    this->constant = constant;
    this->call = call;
    this->expressionv = expressionv;
}

void ExpressionNode::buildSymbolTable() {
    switch (type){
        case EXP_PLUS:
        case EXP_MINUS:
        case EXP_MUL:
        case EXP_DIV:
        case EXP_MOD:
        case EXP_LESS:
        case EXP_LESS_EQUAL:
        case EXP_GREATER:
        case EXP_GREATER_EQUAL:
        case EXP_AND_AND:
        case EXP_OR_OR:
        case EXP_EQUAL:
        case EXP_NOT_EQUAL:
            if(left != NULL){
                left->buildSymbolTable();
            }
            if(right != NULL){
                right->buildSymbolTable();
            }
            break;
        case EXP_EXPV:
            if(expressionv != NULL){
                expressionv->buildSymbolTable();
            }
            break;
        case EXP_NOT:
        case EXP_MINUS_SIGN:
            if(left != NULL){
                left->buildSymbolTable();
            }
            break;
        case EXP_PLUS_PLUS_L:
        case EXP_PLUS_PLUS_R:
        case EXP_MINUS_MINUS_L:
        case EXP_MINUS_MINUS_R:
        case EXP_VAR:
            if(var != NULL){
                var->buildSymbolTable();
            }
            break;
        case EXP_CALL:
            if(call != NULL){
                call->buildSymbolTable();
            }
            break;
        case EXP_CONST:
            if(constant != NULL){
                constant->buildSymbolTable();
            }
            break;
    }
}

ProgramNode::ProgramNode(vector<DeclarationNode *> *declaration_list) {
    this->declaration_list = declaration_list;
}

void ProgramNode::buildSymbolTable() {
    if (declaration_list != NULL) {
        for (int i = 0; i < declaration_list->size(); i++) {
            (*declaration_list)[i]->buildSymbolTable();
        }
    }
}

DeclarationNode::DeclarationNode(VarDeclarationNode *varDeclarationNode) {
    this->varDeclarationNode = varDeclarationNode;
    this->functionDeclarationNode = NULL;
}

void DeclarationNode::buildSymbolTable() {
    if (varDeclarationNode != NULL) {
        varDeclarationNode->buildSymbolTable();
    } else if (functionDeclarationNode != NULL) {
        functionDeclarationNode->buildSymbolTable();
    }
}

FunctionDeclarationNode::FunctionDeclarationNode(FunctionDeclNode *functionDeclNode) {
    this->functionDeclNode = functionDeclNode;
    this->functionDefinitionNode = NULL;
}

void FunctionDeclarationNode::buildSymbolTable() {
    if (functionDeclNode != NULL) {
        functionDeclNode->buildSymbolTable();
    } else if (functionDefinitionNode != NULL) {
        functionDefinitionNode->buildSymbolTable();
    }
}

FunctionDeclarationNode::FunctionDeclarationNode(FunctionDefinitionNode *functionDefinitionNode) {
    this->functionDefinitionNode = functionDefinitionNode;
    this->functionDeclNode = NULL;
}

DeclarationNode::DeclarationNode(FunctionDeclarationNode *functionDeclarationNode) {
    this->functionDeclarationNode = functionDeclarationNode;
    this->varDeclarationNode = NULL;
}

FunctionDefinitionNode::FunctionDefinitionNode(FunctionDeclNode *functionDeclNode, FunctionBodyNode *functionBodyNode) {
    this->functionBodyNode = functionBodyNode;
    this->functionDeclNode = functionDeclNode;
}

void FunctionDefinitionNode::buildSymbolTable() {
    if (functionDeclNode != NULL) {
        functionDeclNode->buildSymbolTable();
    }
    SymbolNode *node = new SymbolNode(functionDeclNode->lineno, functionDeclNode->identifier, SINGLE, TYPE_FUNC,
                                      symTab->getLevel());
    node->func_type = SymbolNode::FUNC_DEFINE;
    Error *err = symTab->sym_insert(node);
    if (err != NULL) {
        err->Print();
        exit(1);
    }
    symTab->enterScope();
    // new scope
    // define argus
    if (functionDeclNode->function_args != NULL) {
        for (int i = 0; i < functionDeclNode->function_args->size(); i++) {
            (*(functionDeclNode->function_args))[i]->buildSymbolTable();
        }
    }
    functionBodyNode->buildSymbolTable();
    symTab->quitScope();
}

FunctionDeclNode::FunctionDeclNode(type_var type, string identifier, vector<FunctionArgNode *> *function_args) {
    this->type = type;
    this->identifier = identifier;
    this->function_args = function_args;
}

void FunctionDeclNode::buildSymbolTable() {
    SymbolNode *node = new SymbolNode(lineno, identifier, SINGLE, TYPE_FUNC, symTab->getLevel());
    node->func_type = SymbolNode::FUNC_DEC;
    Error *err = symTab->sym_insert(node);
    if (err != NULL) {
        err->Print();
        exit(1);
    }
}

FunctionArgNode::FunctionArgNode(type_var type, string identifier) {
    this->type = type;
    this->identifier = identifier;
}

void FunctionArgNode::buildSymbolTable() {
    SymbolNode *node = new SymbolNode(lineno, identifier, SINGLE, type, symTab->getLevel());
    Error *err = symTab->sym_insert(node);
    if (err != NULL) {
        err->Print();
        exit(1);
    }
}

FunctionBodyNode::FunctionBodyNode(FunctionStatementsNode *functionStatementsNode) {
    this->functionStatementsNode = functionStatementsNode;
}

void FunctionBodyNode::buildSymbolTable() {
    if(functionStatementsNode != NULL){
        functionStatementsNode->buildSymbolTable();
    }
}

FunctionStatementsNode::FunctionStatementsNode(vector<StatementNode *> *statements,
                                               ReturnStatementNode *returnStatementNode) {
    this->statements = statements;
    this->returnStatementNode = returnStatementNode;
}

void FunctionStatementsNode::buildSymbolTable() {
    if(statements != NULL){
        for(int i = 0; i < statements->size(); i++){
            (*statements)[i]->buildSymbolTable();
        }
    }
    if(returnStatementNode != NULL){
        returnStatementNode->buildSymbolTable();
    }
}

ReturnStatementNode::ReturnStatementNode(ExpressionVNode *expressionVNode) {
    this->expressionVNode = expressionVNode;
}

void ReturnStatementNode::buildSymbolTable() {
    if(expressionVNode != NULL){
        expressionVNode->buildSymbolTable();
    }
}

StatementNode::StatementNode() {
    this->varDeclarationNode = NULL;
    this->iterationStatementNode = NULL;
    this->selectionStatementNode = NULL;
    this->expressionStatementNode = NULL;
    this->jumpStatementNode = NULL;
}

StatementNode::StatementNode(VarDeclarationNode *varDeclarationNode) {
    StatementNode();
    this->varDeclarationNode = varDeclarationNode;
    this->type = TYPE_VAR_DECLARATION;
}

StatementNode::StatementNode(IterationStatementNode *iterationStatementNode) {
    StatementNode();
    this->iterationStatementNode = iterationStatementNode;
    this->type = TYPE_ITERATION;
}

StatementNode::StatementNode(SelectionStatementNode *selectionStatementNode) {
    StatementNode();
    this->selectionStatementNode = selectionStatementNode;
    this->type = TYPE_SELECTION;
}

StatementNode::StatementNode(ExpressionStatementNode *expressionStatementNode) {
    StatementNode();
    this->expressionStatementNode = expressionStatementNode;
    this->type = TYPE_EXPRESSION;
}

StatementNode::StatementNode(JumpStatementNode *jumpStatementNode) {
    StatementNode();
    this->jumpStatementNode = jumpStatementNode;
    this->type = TYPE_JUMP;
}

void StatementNode::buildSymbolTable() {
    switch (type){
        case TYPE_VAR_DECLARATION:
            if(varDeclarationNode != NULL){
                varDeclarationNode->buildSymbolTable();
            }
            break;
        case TYPE_ITERATION:
            if(iterationStatementNode != NULL){
                iterationStatementNode->buildSymbolTable();
            }
            break;
        case TYPE_SELECTION:
            if(selectionStatementNode != NULL){
                selectionStatementNode->buildSymbolTable();
            }
            break;
        case TYPE_EXPRESSION:
            if(expressionStatementNode != NULL){
                expressionStatementNode->buildSymbolTable();
            }
            break;
        case TYPE_JUMP:
            if(jumpStatementNode != NULL){
                jumpStatementNode->buildSymbolTable();
            }
            break;
    }
}

ExpressionStatementNode::ExpressionStatementNode(ExpressionVNode *expressionVNode) {
    this->expressionVNode = expressionVNode;
}

void ExpressionStatementNode::buildSymbolTable() {
    if(expressionVNode != NULL){
        expressionVNode->buildSymbolTable();
    }
}

IterationStatementNode::IterationStatementNode() {
    this->expressionVNode = NULL;
    this->loopBodyNode = NULL;
    this->compoundStatementNode = NULL;
    this->forConditionNode = NULL;
}

IterationStatementNode::IterationStatementNode(ExpressionVNode *expressionVNode, LoopBodyNode *loopBodyNode) {
    IterationStatementNode();
    this->expressionVNode = expressionVNode;
    this->loopBodyNode = loopBodyNode;
    this->type = TYPE_WHILE;
}

IterationStatementNode::IterationStatementNode(CompoundStatementNode *compoundStatementNode,
                                               ExpressionVNode *expressionVNode) {
    IterationStatementNode();
    this->compoundStatementNode = compoundStatementNode;
    this->expressionVNode = expressionVNode;
    this->type = TYPE_DO_WHILE;
}

IterationStatementNode::IterationStatementNode(ForConditionNode *forConditionNode, LoopBodyNode *loopBodyNode) {
    IterationStatementNode();
    this->forConditionNode = forConditionNode;
    this->loopBodyNode = loopBodyNode;
    this->type = TYPE_FOR;
}

void IterationStatementNode::buildSymbolTable() {
    if(type == TYPE_WHILE){
        symTab->enterScope();
        if(expressionVNode != NULL){
            expressionVNode->buildSymbolTable();
        }
        if(loopBodyNode != NULL){
            loopBodyNode->buildSymbolTable();
        }
        symTab->quitScope();
    } else if(type == TYPE_DO_WHILE){
        symTab->enterScope();
        if(compoundStatementNode != NULL){
            compoundStatementNode->buildSymbolTable();
        }
        symTab->quitScope();
        if(expressionVNode != NULL){
            expressionVNode->buildSymbolTable();
        }
    } else if(type == TYPE_FOR){
        symTab->enterScope();
        if(forConditionNode != NULL){
            forConditionNode->buildSymbolTable();
        }
        if(loopBodyNode != NULL){
            loopBodyNode->buildSymbolTable();
        }
        symTab->quitScope();
    }
}

LoopBodyNode::LoopBodyNode(StatementNode *statementNode) {
    this->statementNode = statementNode;
    this->compoundStatementNode = NULL;
}

LoopBodyNode::LoopBodyNode(CompoundStatementNode *compoundStatementNode) {
    this->compoundStatementNode = compoundStatementNode;
    this->statementNode = NULL;
}

void LoopBodyNode::buildSymbolTable() {
    if(statementNode != NULL){
        statementNode->buildSymbolTable();
    } else if(compoundStatementNode != NULL){
        symTab->enterScope();
        compoundStatementNode->buildSymbolTable();
        symTab->quitScope();
    }
}

CompoundStatementNode::CompoundStatementNode(vector<StatementNode *> *statements) {
    this->statements = statements;
}

void CompoundStatementNode::buildSymbolTable() {
    if(statements != NULL){
        for(int i = 0; i < statements->size(); i++){
            (*statements)[i]->buildSymbolTable();
        }
    }
}

ForConditionNode::ForConditionNode(ForInitListNode *forInitListNode, ExpressionVNode *forExpression,
                                   vector<ExpressionVNode *> *incrementExpressionList) {
    this->forInitListNode = forInitListNode;
    this->forExpression = forExpression;
    this->incrementExpressionList = incrementExpressionList;
}

void ForConditionNode::buildSymbolTable() {
    if(forInitListNode != NULL){
        forInitListNode->buildSymbolTable();
    }
    if(forExpression != NULL){
        forExpression->buildSymbolTable();
    }
    if(incrementExpressionList != NULL){
        for(int i = 0; i < incrementExpressionList->size(); i++){
            (*incrementExpressionList)[i]->buildSymbolTable();
        }
    }
}

void ForInitListNode::buildSymbolTable() {
    if(expressionList != NULL){
        for(int i = 0; i < expressionList->size(); i++){
            (*expressionList)[i]->buildSymbolTable();
        }
    } else if(forDeclarationNode != NULL){
        forDeclarationNode->buildSymbolTable();
    }
}

ConstantNode::ConstantNode(type_var type, int integer, double double_number, char character) {
    this->type = type;
    this->integer = integer;
    this->double_number = double_number;
    this->character = character;
}

void ConstantNode::buildSymbolTable() {}

CallNode::CallNode(string *identifier, vector<ExpressionVNode *> *args) {
    this->identifier = identifier;
    this->args = args;
}

void CallNode::buildSymbolTable() {
    if(identifier != NULL){
        SymbolNode * node = symTab->sym_look_up(*identifier);
        if(node == NULL){
            Error* err = new Error(Error::ERROR_UNDECLARED_FUNCTION, lineno, *identifier);
            err->Print();
            exit(1);
        }
    }
    if(args != NULL){
        for(int i = 0; i < args->size(); i++){
            (*args)[i]->buildSymbolTable();
        }
    }
}

ForInitListNode::ForInitListNode() {
    this->expressionList = NULL;
    this->forDeclarationNode = NULL;
}

ForInitListNode::ForInitListNode(vector<ExpressionVNode *> *expressionList) {
    ForInitListNode();
    this->expressionList = expressionList;
}

ForInitListNode::ForInitListNode(ForDeclarationNode *forDeclarationNode) {
    ForInitListNode();
    this->forDeclarationNode = forDeclarationNode;
}

ForDeclarationNode::ForDeclarationNode(type_var type, vector<VarDeclNode *> *varDeclarationList) {
    this->type = type;
    this->varDeclarationList = varDeclarationList;
}

void ForDeclarationNode::buildSymbolTable() {
    if(varDeclarationList != NULL){
        for(int i = 0; i < varDeclarationList->size(); i++){
            VarDeclNode * varDeclNode = (*varDeclarationList)[i];
            varDeclNode->typeVar = this->type;
            varDeclNode->buildSymbolTable();
        }
    }
}

JumpStatementNode::JumpStatementNode(int type) {
    this->type = type;
}

void JumpStatementNode::buildSymbolTable() {}

SelectionStatementNode::SelectionStatementNode(IfStatementNode *ifStatementNode) {
    this->ifStatementNode = ifStatementNode;
    this->switchStatementNode = NULL;
}

SelectionStatementNode::SelectionStatementNode(SwitchStatementNode *switchStatementNode) {
    this->switchStatementNode = switchStatementNode;
    this->ifStatementNode = NULL;
}

void SelectionStatementNode::buildSymbolTable() {
    if(ifStatementNode != NULL){
        ifStatementNode->buildSymbolTable();
    } else if(switchStatementNode != NULL){
        switchStatementNode->buildSymbolTable();
    }
}

IfStatementNode::IfStatementNode(ExpressionVNode *expressionVNode, IfBodyNode *ifBodyNode) {
    this->expressionVNode = expressionVNode;
    this->ifBodyNode = ifBodyNode;
    this->elseBodyNode = NULL;
}

IfStatementNode::IfStatementNode(ExpressionVNode *expressionVNode, IfBodyNode *ifBodyNode, IfBodyNode *elseBodyNode) {
    IfStatementNode(expressionVNode, ifBodyNode);
    this->elseBodyNode = elseBodyNode;
}

void IfStatementNode::buildSymbolTable() {
    if(expressionVNode != NULL){
        expressionVNode->buildSymbolTable();
    }
    if(ifBodyNode != NULL){
        ifBodyNode->buildSymbolTable();
    }
}

IfBodyNode::IfBodyNode(CompoundStatementNode *compoundStatementNode) {
    this->statementNode = NULL;
    this->compoundStatementNode = compoundStatementNode;
}

IfBodyNode::IfBodyNode(StatementNode *statementNode) {
    this->statementNode = statementNode;
    this->compoundStatementNode = NULL;
}

void IfBodyNode::buildSymbolTable() {
    if(compoundStatementNode != NULL){
        symTab->enterScope();
        compoundStatementNode->buildSymbolTable();
        symTab->quitScope();
    } else if(statementNode != NULL){
        statementNode->buildSymbolTable();
    }
}

SwitchStatementNode::SwitchStatementNode(ExpressionVNode *expressionVNode,
                                         vector<LabeledStatementNode *> *labeledStatementList) {
    this->expressionVNode = expressionVNode;
    this->labeledStatementList = labeledStatementList;
}

void SwitchStatementNode::buildSymbolTable() {
    if(expressionVNode != NULL){
        expressionVNode->buildSymbolTable();
    }
    if(labeledStatementList != NULL){
        symTab->enterScope();
        for(int i = 0; i < labeledStatementList->size(); i++){
            (*labeledStatementList)[i]->buildSymbolTable();
        }
        symTab->quitScope();
    }
}

LabeledStatementNode::LabeledStatementNode(vector<StatementNode *> *statements) {
    this->constantNode = NULL;
    this->statements = statements;
    this->type = TYPE_DEFAULT;
}

void LabeledStatementNode::buildSymbolTable() {
    if(statements != NULL){
        for(int i = 0; i < statements->size(); i++){
            (*statements)[i]->buildSymbolTable();
        }
    }
}

LabeledStatementNode::LabeledStatementNode(ConstantNode *constantNode, vector<StatementNode *> *statements) {
    this->constantNode = constantNode;
    this->type = TYPE_CASE;
    this->statements = statements;
}
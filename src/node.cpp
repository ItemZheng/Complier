#include "node.h"
#include<string>
#include<iostream>

using namespace std;

Node::Node() {
    this->lineno = yylineno;
    this->text = string(yytext);
}

VarDeclarationNode::VarDeclarationNode(type_var type, vector<VarDeclNode *> *vdl) {
    this->type = type;
    this->var_declaration_list = vdl;
}

void VarDeclarationNode::visit() {
    switch (type) {
        case TYPE_INT:
            cout << "int" << " ";
            break;
        case TYPE_LONG:
            cout << "long" << " ";
            break;
        case TYPE_FLOAT:
            cout << "float" << " ";
            break;
        case TYPE_SHORT:
            cout << "short" << " ";
            break;
        case TYPE_VOID:
            cout << "void" << " ";
            break;
        case TYPE_DOUBLE:
            cout << "double" << " ";
            break;
        case TYPE_CHAR:
            cout << "char" << " ";
            break;
        default:
            cout << "undefined type" << " ";
            break;
    }
    int size = (*var_declaration_list).size();
    for (int i = 0; i < size; i++) {
        (*var_declaration_list)[i]->visit();
    }
    cout << endl;
}

void VarDeclarationNode::buildSymbolTable() {
    if (var_declaration_list != NULL) {
        for (int i = 0; i < var_declaration_list->size(); i++) {
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

void VarDeclNode::visit() {
    if (type == SINGLE) {
        cout << " (singel) ";
        if (assign == 0) {
            cout << "(not assign)" << " " << *identifier << " | ";
        } else if (assign == 1) {
            cout << "(assign)" << " " << *identifier << " = ";
            if (expressionv != NULL) {
                expressionv->visit();
                cout << " | ";
            } else {
                cout << "error: single assign" << " | ";
            }
        }
    } else if (type == ARRAY) {
        cout << " (array) ";
        if (assign == 0) {
            cout << "(not assign)" << " ";
            if (array_identifier != NULL) {
                array_identifier->visit();
                cout << " | ";
            } else {
                cout << "error: array_identifier" << " | ";
            }
        } else if (assign == 1) {
            cout << "(assign)" << " ";
            if (array_identifier != NULL) {
                array_identifier->visit();
                cout << " = ";
                if (array_init != NULL) {
                    array_init->visit();
                    cout << " | ";
                } else {
                    cout << " = " << "error: array assign" << " | ";
                }
            } else {
                cout << "error: array_identifier" << " | ";
            }
        }
    } else {
        cout << "error: type_identifier" << endl;
    }
}

void VarDeclNode::buildSymbolTable() {
    SymbolNode *node = NULL;
    if (type == SINGLE) {
        node = new SymbolNode(lineno, *identifier, type, typeVar, symTab->getLevel());
    } else {
        node = new SymbolNode(lineno, *(array_identifier->identifier), type, typeVar, symTab->getLevel());
    }
    Error *err = symTab->sym_insert(node);
    if (err != NULL) {
        err->Print();
        exit(1);
    }

    if (assign) {
        if (type == SINGLE) {
            if (expressionv != NULL) {
                expressionv->buildSymbolTable();
            }
        } else {
            if (array_init != NULL) {
                array_init->buildSymbolTable();
            }
        }
    }
}

ArrayIdentifierNode::ArrayIdentifierNode(string *identifier, int size) {
    this->identifier = identifier;
    this->size = size;
}

void ArrayIdentifierNode::visit() {
    cout << *identifier << "[" << size << "]";
}

void ArrayIdentifierNode::buildSymbolTable() {}

ArrayAccessNode::ArrayAccessNode(string *identifier, int index) {
    this->identifier = identifier;
    this->index = index;
}

void ArrayAccessNode::visit() {
    cout << *identifier << "[" << index << "]";
}

void ArrayAccessNode::buildSymbolTable() {
    SymbolNode *node = symTab->sym_look_up(*identifier);
    if (node == NULL) {
        Error *err = new Error(Error::ERROR_UNDECLARED, lineno, *identifier);
        err->Print();
        exit(1);
    }
    nodeTypeIdentifier = SINGLE;
    nodeTypeVar = node->typeVar;
}

ArrayInitNode::ArrayInitNode(vector<ArrayInitNode *> *array_init,
                             vector<ExpressionVNode *> *expressionvs) {
    this->array_init = array_init;
    this->expressionvs = expressionvs;
}

void ArrayInitNode::visit() {
    cout << " { ";
    if (array_init != NULL) {
        int size = (*array_init).size();
        for (int i = 0; i < size; i++) {
            (*array_init)[i]->visit();
        }
    }
    if (expressionvs != NULL) {
        int size = (*expressionvs).size();
        for (int i = 0; i < size; i++) {
            cout << " < ";
            (*expressionvs)[i]->visit();
            cout << " > ";
        }
    }
    cout << " } ";
}

void ArrayInitNode::buildSymbolTable() {
    if (array_init != NULL) {
        for (int i = 0; i < array_init->size(); i++) {
            (*array_init)[i]->buildSymbolTable();
        }
    }
    if (expressionvs != NULL) {
        for (int i = 0; i < expressionvs->size(); i++) {
            (*expressionvs)[i]->buildSymbolTable();
        }
    }
}

ExpressionVNode::ExpressionVNode(vector<VarNode *> *var_list, ExpressionNode *expression) {
    this->var_list = var_list;
    this->expression = expression;
}

void ExpressionVNode::visit() {
    if (var_list != NULL) {
        int size = (*var_list).size();
        for (int i = size - 1; i >= 0; i--) {
            (*var_list)[i]->visit();
            cout << " = ";
        }
    }
    if (expression != NULL) {
        expression->visit();
    }
}

void ExpressionVNode::buildSymbolTable() {
    if (var_list != NULL) {
        for (int i = 0; i < var_list->size(); i++) {
            (*var_list)[i]->buildSymbolTable();
        }
    }
    if (expression != NULL) {
        expression->buildSymbolTable();
        nodeTypeVar = expression->nodeTypeVar;
        nodeTypeIdentifier = expression->nodeTypeIdentifier;
        nodeSize = expression->nodeSize;
    }
    if (var_list != NULL) {
        for (int j = 0; (j + 1) < var_list->size(); j++) {
            if(!typeEqual((*var_list)[j], (*var_list)[j + 1])){
                Error *err = new Error(Error::ERROR_TYPE_NOT_MATCH, lineno, string(""));
                err->Print();
                exit(1);
            }
        }
        if (expression != NULL) {
            if (var_list->size() > 0) {
                if (!typeEqual((*var_list)[0], expression)) {
                    Error *err = new Error(Error::ERROR_TYPE_NOT_MATCH, lineno, string(""));
                    err->Print();
                    exit(1);
                }
            }
        }
    }
}

VarNode::VarNode(type_identifier type, string *identifier, ArrayAccessNode *array_access) {
    this->type = type;
    this->identifier = identifier;
    this->array_access = array_access;
}

void VarNode::visit() {
    switch (type) {
        case SINGLE:
            cout << " (signle) ";
            break;
        case ARRAY:
            cout << " (array) ";
            break;
        default:
            cout << "error: type_identifier" << endl;
            break;
    }
    if (type == SINGLE) {
        cout << *identifier << " ";
    } else {
        array_access->visit();
    }
}

void VarNode::buildSymbolTable() {
    if (type == SINGLE) {
        SymbolNode *node = symTab->sym_look_up(*identifier);
        if (node == NULL) {
            Error *err = new Error(Error::ERROR_UNDECLARED, lineno, *identifier);
            err->Print();
            exit(1);
        }
        nodeTypeIdentifier = node->typeIdentifier;
        nodeTypeVar = node->typeVar;
    } else if (array_access != NULL) {
        array_access->buildSymbolTable();
        nodeTypeIdentifier = array_access->nodeTypeIdentifier;
        nodeTypeVar = array_access->nodeTypeVar;
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

void ExpressionNode::visit() {
    if (type == EXP_PLUS || type == EXP_MINUS || type == EXP_MUL || type == EXP_DIV ||
        type == EXP_MOD || type == EXP_LESS || type == EXP_LESS_EQUAL || type == EXP_GREATER ||
        type == EXP_GREATER_EQUAL || type == EXP_AND_AND || type == EXP_OR_OR || type == EXP_EQUAL ||
        type == EXP_NOT_EQUAL) {
        if (left != NULL) {
            left->visit();
        } else {
            cout << "error: left is null" << endl;
        }
        switch (type) {
            case EXP_PLUS:
                cout << " + ";
                break;
            case EXP_MINUS:
                cout << " - ";
                break;
            case EXP_MUL:
                cout << " * ";
                break;
            case EXP_DIV:
                cout << " / ";
                break;
            case EXP_MOD:
                cout << " % ";
                break;
            case EXP_LESS:
                cout << " < ";
                break;
            case EXP_LESS_EQUAL:
                cout << " <= ";
                break;
            case EXP_GREATER:
                cout << " > ";
                break;
            case EXP_GREATER_EQUAL:
                cout << " >= ";
                break;
            case EXP_AND_AND:
                cout << " && ";
                break;
            case EXP_OR_OR:
                cout << " || ";
                break;
            case EXP_EQUAL:
                cout << " == ";
                break;
            case EXP_NOT_EQUAL:
                cout << " != ";
                break;
            default:
                break;
        }
        if (right != NULL) {
            right->visit();
        } else {
            cout << "error: right is null" << endl;
        }
    } else if (type == EXP_NOT) {
        cout << " ! ";
        if (left != NULL) {
            left->visit();
        } else {
            cout << "error: left is null" << endl;
        }
    } else if (type == EXP_MINUS_SIGN) {
        cout << " - ";
        if (left != NULL) {
            left->visit();
        } else {
            cout << "error: left is null" << endl;
        }
    } else if (type == EXP_PLUS_PLUS_L || type == EXP_MINUS_MINUS_L) {
        switch (type) {
            case EXP_PLUS_PLUS_L:
                cout << " ++ ";
                break;
            case EXP_MINUS_MINUS_L:
                cout << " -- ";
                break;
            default:
                break;
        }
        if (var != NULL) {
            var->visit();
        } else {
            cout << "error: var is null" << endl;
        }
    } else if (type == EXP_PLUS_PLUS_R || type == EXP_MINUS_MINUS_R) {
        if (var != NULL) {
            var->visit();
        } else {
            cout << "error: var is null" << endl;
        }
        switch (type) {
            case EXP_PLUS_PLUS_R:
                cout << " ++ ";
                break;
            case EXP_MINUS_MINUS_R:
                cout << " -- ";
                break;
            default:
                break;
        }
    } else if (type == EXP_VAR) {
        if (var != NULL) {
            var->visit();
        } else {
            cout << "error: var is null" << endl;
        }
    } else if (type == EXP_CONST) {
        if (constant != NULL) {
            constant->visit();
        } else {
            cout << "error: constant is null" << endl;
        }
    } else if (type == EXP_CALL) {
        if (call != NULL) {
            call->visit();
        } else {
            cout << "error: call is null" << endl;
        }
    } else if (type == EXP_EXPV) {
        if (expressionv != NULL) {
            cout << " ( ";
            expressionv->visit();
            cout << " ) ";
        } else {
            cout << "error: expressionv is null" << endl;
        }
    } else {
        cout << "error: undefined expression" << endl;
    }
}

void ExpressionNode::buildSymbolTable() {
    switch (type) {
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
            if (left != NULL) {
                left->buildSymbolTable();
            }
            if (right != NULL) {
                right->buildSymbolTable();
            }
            if (!typeEqual(left, right)) {
                Error *err = new Error(Error::ERROR_TYPE_NOT_MATCH, lineno, string(""));
                err->Print();
                exit(1);
            } else {
                // todo
                if (left != NULL) {
                    nodeTypeVar = left->nodeTypeVar;
                    nodeSize = left->nodeSize;
                    nodeTypeIdentifier = left->nodeTypeIdentifier;
                }
            }
            break;
        case EXP_EXPV:
            if (expressionv != NULL) {
                expressionv->buildSymbolTable();
                nodeTypeVar = expressionv->nodeTypeVar;
                nodeSize = expressionv->nodeSize;
                nodeTypeIdentifier = expressionv->nodeTypeIdentifier;
            }
            break;
        case EXP_NOT:
        case EXP_MINUS_SIGN:
            if (left != NULL) {
                left->buildSymbolTable();
                nodeTypeVar = left->nodeTypeVar;
                nodeSize = left->nodeSize;
                nodeTypeIdentifier = left->nodeTypeIdentifier;
            }
            break;
        case EXP_PLUS_PLUS_L:
        case EXP_PLUS_PLUS_R:
        case EXP_MINUS_MINUS_L:
        case EXP_MINUS_MINUS_R:
            if (var != NULL) {
                var->buildSymbolTable();
            }
            if (var != NULL) {
                var->buildSymbolTable();
                if (var->nodeTypeIdentifier != SINGLE || var->nodeTypeVar != TYPE_INT) {
                    Error *err = new Error(Error::ERROR_TYPE_NOT_MATCH, lineno, string(""));
                    err->Print();
                    exit(1);
                }
            }
            break;
        case EXP_VAR:
            if (var != NULL) {
                var->buildSymbolTable();
                SymbolNode *node;
                if(var->type == ARRAY){
                    node = symTab->sym_look_up(*(var->array_access->identifier));
                } else if(var->type == SINGLE){
                    node = symTab->sym_look_up(*(var->identifier));
                } else {
                    Error *err = new Error(Error::ERROR_TYPE_NOT_MATCH, lineno, string(""));
                    err->Print();
                    exit(1);
                }
                if(node->typeIdentifier == FUNCTION){
                    Error *err = new Error(Error::ERROR_TYPE_NOT_MATCH, lineno, string(""));
                    err->Print();
                    exit(1);
                }
                nodeTypeVar = var->nodeTypeVar;
                nodeTypeIdentifier = var->nodeTypeIdentifier;
            }
            break;
        case EXP_CALL:
            if (call != NULL) {
                call->buildSymbolTable();
                SymbolNode *node = symTab->sym_look_up(*(call->identifier));
                // todo
                nodeTypeVar = call->nodeTypeVar;
                nodeTypeIdentifier = call->nodeTypeIdentifier;
            }
            break;
        case EXP_CONST:
            if (constant != NULL) {
                constant->buildSymbolTable();
                nodeTypeVar = constant->nodeTypeVar;
                nodeTypeIdentifier = constant->nodeTypeIdentifier;
            }
            break;
    }
}

ProgramNode::ProgramNode(vector<DeclarationNode *> *declaration_list) {
    this->declaration_list = declaration_list;
}

void ProgramNode::visit() {
    int size = (*declaration_list).size();
    for (int i = 0; i < size; i++) {
        (*declaration_list)[i]->visit();
    }
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

void DeclarationNode::visit() {
    if (varDeclarationNode != NULL) {
        varDeclarationNode->visit();
    }
    if (functionDeclarationNode != NULL) {
        functionDeclarationNode->visit();
    }
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

void FunctionDeclarationNode::visit() {
    if (functionDeclNode != NULL) {
        functionDeclNode->visit();
    }
    if (functionDefinitionNode != NULL) {
        functionDefinitionNode->visit();
    }
}

DeclarationNode::DeclarationNode(FunctionDeclarationNode *functionDeclarationNode) {
    this->functionDeclarationNode = functionDeclarationNode;
    this->varDeclarationNode = NULL;
}

FunctionDefinitionNode::FunctionDefinitionNode(FunctionDeclNode *functionDeclNode, FunctionBodyNode *functionBodyNode) {
    this->functionBodyNode = functionBodyNode;
    this->functionDeclNode = functionDeclNode;
}

void FunctionDefinitionNode::visit() {
    if (functionDeclNode != NULL) {
        functionDeclNode->visit();
    }
    if (functionBodyNode != NULL) {
        functionBodyNode->visit();
    }
}

void FunctionDefinitionNode::buildSymbolTable() {
    if (functionDeclNode != NULL) {
        functionDeclNode->buildSymbolTable();
    }
    SymbolNode *node = new SymbolNode(functionDeclNode->lineno, functionDeclNode->identifier, FUNCTION,
                                      functionDeclNode->type,
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

void FunctionDeclNode::visit() {
    switch (type) {
        case TYPE_INT:
            cout << "int" << " ";
            break;
        case TYPE_LONG:
            cout << "long" << " ";
            break;
        case TYPE_FLOAT:
            cout << "float" << " ";
            break;
        case TYPE_SHORT:
            cout << "short" << " ";
            break;
        case TYPE_VOID:
            cout << "void" << " ";
            break;
        case TYPE_DOUBLE:
            cout << "double" << " ";
            break;
        case TYPE_CHAR:
            cout << "char" << " ";
            break;
        default:
            cout << "undefined type" << " ";
            break;
    }
    cout << identifier << " ";
    cout << " ( ";
    if (function_args != NULL) {
        int size = (*function_args).size();
        for (int i = 0; i < size; i++) {
            (*function_args)[i]->visit();
        }
    }
    cout << " ) " << endl;
}

void FunctionDeclNode::buildSymbolTable() {
    SymbolNode *node = new SymbolNode(lineno, identifier, FUNCTION, type, symTab->getLevel());
    // todo add argument types
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

void FunctionArgNode::visit() {
    switch (type) {
        case TYPE_INT:
            cout << "int" << " ";
            break;
        case TYPE_LONG:
            cout << "long" << " ";
            break;
        case TYPE_FLOAT:
            cout << "float" << " ";
            break;
        case TYPE_SHORT:
            cout << "short" << " ";
            break;
        case TYPE_VOID:
            cout << "void" << " ";
            break;
        case TYPE_DOUBLE:
            cout << "double" << " ";
            break;
        case TYPE_CHAR:
            cout << "char" << " ";
            break;
        default:
            cout << "undefined type" << " ";
            break;
    }
    cout << identifier << " | ";
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

void FunctionBodyNode::visit() {
    cout << " { " << endl;
    if (functionStatementsNode != NULL) {
        functionStatementsNode->visit();
    }
    cout << " } " << endl;
}

void FunctionBodyNode::buildSymbolTable() {
    if (functionStatementsNode != NULL) {
        functionStatementsNode->buildSymbolTable();
    }
}

FunctionStatementsNode::FunctionStatementsNode(vector<StatementNode *> *statements,
                                               ReturnStatementNode *returnStatementNode) {
    this->statements = statements;
    this->returnStatementNode = returnStatementNode;
}

void FunctionStatementsNode::visit() {
    if (statements != NULL) {
        int size = (*statements).size();
        for (int i = 0; i < size; i++) {
            (*statements)[i]->visit();
        }
    }
    if (returnStatementNode != NULL) {
        returnStatementNode->visit();
    }
}

void FunctionStatementsNode::buildSymbolTable() {
    if (statements != NULL) {
        for (int i = 0; i < statements->size(); i++) {
            (*statements)[i]->buildSymbolTable();
        }
    }
    if (returnStatementNode != NULL) {
        returnStatementNode->buildSymbolTable();
    }
}

ReturnStatementNode::ReturnStatementNode(ExpressionVNode *expressionVNode) {
    this->expressionVNode = expressionVNode;
}

void ReturnStatementNode::visit() {
    cout << "return ";
    if (expressionVNode != NULL) {
        expressionVNode->visit();
        cout << endl;
    }
}

void ReturnStatementNode::buildSymbolTable() {
    if (expressionVNode != NULL) {
        expressionVNode->buildSymbolTable();
        // todo check return statement
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

void StatementNode::visit() {
    switch (type) {
        case TYPE_VAR_DECLARATION:
            varDeclarationNode->visit();
            cout << endl;
            break;
        case TYPE_ITERATION:
            iterationStatementNode->visit();
            cout << endl;
            break;
        case TYPE_SELECTION:
            selectionStatementNode->visit();
            cout << endl;
            break;
        case TYPE_EXPRESSION:
            if (expressionStatementNode != NULL)expressionStatementNode->visit();
            cout << endl;
            break;
        case TYPE_JUMP:
            jumpStatementNode->visit();
            cout << endl;
            break;
    }
}

void StatementNode::buildSymbolTable() {
    switch (type) {
        case TYPE_VAR_DECLARATION:
            if (varDeclarationNode != NULL) {
                varDeclarationNode->buildSymbolTable();
            }
            break;
        case TYPE_ITERATION:
            if (iterationStatementNode != NULL) {
                iterationStatementNode->buildSymbolTable();
            }
            break;
        case TYPE_SELECTION:
            if (selectionStatementNode != NULL) {
                selectionStatementNode->buildSymbolTable();
            }
            break;
        case TYPE_EXPRESSION:
            if (expressionStatementNode != NULL) {
                expressionStatementNode->buildSymbolTable();
            }
            break;
        case TYPE_JUMP:
            if (jumpStatementNode != NULL) {
                jumpStatementNode->buildSymbolTable();
            }
            break;
    }
}

ExpressionStatementNode::ExpressionStatementNode(ExpressionVNode *expressionVNode) {
    this->expressionVNode = expressionVNode;
}

void ExpressionStatementNode::visit() {
    if (expressionVNode != NULL) {
        expressionVNode->visit();
    }
}

void ExpressionStatementNode::buildSymbolTable() {
    if (expressionVNode != NULL) {
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

void IterationStatementNode::visit() {
    if (type == TYPE_WHILE) {
        cout << " while " << " ( ";
        if (expressionVNode != NULL) {
            expressionVNode->visit();
        } else {
            cout << "error: while expv is null" << endl;
        }
        cout << " ) " << endl;
        loopBodyNode->visit();
    } else if (type == TYPE_DO_WHILE) {
        cout << " do " << endl;
        compoundStatementNode->visit();
        cout << " while " << " ( ";
        expressionVNode->visit();
        cout << " ) " << endl;
    } else if (type == TYPE_FOR) {
        cout << " for " << " ( ";
        forConditionNode->visit();
        cout << " ) ";
        loopBodyNode->visit();
    }
}

void IterationStatementNode::buildSymbolTable() {
    if (type == TYPE_WHILE) {
        symTab->enterScope();
        if (expressionVNode != NULL) {
            expressionVNode->buildSymbolTable();
        }
        if (loopBodyNode != NULL) {
            loopBodyNode->buildSymbolTable();
        }
        symTab->quitScope();
    } else if (type == TYPE_DO_WHILE) {
        symTab->enterScope();
        if (compoundStatementNode != NULL) {
            compoundStatementNode->buildSymbolTable();
        }
        symTab->quitScope();
        if (expressionVNode != NULL) {
            expressionVNode->buildSymbolTable();
        }
    } else if (type == TYPE_FOR) {
        symTab->enterScope();
        if (forConditionNode != NULL) {
            forConditionNode->buildSymbolTable();
        }
        if (loopBodyNode != NULL) {
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

void LoopBodyNode::visit() {
    if (statementNode != NULL) {
        statementNode->visit();
    }
    if (compoundStatementNode != NULL) {
        compoundStatementNode->visit();
    }
}

void LoopBodyNode::buildSymbolTable() {
    if (statementNode != NULL) {
        statementNode->buildSymbolTable();
    } else if (compoundStatementNode != NULL) {
        symTab->enterScope();
        compoundStatementNode->buildSymbolTable();
        symTab->quitScope();
    }
}

CompoundStatementNode::CompoundStatementNode(vector<StatementNode *> *statements) {
    this->statements = statements;
}

void CompoundStatementNode::visit() {
    cout << " { " << endl;
    if (statements != NULL) {
        for (int i = 0; i < statements->size(); i++) {
            (*statements)[i]->visit();
        }
    }
    cout << " } " << endl;
}

void CompoundStatementNode::buildSymbolTable() {
    if (statements != NULL) {
        for (int i = 0; i < statements->size(); i++) {
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

void ForConditionNode::visit() {
    if (forInitListNode != NULL) {
        forInitListNode->visit();
    }
    cout << " ; ";
    if (forExpression != NULL) {
        forExpression->visit();
    }
    cout << " ; ";
    if (incrementExpressionList != NULL) {
        for (int i = 0; i < incrementExpressionList->size(); i++) {
            (*incrementExpressionList)[i]->visit();
            cout << " | ";
        }
    }
}

void ForConditionNode::buildSymbolTable() {
    if (forInitListNode != NULL) {
        forInitListNode->buildSymbolTable();
    }
    if (forExpression != NULL) {
        forExpression->buildSymbolTable();
    }
    if (incrementExpressionList != NULL) {
        for (int i = 0; i < incrementExpressionList->size(); i++) {
            (*incrementExpressionList)[i]->buildSymbolTable();
        }
    }
}

void ForInitListNode::buildSymbolTable() {
    if (expressionList != NULL) {
        for (int i = 0; i < expressionList->size(); i++) {
            (*expressionList)[i]->buildSymbolTable();
        }
    } else if (forDeclarationNode != NULL) {
        forDeclarationNode->buildSymbolTable();
    }
}

ConstantNode::ConstantNode(type_var type, int integer, double double_number, char character) {
    this->type = type;
    this->integer = integer;
    this->double_number = double_number;
    this->character = character;
}

void ConstantNode::visit() {
    switch (type) {
        case TYPE_INT:
            cout << integer;
            break;
        case TYPE_DOUBLE:
            cout << double_number;
            break;
        case TYPE_CHAR:
            cout << character;
            break;
        default:
            cout << "error: undefined type" << endl;
    }
}

void ConstantNode::buildSymbolTable() {
    nodeTypeVar = type;
    nodeTypeIdentifier = SINGLE;
}

CallNode::CallNode(string *identifier, vector<ExpressionVNode *> *args) {
    this->identifier = identifier;
    this->args = args;
}

void CallNode::visit() {
    cout << *identifier << " ( ";
    if (args != NULL) {
        int size = (*args).size();
        for (int i = 0; i < size; i++) {
            (*args)[i]->visit();
            cout << " | ";
        }
    }
    cout << " ) ";
}

void CallNode::buildSymbolTable() {
    if (identifier != NULL) {
        SymbolNode *node = symTab->sym_look_up(*identifier);
        if (node == NULL) {
            Error *err = new Error(Error::ERROR_UNDECLARED_FUNCTION, lineno, *identifier);
            err->Print();
            exit(1);
        }
        nodeTypeIdentifier = SINGLE;
        nodeTypeVar = node->typeVar;
    }
    if (args != NULL) {
        for (int i = 0; i < args->size(); i++) {
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

void ForInitListNode::visit() {
    if (expressionList != NULL) {
        for (int i = 0; i < expressionList->size(); i++) {
            (*expressionList)[i]->visit();
            cout << " | ";
        }
    }
    if (forDeclarationNode != NULL) {
        forDeclarationNode->visit();
    }
}

ForDeclarationNode::ForDeclarationNode(type_var type, vector<VarDeclNode *> *varDeclarationList) {
    this->type = type;
    this->varDeclarationList = varDeclarationList;
}

void ForDeclarationNode::visit() {
    switch (type) {
        case TYPE_INT:
            cout << "int" << " ";
            break;
        case TYPE_LONG:
            cout << "long" << " ";
            break;
        case TYPE_FLOAT:
            cout << "float" << " ";
            break;
        case TYPE_SHORT:
            cout << "short" << " ";
            break;
        case TYPE_VOID:
            cout << "void" << " ";
            break;
        case TYPE_DOUBLE:
            cout << "double" << " ";
            break;
        case TYPE_CHAR:
            cout << "char" << " ";
            break;
        default:
            cout << "undefined type" << " ";
            break;
    }
    for (int i = 0; i < varDeclarationList->size(); i++) {
        (*varDeclarationList)[i]->visit();
    }
}

void ForDeclarationNode::buildSymbolTable() {
    if (varDeclarationList != NULL) {
        for (int i = 0; i < varDeclarationList->size(); i++) {
            VarDeclNode *varDeclNode = (*varDeclarationList)[i];
            varDeclNode->typeVar = this->type;
            varDeclNode->buildSymbolTable();
        }
    }
}

JumpStatementNode::JumpStatementNode(int type) {
    this->type = type;
}

void JumpStatementNode::visit() {
    if (type == TYPE_CONTINUE) {
        cout << " continue ";
    } else if (type == TYPE_BREAK) {
        cout << " break ";
    }
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

void SelectionStatementNode::visit() {
    if (ifStatementNode != NULL) {
        ifStatementNode->visit();
    }
    if (switchStatementNode != NULL) {
        switchStatementNode->visit();
    }
}

void SelectionStatementNode::buildSymbolTable() {
    if (ifStatementNode != NULL) {
        ifStatementNode->buildSymbolTable();
    } else if (switchStatementNode != NULL) {
        switchStatementNode->buildSymbolTable();
    }
}

IfStatementNode::IfStatementNode(ExpressionVNode *expressionVNode, IfBodyNode *ifBodyNode) {
    this->expressionVNode = expressionVNode;
    this->ifBodyNode = ifBodyNode;
    this->elseBodyNode = NULL;
}

IfStatementNode::IfStatementNode(ExpressionVNode *expressionVNode, IfBodyNode *ifBodyNode, IfBodyNode *elseBodyNode) {
    this->expressionVNode = expressionVNode;
    this->ifBodyNode = ifBodyNode;
    this->elseBodyNode = elseBodyNode;
}

void IfStatementNode::visit() {
    cout << " if " << " ( ";
    expressionVNode->visit();
    cout << " ) ";
    ifBodyNode->visit();
    if (elseBodyNode != NULL) {
        cout << " else ";
        elseBodyNode->visit();
    }
}

void IfStatementNode::buildSymbolTable() {
    if (expressionVNode != NULL) {
        expressionVNode->buildSymbolTable();
    }
    if (ifBodyNode != NULL) {
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

void IfBodyNode::visit() {
    if (statementNode != NULL) {
        statementNode->visit();
    }
    if (compoundStatementNode != NULL) {
        compoundStatementNode->visit();
    }
}

void IfBodyNode::buildSymbolTable() {
    if (compoundStatementNode != NULL) {
        symTab->enterScope();
        compoundStatementNode->buildSymbolTable();
        symTab->quitScope();
    } else if (statementNode != NULL) {
        statementNode->buildSymbolTable();
    }
}

SwitchStatementNode::SwitchStatementNode(ExpressionVNode *expressionVNode,
                                         vector<LabeledStatementNode *> *labeledStatementList) {
    this->expressionVNode = expressionVNode;
    this->labeledStatementList = labeledStatementList;
}

void SwitchStatementNode::visit() {
    cout << " switch " << " ( ";
    expressionVNode->visit();
    cout << " ) " << " { ";
    if (labeledStatementList != NULL) {
        for (int i = 0; i < labeledStatementList->size(); i++) {
            (*labeledStatementList)[i]->visit();
            cout << endl;
        }
    }
    cout << " } " << endl;
}

void SwitchStatementNode::buildSymbolTable() {
    if (expressionVNode != NULL) {
        expressionVNode->buildSymbolTable();
    }
    if (labeledStatementList != NULL) {
        symTab->enterScope();
        for (int i = 0; i < labeledStatementList->size(); i++) {
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
    if(constantNode != NULL){
        constantNode->buildSymbolTable();
    }
    if (statements != NULL) {
        for (int i = 0; i < statements->size(); i++) {
            (*statements)[i]->buildSymbolTable();
        }
    }
}

LabeledStatementNode::LabeledStatementNode(ConstantNode *constantNode, vector<StatementNode *> *statements) {
    this->constantNode = constantNode;
    this->type = TYPE_CASE;
    this->statements = statements;
}

void LabeledStatementNode::visit() {
    if (type == TYPE_CASE) {
        cout << " case ";
        constantNode->visit();
        cout << " : ";
        for (int i = 0; i < statements->size(); i++) {
            (*statements)[i]->visit();
        }
    } else if (type == TYPE_DEFAULT) {
        cout << " default : ";
        for (int i = 0; i < statements->size(); i++) {
            (*statements)[i]->visit();
        }
    }
}

bool typeEqual(Node *n1, Node *n2) {
    if (n1 == NULL || n2 == NULL) {
        return false;
    }
    if (n1->nodeTypeIdentifier != n2->nodeTypeIdentifier) {
        return false;
    }
    // SINGLE TYPE
    if (n1->nodeTypeIdentifier == SINGLE) {
        // not function
        return !(n1->nodeTypeVar != n2->nodeTypeVar);
    } else if (n1->nodeTypeIdentifier == ARRAY) {
        if (n1->nodeTypeVar == n2->nodeTypeVar) {
            return n1->nodeSize == n2->nodeSize;
        } else {
            return false;
        }
    }
    return false;
}
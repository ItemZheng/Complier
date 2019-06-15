#include "node.h"
#include<string>
using namespace std;

VarDeclarationNode::VarDeclarationNode(type_var type, vector<VarDeclNode *> * vdl){
    this->type = type;
    this->var_declaration_list = vdl;
}

VarDeclNode::VarDeclNode(type_identifier type, string * identifier,
ArrayIdentifierNode * array_identifier, int assign, ExpressionVNode * expressionv,
ArrayInitNode * array_init){
    this->type = type;
    this->identifier = identifier;
    this->array_identifier = array_identifier;
    this->assign = assign;
    this->expressionv = expressionv;
    this->array_init = array_init;
}

ArrayIdentifierNode::ArrayIdentifierNode(string * identifier, int size, int index){
    this->identifier = identifier;
    this->size = size;
    this->index = index;
}

ArrayInitNode::ArrayInitNode(vector<ArrayInitNode *> * array_init,
vector<ExpressionVNode *> * expressionvs){
    this->array_init = array_init;
    this->expressionvs = expressionvs;
}

ExpressionVNode::ExpressionVNode(vector<VarNode *> * var_list, ExpressionNode * expression){
    this->var_list = var_list;
    this->expression = expression;
}

VarNode::VarNode(type_identifier type, string * identifier, ArrayIdentifierNode * array_identifier){
    this->type = type;
    this->identifier = identifier;
    this->array_identifier = array_identifier;
}

ExpressionNode::ExpressionNode(type_expression type, ExpressionNode * left, ExpressionNode * right,
VarNode * var, ConstantNode * constant, CallNode * call){
    this->type = type;
    this->left = left;
    this->right = right;
    this->var = var;
    this->constant = constant;
    this->call = call;
}
#include "node.h"

ProgramNode::ProgramNode(vector<DeclarationNode *> *declaration_list) {
    this->declaration_list = declaration_list;
}

DeclarationNode::DeclarationNode(VarDeclarationNode *varDeclarationNode) {
    this->varDeclarationNode = varDeclarationNode;
    this->functionDeclarationNode = NULL;
}

FunctionDeclarationNode::FunctionDeclarationNode(FunctionDeclNode *functionDeclNode) {
    this->functionDeclNode = functionDeclNode;
    this->functionDefinitionNode = NULL;
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

FunctionDeclNode::FunctionDeclNode(type_var type, string identifier, vector<FunctionArgNode *> *function_args) {
    this->type = type;
    this->identifier = identifier;
    this->function_args = function_args;
}

FunctionArgNode::FunctionArgNode(type_var type, string identifier) {
    this->type = type;
    this->identifier = identifier;
}

FunctionBodyNode::FunctionBodyNode(FunctionStatementsNode *functionStatementsNode) {
    this->functionStatementsNode = functionStatementsNode;
}

FunctionStatementsNode::FunctionStatementsNode(vector<StatementNode *> *statements,
                                               ReturnStatementNode *returnStatementNode) {
    this->statements = statements;
    this->returnStatementNode = returnStatementNode;
}

ReturnStatementNode::ReturnStatementNode(ExpressionVNode *expressionVNode) {
    this->expressionVNode = expressionVNode;
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

ExpressionStatementNode::ExpressionStatementNode(ExpressionVNode *expressionVNode) {
    this->expressionVNode = expressionVNode;
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

LoopBodyNode::LoopBodyNode(StatementNode *statementNode) {
    this->statementNode = statementNode;
    this->compoundStatementNode = NULL;
}

LoopBodyNode::LoopBodyNode(CompoundStatementNode *compoundStatementNode) {
    this->compoundStatementNode = compoundStatementNode;
    this->statementNode = NULL;
}

CompoundStatementNode::CompoundStatementNode(vector<StatementNode *> *statements) {
    this->statements = statements;
}

ForConditionNode::ForConditionNode(ForInitListNode *forInitListNode, ExpressionVNode *forExpression,
                                   vector<ExpressionVNode *> *incrementExpressionList) {
    this->forInitListNode = forInitListNode;
    this->forExpression = forExpression;
    this->incrementExpressionList = incrementExpressionList;
}

ConstantNode::ConstantNode(type_var type, int integer, double double_number, char character){
    this->type = type;
    this->integer = integer;
    this->double_number = double_number;
    this->character = character;
}

CallNode::CallNode(string * identifier, vector<ExpressionVNode *> * args){
    this->identifier = identifier;
    this->args = args;
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

JumpStatementNode::JumpStatementNode(int type) {
    this->type = type;
}

SelectionStatementNode::SelectionStatementNode(IfStatementNode *ifStatementNode) {
    this->ifStatementNode = ifStatementNode;
    this->switchStatementNode = NULL;
}

SelectionStatementNode::SelectionStatementNode(SwitchStatementNode *switchStatementNode) {
    this->switchStatementNode = switchStatementNode;
    this->ifStatementNode = NULL;
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

IfBodyNode::IfBodyNode(CompoundStatementNode *compoundStatementNode) {
    this->statementNode = NULL;
    this->compoundStatementNode = compoundStatementNode;
}

IfBodyNode::IfBodyNode(StatementNode *statementNode) {
    this->statementNode = statementNode;
    this->compoundStatementNode = NULL;
}

SwitchStatementNode::SwitchStatementNode(ExpressionVNode *expressionVNode,
                                         vector<LabeledStatementNode *> *labeledStatementList) {
    this->expressionVNode = expressionVNode;
    this->labeledStatementList = labeledStatementList;
}

LabeledStatementNode::LabeledStatementNode(vector<StatementNode *> *statements) {
    this->constantNode = NULL;
    this->statements = statements;
    this->type = TYPE_DEFAULT;
}

LabeledStatementNode::LabeledStatementNode(ConstantNode *constantNode, vector<StatementNode *> *statements) {
    this->constantNode = constantNode;
    this->type = TYPE_CASE;
    this->statements = statements;
}
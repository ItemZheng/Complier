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
    this->tpye = type;
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

ConstantNode::ConstantNode(type_var type, int integer, double double_number, char character){
    this->type = tpye;
    this->integer = integer;
    this->double_number = double_number;
    this->character = character;
}

CallNode::CallNode(string * identifier, vector<ExpressionVNode *> * args){
    this->identifier = identifier;
    this->args = args;
}
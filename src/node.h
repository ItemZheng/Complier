//
// Created by BossWang & ItemZheng on 2019-06-15.
//

#include<vector>
#include"type.h"
#include<string>
#ifndef COMPILER_NODE_H
#define COMPILER_NODE_H

class Node {
virtual void visit() = 0;
virtual void codeGen() = 0;
};

class VarDeclarationNode : public Node{
    public:
        type_var type;
        vector<VarDeclNode*> * var_declaration_list; 
    public:
        void visit();
        void codeGen();
}

class VarDeclNode : public Node{
    public:
        type_identifier type;
        std::string * identifier;
        ArrayIdentifierNode * array_identifier;
        int assign;
        ExpressionvNode * expressionv;
        ArrayInitNode * array_init;
    public:
        void visit();
        void codeGen();
}

class ArrayIdentifierNode : public Node{
    public:
        std::string * identifier;
        int size;
        int index;
    public:
        void visit();
        void codeGen();
}

class ArrayInitNode : public Node{
    public:
        vector<ArrayInitNode *> * array_init;
        vector<ExpressionvNode *> * expressionvs;
    public:
        void visit();
        void codeGen();
}

class ExpressionvNode : public Node{
    public:
        vector<VarNode *> var_list;
        ExpressionNode * expression;
    public:
        void visit();
        void codeGen();
}

class VarNode : public Node{
    public:
        type_identifier type;
        std::string * identifier;
        ArrayIdentifierNode * array_identifier;
    public:
        void visit();
        void codeGen();
}

class ExpressionNode : public Node{
    public:
        type_expression type;
        ExpressionNode * left;
        ExpressionNode * right;
        VarNode * var;
        ConstantNode * constant;
        CallNode * call;
    public:
        void visit();
        void codeGen();
}

class ConstantNode : public Node{
    public:
        type_var type;
        int integer;
        double double_number;
        char character;
    public:
        void visit();
        void codeGen();
}

class CallNode : public Node{
    public:
        std::string * identifier;
        vector<ExpressionvNode *> * args;
    public:
        void visit();
        void codeGen();
}

#endif //COMPILER_NODE_H

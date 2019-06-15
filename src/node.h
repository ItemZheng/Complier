//
// Created by BossWang & ItemZheng on 2019-06-15.
//

#include<vector>
#include"type.h"
#include<string>
#ifndef COMPILER_NODE_H
#define COMPILER_NODE_H

# include <vector>
# include <type.h>

using namespace std;

class Node {
    virtual void visit() = 0;

    virtual void codeGen() = 0;
};

// Declarations
class DeclarationNode;

class FunctionDeclarationNode;

class VarDeclarationNode;

class FunctionDeclNode;

class FunctionDefinitionNode;

class FunctionBodyNode;

class FunctionArgNode;

class FunctionStatementsNode;

class ReturnStatementNode;

class StatementNode;

class ExpressionVNode;

class IterationStatementNode;

class SelectionStatementNode;

class ExpressionStatementNode;

class JumpStatementNode;

class LoopBodyNode;

class CompoundStatementNode;

class ForConditionNode;

class ForInitListNode;

class ForDeclarationNode;

class VarDeclNode;

class IfStatementNode;

class SwitchStatementNode;

class IfBodyNode;

class ElseBodyNode;

class LabeledStatementNode;

class ConstantNode;

class VarDeclarationNode;

class VarDeclNode;

class ExpressionVNode;

class ArrayIdentifierNode;

class ArrayInitNode;

class ExpressionNode;

class VarNode;

class CallNode;

class ConstantNode;

// program: declaration_list
class ProgramNode : Node {
public:
    vector<DeclarationNode *> *declaration_list;
public:
    void visit();

    void codeGen();
};

class DeclarationNode : Node {
public:
    FunctionDeclarationNode *functionDeclarationNode;
    VarDeclarationNode *varDeclarationNode;
public:
    void visit();

    void codeGen();
};

class FunctionDeclarationNode : Node {
public:
    FunctionDeclNode *functionDeclNode;
    FunctionDefinitionNode *functionDefinitionNode;
public:
    void visit();

    void codeGen();
};

class FunctionDefinitionNode : Node {
public:
    FunctionDeclNode *functionDeclNode;
    FunctionBodyNode *functionBodyNode;
public:
    void visit();

    void codeGen();
};

class FunctionDeclNode : Node {
public:
    type_var type;
    string identifier;
    vector<FunctionArgNode *> *function_args;
public:
    void visit();

    void codeGen();
};

class FunctionArgNode : Node {
public:
    type_var type;
    string identifier;
public:
    void visit();

    void codeGen();
};

class FunctionBodyNode : Node {
public:
    FunctionStatementsNode *functionStatementsNode;
public:
    void visit();

    void codeGen();
};

class FunctionStatementsNode : Node {
public:
    vector<StatementNode *> *statements;
    ReturnStatementNode *returnStatementNode;
public:
    void visit();

    void codeGen();
};

class ReturnStatementNode : Node {
public:
    ExpressionVNode *expressionVNode;
public:
    void visit();

    void codeGen();
};

class StatementNode : Node {
public:
    const int TYPE_VAR_DECLARATION = 0;
    const int TYPE_ITERATION = 1;
    const int TYPE_SELECTION = 2;
    const int TYPE_EXPRESSION = 3;
    const int TYPE_JUMP = 4;
public:
    int type;
    VarDeclarationNode *varDeclarationNode;
    IterationStatementNode *iterationStatementNode;
    SelectionStatementNode *selectionStatementNode;
    ExpressionStatementNode *expressionStatementNode;
    JumpStatementNode *jumpStatementNode;
public:
    void visit();

    void codeGen();
};

class ExpressionStatementNode : Node {
public:
    ExpressionVNode *expressionVNode;
public:
    void visit();

    void codeGen();
};

class IterationStatementNode : Node {
public:
    const int TYPE_WHILE = 0;
    const int TYPE_DO_WHILE = 1;
    const int TYPE_FOR = 2;
public:
    int type;
    // for while
    ExpressionVNode *expressionVNode;
    LoopBodyNode *loopBodyNode;
    // for do while
    CompoundStatementNode *compoundStatementNode;
    // for for-loop
    ForConditionNode forConditionNode;
public:
    void visit();

    void codeGen();
};

class LoopBodyNode : Node{
public:
    StatementNode *statementNode;
    CompoundStatementNode *compoundStatementNode;
public:
    void visit();

    void codeGen();
};

class CompoundStatementNode : Node{
public:
    vector<StatementNode *> statements;
public:
    void visit();

    void codeGen();
};

class ForConditionNode : Node{
public:
    ForInitListNode *forInitListNode;
    ExpressionVNode *forExpression;
    vector<ExpressionVNode *> *incrementExpressionList;
public:
    void visit();

    void codeGen();
};

class ForInitListNode :Node{
public:
    vector<ExpressionVNode *> *expressionList;
    ForDeclarationNode *forDeclarationNode;
public:
    void visit();

    void codeGen();
};

class ForDeclarationNode : Node{
public:
    type_var type;
    vector <VarDeclNode *> *varDeclarationList;
public:
    void visit();

    void codeGen();
};

class JumpStatementNode : Node{
public:
    const int TYPE_CONTINUE = 0;
    const int TYPE_BREAK = 1;
public:
    int type;
public:
    void visit();

    void codeGen();
};

class VarDeclarationNode : public Node{
    public:
        type_var type;
        vector<VarDeclNode *> * var_declaration_list; 
    public:
        VarDeclarationNode(type_var type, vector<VarDeclNode *> * vdl);
        ~VarDeclarationNode()
        void visit();
        void codeGen();
}

class VarDeclNode : public Node{
    public:
        type_identifier type;
        std::string * identifier;
        ArrayIdentifierNode * array_identifier;
        int assign;
        ExpressionVNode * expressionv;
        ArrayInitNode * array_init;
    public:
        VarDeclNode(type_identifier type, string * identifier, 
        ArrayIdentifierNode * array_identifier, int assign, ExpressiionVNode * expressionv,
        ArrayInitNode * array_init)
        ~VarDeclNode();
        void visit();
        void codeGen();
}

class ArrayIdentifierNode : public Node{
    public:
        std::string * identifier;
        int size;
        int index;
    public:
        ArrayIdentifierNode(string * identifier, int size);
        ~ArrayIdentifierNode();
        void visit();
        void codeGen();
}

class ArrayInitNode : public Node{
    public:
        vector<ArrayInitNode *> * array_init;
        vector<ExpressionVNode *> * expressionvs;
    public:
        ArrayInitNode(vector<ArrayInitNode *> * array_init,
        vector<ExpressiionVNode *> * expressionvs);
        ~ArrayInitNode();
        void visit();
        void codeGen();
}

class ExpressionVNode : public Node{
    public:
        vector<VarNode *> * var_list;
        ExpressionNode * expression;
    public:
        ExpressiionVNode(vector<VarNode *> * var_list, ExpressionNode * expression);
        ~ExpressionVNode()
        void visit();
        void codeGen();
}

class VarNode : public Node{
    public:
        type_identifier type;
        std::string * identifier;
        ArrayIdentifierNode * array_identifier;
    public:
        VarNode(type_identifier type, string * identifier, ArrayIdentifierNode * array_identifier);
        ~VarNode();
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
        ExpressionNode(type_expression type, ExpressionNode * left, ExpressionNode * right,
        VarNode * var, ConstantNode * constant, CallNode * call);
        ~ExpressionNode();
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
        ConstantNode(type_var type, int integer, double double_number, char character);
        ~ConstantNode();
        void visit();
        void codeGen();
}

class CallNode : public Node{
    public:
        std::string * identifier;
        vector<ExpressionVNode *> * args;
    public:
        CallNode(string * identifier, vector<ExpressionVNode *> * args);
        ~CallNode();
        void visit();
        void codeGen();
}
class SelectionStatementNode :Node{
public:
    IfStatementNode *ifStatementNode;
    SwitchStatementNode *switchStatementNode;
public:
    void visit();

    void codeGen();
};


class IfStatementNode :Node{
public:
    ExpressionVNode *expressionVNode;
    IfBodyNode *ifBodyNode;
    IfBodyNode *elseBodyNode;
public:
    void visit();

    void codeGen();
};

class IfBodyNode :Node{
public:
    CompoundStatementNode *compoundStatementNode;
    StatementNode *statementNode;
public:
    void visit();
    void codeGen();
};

class SwitchStatementNode :Node{
public:
    ExpressionVNode *expressionVNode;
    vector<LabeledStatementNode*> *labeledStatementList;
public:
    void visit();
    void codeGen();
 };

class LabeledStatementNode:Node{
public:
    const int TYPE_CASE = 0;
    const int TYPE_DEFAULT = 0;
public:
    int type;
    ConstantNode *constantNode;
    vector<StatementNode*> *statements;
public:
    void visit();
    void codeGen();
};

#endif //COMPILER_NODE_H

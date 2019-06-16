//
// Created by BossWang & ItemZheng on 2019-06-15.
//

#include<vector>
#include"type.h"
#include<string>

#ifndef COMPILER_NODE_H
#define COMPILER_NODE_H

using namespace std;

class Node {
public:
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
class ProgramNode : public Node {
public:
    vector<DeclarationNode *> *declaration_list;
public:
    ProgramNode(vector<DeclarationNode *> *declaration_list);

    void visit() {}

    void codeGen() {}
};

class DeclarationNode : public Node {
public:
    FunctionDeclarationNode *functionDeclarationNode;
    VarDeclarationNode *varDeclarationNode;

public:
    DeclarationNode(FunctionDeclarationNode *functionDeclarationNode);

    DeclarationNode(VarDeclarationNode *varDeclarationNode);

    void visit() {}

    void codeGen() {}
};

class FunctionDeclarationNode : public Node {
public:
    FunctionDeclNode *functionDeclNode;
    FunctionDefinitionNode *functionDefinitionNode;
public:
    FunctionDeclarationNode(FunctionDeclNode *functionDeclNode);

    FunctionDeclarationNode(FunctionDefinitionNode *functionDefinitionNode);

    void visit() {}

    void codeGen() {}
};

class FunctionDefinitionNode : public Node {
public:
    FunctionDeclNode *functionDeclNode;
    FunctionBodyNode *functionBodyNode;
public:
    FunctionDefinitionNode(FunctionDeclNode *functionDeclNode, FunctionBodyNode *functionBodyNode);

    void visit() {}

    void codeGen() {}
};

class FunctionDeclNode : public Node {
public:
    type_var type;
    string identifier;
    vector<FunctionArgNode *> *function_args;
public:
    FunctionDeclNode(type_var type, string identifier, vector<FunctionArgNode *> *function_args);

    void visit() {}

    void codeGen() {}
};

class FunctionArgNode : public Node {
public:
    type_var type;
    string identifier;
public:
    FunctionArgNode(type_var type, string identifier);

    void visit() {}

    void codeGen() {}
};

class FunctionBodyNode : public Node {
public:
    FunctionStatementsNode *functionStatementsNode;
public:
    FunctionBodyNode(FunctionStatementsNode *functionStatementsNode);

    void visit() {}

    void codeGen() {}
};

class FunctionStatementsNode : public Node {
public:
    vector<StatementNode *> *statements;
    ReturnStatementNode *returnStatementNode;
public:
    FunctionStatementsNode(vector<StatementNode *> *statements, ReturnStatementNode *returnStatementNode);

    void visit() {}

    void codeGen() {}
};

class ReturnStatementNode : public Node {
public:
    ExpressionVNode *expressionVNode;
public:
    ReturnStatementNode(ExpressionVNode *expressionVNode);

    void visit() {}

    void codeGen() {}
};

class StatementNode : public Node {
public:
    static const int TYPE_VAR_DECLARATION = 0;
    static const int TYPE_ITERATION = 1;
    static const int TYPE_SELECTION = 2;
    static const int TYPE_EXPRESSION = 3;
    static const int TYPE_JUMP = 4;
public:
    int type;
    VarDeclarationNode *varDeclarationNode;
    IterationStatementNode *iterationStatementNode;
    SelectionStatementNode *selectionStatementNode;
    ExpressionStatementNode *expressionStatementNode;
    JumpStatementNode *jumpStatementNode;
public:
    StatementNode();

    StatementNode(VarDeclarationNode *varDeclarationNode);

    StatementNode(IterationStatementNode *iterationStatementNode);

    StatementNode(SelectionStatementNode *selectionStatementNode);

    StatementNode(ExpressionStatementNode *expressionStatementNode);

    StatementNode(JumpStatementNode *jumpStatementNode);

    void visit() {}

    void codeGen() {}
};

class ExpressionStatementNode : public Node {
public:
    ExpressionVNode *expressionVNode;
public:
    ExpressionStatementNode(ExpressionVNode *expressionVNode);

    void visit() {}

    void codeGen() {}
};

class IterationStatementNode : public Node {
public:
    static const int TYPE_WHILE = 0;
    static const int TYPE_DO_WHILE = 1;
    static const int TYPE_FOR = 2;
public:
    int type;
    // for while
    ExpressionVNode *expressionVNode;
    LoopBodyNode *loopBodyNode;
    // for do while
    CompoundStatementNode *compoundStatementNode;
    // for for-loop
    ForConditionNode *forConditionNode;
public:
    IterationStatementNode();

    IterationStatementNode(ExpressionVNode *expressionVNode, LoopBodyNode *loopBodyNode);

    IterationStatementNode(CompoundStatementNode *compoundStatementNode, ExpressionVNode *expressionVNode);

    IterationStatementNode(ForConditionNode *forConditionNode, LoopBodyNode *loopBodyNode);

    void visit() {}

    void codeGen() {}
};

class LoopBodyNode : public Node {
public:
    StatementNode *statementNode;
    CompoundStatementNode *compoundStatementNode;
public:
    LoopBodyNode(StatementNode *statementNode);

    LoopBodyNode(CompoundStatementNode *compoundStatementNode);

    void visit() {}

    void codeGen() {}
};

class CompoundStatementNode : public Node {
public:
    vector<StatementNode *> *statements;
public:
    CompoundStatementNode(vector<StatementNode *> *statements);

    void visit() {}

    void codeGen() {}
};

class ForConditionNode : public Node {
public:
    ForInitListNode *forInitListNode;
    ExpressionVNode *forExpression;
    vector<ExpressionVNode *> *incrementExpressionList;
public:
    ForConditionNode(ForInitListNode *forInitListNode, ExpressionVNode *forExpression,
                     vector<ExpressionVNode *> *incrementExpressionList);

    void visit() {}

    void codeGen() {}
};

class ForInitListNode : public Node {
public:
    vector<ExpressionVNode *> *expressionList;
    ForDeclarationNode *forDeclarationNode;
public:
    ForInitListNode();

    ForInitListNode(vector<ExpressionVNode *> *expressionList);

    ForInitListNode(ForDeclarationNode *forDeclarationNode);

    void visit() {}

    void codeGen() {}
};

class ForDeclarationNode : public Node {
public:
    type_var type;
    vector<VarDeclNode *> *varDeclarationList;
public:
    ForDeclarationNode(type_var type, vector<VarDeclNode *> *varDeclarationList);

    void visit() {}

    void codeGen() {}
};

class JumpStatementNode : public Node {
public:
    static const int TYPE_CONTINUE = 0;
    static const int TYPE_BREAK = 1;
public:
    int type;
public:
    JumpStatementNode(int type);

    void visit() {}

    void codeGen() {}
};

class VarDeclarationNode : public Node {
public:
    type_var type;
    vector<VarDeclNode *> *var_declaration_list;
public:
    VarDeclarationNode(type_var type, vector<VarDeclNode *> * vdl);

    ~VarDeclarationNode();

    void visit() {}

    void codeGen() {}
};

class VarDeclNode : public Node {
public:
    type_identifier type;
    std::string *identifier;
    ArrayIdentifierNode *array_identifier;
    int assign;
    ExpressionVNode *expressionv;
    ArrayInitNode *array_init;
public:
    VarDeclNode(type_identifier type, string *identifier,
                ArrayIdentifierNode *array_identifier, int assign, ExpressionVNode *expressionv,
                ArrayInitNode *array_init);

    ~VarDeclNode();

    void visit() {}

    void codeGen() {}
};

class ArrayIdentifierNode : public Node {
public:
    std::string *identifier;
    int size;
public:
    ArrayIdentifierNode(string *identifier, int size);

    ~ArrayIdentifierNode();

    void visit() {}

    void codeGen() {}
};

class ArrayAccessNode : public Node{
public:
    std::string *identifier;
    int index;
public:
    ArrayAccessNode(string *identifier, int index);

    ~ArrayAccessNode();

    void visit(){}

    void codeGen(){}
};

class ArrayInitNode : public Node {
public:
    vector<ArrayInitNode *> *array_init;
    vector<ExpressionVNode *> *expressionvs;
public:
    ArrayInitNode(vector<ArrayInitNode *> *array_init,
                  vector<ExpressionVNode *> *expressionvs);

    ~ArrayInitNode();

    void visit() {}

    void codeGen() {}
};

class ExpressionVNode : public Node {
public:
    vector<VarNode *> *var_list;
    ExpressionNode *expression;
public:
    ExpressionVNode(vector<VarNode *>
                    *var_list,
                    ExpressionNode *expression
    );

    ~ExpressionVNode();

    void visit() {}

    void codeGen() {}
};

class VarNode : public Node {
public:
    type_identifier type;
    std::string *identifier;
    ArrayAccessNode *array_access;
public:
    VarNode(type_identifier type, string *identifier, ArrayAccessNode *array_access);

    ~VarNode();

    void visit() {}

    void codeGen() {}
};

class ExpressionNode : public Node {
public:
    type_expression type;
    ExpressionNode *left;
    ExpressionNode *right;
    VarNode *var;
    ConstantNode *constant;
    CallNode *call;
    ExpressionVNode * expressionv;
public:
    ExpressionNode(type_expression type, ExpressionNode *left, ExpressionNode *right,
                   VarNode *var, ConstantNode *constant, CallNode *call, ExpressionVNode *expressionv);
    ~ExpressionNode();

    void visit() {}

    void codeGen() {}
};

class ConstantNode : public Node {
public:
    type_var type;
    int integer;
    double double_number;
    char character;
public:
    ConstantNode(type_var type, int integer, double double_number, char character);

    ~ConstantNode();

    void visit() {}

    void codeGen() {}
};

class CallNode : public Node {
public:
    std::string *identifier;
    vector<ExpressionVNode *> *args;
public:
    CallNode(string *identifier, vector<ExpressionVNode *> *args);

    ~CallNode();

    void visit() {}

    void codeGen() {}
};

class SelectionStatementNode : public Node {
public:
    IfStatementNode *ifStatementNode;
    SwitchStatementNode *switchStatementNode;
public:
    SelectionStatementNode(IfStatementNode *ifStatementNode);

    SelectionStatementNode(SwitchStatementNode *switchStatementNode);

    void visit() {}

    void codeGen() {}
};


class IfStatementNode : public Node {
public:
    ExpressionVNode *expressionVNode;
    IfBodyNode *ifBodyNode;
    IfBodyNode *elseBodyNode;
public:
    IfStatementNode(ExpressionVNode *expressionVNode, IfBodyNode *ifBodyNode);

    IfStatementNode(ExpressionVNode *expressionVNode, IfBodyNode *ifBodyNode, IfBodyNode *elseBodyNode);

    void visit() {}

    void codeGen() {}
};

class IfBodyNode : public Node {
public:
    CompoundStatementNode *compoundStatementNode;
    StatementNode *statementNode;
public:
    IfBodyNode(CompoundStatementNode *compoundStatementNode);

    IfBodyNode(StatementNode *statementNode);

    void visit() {}

    void codeGen() {}
};

class SwitchStatementNode : public Node {
public:
    ExpressionVNode *expressionVNode;
    vector<LabeledStatementNode *> *labeledStatementList;
public:
    SwitchStatementNode(ExpressionVNode *expressionVNode, vector<LabeledStatementNode *> *labeledStatementList);

    void visit() {}

    void codeGen() {}
};

class LabeledStatementNode : public Node {
public:
    static const int TYPE_CASE = 0;
    static const int TYPE_DEFAULT = 0;
public:
    int type;
    ConstantNode *constantNode;
    vector<StatementNode *> *statements;
public:
    LabeledStatementNode(ConstantNode *constantNode, vector<StatementNode *> *statements);

    LabeledStatementNode(vector<StatementNode *> *statements);

    void visit() {}

    void codeGen() {}
};

#endif //COMPILER_NODE_H

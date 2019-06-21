%{
#include "node.h"
#include "codeGen.h"
#include "error.h"
#include "objGen.h"
#include "symtab.h"
#include <math.h>
#include <string>
#include <iostream>
#include <vector>
#define YYDEBUG 1

using namespace std;
int yyerror(char const *str);
/* from .l file */
extern int yylex();
extern char *yytext;
extern int yylineno;
extern FILE *yyin;

ProgramNode * root = NULL;
SymbolTable * symTab = new SymbolTable();
vector<MyError*> errors = vector<MyError*>();
llvm::LLVMContext llvmContext;

%}
%union {
    std::string  *str;
    Node  *node;
    type_var type;
    vector<DeclarationNode *> *declaration_list;
    vector<FunctionArgNode *> *function_args;
    vector<StatementNode *> *statements;
    vector<ExpressionVNode *> *incrementExpressionList;
    vector<VarDeclNode *> *varDeclarationList;
    vector<ArrayInitNode *> *array_init;
    vector<VarNode *> *var_list;
    vector<LabeledStatementNode *> *labeledStatementList;
}
%token INT LONG FLOAT SHORT VOID DOUBLE CHAR UNSIGNED CONST SIGNED STRUCT UNION ENUM VOLATILE
%token IF ELSE SWITCH GOTO CASE DO WHILE FOR CONTINUE BREAK RETURN DEFAULT TYPEDEF
%token AUTO REGISTER EXTERN STATIC
%token SIZEOF
%token SINGLE_COMMENT COMMENTS COLON
%token LEFT_PAREN RIGHT_PAREN LEFT_BRACKET RIGHT_BRACKET LEFT_BRACE RIGHT_BRACE LESS LESS_EQUAL GREATER GREATER_EQUAL
%token PLUS PLUS_PLUS MINUS MINUS_MINUS DIV MOD MUL AND_AND OR_OR EQUAL NOT_EQUAL NOT COMMA SEMI ASSIGN
%token <str> IDENTIFIER INTEGER DOUBLE_NUMBER CHARACTER STRING

%type <node> program function_declaration function_decl function_definition
%type <node> declaration function_body function_arg function_statements return_statement
%type <node> expressionv statement iterationStatement selectionStatement expressionStatement jumpStatement
%type <node> loopBody compoundStatement forCondition forInitList forExpression constant
%type <node> forDeclaration ifStatement switchStatement labeledStatement ifBody
%type <node> var_declaration var_decl array_identifier array_access array_init expression var call
%type <declaration_list> declaration_list
%type <type> type
%type <function_args> function_args function_arg_list
%type <statements> statements
%type <incrementExpressionList> incrementExpressionList expression_list args args_list
%type <labeledStatementList> labeledStatementList
%type <varDeclarationList> var_declaration_list
%type <array_init> array_init_list

%nonassoc IFX
%nonassoc ELSE

/* Lowest Precedence */
%right ASSIGN
%left OR_OR
%left AND_AND
%left EQUAL NOT_EQUAL
%left LESS LESS_EQUAL GREATER GREATER_EQUAL
%left PLUS MINUS
%left MOD MUL DIV
%right NOT PLUS_PLUS MINUS_MINUS NEG
%left LEFT_PAREN
/* Highest Precedence */

%%

// RULE BEGIN
program:
    	declaration_list {
		// create root
		root = new ProgramNode($1);
	}
	;

declaration_list:
 	declaration_list declaration {
		$1->push_back((DeclarationNode *)$2);
		$$ = $1;
 	}
 	| declaration  {
		 $$ = new vector<DeclarationNode *>();
		 $$->push_back((DeclarationNode *)$1);
 	}
	;

// BOSS WANG BEGIN

var_declaration: type var_declaration_list SEMI {
	$$ = new VarDeclarationNode($1, $2);

};

type:
	INT {
		$$ = TYPE_INT;
	}
	| DOUBLE {
		$$ = TYPE_DOUBLE;
	}
	| FLOAT {
		$$ = TYPE_FLOAT;
	}
	| VOID {
		$$ = TYPE_VOID;
	}
	| LONG {
		$$ = TYPE_LONG;
	}
	| SHORT {
		$$ = TYPE_SHORT;
	}
	| CHAR {
		$$ = TYPE_CHAR;
	};


var_declaration_list:
	var_declaration_list COMMA var_decl {
		$1->push_back((VarDeclNode *)$3);
		$$ = $1;
	}
	| var_decl {
		$$ = new vector<VarDeclNode *>;
		$$->push_back((VarDeclNode *)$1);
	}
	;


var_decl :
	IDENTIFIER {
		$$ = new VarDeclNode(SINGLE, $1, NULL, 0, NULL, NULL);
	}
	| IDENTIFIER ASSIGN expressionv {
		$$ = new VarDeclNode(SINGLE, $1, NULL, 1, (ExpressionVNode *)$3, NULL);
	}
	| array_identifier {
		$$ = new VarDeclNode(ARRAY, NULL, (ArrayIdentifierNode *)$1, 0, NULL, NULL);
	}
	| array_identifier ASSIGN array_init {
		$$ = new VarDeclNode(ARRAY, NULL, (ArrayIdentifierNode *)$1, 1, NULL, (ArrayInitNode *)$3);
	}
	;

array_identifier:
	IDENTIFIER LEFT_BRACKET INTEGER RIGHT_BRACKET {
		int temp = atoi($3->c_str());
		$$ = new ArrayIdentifierNode($1, temp);
	}
	;

array_access:
	IDENTIFIER LEFT_BRACKET INTEGER RIGHT_BRACKET {
		int temp = atoi($3->c_str());
		$$ = new ArrayAccessNode($1, temp);
	}
	;

array_init:
	LEFT_BRACE array_init_list RIGHT_BRACE {
		$$ = new ArrayInitNode($2, NULL);
	}
	| LEFT_BRACE expression_list RIGHT_BRACE {
		$$ = new ArrayInitNode(NULL, $2);
	}
	;


array_init_list:
	array_init_list COMMA array_init {
		$1->push_back((ArrayInitNode *)$1);
		$$ = $1;
	}
	| array_init {
		$$ = new vector<ArrayInitNode *>;
		$$->push_back((ArrayInitNode *)$1);
	}
	;

expression_list:
	expression_list COMMA expressionv {
		$1->push_back((ExpressionVNode *)$3);
		$$ = $1;
	}
	| expressionv{
		$$ = new vector<ExpressionVNode *>;
		$$->push_back((ExpressionVNode *)$1);
	};

expressionv: var ASSIGN expressionv{
		((ExpressionVNode *)$3)->var_list->push_back((VarNode *)$1);
		$$ = $3;
	}
	| expression{
		vector<VarNode *> *temp = new vector<VarNode *>;
		$$ = new ExpressionVNode(temp, (ExpressionNode *)$1);
	}

expression:
	expression PLUS expression{
		$$ = new ExpressionNode(EXP_PLUS, (ExpressionNode *)$1, (ExpressionNode *)$3, NULL, NULL, NULL, NULL);
	}
	| expression MINUS expression {
		$$ = new ExpressionNode(EXP_MINUS, (ExpressionNode *)$1, (ExpressionNode *)$3, NULL, NULL, NULL, NULL);
	}
	| expression MUL expression {
		$$ = new ExpressionNode(EXP_MUL, (ExpressionNode *)$1, (ExpressionNode *)$3, NULL, NULL, NULL, NULL);
	}
	| expression DIV expression {
		$$ = new ExpressionNode(EXP_DIV, (ExpressionNode *)$1, (ExpressionNode *)$3, NULL, NULL, NULL, NULL);
	}
	| expression MOD expression {
		$$ = new ExpressionNode(EXP_MOD, (ExpressionNode *)$1, (ExpressionNode *)$3, NULL, NULL, NULL, NULL);
	}
	| LEFT_PAREN expressionv RIGHT_PAREN {
		$$ = new ExpressionNode(EXP_EXPV, NULL, NULL, NULL, NULL, NULL, (ExpressionVNode *)$2);
	}
	| expression LESS expression {
		$$ = new ExpressionNode(EXP_LESS, (ExpressionNode *)$1, (ExpressionNode *)$3, NULL, NULL, NULL, NULL);
	}
	| expression LESS_EQUAL expression {
		$$ = new ExpressionNode(EXP_LESS_EQUAL, (ExpressionNode *)$1, (ExpressionNode *)$3, NULL, NULL, NULL, NULL);
	}
	| expression GREATER expression {
		$$ = new ExpressionNode(EXP_GREATER, (ExpressionNode *)$1, (ExpressionNode *)$3, NULL, NULL, NULL, NULL);
	}
	| expression GREATER_EQUAL expression {
		$$ = new ExpressionNode(EXP_GREATER_EQUAL, (ExpressionNode *)$1, (ExpressionNode *)$3, NULL, NULL, NULL, NULL);
	}
	| expression AND_AND expression {
		$$ = new ExpressionNode(EXP_AND_AND, (ExpressionNode *)$1, (ExpressionNode *)$3, NULL, NULL, NULL, NULL);
	}
	| expression OR_OR expression {
		$$ = new ExpressionNode(EXP_OR_OR, (ExpressionNode *)$1, (ExpressionNode *)$3, NULL, NULL, NULL, NULL);
	}
	| NOT expression {
		$$ = new ExpressionNode(EXP_NOT, (ExpressionNode *)$2, NULL, NULL, NULL, NULL, NULL);
	}
	| expression EQUAL expression {
		$$ = new ExpressionNode(EXP_EQUAL, (ExpressionNode *)$1, (ExpressionNode *)$3, NULL, NULL, NULL, NULL);
	}
	| expression NOT_EQUAL expression {
		$$ = new ExpressionNode(EXP_NOT_EQUAL, (ExpressionNode *)$1, (ExpressionNode *)$3, NULL, NULL, NULL, NULL);
	}
	| MINUS expression %prec NEG {
		$$ = new ExpressionNode(EXP_MINUS_SIGN, (ExpressionNode *)$2, NULL, NULL, NULL, NULL, NULL);
	}
	| PLUS_PLUS var {
		$$ = new ExpressionNode(EXP_PLUS_PLUS_L, NULL, NULL, (VarNode *)$2, NULL, NULL, NULL);
	}
	| var PLUS_PLUS {
		$$ = new ExpressionNode(EXP_PLUS_PLUS_R, NULL, NULL, (VarNode *)$1, NULL, NULL, NULL);
	}
	| MINUS_MINUS var {
		$$ = new ExpressionNode(EXP_MINUS_MINUS_L, NULL, NULL, (VarNode *)$2, NULL, NULL, NULL);
	}
	| var MINUS_MINUS {
		$$ = new ExpressionNode(EXP_MINUS_MINUS_R, NULL, NULL, (VarNode *)$1, NULL, NULL, NULL);
	}
	| var {
		$$ = new ExpressionNode(EXP_VAR, NULL, NULL, (VarNode *)$1, NULL, NULL, NULL);
	}
	| call {
		$$ = new ExpressionNode(EXP_CALL, NULL, NULL, NULL, NULL, (CallNode *)$1, NULL);
	}
	| constant {
		$$ = new ExpressionNode(EXP_CONST, NULL, NULL, NULL,(ConstantNode *)$1, NULL, NULL);
	}
	;

var:
	IDENTIFIER {
		$$ = new VarNode(SINGLE, $1, NULL);
	}
	| array_access {
		$$ = new VarNode(ARRAY, NULL, (ArrayAccessNode *)$1);
	}
	;

constant:
	INTEGER {
		int temp = atoi($1->c_str());
		$$ = new ConstantNode(TYPE_INT, temp, 0, '0');
	}
	| DOUBLE_NUMBER {
		double temp = atof($1->c_str());
		$$ = new ConstantNode(TYPE_DOUBLE, 0, temp, '0');
	}
	| CHARACTER {
		char temp = (*($1))[1];
		$$ = new ConstantNode(TYPE_CHAR, 0, 0, temp);
	};

call: IDENTIFIER LEFT_PAREN args RIGHT_PAREN {
	$$ = new CallNode($1, $3);
};

args:
	args_list {
		$$ = $1;
	}| /* EMPTY */ {
		$$ = NULL;
	}
	;


args_list:
	args_list COMMA expressionv {
		$1->push_back((ExpressionVNode *)$3);
		$$ = $1;
	}| expressionv {
		$$ = new vector<ExpressionVNode *>;
		$$->push_back((ExpressionVNode *)$1);
	};


// BOSS WANG END

declaration:
	function_declaration {
		$$ = new DeclarationNode((FunctionDeclarationNode *)$1);
	}
	| var_declaration {
		$$ = new DeclarationNode((VarDeclarationNode *)$1);
	}
	;

function_declaration:
	function_decl SEMI {
		$$ = new FunctionDeclarationNode((FunctionDeclNode *) $1);
	}
	| function_definition {
		$$ = new FunctionDeclarationNode((FunctionDefinitionNode *)$1);
	}
	;

function_definition:
	function_decl function_body {
		$$ = new FunctionDefinitionNode((FunctionDeclNode *)$1, (FunctionBodyNode *)$2);
	}
	;

function_decl:
	type IDENTIFIER LEFT_PAREN function_args RIGHT_PAREN {
		$$ = new FunctionDeclNode($1, *$2, $4);
	}
	;

function_args:
	function_arg_list {
		$$ = $1;
	}
	|  /* EMPTY */ {
		$$ = NULL;
	}
	;

function_arg_list:
	function_arg {
		$$ = new vector<FunctionArgNode *>();
		$$->push_back((FunctionArgNode *)$1);
	}
	|  function_arg_list COMMA function_arg {
		$1->push_back((FunctionArgNode *)$3);
		$$ = $1;
        }
        ;


function_arg:
	type IDENTIFIER {
		$$ = new FunctionArgNode($1, *$2);
	}
	;

function_body:
	LEFT_BRACE function_statements RIGHT_BRACE {
		$$ = new FunctionBodyNode((FunctionStatementsNode *) $2);
	}
	;


function_statements:
	statements return_statement {
		$$ = new FunctionStatementsNode($1, (ReturnStatementNode *)$2);
	}
	;

return_statement:
	RETURN expressionv SEMI {
		$$ = new ReturnStatementNode((ExpressionVNode *)$2);
	}
	| RETURN SEMI{
		$$ = new ReturnStatementNode(NULL);
	}
	|  /* EMPTY */ {
		$$ = NULL;
	}
        ;

statements:
 	statements statement {
		if($1 == NULL) {
			$$ = new vector<StatementNode *>();
		} else {
			$$ = $1;
		}
		$$->push_back((StatementNode *) $2);
	}
	|  /* EMPTY */ {
		$$ = NULL;
	}
	;

statement:
	var_declaration{
		$$ = new StatementNode((VarDeclarationNode *)$1);
	}
	| iterationStatement {
		$$ = new StatementNode((IterationStatementNode *)$1);
	}
	| selectionStatement {
		$$ = new StatementNode((SelectionStatementNode *)$1);
	}
	| expressionStatement {
		$$ = new StatementNode((ExpressionStatementNode *)$1);
	}
	| jumpStatement {
		$$ = new StatementNode((JumpStatementNode *)$1);
	}
	;

expressionStatement:
	expressionv SEMI {
		$$ = new ExpressionStatementNode((ExpressionVNode *)$1);
	}
	| SEMI {
		$$ = NULL;
	};

iterationStatement:
    WHILE LEFT_PAREN expressionv RIGHT_PAREN loopBody {
	$$ = new IterationStatementNode((ExpressionVNode *)$3, (LoopBodyNode *)$5);
    }
    | 	DO compoundStatement WHILE LEFT_PAREN expressionv RIGHT_PAREN SEMI {
	$$ = new IterationStatementNode((CompoundStatementNode *)$2, (ExpressionVNode *)$5);
    }
    |   FOR LEFT_PAREN forCondition RIGHT_PAREN loopBody {
	$$ = new IterationStatementNode((ForConditionNode *)$3, (LoopBodyNode *)$5);
    }
    ;

loopBody:
	statement{
		$$ = new LoopBodyNode((StatementNode *)$1);
	}
	| compoundStatement {
		$$ = new LoopBodyNode((CompoundStatementNode *)$1);
	}
	;

compoundStatement: LEFT_BRACE statements RIGHT_BRACE {
	$$ = new CompoundStatementNode($2);
} ;

forCondition: forInitList SEMI forExpression SEMI incrementExpressionList {
	$$ = new ForConditionNode((ForInitListNode *)$1, (ExpressionVNode *) $3, $5);
};

forExpression:
	expressionv {
		$$ = $1;
	}
	| /*Empty*/ {
		$$ = NULL;
	}
	;

incrementExpressionList:
	expression_list {
		$$ = $1;
	}| /*Empty*/ {
		$$ = NULL;
	}
	;


forInitList :
	 /*Empty*/ {
		$$ = NULL;
	}
  	| forDeclaration {
		$$ = new ForInitListNode((ForDeclarationNode *)$1);
  	}
  	| expression_list {
		$$ = new ForInitListNode($1);
  	};

forDeclaration: type var_declaration_list {
		$$ = new ForDeclarationNode($1, $2);
	}
	;

jumpStatement:
	CONTINUE SEMI {
		$$ = new JumpStatementNode(JumpStatementNode::TYPE_CONTINUE);
	}
	| BREAK SEMI {
		$$ = new JumpStatementNode(JumpStatementNode::TYPE_BREAK);
	};

selectionStatement:
	ifStatement {
		$$ = new SelectionStatementNode((IfStatementNode *)$1);
	}
	| switchStatement {
		$$ = new SelectionStatementNode((SwitchStatementNode *)$1);
	};

// Bison 应该会优先选择shift，所以这里没有二义性
ifStatement :
	IF LEFT_PAREN expressionv RIGHT_PAREN ifBody %prec IFX{
		$$ = new IfStatementNode((ExpressionVNode *)$3, (IfBodyNode *)$5);
	}
	|  IF LEFT_PAREN expressionv RIGHT_PAREN ifBody ELSE ifBody {
		$$ = new IfStatementNode((ExpressionVNode *)$3, (IfBodyNode *)$5, (IfBodyNode *)$7);
	}
	;

// 检查 continue/break 位置是否合法
ifBody:
	compoundStatement {
		$$ = new IfBodyNode((CompoundStatementNode *)$1);
	}
	| statement {
		$$ = new IfBodyNode((StatementNode *)$1);
	}
	;


switchStatement:
 	SWITCH LEFT_PAREN expressionv RIGHT_PAREN LEFT_BRACE labeledStatementList RIGHT_BRACE {
		$$ = new SwitchStatementNode((ExpressionVNode *)$3, $6);
 	}
 	;


labeledStatementList:
	labeledStatementList labeledStatement{
		if($1 == NULL){
			$$ = new vector<LabeledStatementNode *>();
		} else {
			$$ = $1;
		}
		$$->push_back((LabeledStatementNode *)$2);
	}
	| /*EMPTY*/ {
		$$ = NULL;
	}


// 检查单个switch是否存在相同的label
labeledStatement :
	CASE constant COLON statements {
		$$ = new LabeledStatementNode((ConstantNode *)$2, $4);
	}
	| DEFAULT COLON statements {
		$$ = new LabeledStatementNode($3);
	};

%%

int yyerror(char const *str)
{
    extern char *yytext;
    MyError* err = new MyError(MyError::ERROR_SYNTAX, yylineno, yytext);
    err->Print();
    return 0;
}

int main(int argv, char **argc)
{
//	# define YYDEBUG 1
//	yydebug = 1;

    if(argv != 2){
	cout << "Usage: " << string(argc[0]) << " file" << endl;
	exit(0);
    }

    // yyin = stdin;
    FILE* fp=fopen(argc[1], "r");
    if(fp == NULL){
    	cout << "Cannot open file: " << string(argc[0]) << endl;
	exit(1);
    }
    MyError::setCurrentFile(string(argc[1]));
    yyin = fp;
    if (yyparse()) {
        exit(1);
    }

    root->buildSymbolTable();

    CodeGenContext context;
    context.generateCode(*root);
    ObjGen(context, "out.o");
    // root->visit();
}
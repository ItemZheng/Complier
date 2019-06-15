%{
#include "node.h"
#include <math.h>
#include <string>
#include <iostream>
#define YYDEBUG 1

using namespace std;
int yyerror(char const *str);
/* from .l file */
extern int yylex();
extern char *yytext;
extern int yylineno;
extern FILE *yyin;

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
// %type <>  TODO

%type <node> var_declaration var_decl expressionv array_identifier array_access array_init expression var call constant
%type <type> type
%type <varDeclarationList> var_declaration_list 
%type <array_init> array_init_list
%type <incrementExpressionList> expression_list args args_list

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
	}
	;

declaration_list:
 	declaration_list declaration {

 	}
 	| declaration  {

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

expression_list: expression_list COMMA expressionv {
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
		$$ = new ExpressionNode(EXP_PLUS, (ExpressionNode *)$1, (ExpressionNode *)$3, NULL, NULL, NULL);
	}
	| expression MINUS expression {
		$$ = new ExpressionNode(EXP_MINUS, (ExpressionNode *)$1, (ExpressionNode *)$3, NULL, NULL, NULL);
	}
	| expression MUL expression {
		$$ = new ExpressionNode(EXP_MUL, (ExpressionNode *)$1, (ExpressionNode *)$3, NULL, NULL, NULL);
	}
	| expression DIV expression {
		$$ = new ExpressionNode(EXP_DIV, (ExpressionNode *)$1, (ExpressionNode *)$3, NULL, NULL, NULL);
	}
	| expression MOD expression {
		$$ = new ExpressionNode(EXP_MOD, (ExpressionNode *)$1, (ExpressionNode *)$3, NULL, NULL, NULL);
	}
	| LEFT_PAREN expressionv RIGHT_PAREN {
		$$ = $2;
	}
	| expression LESS expression {
		$$ = new ExpressionNode(EXP_LESS, (ExpressionNode *)$1, (ExpressionNode *)$3, NULL, NULL, NULL);
	}
	| expression LESS_EQUAL expression {
		$$ = new ExpressionNode(EXP_LESS_EQUAL, (ExpressionNode *)$1, (ExpressionNode *)$3, NULL, NULL, NULL);
	}
	| expression GREATER expression {
		$$ = new ExpressionNode(EXP_GREATER, (ExpressionNode *)$1, (ExpressionNode *)$3, NULL, NULL, NULL);
	}
	| expression GREATER_EQUAL expression {
		$$ = new ExpressionNode(EXP_GREATER_EQUAL, (ExpressionNode *)$1, (ExpressionNode *)$3, NULL, NULL, NULL);
	}
	| expression AND_AND expression {
		$$ = new ExpressionNode(EXP_AND_AND, (ExpressionNode *)$1, (ExpressionNode *)$3, NULL, NULL, NULL);
	}
	| expression OR_OR expression {
		$$ = new ExpressionNode(EXP_OR_OR, (ExpressionNode *)$1, (ExpressionNode *)$3, NULL, NULL, NULL);
	}
	| NOT expression {
		$$ = new ExpressionNode(EXP_NOT, (ExpressionNode *)$2, NULL, NULL, NULL, NULL);
	}
	| expression EQUAL expression {
		$$ = new ExpressionNode(EXP_EQUAL, (ExpressionNode *)$1, (ExpressionNode *)$3, NULL, NULL, NULL);
	}
	| expression NOT_EQUAL expression {
		$$ = new ExpressionNode(EXP_NOT_EQUAL, (ExpressionNode *)$1, (ExpressionNode *)$3, NULL, NULL, NULL);
	}
	| MINUS expression %prec NEG {
		$$ = new ExpressionNode(EXP_MINUS_SIGN, (ExpressionNode *)$2, NULL, NULL, NULL, NULL);
	}
	| PLUS_PLUS var {
		$$ = new ExpressionNode(EXP_PLUS_PLUS_L, NULL, NULL, (VarNode *)$2, NULL, NULL);
	}
	| var PLUS_PLUS {
		$$ = new ExpressionNode(EXP_PLUS_PLUS_R, NULL, NULL, (VarNode *)$1, NULL, NULL);
	}
	| MINUS_MINUS var {
		$$ = new ExpressionNode(EXP_MINUS_MINUS_L, NULL, NULL, (VarNode *)$2, NULL, NULL);
	}
	| var MINUS_MINUS {
		$$ = new ExpressionNode(EXP_MINUS_MINUS_R, NULL, NULL, (VarNode *)$1, NULL, NULL);
	}
	| var {
		$$ = new ExpressionNode(EXP_VAR, NULL, NULL, (VarNode *)$1, NULL, NULL);
	}
	| call {
		$$ = new ExpressionNode(EXP_CALL, NULL, NULL, NULL, NULL, (CallNode *)$1);
	}
	| constant {
		$$ = new ExpressionNode(EXP_CONST, NULL, NULL, NULL,(ConstantNode *)$1, NULL);
	}
	;

var:
	IDENTIFIER {
		$$ = new VarNode(SINGLE, $1, NULL);
	}
	| array_access {
		$$ = new VarNode(SINGLE, NULL, (ArrayAccessNode *)$1);
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

	}
	| var_declaration {

	}
	;

function_declaration:
	function_decl SEMI {

	}
	| function_definition {

	}
	;

function_definition:
	function_decl function_body {

	}
	;

function_decl:
	type IDENTIFIER LEFT_PAREN function_args RIGHT_PAREN {

	}
	;

function_args:
	function_arg_list {

	}
	|  /* EMPTY */ {

	}
	;

function_arg_list:
	function_arg {

	}
	|  function_arg COMMA function_arg_list {

        }
        ;


function_arg:
	type IDENTIFIER {

	}
	;

function_body:
	LEFT_BRACE function_statements RIGHT_BRACE {

	}
	;


function_statements:
	statements return_statement {

	}
	;

return_statement:
	RETURN expressionv SEMI {

	}
	|  /* EMPTY */ {

	}
        ;

statements:
 	statement statements {

	}
	|  /* EMPTY */ {

	}
	;

statement:
	var_declaration{

	}

	| iterationStatement {

	}
	| selectionStatement {

	}
	| expressionStatement {

	}
	| jumpStatement {

	}
	;

expressionStatement:
	expressionv SEMI {

	}
	| SEMI {

	};

iterationStatement:
    WHILE LEFT_PAREN expressionv RIGHT_PAREN loopBody {

    }
    | 	DO compoundStatement WHILE LEFT_PAREN expressionv RIGHT_PAREN SEMI {

    }
    |   FOR LEFT_PAREN forCondition RIGHT_PAREN loopBody {

    }
    ;

loopBody:
	statement{

	}
	| compoundStatement {

	}
	;

compoundStatement: LEFT_BRACE statements RIGHT_BRACE {

} ;

forCondition: forInitList SEMI forExpression SEMI incrementExpressionList {

};

forExpression:
	expressionv {

	}
	| /*Empty*/ {

	}
	;

incrementExpressionList:
	expression_list {

	}| /*Empty*/ {

	}
	;


forInitList :
	 /*Empty*/ {

	}
  	| forDeclaration {

  	}
  	| expression_list {

  	};

forDeclaration: type var_declaration_list {

	}
	;

jumpStatement:
	CONTINUE SEMI {

	}
	| BREAK SEMI {

	};

selectionStatement:
	ifStatement {

	}
	| switchStatement {

	};

// Bison 应该会优先选择shift，所以这里没有二义性
ifStatement :
	IF LEFT_PAREN expressionv RIGHT_PAREN ifBody %prec IFX{

	}
	|  IF LEFT_PAREN expressionv RIGHT_PAREN ifBody ELSE elseBody {

	}
	;

// 检查 continue/break 位置是否合法
ifBody:
	compoundStatement {

	}
	| statement {

	}
	;

elseBody:
	compoundStatement{

	}
	| statement {

	}
	;

switchStatement:
 	SWITCH LEFT_PAREN expressionv RIGHT_PAREN LEFT_BRACE labeledStatementList RIGHT_BRACE {

 	}
 	;


labeledStatementList:
	labeledStatement labeledStatementList {

	}
	| /*EMPTY*/ {

	}


// 检查单个switch是否存在相同的label
labeledStatement :
	CASE constant COLON statements {

	}
	| DEFAULT COLON statements {

	};

%%

int yyerror(char const *str)
{
    extern char *yytext;
    fprintf(stderr, "Parser error near %s at line %d\n", yytext, yylineno);
    return 0;
}

int main(void)
{
//	# define YYDEBUG 1
//	yydebug = 1;
    yyin = stdin;
    if (yyparse()) {
        exit(1);
    }
}
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

ProgramNode * root = NULL;

%}
%union {
    std::string  *str;
    Node  *node;
    vector<DeclarationNode *> *declaration_list;
    vector<FunctionArgNode *> *function_args;
    vector<StatementNode *> *statements;
    vector<ExpressionVNode *> *incrementExpressionList;
    vector<VarDeclNode *> *varDeclarationList;
    vector<ArrayInitNode *> *array_init;
    vector<VarNode *> *var_list;
    vector<LabeledStatementNode *> *labeledStatementList;
    type_var type;
}
%token INT LONG FLOAT SHORT VOID DOUBLE CHAR UNSIGNED CONST SIGNED STRUCT UNION ENUM VOLATILE
%token IF ELSE SWITCH GOTO CASE DO WHILE FOR CONTINUE BREAK RETURN DEFAULT TYPEDEF
%token AUTO REGISTER EXTERN STATIC
%token SIZEOF
%token INTEGER DOUBLE_NUMBER CHARACTER STRING SINGLE_COMMENT COMMENTS COLON
%token LEFT_PAREN RIGHT_PAREN LEFT_BRACKET RIGHT_BRACKET LEFT_BRACE RIGHT_BRACE LESS LESS_EQUAL GREATER GREATER_EQUAL
%token PLUS PLUS_PLUS MINUS MINUS_MINUS DIV MOD MUL AND_AND OR_OR EQUAL NOT_EQUAL NOT COMMA SEMI ASSIGN
%token <str> IDENTIFIER

%type <node> program function_declaration var_declaration function_decl function_definition
%type <node> declaration function_body function_arg function_statements return_statement
%type <node> expressionv statement iterationStatement selectionStatement expressionStatement jumpStatement
%type <node> loopBody compoundStatement forCondition forInitList forExpression constant
%type <node> forDeclaration ifStatement switchStatement labeledStatement ifBody
%type <declaration_list> declaration_list
%type <type> type
%type <function_args> function_args function_arg_list
%type <statements> statements
%type <incrementExpressionList> incrementExpressionList expression_list
%type <varDeclarationList> var_declaration_list
%type <labeledStatementList> labeledStatementList

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

};

type:
	INT {

	}
	| DOUBLE {

	}
	| FLOAT {

	}
	| VOID {

	}
	| LONG {

	}
	| SHORT {

	}
	| CHAR {

	};


var_declaration_list:
	var_declaration_list COMMA var_decl {

	}
	| var_decl {

	}
	;


var_decl :
	IDENTIFIER {

	}
	| IDENTIFIER ASSIGN expressionv {

	}
	| array_identifier {

	}
	| array_identifier ASSIGN array_init {

	}
	;

array_identifier:
	IDENTIFIER LEFT_BRACKET INTEGER RIGHT_BRACKET {

	}
	;


array_init:
	LEFT_BRACE array_init_list RIGHT_BRACE {

	}
	| LEFT_BRACE expression_list RIGHT_BRACE {

	}
	;


array_init_list:
	array_init_list COMMA array_init {

	}
	| array_init {

	}
	;

expression_list: expression_list COMMA expressionv {

}
	| expressionv{

	};

expressionv: var ASSIGN expressionv{

	}
	| expression{

	}

expression:
	expression PLUS expression{

	}
	| expression MINUS expression {

	}
	| expression MUL expression {

	}
	| expression DIV expression {

	}
	| expression MOD expression {

	}
	| LEFT_PAREN expressionv RIGHT_PAREN {

	}
	| expression LESS expression {

	}
	| expression LESS_EQUAL expression {

	}
	| expression GREATER expression {

	}
	| expression GREATER_EQUAL expression {

	}
	| expression AND_AND expression {

	}
	| expression OR_OR expression {

	}
	| NOT expression {

	}
	| expression EQUAL expression {

	}
	| expression NOT_EQUAL expression {

	}
	| MINUS expression %prec NEG {

	}
	| PLUS_PLUS var {

	}
	| var PLUS_PLUS {

	}
	| MINUS_MINUS var {

	}
	| var MINUS_MINUS {

	}
	| var {

	}
	| call {

	}
	| constant {

	}
	;

var:
	IDENTIFIER {

	}
	| array_identifier {

	}
	;

constant:
	INTEGER {

	}
	| DOUBLE_NUMBER {

	}
	| CHARACTER {

	};

call: IDENTIFIER LEFT_PAREN args RIGHT_PAREN {

};

args:
	args_list {

	}| /* EMPTY */ {

	}
	;


args_list:
	args_list COMMA expressionv {

	}| expressionv {

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
	|  function_arg COMMA function_arg_list {
		$3->push_back((FunctionArgNode *)$1);
		$$ = $3;
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
	|  /* EMPTY */ {
		$$ = NULL;
	}
        ;

statements:
 	statement statements {
		if($2 == NULL) {
			$$ = new vector<StatementNode *>();
		} else {
			$$ = $2;
		}
		$$->push_back((StatementNode *) $1);
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
	labeledStatement labeledStatementList {
		if($2 == NULL){
			$$ = new vector<LabeledStatementNode *>();
		} else {
			$$ = $2;
		}
		$$->push_back((LabeledStatementNode *)$1);
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
%{
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
    int          int_value;
    double       double_value;
    std::string  *str;
    // TODO
}
%token INT LONG FLOAT SHORT VOID DOUBLE CHAR UNSIGNED CONST SIGNED STRUCT UNION ENUM VOLATILE
%token IF ELSE SWITCH GOTO CASE DO WHILE FOR CONTINUE BREAK RETURN DEFAULT TYPEDEF
%token AUTO REGISTER EXTERN STATIC
%token SIZEOF
%token IDENTIFIER INTEGER DOUBLE_NUMBER CHARACTER STRING SINGLE_COMMENT COMMENTS COLON
%token LEFT_PAREN RIGHT_PAREN LEFT_BRACKET RIGHT_BRACKET LEFT_BRACE RIGHT_BRACE LESS LESS_EQUAL GREATER GREATER_EQUAL
%token PLUS PLUS_PLUS MINUS MINUS_MINUS DIV MOD MUL AND_AND OR_OR EQUAL NOT_EQUAL NOT COMMA SEMI ASSIGN

%left MINUS
%nonassoc NEG
// %type <>  TODO

%%

// RULE BEGIN
program:
    	declaration_list {
		// create root
	};

declaration_list:
 	declaration_list declaration {

 	}
 	| declaration  {

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
	| IDENTIFIER ASSIGN expression {

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

expression_list: expression_list COMMA expression {

};

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
	| LEFT_PAREN expression RIGHT_PAREN {

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
	| var ASSIGN expression {

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
	args_list COMMA expression {

	}| expression {

	};


// BOSS WANG END

declaration:
	function_declaration {

	}
	| var_declaration {

	}
	;

function_declaration:
	function_declaration_only{

	}
	| function_definition {

	}
	;

function_declaration_only:
	function_decl SEMI {

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
	RETURN IDENTIFIER SEMI {

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
	iterationStatement {

	}
	| selectionStatement {

	}
	| expressionStatement {

	}
	| jumpStatement {

	}
	;

expressionStatement:
	expression SEMI {

	}
	| SEMI {

	};

iterationStatement:
    WHILE LEFT_PAREN expression RIGHT_PAREN loopBody {

    }
    | 	DO compoundStatement WHILE LEFT_PAREN expression RIGHT_PAREN SEMI {

    }
    |   FOR LEFT_PAREN forCondition RIGHT_PAREN loopBody {

    }
    ;

loopBody:
	statement{

	}
	| compoundStatement {

	}
	| SEMI {

	} ;

compoundStatement: LEFT_BRACE statements RIGHT_BRACE {

} ;

forCondition: forInitList SEMI forExpression SEMI incrementExpressionList {

};

forExpression:
	expression {

	}
	| /*Empty*/ {

	}
	;

incrementExpressionList:
	expressions {

	}| /*Empty*/ {

	}
	;

expressions:
	expression COMMA expressions {

	}
	| expression {

	};


forInitList :
	 /*Empty*/ {

	}
  	| forDeclaration {

  	}
  	| expressions {

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
	IF LEFT_PAREN expression RIGHT_PAREN ifBody {

	}
	|  IF LEFT_PAREN expression RIGHT_PAREN ifBody ELSE elseBody {

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
 	SWITCH LEFT_PAREN expression RIGHT_PAREN LEFT_BRACE labeledStatementList RIGHT_BRACE {

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
    yyin = stdin;
    if (yyparse()) {
        exit(1);
    }
}
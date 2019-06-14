Rule: parse.y lexer.l
	yacc -d -v parse.y
	flex lexer.l
	g++ lex.yy.c y.tab.c

clean:
	rm lex.yy.c y.tab.c y.tab.h y.output a.out
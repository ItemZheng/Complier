Compiler: ./rule/parse.y ./rule/lexer.l
	yacc -d -v ./rule/parse.y
	flex ./rule/lexer.l
	g++ lex.yy.c y.tab.c -o compiler

test:	./*
	make
	./test.sh

clean:
	rm -rf ./lex.yy.c ./y.tab.c ./y.tab.h ./y.output ./error.log compiler
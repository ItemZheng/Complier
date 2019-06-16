Compiler: ./rule/parse.y ./rule/lexer.l ./node.cpp ./node.h ./type.h
	yacc -d -v ./rule/parse.y
	flex ./rule/lexer.l
	g++ -std=c++11 node.cpp lex.yy.c y.tab.c -o compiler 

test:Compiler
	make
	./test.sh

clean:
	rm -rf ./lex.yy.c ./y.tab.c ./y.tab.h ./y.output ./error.log compiler
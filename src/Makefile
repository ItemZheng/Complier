Compiler: ./rule/parse.y ./rule/lexer.l ./node.cpp ./node.h \
			./type.h ./error.h ./error.cpp ./symtab.h ./symtab.cpp
	yacc -d -v ./rule/parse.y
	flex ./rule/lexer.l
	mv lex.yy.c lex.yy.cpp
	mv y.tab.c y.tab.cpp
	g++ error.cpp node.cpp symtab.cpp lex.yy.cpp y.tab.cpp -o compiler

test: Compiler
	./test.sh

clean:
	rm -rf ./lex.yy.cpp ./y.tab.cpp ./y.tab.h ./y.output ./error.log compiler ./a.out
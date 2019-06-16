cmake_minimum_required(VERSION 3.13)
project(Compiler)

set(CMAKE_CXX_STANDARD 14)

add_executable(Compiler ./src/y.tab.cpp ./src/y.tab.h ./src/lex.yy.cpp ./src/node.cpp ./src/node.h ./src/type.h ./src/error.h ./src/error.cpp ./src/symtab.h ./src/symtab.cpp src/test/Success/test_loop.c src/test/Success/test_all.c src/test/Fail/test_undec1.c src/test/Fail/test_undec2.c src/test/Fail/test_undec3.c src/test/Fail/test_undec4.c src/test/Fail/test_redec1.c src/test/Fail/test_redec2.c src/test/Success/test_sym1.c src/test/Success/test_sym2.c src/test/Success/test_sym_loop.c src/test/Success/test_sym_switch.c src/test/Success/test_sym_if.c src/test/Fail/test_redec3.c src/test/Success/test_sym3.c src/test/Fail/test_redec4.c)
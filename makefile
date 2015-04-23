all: mpaparser.zip mpaparser

mpaparser.zip:  mpaparser.l  mpaparser.y
	zip mpaparser.zip mpaparser.l mpaparser.y

mpaparser: lex.yy.c y.tab.c functions.c
	gcc -g -o mpaparser functions.c y.tab.c lex.yy.c -ll -ly

lex.yy.c: mpaparser.l
	lex mpaparser.l

y.tab.c: mpaparser.y
	yacc -v -d mpaparser.y

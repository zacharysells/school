all: parser

parser: lex.yy.c
	gcc lex.yy.c -ll -o parser

lex.yy.c: lab1.lex
	flex lab1.lex

clean:
	rm -f a.out parser lex.yy.c

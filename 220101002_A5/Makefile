a.out: lex.yy.c lexer.cpp
	g++ lex.yy.c lexer.cpp -o a.out -ll

lex.yy.c: lexer.l
	flex lexer.l

clean:
	rm -f lex.yy.c a.out

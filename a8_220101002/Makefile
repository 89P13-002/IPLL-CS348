ouput : y.tab.c lex.yy.c
	gcc -o output y.tab.c lex.yy.c -lfl

y.tab.c : 220101002.y 
	yacc -d 220101002.y 

lex.yy.c: 220101002.l
	flex 220101002.l

clean : 
	rm -f y.tab.c y.tab.h lex.yy.c output 
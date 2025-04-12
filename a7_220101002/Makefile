parser: lex.yy.c y.tab.c y.tab.h
	g++ lex.yy.c y.tab.c -lm -o parser

lex.yy.c: a7_220101002.l
	lex a7_220101002.l

y.tab.c y.tab.h: a7_220101002.y
	yacc -d a7_220101002.y

clean:
	rm -f parser lex.yy.c y.tab.c y.tab.h output.txt symbol_table.txt y.output

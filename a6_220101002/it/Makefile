out: lex.yy.c
	g++ lex.yy.c  -o out -ll

lex.yy.c: a6it_220101002.l
	flex a6it_220101002.l

clean:
	rm -f lex.yy.c out output.txt sym_table.txt

compiler: lex.yy.o y.tab.o a9_220101002_handle.o
	g++ lex.yy.o y.tab.o a9_220101002_handle.o -lfl -o compiler

a9_220101002_handle.o: a9_220101002_handle.cpp a9_220101002_handle.h
	g++ -c a9_220101002_handle.h
	g++ -c a9_220101002_handle.cpp


lex.yy.o: lex.yy.c
	g++ -c lex.yy.c

y.tab.o: y.tab.c
	g++ -c y.tab.c

lex.yy.c: a9_220101002.l y.tab.h a9_220101002_handle.h
	flex a9_220101002.l

y.tab.c: a9_220101002.y
	bison -dtv -o y.tab.c a9_220101002.y

y.tab.h: a9_220101002.y
	bison -dtv -o y.tab.h a9_220101002.y

clean:
	rm -f lex.yy.c y.tab.c y.tab.h *.o y.output compiler *.gch *.out


# ./compiler < input.txt > output.txt
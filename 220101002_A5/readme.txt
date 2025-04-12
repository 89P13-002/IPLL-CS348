command to run the code :
$ make clean (if needed)
$ make 
$ ./a.out

File description :
input.nc : Contion the file to be tokenaized
lexer.cpp : Contain a helper fun for reading the input.nc and tokenizing it
lexer.l : Contain the regular expression for validation and tokenaization
symbol_lit_table.txt : Print the symbol and literral table 
output.txt : Tokenaized output of input.cc
Makefile : Makefile
lex.yy.c : Output after compliling lexer.l
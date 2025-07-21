%{
    #include <bits/stdc++.h>

    #define KEYWORD       1
    #define IDENTIFIER    2
    #define INTCONST      3
    #define FLOATCONST    4
    #define CHARCONST     5
    #define STRING        6
    #define PUNCTUATOR    7
    #define SINGLECOMMENT 8
    #define MULTCOMMENT   9

    using namespace std;

    set<string> idTable;
    map<string, int> litTable;
    ofstream outfile("output.txt");
    ofstream symfile("sym_table.txt");
%}

/*KEYWORDS*/
KEYWORD     "return"|"char"|"bool"|"begin"|"void"|"for"|"if"|"end"|"float"|"const"|"do"|"integer"|"while"|"else"

/*IDENTIFIER*/
IDENTIFIER  [_a-zA-Z][_a-zA-Z0-9]*

/*DIGITS*/
DIGIT      [0-9]
NONZERO    [1-9]

/*INTEGER CONSTANT*/
INTCONST   ({NONZERO}{DIGIT}*|0)

/*FLOATING CONSTANT*/
DIGITSEQ   {DIGIT}+
SIGN       [+-]
EXPONENT   ([eE]{SIGN}?{DIGITSEQ})
FRACTION   ({DIGITSEQ}?\.{DIGITSEQ}|{DIGITSEQ}\.)
FLOATCONST ({FRACTION}{EXPONENT}?|{DIGITSEQ}{EXPONENT})

/*MULTI-LINE COMMENT*/
MULTCOMMENT    "/*"([^*]|[*][^/])*"*/"

/*SINGLE LINE COMMENT*/
SINGLECOMMENT  "//".*

/*ESCAPE CHARACTER*/
ESCCHAR    [\\][abfnrtv"'\\?]

/*CHARACTER CONSTANT*/
CHARCONST  \'([^\\\'\n]|{ESCCHAR})+\'

/*STRING CONSTANT*/
STRING    \"([^\\\"\n]|{ESCCHAR})*\"

/*PUNCTUATOR*/
BRACKET    "["|"]"|"("|")"
IMM        "++"|"--"
ARITHOP    "+"|"-"|"*"|"/"|"%"|"^"
COMP       "!"|"<="|">="|"=="|"<"|">"|"!="
BOOLOP     "&"|"&&"|"|"|"||"|">>"|"<<"
ASSIGN     "->"|"="
OTHER      "?"|":"|";"|"," 
PUNCTUATOR {BRACKET}|{IMM}|{ARITHOP}|{COMP}|{BOOLOP}|{ASSIGN}|{OTHER}

/*WHITESPACE , TAB , NEW LINE CHARACTER*/
WHITESPACE  [ \t\n]+

%%
{KEYWORD}       {outfile<<"<KEYWORD, 1, "<<yytext<<">\n";return KEYWORD;}
{IDENTIFIER}    {outfile<<"<IDENTIFIER, 2, "<<yytext<<">\n";idTable.insert(yytext); return IDENTIFIER;}
{INTCONST}      {outfile<<"<INTCONST, 3, "<<yytext<<">\n";litTable[yytext] = INTCONST; return INTCONST;}
{FLOATCONST}    {outfile<<"<FLOATCONST, 4,"<<yytext<<">\n";litTable[yytext] = FLOATCONST; return FLOATCONST;}
{CHARCONST}     {outfile<<"<CHARCONST, 5, "<<yytext<<">\n";litTable[yytext] = CHARCONST; return CHARCONST;}
{STRING}        {outfile<<"<STRING, 6, "<<yytext<<">\n";litTable[yytext] = STRING; return STRING;}
{PUNCTUATOR}    {outfile<<"<PUNCTUATOR, 7, "<<yytext<<">\n";return PUNCTUATOR;}
{SINGLECOMMENT} {outfile<<"<SINGLECOMMENT, 8, "<<yytext<<">\n";return SINGLECOMMENT;}
{MULTCOMMENT}   {outfile<<"<MULTCOMMENT, 9, "<<yytext<<">\n";return MULTCOMMENT;}
{WHITESPACE}    {/* ignore whitespace */}
.               {outfile<<"<INVALID TOKEN, "<<yytext<<">\n";}
%%

void recursiveLex(){
    int token = yylex();
    if (token == 0){
        return;
    }
    recursiveLex();
}

int main() {
    yyin = fopen("a6_220101002_test.nc","r");
    recursiveLex();

    symfile << "Literals:\n\n";
    for(const auto &lit : litTable){
        symfile<<left<<setw(50)<<lit.first<<": "<<(lit.second == INTCONST ? "INTCONST" : lit.second == FLOATCONST ? "FLOATCONST" : lit.second == CHARCONST ? "CHARCONST" : "STRING")<<"\n";
    }

    symfile << "\nIdentifiers:\n\n";
    for(const auto &id : idTable){
        symfile<<left<<setw(50)<<id<<"\n";
    }

    fclose(yyin);
    outfile.close();
    symfile.close();
    cout<<"Tokenized output written to output.txt\n";
    cout<<"Symbol table written to sym_table.txt\n";
    return 0;
}
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
    map<string,int> litTable;
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
{KEYWORD}           {return KEYWORD;}
{IDENTIFIER}        {return IDENTIFIER;}
{INTCONST}          {return INTCONST;}
{FLOATCONST}        {return FLOATCONST;}
{CHARCONST}         {return CHARCONST;}
{STRING}            {return STRING;}
{PUNCTUATOR}        {return PUNCTUATOR;}
{SINGLECOMMENT}     {return SINGLECOMMENT;}
{MULTCOMMENT}       {return MULTCOMMENT;}
{WHITESPACE}        ;
.                   {return yytext[0];}
%%
 
int main(){
    yyin = fopen("a6_220101002_test.nc","r");
    ofstream outfile("output.txt");
    ofstream symfile("sym_table.txt");
    int token;
    while((token = yylex())){
        if(token == KEYWORD){
            outfile<<"<KEYWORD, "<<token<<", "<<yytext<<">\n";      
        } 
        else if(token == IDENTIFIER){
            outfile<<"<IDENTIFIER, "<<token<<", "<<yytext<<">\n";      
            idTable.insert(yytext);
        } 
        else if(token == INTCONST){
            outfile<<"<INTCONST, "<<token<<", "<<yytext<<">\n";      
            litTable[yytext] = INTCONST;
        } 
        else if(token == FLOATCONST){
            outfile<<"<FLOATCONST, "<<token<<", "<<yytext<<">\n";      
            litTable[yytext] = FLOATCONST;
        } 
        else if(token == CHARCONST){
            outfile<<"<CHARCONST, "<<token<<", "<<yytext<<">\n";      
            litTable[yytext] = CHARCONST;
        } 
        else if(token == STRING){
            outfile<<"<STRING, "<<token<<", "<<yytext<<">\n";      
            litTable[yytext] = STRING;
        } 
        else if(token == PUNCTUATOR){
            outfile<<"<PUNCTUATOR, "<<token<<", "<<yytext<<">\n";      
        } 
        else if(token == SINGLECOMMENT){
            outfile<<"<SINGLECOMMENT, "<<token<<", "<<yytext<<">\n";      
        } 
        else if(token == MULTCOMMENT){
            outfile<<"<MULTCOMMENT, "<<token<<", "<<yytext<<">\n";      
        } 
        else{
            outfile<<"<INVALID TOKEN, "<<yytext<<">\n";      
        }
    }

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
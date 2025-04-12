%{
    #include<bits/stdc++.h>
    #include "y.tab.h"
    
    using namespace std;
    
    map<string, int> symbol_table;
    extern ofstream output;
    
    void add_to_symbol_table(const char* name, const int lnum);
    void print_symbol_table();
    
    int lineNum = 1;
%}

%option nounput
%x MULTILINECOMMENT
%x SINGLELINECOMMENT

/* KEYWORDS */
RETURN      "return"
VOID        "void"
FLOAT       "float"
INTEGER     "integer"
CHAR        "char"
FOR         "for"
CONST       "const"
WHILE       "while"
BOOL        "bool"
IF          "if"
DO          "do"
ELSE        "else"
BEGINBLOCK  "begin"
END         "end"

/* OPERATORS AND PUNCTUATORS */
LBRACKET    "["
RBRACKET    "]"
LPAREN      "("
RPAREN      ")"
DEREF       "->"
INCR        "++"
DECR        "--"
BITAND      "&"
MULT        "*"
ADD         "+"
SUB         "-"
LOGICALNOT  "!"
DIV         "/"
MOD         \%
LSHIFT      "<<"
RSHIFT      ">>"
LESS        "<"
GREATER     ">"
LESSEQUAL   "<="
GREATEREQUAL ">="
EQUALITY    "=="
NOTEQUAL    "!="
BITXOR      "^"
BITOR       "|"
LOGICALAND  "&&"
LOGICALOR   "||"
QUESTION    "?"
COLON       ":"
SEMICOLON   ";"
ASSIGN      "="
COMMA       ","

/* IDENTIFIER */
IDENTIFIER  [_a-zA-Z][_a-zA-Z0-9]*

/* DIGITS */
DIGIT      [0-9]
NONZERO    [1-9]

/* INTEGER CONSTANT */
INTCONST   ({NONZERO}{DIGIT}*|0)

/* FLOATING CONSTANT */
DIGITSEQ    {DIGIT}+
SIGN        [+-]
EXPONENT    [eE]{SIGN}?{DIGITSEQ}
FRACTION    ({DIGITSEQ}?\.{DIGITSEQ}|{DIGITSEQ}\.)
FLOATCONST  ({FRACTION}{EXPONENT}?|{DIGITSEQ}{EXPONENT})

/*ESCAPE CHARACTER*/
ESCCHAR    \\[abfnrtv"'\\?]

/*CHARACTER CONSTANT*/
CHARCONST  \'([^\\\'\n]|{ESCCHAR})+\'

/* STRING LITERAL */
STRING      \"([^\\\"\n]|{ESCCHAR})*\"

/* WHITESPACE */
WHITESPACE  [ \t]+

/* NEWLINE */
NEWLINE     \n

%%

"/*"                    {BEGIN(MULTILINECOMMENT); output<<"Line No: "<<lineNum<<" Multiline Comment started.\n";}
<MULTILINECOMMENT>"*/"  {BEGIN(INITIAL); output<<"Line No: "<<lineNum<<" Multiline Comment ended\n";}
<MULTILINECOMMENT>\n    {lineNum++;}
<MULTILINECOMMENT>.     {/* ignoring comment content */ }

"//"                    {BEGIN(SINGLELINECOMMENT); output<<"Line No: "<<lineNum<<" Single line comment.\n";}
<SINGLELINECOMMENT>\n   {lineNum++;BEGIN(INITIAL);}
<SINGLELINECOMMENT>.    {/* ignoring comment content */ }

{RETURN}  {return RETURN;}
{VOID}    {return VOID;}
{FLOAT}   {return FLOAT;}
{INTEGER} {return INTEGER;}
{CHAR}    {return CHAR;}
{FOR}     {return FOR;}
{CONST}   {return CONST;}
{WHILE}   {return WHILE;}
{BOOL}    {return BOOL;}
{IF} {return IF;}
{DO} {return DO;}
{ELSE}  {return ELSE;}
{BEGINBLOCK}  {return BEGINBLOCK;}
{END}   {return END;}

{LBRACKET} {return LBRACKET;}
{RBRACKET} {return RBRACKET;}
{LPAREN}  {return LPAREN;}
{RPAREN}  {return RPAREN;}
{DEREF}   {return DEREF;}
{INCR} {return INCR;}
{DECR} {return DECR;}
{BITAND}  {return BITAND;}
{MULT} {return MULT;}
{ADD}  {return ADD;}
{SUB}  {return SUB;}
{LOGICALNOT}  {return LOGICALNOT;}
{DIV}  {return DIV;}
{MOD}  {return MOD;}
{LSHIFT}   {return LSHIFT;}
{RSHIFT}   {return RSHIFT;}
{LESS} {return LESS;}
{GREATER}  {return GREATER;}
{LESSEQUAL}  {return LESSEQUAL;}
{GREATEREQUAL} {return GREATEREQUAL;}
{EQUALITY} {return EQUALITY;}
{NOTEQUAL} {return NOTEQUAL;}
{BITXOR}   {return BITXOR;}
{BITOR}   {return BITOR;}
{LOGICALAND}  {return LOGICALAND;}
{LOGICALOR}  {return LOGICALOR;}
{QUESTION} {return QUESTION;}
{COLON}   {return COLON;}
{SEMICOLON}   {return SEMICOLON;}
{ASSIGN}   {return ASSIGN;}
{COMMA}   {return COMMA;}

{IDENTIFIER} {
    string id_name(yytext);
    
    if (symbol_table.find(id_name) == symbol_table.end()) {
        add_to_symbol_table(yytext, lineNum);
    }
    return IDENTIFIER;
}

{INTCONST} {return INTCONST;}

{FLOATCONST} {return FLOATCONST;}

{CHARCONST} {return CHARCONST;}

{STRING} {return STRING;}

{WHITESPACE} {}

{NEWLINE} {lineNum++;}

. {output<<"No regular expression matched for "<<yytext<<"\n";}

%%

void add_to_symbol_table(const char* name, const int lnum) {
    symbol_table[string(name)] = lnum;
}

void print_symbol_table() {
    ofstream sym_tab("symbol_table.txt");
    
    sym_tab<<"\n------------------- Symbol Table ---------------------\n";
    sym_tab<<left<<setw(40)<<"Name"<<setw(20)<<"Line Number\n";
    sym_tab<<"\n------------------------------------------------------\n";
    
    for (const auto& entry : symbol_table) {
        sym_tab<<left<<setw(40)<<entry.first<<setw(20)<<entry.second<<"\n";
    }
    sym_tab<<"\n------------------------------------------------------\n";
    
    sym_tab.close();
}

int yywrap() {
    return 1;
}
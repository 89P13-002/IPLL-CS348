%{
    #include<bits/stdc++.h>
    #include "a9_220101002_handle.h"
    #include "y.tab.h"
    
    using namespace std;

%}

%option noyywrap
%option yylineno

%x SINGLELINECOMMENT MULTILINECOMMENT

/* KEYWORDS */
RETURN      "return"
VOID        "void"
BOOL        "bool"
FLOAT       "float"
INTEGER     "integer"
CHAR        "char"
CONST       "const"
DO          "do"
WHILE       "while"
IF          "if"
ELSE        "else"
FOR         "for"
GOTO        "goto"
BREAK       "break"
BLOCKBEGIN  "begin"
BLOCKEND    "end"
/* OPERATORS AND PUNCTUATORS */
LSQRBRC     "["
RSQRBRC     "]"
LPAREN      "("
RPAREN      ")"

DEREF       "->"

INCR        "++"
DECR        "--"

LOGICALAND  "&&"
LOGICALOR   "||"
BITAND      "&"
BITXOR      "^"
BITOR       "|"
LOGICALNOT  "!"
COMPLEMENT  "~"
QUESTION    "?"
COLON       ":"

MULT        "*"
ADD         "+"
SUB         "-"
DIV         "/"
MOD         "%"

LSHIFT      "<<"
RSHIFT      ">>"
LESSEQUAL   "<="
GREATEREQUAL ">="
EQUALITY    "=="
LESS        "<"
GREATER     ">"
NOTEQUAL    "!="
ASSIGN      "="

SEMICOLON   ";"

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
WHITESPACE  [ \t]
NEWLINE     (\r\n|\r|\n)

%%
"//"                       {BEGIN(SINGLELINECOMMENT);}
<SINGLELINECOMMENT>.       {}
<SINGLELINECOMMENT>\n      {BEGIN(INITIAL);}
<SINGLELINECOMMENT><<EOF>> {BEGIN(INITIAL);}

"/*"                       {BEGIN(MULTILINECOMMENT);}
<MULTILINECOMMENT>"*/"     {BEGIN(INITIAL);}
<MULTILINECOMMENT>.        {}
<MULTILINECOMMENT>\n       {}


{RETURN} {return RETURN;}
{VOID} {return VOID;}
{BOOL} {return BOOL;}
{FLOAT} {return FLOAT;}
{INTEGER} {return INTEGER;}
{CHAR} {return CHAR;}
{CONST} {return CONST;}
{DO} {return DO;}
{WHILE} {return WHILE;}
{IF} {return IF;}
{ELSE} {return ELSE;}
{FOR} {return FOR;}
{GOTO} {return GOTO;}
{BREAK} {return BREAK;}

{LSQRBRC} {return LSQRBRC;}
{RSQRBRC} {return RSQRBRC;}
{BLOCKBEGIN} {return BLOCKBEGIN;}
{BLOCKEND} {return BLOCKEND;}
{LPAREN} {return LPAREN;}
{RPAREN} {return RPAREN;}

{DEREF} {return DEREF;}

{INCR} {return INCR;}
{DECR} {return DECR;}

{LOGICALAND} {return LOGICALAND;}
{LOGICALOR} {return LOGICALOR;}
{BITAND} {return BITAND;}
{BITXOR} {return BITXOR;}
{BITOR} {return BITOR;}
{LOGICALNOT} {return LOGICALNOT;}
{COMPLEMENT} {return COMPLEMENT;}
{QUESTION} {return QUESTION;}
{COLON} {return COLON;}

{MULT} {return MULT;}
{ADD} {return ADD;}
{SUB} {return SUB;}
{DIV} {return DIV;}
{MOD} {return MOD;}

{LSHIFT} {return LSHIFT;}
{RSHIFT} {return RSHIFT;}
{LESSEQUAL} {return LESSEQUAL;}
{GREATEREQUAL} {return GREATEREQUAL;}
{EQUALITY} {return EQUALITY;}
{LESS} {return LESS;}
{GREATER} {return GREATER;}
{NOTEQUAL} {return NOTEQUAL;}
{ASSIGN} {return ASSIGN;}

{SEMICOLON} {return SEMICOLON;}

{COMMA} {return COMMA;}

{IDENTIFIER} {
    yylval.str = new string(yytext);
    return IDENTIFIER;
}

{INTCONST} {
    yylval.intval = atoi(yytext);
    return INTCONST;
}

{FLOATCONST} {
    yylval.floatval = stof(yytext); 
    return FLOATCONST;
}

{CHARCONST} {
    yylval.charval = yytext[1];
    // cout<<"charval : "<<yylval.charval<<"\n";
    return CHARCONST;
}

{STRING} {
    yylval.str = new string(yytext);
    return STRING;
}

{WHITESPACE}* {/* Ignore whitespace */} 
{NEWLINE}* {/* Ignore newline char */}

. {cout<<"No lex rule matched : "<<yytext<<"\n";}
%%
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"
%}

hexdig      [0-9a-fA-F]
bindig      [01]
decdig      [0-9]
expr        "expr"
bintodec    "bintodec"
bintohex    "bintohex"
hextobin    "hextobin"
hextodec    "hextodec"
binnum      {bindig}+
decnum      {decdig}+
hexnum      {hexdig}+     
whitespace  [ \t\n]+
lparen      "("
rparen      ")"
add         "+"
sub         "-"
exp         "**"
mult        "*"
div         "/"


%%

{expr}         { return EXPR; }
{bintodec}     { return BINTODEC; }
{bintohex}     { return BINTOHEX; }
{hextobin}     { return HEXTOBIN; }
{hextodec}     { return HEXTODEC; }
{lparen}       { return LPAREN; }
{rparen}       { return RPAREN; }
{add}          { return ADD; }
{sub}          { return SUB; }
{mult}         { return MULT; }
{div}          { return DIV; }
{exp}          { return EXP; }

{binnum} {
    yylval.bin = strdup(yytext);
    return BINNUM;
}

{decnum} {
    yylval.dec = atoi(yytext);
    return DECNUM;
}

{hexnum} {
    yylval.hex = strdup(yytext);
    return HEXNUM;
}

{whitespace}   { /* Ignoring whitespace and newline */ }
.              { /* Ignoring undefined char */ }

%%

int yywrap() {
    return 1;
}

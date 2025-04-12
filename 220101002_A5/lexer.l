%{
    #define KEY_WORD       1
    #define IDENTIFIER     2
    #define INT_CONST      3
    #define CHAR_CONST     4
    #define STRING_LIT     5
    #define PUNCTUATOR     6 
    #define SINGLE_COMMENT 7
    #define MULT_COMMENT   8
%}

/*------- KEYWORDS ---------------*/
KEY_WORD     "char"|"else"|"for"|"if"|"int"|"return"|"void"

/*--------IDENTIFIER----------------*/
IDENTIFIER  [_a-zA-Z][_a-zA-Z0-9]*

/*--------INTEGER CONSTANT-----------*/
INT_CONST   [+-]?[0-9]+

/*--------ESCAPE CHARACTER-----------*/
ESC_CHAR    \\[abfntrv\\"'\\?]

/*--------CHARACTER CONSTANT-----------*/
CHAR_CONST  \'([^\\'\n]|{ESC_CHAR})+\'

/*--------STRING CONSTANT-----------*/
STRING_LIT  \"([^\\\"\n]|{ESC_CHAR})*\"

/*---------PUNCTUATOR--------------*/
PUNCTUATOR  (\->|<=|>=|==|!=|&&|\|\||[\[\]\(\){}\:\;\.,\*/%\!\?\&\|\=\+\-])

/*---------WHITESPACE , TAB , NEW LINE CHARACTER-----------*/
WHITESPACE  [ \t\n]+ 

/*--------SINGLE LINE COMMENT---------*/
SINGLE_COMMENT  "//".*

/*--------MULTI-LINE COMMENT----------*/
MULT_COMMENT    "/\\*([^*]|\\*+[^*/])*\\*+/"

%% 
{KEY_WORD}        return KEY_WORD;
{IDENTIFIER}      return IDENTIFIER;
{INT_CONST}       return INT_CONST;
{CHAR_CONST}      return CHAR_CONST;
{STRING_LIT}      return STRING_LIT;
{PUNCTUATOR}      return PUNCTUATOR;
{SINGLE_COMMENT}  return SINGLE_COMMENT;
{MULT_COMMENT}    return MULT_COMMENT;
{WHITESPACE}      
%%

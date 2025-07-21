/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IDENTIFIER = 258,              /* IDENTIFIER  */
    INTCONST = 259,                /* INTCONST  */
    FLOATCONST = 260,              /* FLOATCONST  */
    STRING = 261,                  /* STRING  */
    CHARCONST = 262,               /* CHARCONST  */
    RETURN = 263,                  /* RETURN  */
    VOID = 264,                    /* VOID  */
    BOOL = 265,                    /* BOOL  */
    FLOAT = 266,                   /* FLOAT  */
    INTEGER = 267,                 /* INTEGER  */
    CHAR = 268,                    /* CHAR  */
    CONST = 269,                   /* CONST  */
    DO = 270,                      /* DO  */
    WHILE = 271,                   /* WHILE  */
    IF = 272,                      /* IF  */
    ELSE = 273,                    /* ELSE  */
    FOR = 274,                     /* FOR  */
    GOTO = 275,                    /* GOTO  */
    BREAK = 276,                   /* BREAK  */
    LSQRBRC = 277,                 /* LSQRBRC  */
    RSQRBRC = 278,                 /* RSQRBRC  */
    LPAREN = 279,                  /* LPAREN  */
    RPAREN = 280,                  /* RPAREN  */
    BLOCKBEGIN = 281,              /* BLOCKBEGIN  */
    BLOCKEND = 282,                /* BLOCKEND  */
    DEREF = 283,                   /* DEREF  */
    INCR = 284,                    /* INCR  */
    DECR = 285,                    /* DECR  */
    LOGICALAND = 286,              /* LOGICALAND  */
    LOGICALOR = 287,               /* LOGICALOR  */
    BITAND = 288,                  /* BITAND  */
    BITXOR = 289,                  /* BITXOR  */
    BITOR = 290,                   /* BITOR  */
    LOGICALNOT = 291,              /* LOGICALNOT  */
    COMPLEMENT = 292,              /* COMPLEMENT  */
    QUESTION = 293,                /* QUESTION  */
    COLON = 294,                   /* COLON  */
    MULT = 295,                    /* MULT  */
    ADD = 296,                     /* ADD  */
    SUB = 297,                     /* SUB  */
    DIV = 298,                     /* DIV  */
    MOD = 299,                     /* MOD  */
    LSHIFT = 300,                  /* LSHIFT  */
    RSHIFT = 301,                  /* RSHIFT  */
    LESSEQUAL = 302,               /* LESSEQUAL  */
    GREATEREQUAL = 303,            /* GREATEREQUAL  */
    EQUALITY = 304,                /* EQUALITY  */
    LESS = 305,                    /* LESS  */
    GREATER = 306,                 /* GREATER  */
    NOTEQUAL = 307,                /* NOTEQUAL  */
    ASSIGN = 308,                  /* ASSIGN  */
    SEMICOLON = 309,               /* SEMICOLON  */
    COMMA = 310                    /* COMMA  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 19 "a9_220101002.y"

    int intval;
    char charval;
    float floatval;
    void* ptr;
    string* str;

    SymType* symType;
    Sym* symp;
    Datatype types;
    opcode opc;
    Expression* expr;
    Declaration* dec;
    vector<Declaration*> * declist;
    param* prm;
    vector<param*> *prmlist;

#line 137 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

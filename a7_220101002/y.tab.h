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
# define YYDEBUG 0
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
    RETURN = 258,                  /* RETURN  */
    VOID = 259,                    /* VOID  */
    FLOAT = 260,                   /* FLOAT  */
    INTEGER = 261,                 /* INTEGER  */
    CHAR = 262,                    /* CHAR  */
    FOR = 263,                     /* FOR  */
    CONST = 264,                   /* CONST  */
    WHILE = 265,                   /* WHILE  */
    BOOL = 266,                    /* BOOL  */
    IF = 267,                      /* IF  */
    DO = 268,                      /* DO  */
    ELSE = 269,                    /* ELSE  */
    BEGINBLOCK = 270,              /* BEGINBLOCK  */
    END = 271,                     /* END  */
    IDENTIFIER = 272,              /* IDENTIFIER  */
    INTCONST = 273,                /* INTCONST  */
    FLOATCONST = 274,              /* FLOATCONST  */
    CHARCONST = 275,               /* CHARCONST  */
    STRING = 276,                  /* STRING  */
    LBRACKET = 277,                /* LBRACKET  */
    RBRACKET = 278,                /* RBRACKET  */
    LPAREN = 279,                  /* LPAREN  */
    RPAREN = 280,                  /* RPAREN  */
    DEREF = 281,                   /* DEREF  */
    INCR = 282,                    /* INCR  */
    DECR = 283,                    /* DECR  */
    BITAND = 284,                  /* BITAND  */
    MULT = 285,                    /* MULT  */
    ADD = 286,                     /* ADD  */
    SUB = 287,                     /* SUB  */
    LOGICALNOT = 288,              /* LOGICALNOT  */
    DIV = 289,                     /* DIV  */
    MOD = 290,                     /* MOD  */
    LSHIFT = 291,                  /* LSHIFT  */
    RSHIFT = 292,                  /* RSHIFT  */
    LESS = 293,                    /* LESS  */
    GREATER = 294,                 /* GREATER  */
    LESSEQUAL = 295,               /* LESSEQUAL  */
    GREATEREQUAL = 296,            /* GREATEREQUAL  */
    EQUALITY = 297,                /* EQUALITY  */
    NOTEQUAL = 298,                /* NOTEQUAL  */
    BITXOR = 299,                  /* BITXOR  */
    BITOR = 300,                   /* BITOR  */
    LOGICALAND = 301,              /* LOGICALAND  */
    LOGICALOR = 302,               /* LOGICALOR  */
    QUESTION = 303,                /* QUESTION  */
    COLON = 304,                   /* COLON  */
    SEMICOLON = 305,               /* SEMICOLON  */
    ASSIGN = 306,                  /* ASSIGN  */
    COMMA = 307,                   /* COMMA  */
    LOWER_THAN_ELSE = 308          /* LOWER_THAN_ELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define RETURN 258
#define VOID 259
#define FLOAT 260
#define INTEGER 261
#define CHAR 262
#define FOR 263
#define CONST 264
#define WHILE 265
#define BOOL 266
#define IF 267
#define DO 268
#define ELSE 269
#define BEGINBLOCK 270
#define END 271
#define IDENTIFIER 272
#define INTCONST 273
#define FLOATCONST 274
#define CHARCONST 275
#define STRING 276
#define LBRACKET 277
#define RBRACKET 278
#define LPAREN 279
#define RPAREN 280
#define DEREF 281
#define INCR 282
#define DECR 283
#define BITAND 284
#define MULT 285
#define ADD 286
#define SUB 287
#define LOGICALNOT 288
#define DIV 289
#define MOD 290
#define LSHIFT 291
#define RSHIFT 292
#define LESS 293
#define GREATER 294
#define LESSEQUAL 295
#define GREATEREQUAL 296
#define EQUALITY 297
#define NOTEQUAL 298
#define BITXOR 299
#define BITOR 300
#define LOGICALAND 301
#define LOGICALOR 302
#define QUESTION 303
#define COLON 304
#define SEMICOLON 305
#define ASSIGN 306
#define COMMA 307
#define LOWER_THAN_ELSE 308

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

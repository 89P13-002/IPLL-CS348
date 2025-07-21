/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "a7_220101002.y"

    #include<bits/stdc++.h>
    
    using namespace std;

    extern int yylex();
    extern int lineNum;
    extern map<string, int> symbol_table;
    extern void print_symbol_table();
    
    void yyerror(const char *s);
    int yydebug = 1; 
    ofstream output;

#line 86 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_RETURN = 3,                     /* RETURN  */
  YYSYMBOL_VOID = 4,                       /* VOID  */
  YYSYMBOL_FLOAT = 5,                      /* FLOAT  */
  YYSYMBOL_INTEGER = 6,                    /* INTEGER  */
  YYSYMBOL_CHAR = 7,                       /* CHAR  */
  YYSYMBOL_FOR = 8,                        /* FOR  */
  YYSYMBOL_CONST = 9,                      /* CONST  */
  YYSYMBOL_WHILE = 10,                     /* WHILE  */
  YYSYMBOL_BOOL = 11,                      /* BOOL  */
  YYSYMBOL_IF = 12,                        /* IF  */
  YYSYMBOL_DO = 13,                        /* DO  */
  YYSYMBOL_ELSE = 14,                      /* ELSE  */
  YYSYMBOL_BEGINBLOCK = 15,                /* BEGINBLOCK  */
  YYSYMBOL_END = 16,                       /* END  */
  YYSYMBOL_IDENTIFIER = 17,                /* IDENTIFIER  */
  YYSYMBOL_INTCONST = 18,                  /* INTCONST  */
  YYSYMBOL_FLOATCONST = 19,                /* FLOATCONST  */
  YYSYMBOL_CHARCONST = 20,                 /* CHARCONST  */
  YYSYMBOL_STRING = 21,                    /* STRING  */
  YYSYMBOL_LBRACKET = 22,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 23,                  /* RBRACKET  */
  YYSYMBOL_LPAREN = 24,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 25,                    /* RPAREN  */
  YYSYMBOL_DEREF = 26,                     /* DEREF  */
  YYSYMBOL_INCR = 27,                      /* INCR  */
  YYSYMBOL_DECR = 28,                      /* DECR  */
  YYSYMBOL_BITAND = 29,                    /* BITAND  */
  YYSYMBOL_MULT = 30,                      /* MULT  */
  YYSYMBOL_ADD = 31,                       /* ADD  */
  YYSYMBOL_SUB = 32,                       /* SUB  */
  YYSYMBOL_LOGICALNOT = 33,                /* LOGICALNOT  */
  YYSYMBOL_DIV = 34,                       /* DIV  */
  YYSYMBOL_MOD = 35,                       /* MOD  */
  YYSYMBOL_LSHIFT = 36,                    /* LSHIFT  */
  YYSYMBOL_RSHIFT = 37,                    /* RSHIFT  */
  YYSYMBOL_LESS = 38,                      /* LESS  */
  YYSYMBOL_GREATER = 39,                   /* GREATER  */
  YYSYMBOL_LESSEQUAL = 40,                 /* LESSEQUAL  */
  YYSYMBOL_GREATEREQUAL = 41,              /* GREATEREQUAL  */
  YYSYMBOL_EQUALITY = 42,                  /* EQUALITY  */
  YYSYMBOL_NOTEQUAL = 43,                  /* NOTEQUAL  */
  YYSYMBOL_BITXOR = 44,                    /* BITXOR  */
  YYSYMBOL_BITOR = 45,                     /* BITOR  */
  YYSYMBOL_LOGICALAND = 46,                /* LOGICALAND  */
  YYSYMBOL_LOGICALOR = 47,                 /* LOGICALOR  */
  YYSYMBOL_QUESTION = 48,                  /* QUESTION  */
  YYSYMBOL_COLON = 49,                     /* COLON  */
  YYSYMBOL_SEMICOLON = 50,                 /* SEMICOLON  */
  YYSYMBOL_ASSIGN = 51,                    /* ASSIGN  */
  YYSYMBOL_COMMA = 52,                     /* COMMA  */
  YYSYMBOL_LOWER_THAN_ELSE = 53,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 54,                  /* $accept  */
  YYSYMBOL_primary_expression = 55,        /* primary_expression  */
  YYSYMBOL_CONSTANT = 56,                  /* CONSTANT  */
  YYSYMBOL_postfix_expression = 57,        /* postfix_expression  */
  YYSYMBOL_argument_expression_list = 58,  /* argument_expression_list  */
  YYSYMBOL_argument_expression_list_opt = 59, /* argument_expression_list_opt  */
  YYSYMBOL_unary_expression = 60,          /* unary_expression  */
  YYSYMBOL_unary_operator = 61,            /* unary_operator  */
  YYSYMBOL_multiplicative_expression = 62, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 63,       /* additive_expression  */
  YYSYMBOL_relational_expression = 64,     /* relational_expression  */
  YYSYMBOL_equality_expression = 65,       /* equality_expression  */
  YYSYMBOL_logical_AND_expression = 66,    /* logical_AND_expression  */
  YYSYMBOL_logical_OR_expression = 67,     /* logical_OR_expression  */
  YYSYMBOL_conditional_expression = 68,    /* conditional_expression  */
  YYSYMBOL_assignment_expression = 69,     /* assignment_expression  */
  YYSYMBOL_expression = 70,                /* expression  */
  YYSYMBOL_declaration = 71,               /* declaration  */
  YYSYMBOL_init_declarator = 72,           /* init_declarator  */
  YYSYMBOL_type_specifier = 73,            /* type_specifier  */
  YYSYMBOL_declarator = 74,                /* declarator  */
  YYSYMBOL_direct_declarator = 75,         /* direct_declarator  */
  YYSYMBOL_pointer = 76,                   /* pointer  */
  YYSYMBOL_pointer_opt = 77,               /* pointer_opt  */
  YYSYMBOL_parameter_list = 78,            /* parameter_list  */
  YYSYMBOL_parameter_list_opt = 79,        /* parameter_list_opt  */
  YYSYMBOL_parameter_declaration = 80,     /* parameter_declaration  */
  YYSYMBOL_identifier_opt = 81,            /* identifier_opt  */
  YYSYMBOL_initializer = 82,               /* initializer  */
  YYSYMBOL_statement = 83,                 /* statement  */
  YYSYMBOL_compound_statement = 84,        /* compound_statement  */
  YYSYMBOL_block_item_list = 85,           /* block_item_list  */
  YYSYMBOL_block_item_list_opt = 86,       /* block_item_list_opt  */
  YYSYMBOL_block_item = 87,                /* block_item  */
  YYSYMBOL_expression_statement = 88,      /* expression_statement  */
  YYSYMBOL_selection_statement = 89,       /* selection_statement  */
  YYSYMBOL_iteration_statement = 90,       /* iteration_statement  */
  YYSYMBOL_jump_statement = 91,            /* jump_statement  */
  YYSYMBOL_expression_opt = 92,            /* expression_opt  */
  YYSYMBOL_translation_unit = 93,          /* translation_unit  */
  YYSYMBOL_external_declaration = 94,      /* external_declaration  */
  YYSYMBOL_variable_declaration = 95,      /* variable_declaration  */
  YYSYMBOL_function_declaration = 96,      /* function_declaration  */
  YYSYMBOL_function_declarator = 97,       /* function_declarator  */
  YYSYMBOL_direct_function_declarator = 98, /* direct_function_declarator  */
  YYSYMBOL_function_definition = 99        /* function_definition  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  16
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   174

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  103
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  167

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   308


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    52,    52,    53,    54,    55,    59,    60,    61,    65,
      66,    67,    68,    72,    73,    77,    78,    82,    83,    87,
      88,    89,    90,    91,    95,    96,    97,    98,   102,   103,
     104,   108,   109,   110,   111,   112,   116,   117,   118,   122,
     123,   127,   128,   132,   133,   137,   138,   142,   147,   151,
     152,   156,   157,   158,   159,   160,   164,   168,   169,   170,
     174,   178,   179,   183,   184,   188,   189,   193,   197,   198,
     202,   207,   208,   209,   210,   211,   215,   220,   221,   225,
     226,   230,   231,   235,   239,   240,   244,   248,   252,   253,
     259,   260,   264,   265,   266,   270,   271,   272,   273,   277,
     281,   282,   286,   290
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "RETURN", "VOID",
  "FLOAT", "INTEGER", "CHAR", "FOR", "CONST", "WHILE", "BOOL", "IF", "DO",
  "ELSE", "BEGINBLOCK", "END", "IDENTIFIER", "INTCONST", "FLOATCONST",
  "CHARCONST", "STRING", "LBRACKET", "RBRACKET", "LPAREN", "RPAREN",
  "DEREF", "INCR", "DECR", "BITAND", "MULT", "ADD", "SUB", "LOGICALNOT",
  "DIV", "MOD", "LSHIFT", "RSHIFT", "LESS", "GREATER", "LESSEQUAL",
  "GREATEREQUAL", "EQUALITY", "NOTEQUAL", "BITXOR", "BITOR", "LOGICALAND",
  "LOGICALOR", "QUESTION", "COLON", "SEMICOLON", "ASSIGN", "COMMA",
  "LOWER_THAN_ELSE", "$accept", "primary_expression", "CONSTANT",
  "postfix_expression", "argument_expression_list",
  "argument_expression_list_opt", "unary_expression", "unary_operator",
  "multiplicative_expression", "additive_expression",
  "relational_expression", "equality_expression", "logical_AND_expression",
  "logical_OR_expression", "conditional_expression",
  "assignment_expression", "expression", "declaration", "init_declarator",
  "type_specifier", "declarator", "direct_declarator", "pointer",
  "pointer_opt", "parameter_list", "parameter_list_opt",
  "parameter_declaration", "identifier_opt", "initializer", "statement",
  "compound_statement", "block_item_list", "block_item_list_opt",
  "block_item", "expression_statement", "selection_statement",
  "iteration_statement", "jump_statement", "expression_opt",
  "translation_unit", "external_declaration", "variable_declaration",
  "function_declaration", "function_declarator",
  "direct_function_declarator", "function_definition", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-145)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-90)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     138,  -145,  -145,  -145,  -145,  -145,    -6,   104,  -145,  -145,
    -145,  -145,   -18,    -9,   -12,  -145,  -145,  -145,    -1,   138,
    -145,   108,   -14,  -145,    68,  -145,  -145,     0,     5,   -15,
      38,  -145,  -145,  -145,  -145,  -145,  -145,   108,  -145,  -145,
    -145,  -145,  -145,  -145,  -145,    90,    19,   108,    31,    13,
      55,   -23,    35,    20,  -145,  -145,    27,  -145,   108,    60,
      66,  -145,  -145,  -145,     5,  -145,  -145,    68,    87,  -145,
    -145,  -145,  -145,  -145,    63,    67,  -145,  -145,   102,   138,
    -145,    98,   108,   108,   113,   108,  -145,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,  -145,    81,   108,   108,    96,    97,   130,  -145,  -145,
    -145,  -145,  -145,  -145,  -145,  -145,   127,    99,   128,  -145,
    -145,  -145,  -145,  -145,  -145,  -145,    31,    31,    13,    13,
      13,    13,    55,    55,   -23,    35,   103,  -145,   105,   129,
    -145,   108,   -10,  -145,  -145,   108,  -145,   108,   108,    10,
    -145,   139,   138,  -145,  -145,   106,   144,   136,   135,   108,
      10,  -145,  -145,   137,  -145,    10,  -145
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    51,    54,    53,    52,    55,     0,     0,    90,    94,
      93,    92,     0,     0,     0,   100,     1,    91,     0,    66,
      95,     0,     0,   101,    80,    99,   103,     0,    62,    65,
       0,    63,     2,     6,     7,     8,     4,     0,    19,    20,
      21,    22,    23,     9,     3,    17,    24,     0,    28,    31,
      36,    39,    41,    43,    45,    70,     0,    97,    89,     0,
       0,    47,    88,    81,    62,    82,    71,    79,     0,    77,
      72,    73,    74,    75,     0,     0,    60,    61,    69,     0,
     102,     0,     0,    16,     0,     0,    18,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    98,     0,    89,     0,     0,    49,     0,    78,    76,
      83,    96,    68,    67,    64,     5,     0,    15,     0,    13,
      12,    46,    25,    26,    27,    24,    29,    30,    32,    33,
      34,    35,    37,    38,    40,    42,     0,    87,     0,     0,
      48,     0,    57,    56,    10,     0,    11,     0,    89,    89,
      50,     0,    66,    14,    44,     0,    84,     0,     0,    89,
      89,    58,    59,     0,    85,    89,    86
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -145,  -145,  -145,  -145,  -145,  -145,   -40,  -145,    15,    41,
      25,    65,    62,  -145,    17,   -21,   -22,  -145,  -145,     2,
    -145,  -145,  -145,   101,  -145,    14,    88,  -145,    28,  -144,
     154,  -145,  -145,   107,  -145,  -145,  -145,  -145,   -57,  -145,
     163,  -145,  -145,  -145,   158,  -145
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    43,    44,    45,   117,   118,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    61,    62,    63,   105,    28,
     106,   143,    77,    78,    29,    30,    31,   113,    56,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,     7,
       8,     9,    10,    14,    15,    11
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      55,   102,     6,    24,    18,   156,    19,    86,    22,     6,
      19,    12,   151,    58,   152,    81,   164,    27,    59,    96,
      97,   166,    60,    75,    13,    24,    64,    32,    33,    34,
      35,    36,    20,    21,    37,    76,    57,    79,    25,    38,
      39,    40,    41,    42,    90,    91,   138,   122,   123,   124,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     116,    87,   119,    80,   121,    88,    89,    99,   100,    64,
      85,    58,     1,     2,     3,     4,    59,   101,   136,     5,
      60,    98,   139,    24,   103,    32,    33,    34,    35,    36,
     104,   155,    37,    92,    93,    94,    95,    38,    39,    40,
      41,    42,   163,   109,    16,   126,   127,   125,     1,     2,
       3,     4,    82,   110,    83,     5,    84,   111,   -89,   112,
      55,   132,   133,   115,   153,    32,    33,    34,    35,    36,
     120,   137,    37,   128,   129,   130,   131,    38,    39,    40,
      41,    42,     1,     2,     3,     4,   140,   142,   141,     5,
     144,   145,   147,   146,   149,   148,   159,   157,   160,   161,
     162,   135,   165,   134,   154,   107,   158,   114,    26,   150,
      17,    23,     0,     0,   108
};

static const yytype_int16 yycheck[] =
{
      21,    58,     0,    15,    22,   149,    24,    47,    17,     7,
      24,    17,    22,     3,    24,    37,   160,    18,     8,    42,
      43,   165,    12,    23,    30,    15,    24,    17,    18,    19,
      20,    21,    50,    51,    24,    30,    50,    52,    50,    29,
      30,    31,    32,    33,    31,    32,   103,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
      82,    30,    83,    25,    85,    34,    35,    47,    48,    67,
      51,     3,     4,     5,     6,     7,     8,    50,   100,    11,
      12,    46,   104,    15,    24,    17,    18,    19,    20,    21,
      24,   148,    24,    38,    39,    40,    41,    29,    30,    31,
      32,    33,   159,    16,     0,    90,    91,   147,     4,     5,
       6,     7,    22,    50,    24,    11,    26,    50,    50,    17,
     141,    96,    97,    25,   145,    17,    18,    19,    20,    21,
      17,    50,    24,    92,    93,    94,    95,    29,    30,    31,
      32,    33,     4,     5,     6,     7,    50,    17,    51,    11,
      23,    52,    49,    25,    25,    50,    50,    18,    14,    23,
      25,    99,    25,    98,   147,    64,   152,    79,    14,   141,
       7,    13,    -1,    -1,    67
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,     5,     6,     7,    11,    73,    93,    94,    95,
      96,    99,    17,    30,    97,    98,     0,    94,    22,    24,
      50,    51,    17,    98,    15,    50,    84,    18,    73,    78,
      79,    80,    17,    18,    19,    20,    21,    24,    29,    30,
      31,    32,    33,    55,    56,    57,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    82,    50,     3,     8,
      12,    69,    70,    71,    73,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    23,    30,    76,    77,    52,
      25,    70,    22,    24,    26,    51,    60,    30,    34,    35,
      31,    32,    38,    39,    40,    41,    42,    43,    46,    47,
      48,    50,    92,    24,    24,    72,    74,    77,    87,    16,
      50,    50,    17,    81,    80,    25,    70,    58,    59,    69,
      17,    69,    60,    60,    60,    60,    62,    62,    63,    63,
      63,    63,    64,    64,    65,    66,    70,    50,    92,    70,
      50,    51,    17,    75,    23,    52,    25,    49,    50,    25,
      82,    22,    24,    69,    68,    92,    83,    18,    79,    50,
      14,    23,    25,    92,    83,    25,    83
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    54,    55,    55,    55,    55,    56,    56,    56,    57,
      57,    57,    57,    58,    58,    59,    59,    60,    60,    61,
      61,    61,    61,    61,    62,    62,    62,    62,    63,    63,
      63,    64,    64,    64,    64,    64,    65,    65,    65,    66,
      66,    67,    67,    68,    68,    69,    69,    70,    71,    72,
      72,    73,    73,    73,    73,    73,    74,    75,    75,    75,
      76,    77,    77,    78,    78,    79,    79,    80,    81,    81,
      82,    83,    83,    83,    83,    83,    84,    85,    85,    86,
      86,    87,    87,    88,    89,    89,    90,    91,    92,    92,
      93,    93,    94,    94,    94,    95,    95,    95,    95,    96,
      97,    97,    98,    99
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     1,     1,     1,
       4,     4,     3,     1,     3,     1,     0,     1,     2,     1,
       1,     1,     1,     1,     1,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     1,     3,     1,     5,     1,     3,     1,     3,     1,
       3,     1,     1,     1,     1,     1,     2,     1,     4,     4,
       1,     1,     0,     1,     3,     1,     0,     3,     1,     0,
       1,     1,     1,     1,     1,     1,     3,     1,     2,     1,
       0,     1,     1,     2,     5,     7,     9,     3,     1,     0,
       1,     2,     1,     1,     1,     3,     6,     4,     5,     3,
       1,     2,     4,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* primary_expression: IDENTIFIER  */
#line 52 "a7_220101002.y"
                 {output<<"Line No: "<<lineNum<<" Reduction: primary_expression -> IDENTIFIER\n";}
#line 1451 "y.tab.c"
    break;

  case 3: /* primary_expression: CONSTANT  */
#line 53 "a7_220101002.y"
               {output<<"Line No: "<<lineNum<<" Reduction: primary_expression -> CONSTANT\n";}
#line 1457 "y.tab.c"
    break;

  case 4: /* primary_expression: STRING  */
#line 54 "a7_220101002.y"
              {output<<"Line No: "<<lineNum<<" Reduction: primary_expression -> STRING\n";}
#line 1463 "y.tab.c"
    break;

  case 5: /* primary_expression: LPAREN expression RPAREN  */
#line 55 "a7_220101002.y"
                               {output<<"Line No: "<<lineNum<<" Reduction: primary_expression -> ( expression )\n";}
#line 1469 "y.tab.c"
    break;

  case 6: /* CONSTANT: INTCONST  */
#line 59 "a7_220101002.y"
               {output<<"Line No: "<<lineNum<<" Reduction: CONSTANT -> INTCONST\n";}
#line 1475 "y.tab.c"
    break;

  case 7: /* CONSTANT: FLOATCONST  */
#line 60 "a7_220101002.y"
                {output<<"Line No: "<<lineNum<<" Reduction: CONSTANT -> FLOATCONST\n";}
#line 1481 "y.tab.c"
    break;

  case 8: /* CONSTANT: CHARCONST  */
#line 61 "a7_220101002.y"
                {output<<"Line No: "<<lineNum<<" Reduction: CONSTANT -> CHARCONST\n";}
#line 1487 "y.tab.c"
    break;

  case 9: /* postfix_expression: primary_expression  */
#line 65 "a7_220101002.y"
                        {output<<"Line No: "<<lineNum<<" Reduction: postfix_expression -> primary_expression\n";}
#line 1493 "y.tab.c"
    break;

  case 10: /* postfix_expression: postfix_expression LBRACKET expression RBRACKET  */
#line 66 "a7_220101002.y"
                                                       {output<<"Line No: "<<lineNum<<" Reduction: postfix_expression -> postfix_expression [ expression ]\n";}
#line 1499 "y.tab.c"
    break;

  case 11: /* postfix_expression: postfix_expression LPAREN argument_expression_list_opt RPAREN  */
#line 67 "a7_220101002.y"
                                                                     {output<<"Line No: "<<lineNum<<" Reduction: postfix_expression -> postfix_expression ( argument_expression_list_opt )\n";}
#line 1505 "y.tab.c"
    break;

  case 12: /* postfix_expression: postfix_expression DEREF IDENTIFIER  */
#line 68 "a7_220101002.y"
                                           {output<<"Line No: "<<lineNum<<" Reduction: postfix_expression -> postfix_expression -> IDENTIFIER\n";}
#line 1511 "y.tab.c"
    break;

  case 13: /* argument_expression_list: assignment_expression  */
#line 72 "a7_220101002.y"
                             {output<<"Line No: "<<lineNum<<" Reduction: argument_expression_list -> assignment_expression\n";}
#line 1517 "y.tab.c"
    break;

  case 14: /* argument_expression_list: argument_expression_list COMMA assignment_expression  */
#line 73 "a7_220101002.y"
                                                            {output<<"Line No: "<<lineNum<<" Reduction: argument_expression_list -> argument_expression_list , assignment_expression\n";}
#line 1523 "y.tab.c"
    break;

  case 15: /* argument_expression_list_opt: argument_expression_list  */
#line 77 "a7_220101002.y"
                                {output<<"Line No: "<<lineNum<<" Reduction: argument_expression_list_opt -> argument_expression_list\n";}
#line 1529 "y.tab.c"
    break;

  case 16: /* argument_expression_list_opt: %empty  */
#line 78 "a7_220101002.y"
                     {output<<"Line No: "<<lineNum<<" Reduction: argument_expression_list_opt -> epsilon\n";}
#line 1535 "y.tab.c"
    break;

  case 17: /* unary_expression: postfix_expression  */
#line 82 "a7_220101002.y"
                          {output<<"Line No: "<<lineNum<<" Reduction: unary_expression -> postfix_expression\n";}
#line 1541 "y.tab.c"
    break;

  case 18: /* unary_expression: unary_operator unary_expression  */
#line 83 "a7_220101002.y"
                                       {output<<"Line No: "<<lineNum<<" Reduction: unary_expression -> unary_operator unary_expression\n";}
#line 1547 "y.tab.c"
    break;

  case 19: /* unary_operator: BITAND  */
#line 87 "a7_220101002.y"
                 {output<<"Line No: "<<lineNum<<" Reduction: unary_operator -> &\n";}
#line 1553 "y.tab.c"
    break;

  case 20: /* unary_operator: MULT  */
#line 88 "a7_220101002.y"
           {output<<"Line No: "<<lineNum<<" Reduction: unary_operator -> *\n";}
#line 1559 "y.tab.c"
    break;

  case 21: /* unary_operator: ADD  */
#line 89 "a7_220101002.y"
          {output<<"Line No: "<<lineNum<<" Reduction: unary_operator -> +\n";}
#line 1565 "y.tab.c"
    break;

  case 22: /* unary_operator: SUB  */
#line 90 "a7_220101002.y"
         {output<<"Line No: "<<lineNum<<" Reduction: unary_operator -> -\n";}
#line 1571 "y.tab.c"
    break;

  case 23: /* unary_operator: LOGICALNOT  */
#line 91 "a7_220101002.y"
                 {output<<"Line No: "<<lineNum<<" Reduction: unary_operator -> !\n";}
#line 1577 "y.tab.c"
    break;

  case 24: /* multiplicative_expression: unary_expression  */
#line 95 "a7_220101002.y"
                        {output<<"Line No: "<<lineNum<<" Reduction: multiplicative_expression -> unary_expression\n";}
#line 1583 "y.tab.c"
    break;

  case 25: /* multiplicative_expression: multiplicative_expression MULT unary_expression  */
#line 96 "a7_220101002.y"
                                                       {output<<"Line No: "<<lineNum<<" Reduction: multiplicative_expression -> multiplicative_expression * unary_expression\n";}
#line 1589 "y.tab.c"
    break;

  case 26: /* multiplicative_expression: multiplicative_expression DIV unary_expression  */
#line 97 "a7_220101002.y"
                                                      {output<<"Line No: "<<lineNum<<" Reduction: multiplicative_expression -> multiplicative_expression / unary_expression\n";}
#line 1595 "y.tab.c"
    break;

  case 27: /* multiplicative_expression: multiplicative_expression MOD unary_expression  */
#line 98 "a7_220101002.y"
                                                      {output<<"Line No: "<<lineNum<<" Reduction: multiplicative_expression -> multiplicative_expression % unary_expression\n";}
#line 1601 "y.tab.c"
    break;

  case 28: /* additive_expression: multiplicative_expression  */
#line 102 "a7_220101002.y"
                                 {output<<"Line No: "<<lineNum<<" Reduction: additive_expression -> multiplicative_expression\n";}
#line 1607 "y.tab.c"
    break;

  case 29: /* additive_expression: additive_expression ADD multiplicative_expression  */
#line 103 "a7_220101002.y"
                                                         {output<<"Line No: "<<lineNum<<" Reduction: additive_expression -> additive_expression + multiplicative_expression\n";}
#line 1613 "y.tab.c"
    break;

  case 30: /* additive_expression: additive_expression SUB multiplicative_expression  */
#line 104 "a7_220101002.y"
                                                         {output<<"Line No: "<<lineNum<<" Reduction: additive_expression -> additive_expression - multiplicative_expression\n";}
#line 1619 "y.tab.c"
    break;

  case 31: /* relational_expression: additive_expression  */
#line 108 "a7_220101002.y"
                           {output<<"Line No: "<<lineNum<<" Reduction: relational_expression -> additive_expression\n";}
#line 1625 "y.tab.c"
    break;

  case 32: /* relational_expression: relational_expression LESS additive_expression  */
#line 109 "a7_220101002.y"
                                                      {output<<"Line No: "<<lineNum<<" Reduction: relational_expression -> relational_expression < additive_expression\n";}
#line 1631 "y.tab.c"
    break;

  case 33: /* relational_expression: relational_expression GREATER additive_expression  */
#line 110 "a7_220101002.y"
                                                         {output<<"Line No: "<<lineNum<<" Reduction: relational_expression -> relational_expression > additive_expression\n";}
#line 1637 "y.tab.c"
    break;

  case 34: /* relational_expression: relational_expression LESSEQUAL additive_expression  */
#line 111 "a7_220101002.y"
                                                           {output<<"Line No: "<<lineNum<<" Reduction: relational_expression -> relational_expression <= additive_expression\n";}
#line 1643 "y.tab.c"
    break;

  case 35: /* relational_expression: relational_expression GREATEREQUAL additive_expression  */
#line 112 "a7_220101002.y"
                                                              {output<<"Line No: "<<lineNum<<" Reduction: relational_expression -> relational_expression >= additive_expression\n";}
#line 1649 "y.tab.c"
    break;

  case 36: /* equality_expression: relational_expression  */
#line 116 "a7_220101002.y"
                             {output<<"Line No: "<<lineNum<<" Reduction: equality_expression -> relational_expression\n";}
#line 1655 "y.tab.c"
    break;

  case 37: /* equality_expression: equality_expression EQUALITY relational_expression  */
#line 117 "a7_220101002.y"
                                                          {output<<"Line No: "<<lineNum<<" Reduction: equality_expression -> equality_expression == relational_expression\n";}
#line 1661 "y.tab.c"
    break;

  case 38: /* equality_expression: equality_expression NOTEQUAL relational_expression  */
#line 118 "a7_220101002.y"
                                                          {output<<"Line No: "<<lineNum<<" Reduction: equality_expression -> equality_expression != relational_expression\n";}
#line 1667 "y.tab.c"
    break;

  case 39: /* logical_AND_expression: equality_expression  */
#line 122 "a7_220101002.y"
                           {output<<"Line No: "<<lineNum<<" Reduction: logical_AND_expression -> equality_expression\n";}
#line 1673 "y.tab.c"
    break;

  case 40: /* logical_AND_expression: logical_AND_expression LOGICALAND equality_expression  */
#line 123 "a7_220101002.y"
                                                             {output<<"Line No: "<<lineNum<<" Reduction: logical_AND_expression -> logical_AND_expression && equality_expression\n";}
#line 1679 "y.tab.c"
    break;

  case 41: /* logical_OR_expression: logical_AND_expression  */
#line 127 "a7_220101002.y"
                              {output<<"Line No: "<<lineNum<<" Reduction: logical_OR_expression -> logical_AND_expression\n";}
#line 1685 "y.tab.c"
    break;

  case 42: /* logical_OR_expression: logical_OR_expression LOGICALOR logical_AND_expression  */
#line 128 "a7_220101002.y"
                                                              {output<<"Line No: "<<lineNum<<" Reduction: logical_OR_expression -> logical_OR_expression || logical_AND_expression\n";}
#line 1691 "y.tab.c"
    break;

  case 43: /* conditional_expression: logical_OR_expression  */
#line 132 "a7_220101002.y"
                             {output<<"Line No: "<<lineNum<<" Reduction: conditional_expression -> logical_OR_expression\n";}
#line 1697 "y.tab.c"
    break;

  case 44: /* conditional_expression: logical_OR_expression QUESTION expression COLON conditional_expression  */
#line 133 "a7_220101002.y"
                                                                              {output<<"Line No: "<<lineNum<<" Reduction: conditional_expression -> logical_OR_expression ? expression : conditional_expression\n";}
#line 1703 "y.tab.c"
    break;

  case 45: /* assignment_expression: conditional_expression  */
#line 137 "a7_220101002.y"
                              {output<<"Line No: "<<lineNum<<" Reduction: assignment_expression -> conditional_expression\n";}
#line 1709 "y.tab.c"
    break;

  case 46: /* assignment_expression: unary_expression ASSIGN assignment_expression  */
#line 138 "a7_220101002.y"
                                                     {output<<"Line No: "<<lineNum<<" Reduction: assignment_expression -> unary_expression = assignment_expression\n";}
#line 1715 "y.tab.c"
    break;

  case 47: /* expression: assignment_expression  */
#line 142 "a7_220101002.y"
                             {output<<"Line No: "<<lineNum<<" Reduction: expression -> assignment_expression\n";}
#line 1721 "y.tab.c"
    break;

  case 48: /* declaration: type_specifier init_declarator SEMICOLON  */
#line 147 "a7_220101002.y"
                                                {output<<"Line No: "<<lineNum<<" Reduction: declaration -> type_specifier init_declarator ;\n";}
#line 1727 "y.tab.c"
    break;

  case 49: /* init_declarator: declarator  */
#line 151 "a7_220101002.y"
                  {output<<"Line No: "<<lineNum<<" Reduction: init_declarator -> declarator\n";}
#line 1733 "y.tab.c"
    break;

  case 50: /* init_declarator: declarator ASSIGN initializer  */
#line 152 "a7_220101002.y"
                                     {output<<"Line No: "<<lineNum<<" Reduction: init_declarator -> declarator = initializer\n";}
#line 1739 "y.tab.c"
    break;

  case 51: /* type_specifier: VOID  */
#line 156 "a7_220101002.y"
           {output<<"Line No: "<<lineNum<<" Reduction: type_specifier -> VOID\n";}
#line 1745 "y.tab.c"
    break;

  case 52: /* type_specifier: CHAR  */
#line 157 "a7_220101002.y"
           {output<<"Line No: "<<lineNum<<" Reduction: type_specifier -> CHAR\n";}
#line 1751 "y.tab.c"
    break;

  case 53: /* type_specifier: INTEGER  */
#line 158 "a7_220101002.y"
                 {output<<"Line No: "<<lineNum<<" Reduction: type_specifier -> INTEGER\n";}
#line 1757 "y.tab.c"
    break;

  case 54: /* type_specifier: FLOAT  */
#line 159 "a7_220101002.y"
           {output<<"Line No: "<<lineNum<<" Reduction: type_specifier -> FLOAT\n";}
#line 1763 "y.tab.c"
    break;

  case 55: /* type_specifier: BOOL  */
#line 160 "a7_220101002.y"
           {output<<"Line No: "<<lineNum<<" Reduction: type_specifier -> BOOL\n";}
#line 1769 "y.tab.c"
    break;

  case 56: /* declarator: pointer_opt direct_declarator  */
#line 164 "a7_220101002.y"
                                     {output<<"Line No: "<<lineNum<<" Reduction: declarator -> pointer_opt direct_declarator\n";}
#line 1775 "y.tab.c"
    break;

  case 57: /* direct_declarator: IDENTIFIER  */
#line 168 "a7_220101002.y"
                  {output<<"Line No: "<<lineNum<<" Reduction: direct_declarator -> IDENTIFIER\n";}
#line 1781 "y.tab.c"
    break;

  case 58: /* direct_declarator: IDENTIFIER LBRACKET INTCONST RBRACKET  */
#line 169 "a7_220101002.y"
                                             {output<<"Line No: "<<lineNum<<" Reduction: direct_declarator -> IDENTIFIER [ INTCONST ]\n";}
#line 1787 "y.tab.c"
    break;

  case 59: /* direct_declarator: IDENTIFIER LPAREN parameter_list_opt RPAREN  */
#line 170 "a7_220101002.y"
                                                   {output<<"Line No: "<<lineNum<<" Reduction: direct_declarator -> IDENTIFIER ( parameter_list_opt )\n";}
#line 1793 "y.tab.c"
    break;

  case 60: /* pointer: MULT  */
#line 174 "a7_220101002.y"
            {output<<"Line No: "<<lineNum<<" Reduction: pointer -> *\n";}
#line 1799 "y.tab.c"
    break;

  case 61: /* pointer_opt: pointer  */
#line 178 "a7_220101002.y"
               {output<<"Line No: "<<lineNum<<" Reduction: pointer_opt -> pointer\n";}
#line 1805 "y.tab.c"
    break;

  case 62: /* pointer_opt: %empty  */
#line 179 "a7_220101002.y"
                     {output<<"Line No: "<<lineNum<<" Reduction: pointer_opt -> epsilon\n";}
#line 1811 "y.tab.c"
    break;

  case 63: /* parameter_list: parameter_declaration  */
#line 183 "a7_220101002.y"
                             {output<<"Line No: "<<lineNum<<" Reduction: parameter_list -> parameter_declaration\n";}
#line 1817 "y.tab.c"
    break;

  case 64: /* parameter_list: parameter_list COMMA parameter_declaration  */
#line 184 "a7_220101002.y"
                                                  {output<<"Line No: "<<lineNum<<" Reduction: parameter_list -> parameter_list , parameter_declaration\n";}
#line 1823 "y.tab.c"
    break;

  case 65: /* parameter_list_opt: parameter_list  */
#line 188 "a7_220101002.y"
                      {output<<"Line No: "<<lineNum<<" Reduction: parameter_list_opt -> parameter_list\n";}
#line 1829 "y.tab.c"
    break;

  case 66: /* parameter_list_opt: %empty  */
#line 189 "a7_220101002.y"
                     {output<<"Line No: "<<lineNum<<" Reduction: parameter_list_opt -> epsilon\n";}
#line 1835 "y.tab.c"
    break;

  case 67: /* parameter_declaration: type_specifier pointer_opt identifier_opt  */
#line 193 "a7_220101002.y"
                                                 {output<<"Line No: "<<lineNum<<" Reduction: parameter_declaration -> type_specifier pointer_opt identifier_opt\n";}
#line 1841 "y.tab.c"
    break;

  case 68: /* identifier_opt: IDENTIFIER  */
#line 197 "a7_220101002.y"
                  {output<<"Line No: "<<lineNum<<" Reduction: identifier_opt -> IDENTIFIER\n";}
#line 1847 "y.tab.c"
    break;

  case 69: /* identifier_opt: %empty  */
#line 198 "a7_220101002.y"
                     {output<<"Line No: "<<lineNum<<" Reduction: identifier_opt -> epsilon\n";}
#line 1853 "y.tab.c"
    break;

  case 70: /* initializer: assignment_expression  */
#line 202 "a7_220101002.y"
                             {output<<"Line No: "<<lineNum<<" Reduction: initializer -> assignment_expression\n";}
#line 1859 "y.tab.c"
    break;

  case 71: /* statement: compound_statement  */
#line 207 "a7_220101002.y"
                          {output<<"Line No: "<<lineNum<<" Reduction: statement -> compound_statement\n";}
#line 1865 "y.tab.c"
    break;

  case 72: /* statement: expression_statement  */
#line 208 "a7_220101002.y"
                            {output<<"Line No: "<<lineNum<<" Reduction: statement -> expression_statement\n";}
#line 1871 "y.tab.c"
    break;

  case 73: /* statement: selection_statement  */
#line 209 "a7_220101002.y"
                           {output<<"Line No: "<<lineNum<<" Reduction: statement -> selection_statement\n";}
#line 1877 "y.tab.c"
    break;

  case 74: /* statement: iteration_statement  */
#line 210 "a7_220101002.y"
                           {output<<"Line No: "<<lineNum<<" Reduction: statement -> iteration_statement\n";}
#line 1883 "y.tab.c"
    break;

  case 75: /* statement: jump_statement  */
#line 211 "a7_220101002.y"
                      {output<<"Line No: "<<lineNum<<" Reduction: statement -> jump_statement\n";}
#line 1889 "y.tab.c"
    break;

  case 76: /* compound_statement: BEGINBLOCK block_item_list_opt END  */
#line 215 "a7_220101002.y"
                                          {output<<"Line No: "<<lineNum<<" Reduction: compound_statement -> begin block_item_list_opt end\n";}
#line 1895 "y.tab.c"
    break;

  case 77: /* block_item_list: block_item  */
#line 220 "a7_220101002.y"
                  {output<<"Line No: "<<lineNum<<" Reduction: block_item_list -> block_item\n";}
#line 1901 "y.tab.c"
    break;

  case 78: /* block_item_list: block_item_list block_item  */
#line 221 "a7_220101002.y"
                                  {output<<"Line No: "<<lineNum<<" Reduction: block_item_list -> block_item_list block_item\n";}
#line 1907 "y.tab.c"
    break;

  case 79: /* block_item_list_opt: block_item_list  */
#line 225 "a7_220101002.y"
                       {output<<"Line No: "<<lineNum<<" Reduction: block_item_list_opt -> block_item_list\n";}
#line 1913 "y.tab.c"
    break;

  case 80: /* block_item_list_opt: %empty  */
#line 226 "a7_220101002.y"
                     {output<<"Line No: "<<lineNum<<" Reduction: block_item_list_opt -> epsilon\n";}
#line 1919 "y.tab.c"
    break;

  case 81: /* block_item: declaration  */
#line 230 "a7_220101002.y"
                   {output<<"Line No: "<<lineNum<<" Reduction: block_item -> declaration\n";}
#line 1925 "y.tab.c"
    break;

  case 82: /* block_item: statement  */
#line 231 "a7_220101002.y"
                 {output<<"Line No: "<<lineNum<<" Reduction: block_item -> statement\n";}
#line 1931 "y.tab.c"
    break;

  case 83: /* expression_statement: expression_opt SEMICOLON  */
#line 235 "a7_220101002.y"
                                {output<<"Line No: "<<lineNum<<" Reduction: expression_statement -> expression_opt ;\n";}
#line 1937 "y.tab.c"
    break;

  case 84: /* selection_statement: IF LPAREN expression RPAREN statement  */
#line 239 "a7_220101002.y"
                                                                   {output<<"Line No: "<<lineNum<<" Reduction: selection_statement -> if ( expression ) statement\n";}
#line 1943 "y.tab.c"
    break;

  case 85: /* selection_statement: IF LPAREN expression RPAREN statement ELSE statement  */
#line 240 "a7_220101002.y"
                                                            {output<<"Line No: "<<lineNum<<" Reduction: selection_statement -> if ( expression ) statement else statement\n";}
#line 1949 "y.tab.c"
    break;

  case 86: /* iteration_statement: FOR LPAREN expression_opt SEMICOLON expression_opt SEMICOLON expression_opt RPAREN statement  */
#line 244 "a7_220101002.y"
                                                                                                    {output<<"Line No: "<<lineNum<<" Reduction: iteration_statement -> for ( expression_opt ; expression_opt ; expression_opt ) statement\n";}
#line 1955 "y.tab.c"
    break;

  case 87: /* jump_statement: RETURN expression_opt SEMICOLON  */
#line 248 "a7_220101002.y"
                                       {output<<"Line No: "<<lineNum<<" Reduction: jump_statement -> RETURN expression_opt ;\n";}
#line 1961 "y.tab.c"
    break;

  case 88: /* expression_opt: expression  */
#line 252 "a7_220101002.y"
                  {output<<"Line No: "<<lineNum<<" Reduction: expression_opt -> expression\n";}
#line 1967 "y.tab.c"
    break;

  case 89: /* expression_opt: %empty  */
#line 253 "a7_220101002.y"
                     {output<<"Line No: "<<lineNum<<" Reduction: expression_opt -> epsilon\n";}
#line 1973 "y.tab.c"
    break;

  case 90: /* translation_unit: external_declaration  */
#line 259 "a7_220101002.y"
                            {output<<"Line No: "<<lineNum<<" Reduction: translation_unit -> external_declaration\n";}
#line 1979 "y.tab.c"
    break;

  case 91: /* translation_unit: translation_unit external_declaration  */
#line 260 "a7_220101002.y"
                                             {output<<"Line No: "<<lineNum<<" Reduction: translation_unit -> translation_unit external_declaration\n";}
#line 1985 "y.tab.c"
    break;

  case 92: /* external_declaration: function_definition  */
#line 264 "a7_220101002.y"
                           {output<<"Line No: "<<lineNum<<" Reduction: external_declaration -> function_definition\n";}
#line 1991 "y.tab.c"
    break;

  case 93: /* external_declaration: function_declaration  */
#line 265 "a7_220101002.y"
                            {output<<"Line No: "<<lineNum<<" Reduction: external_declaration -> function_declaration\n";}
#line 1997 "y.tab.c"
    break;

  case 94: /* external_declaration: variable_declaration  */
#line 266 "a7_220101002.y"
                            {output<<"Line No: "<<lineNum<<" Reduction: external_declaration -> variable_declaration\n";}
#line 2003 "y.tab.c"
    break;

  case 95: /* variable_declaration: type_specifier IDENTIFIER SEMICOLON  */
#line 270 "a7_220101002.y"
                                           {output<<"Line No: "<<lineNum<<" Reduction: variable_declaration -> type_specifier IDENTIFIER ;\n";}
#line 2009 "y.tab.c"
    break;

  case 96: /* variable_declaration: type_specifier IDENTIFIER LBRACKET INTCONST RBRACKET SEMICOLON  */
#line 271 "a7_220101002.y"
                                                                      {output<<"Line No: "<<lineNum<<" Reduction: variable_declaration -> type_specifier IDENTIFIER [ INTCONST ] ;\n";}
#line 2015 "y.tab.c"
    break;

  case 97: /* variable_declaration: type_specifier MULT IDENTIFIER SEMICOLON  */
#line 272 "a7_220101002.y"
                                                {output<<"Line No: "<<lineNum<<" Reduction: variable_declaration -> type_specifier * IDENTIFIER ;\n";}
#line 2021 "y.tab.c"
    break;

  case 98: /* variable_declaration: type_specifier IDENTIFIER ASSIGN initializer SEMICOLON  */
#line 273 "a7_220101002.y"
                                                              {output<<"Line No: "<<lineNum<<" Reduction: variable_declaration -> type_specifier IDENTIFIER = initializer ;\n";}
#line 2027 "y.tab.c"
    break;

  case 99: /* function_declaration: type_specifier function_declarator SEMICOLON  */
#line 277 "a7_220101002.y"
                                                    {output<<"Line No: "<<lineNum<<" Reduction: function_declaration -> type_specifier function_declarator ;\n";}
#line 2033 "y.tab.c"
    break;

  case 100: /* function_declarator: direct_function_declarator  */
#line 281 "a7_220101002.y"
                                  {output<<"Line No: "<<lineNum<<" Reduction: function_declarator -> direct_function_declarator\n";}
#line 2039 "y.tab.c"
    break;

  case 101: /* function_declarator: MULT direct_function_declarator  */
#line 282 "a7_220101002.y"
                                       {output<<"Line No: "<<lineNum<<" Reduction: function_declarator -> * direct_function_declarator\n";}
#line 2045 "y.tab.c"
    break;

  case 102: /* direct_function_declarator: IDENTIFIER LPAREN parameter_list_opt RPAREN  */
#line 286 "a7_220101002.y"
                                                   {output<<"Line No: "<<lineNum<<" Reduction: direct_function_declarator -> IDENTIFIER ( parameter_list_opt )\n";}
#line 2051 "y.tab.c"
    break;

  case 103: /* function_definition: type_specifier function_declarator compound_statement  */
#line 290 "a7_220101002.y"
                                                             {output<<"Line No: "<<lineNum<<" Reduction: function_definition -> type_specifier function_declarator compound_statement\n";}
#line 2057 "y.tab.c"
    break;


#line 2061 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 293 "a7_220101002.y"



void yyerror(const char *s) {
    output<<"Line No: "<<lineNum<<" Error at line "<<lineNum<<" : "<<s<< endl;
}

int main() {
    output.open("output.txt");
    
    int result = yyparse();
    
    if (result == 0) {
        print_symbol_table();
        cout<<"Parsing completed successfully!\n";
    }

    output.close();
    return result;
}

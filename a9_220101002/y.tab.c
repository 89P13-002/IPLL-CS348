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
#line 1 "a9_220101002.y"

    #include<bits/stdc++.h>
    #include "a9_220101002_handle.h"
    using namespace std;

    extern int yylex();
    extern char* yytext;
    extern int yylineno;
    void yyerror(string s);

    extern int nxtinst;
    extern QuadArr qlst;
    extern SymTable gsymtab;
    extern SymTable* symtab;

    int strcnt = 0;

#line 89 "y.tab.c"

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

#line 212 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
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
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_INTCONST = 4,                   /* INTCONST  */
  YYSYMBOL_FLOATCONST = 5,                 /* FLOATCONST  */
  YYSYMBOL_STRING = 6,                     /* STRING  */
  YYSYMBOL_CHARCONST = 7,                  /* CHARCONST  */
  YYSYMBOL_RETURN = 8,                     /* RETURN  */
  YYSYMBOL_VOID = 9,                       /* VOID  */
  YYSYMBOL_BOOL = 10,                      /* BOOL  */
  YYSYMBOL_FLOAT = 11,                     /* FLOAT  */
  YYSYMBOL_INTEGER = 12,                   /* INTEGER  */
  YYSYMBOL_CHAR = 13,                      /* CHAR  */
  YYSYMBOL_CONST = 14,                     /* CONST  */
  YYSYMBOL_DO = 15,                        /* DO  */
  YYSYMBOL_WHILE = 16,                     /* WHILE  */
  YYSYMBOL_IF = 17,                        /* IF  */
  YYSYMBOL_ELSE = 18,                      /* ELSE  */
  YYSYMBOL_FOR = 19,                       /* FOR  */
  YYSYMBOL_GOTO = 20,                      /* GOTO  */
  YYSYMBOL_BREAK = 21,                     /* BREAK  */
  YYSYMBOL_LSQRBRC = 22,                   /* LSQRBRC  */
  YYSYMBOL_RSQRBRC = 23,                   /* RSQRBRC  */
  YYSYMBOL_LPAREN = 24,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 25,                    /* RPAREN  */
  YYSYMBOL_BLOCKBEGIN = 26,                /* BLOCKBEGIN  */
  YYSYMBOL_BLOCKEND = 27,                  /* BLOCKEND  */
  YYSYMBOL_DEREF = 28,                     /* DEREF  */
  YYSYMBOL_INCR = 29,                      /* INCR  */
  YYSYMBOL_DECR = 30,                      /* DECR  */
  YYSYMBOL_LOGICALAND = 31,                /* LOGICALAND  */
  YYSYMBOL_LOGICALOR = 32,                 /* LOGICALOR  */
  YYSYMBOL_BITAND = 33,                    /* BITAND  */
  YYSYMBOL_BITXOR = 34,                    /* BITXOR  */
  YYSYMBOL_BITOR = 35,                     /* BITOR  */
  YYSYMBOL_LOGICALNOT = 36,                /* LOGICALNOT  */
  YYSYMBOL_COMPLEMENT = 37,                /* COMPLEMENT  */
  YYSYMBOL_QUESTION = 38,                  /* QUESTION  */
  YYSYMBOL_COLON = 39,                     /* COLON  */
  YYSYMBOL_MULT = 40,                      /* MULT  */
  YYSYMBOL_ADD = 41,                       /* ADD  */
  YYSYMBOL_SUB = 42,                       /* SUB  */
  YYSYMBOL_DIV = 43,                       /* DIV  */
  YYSYMBOL_MOD = 44,                       /* MOD  */
  YYSYMBOL_LSHIFT = 45,                    /* LSHIFT  */
  YYSYMBOL_RSHIFT = 46,                    /* RSHIFT  */
  YYSYMBOL_LESSEQUAL = 47,                 /* LESSEQUAL  */
  YYSYMBOL_GREATEREQUAL = 48,              /* GREATEREQUAL  */
  YYSYMBOL_EQUALITY = 49,                  /* EQUALITY  */
  YYSYMBOL_LESS = 50,                      /* LESS  */
  YYSYMBOL_GREATER = 51,                   /* GREATER  */
  YYSYMBOL_NOTEQUAL = 52,                  /* NOTEQUAL  */
  YYSYMBOL_ASSIGN = 53,                    /* ASSIGN  */
  YYSYMBOL_SEMICOLON = 54,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 55,                     /* COMMA  */
  YYSYMBOL_YYACCEPT = 56,                  /* $accept  */
  YYSYMBOL_M = 57,                         /* M  */
  YYSYMBOL_N = 58,                         /* N  */
  YYSYMBOL_primary_expression = 59,        /* primary_expression  */
  YYSYMBOL_postfix_expression = 60,        /* postfix_expression  */
  YYSYMBOL_argument_expression_list = 61,  /* argument_expression_list  */
  YYSYMBOL_unary_expression = 62,          /* unary_expression  */
  YYSYMBOL_unary_operator = 63,            /* unary_operator  */
  YYSYMBOL_multiplicative_expression = 64, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 65,       /* additive_expression  */
  YYSYMBOL_shift_expression = 66,          /* shift_expression  */
  YYSYMBOL_relational_expression = 67,     /* relational_expression  */
  YYSYMBOL_equality_expression = 68,       /* equality_expression  */
  YYSYMBOL_AND_expression = 69,            /* AND_expression  */
  YYSYMBOL_XOR_expression = 70,            /* XOR_expression  */
  YYSYMBOL_OR_expression = 71,             /* OR_expression  */
  YYSYMBOL_logical_and_expression = 72,    /* logical_and_expression  */
  YYSYMBOL_logical_or_expression = 73,     /* logical_or_expression  */
  YYSYMBOL_conditional_expression = 74,    /* conditional_expression  */
  YYSYMBOL_assignment_expression = 75,     /* assignment_expression  */
  YYSYMBOL_expression = 76,                /* expression  */
  YYSYMBOL_declaration = 77,               /* declaration  */
  YYSYMBOL_init_declarator_list = 78,      /* init_declarator_list  */
  YYSYMBOL_init_declarator = 79,           /* init_declarator  */
  YYSYMBOL_type_specifier = 80,            /* type_specifier  */
  YYSYMBOL_declarator = 81,                /* declarator  */
  YYSYMBOL_direct_declarator = 82,         /* direct_declarator  */
  YYSYMBOL_pointer = 83,                   /* pointer  */
  YYSYMBOL_parameter_list = 84,            /* parameter_list  */
  YYSYMBOL_parameter_type_list_opt = 85,   /* parameter_type_list_opt  */
  YYSYMBOL_parameter_declaration = 86,     /* parameter_declaration  */
  YYSYMBOL_initializer = 87,               /* initializer  */
  YYSYMBOL_statement = 88,                 /* statement  */
  YYSYMBOL_compound_statement = 89,        /* compound_statement  */
  YYSYMBOL_block_item_list = 90,           /* block_item_list  */
  YYSYMBOL_block_item = 91,                /* block_item  */
  YYSYMBOL_expression_statement = 92,      /* expression_statement  */
  YYSYMBOL_selection_statement = 93,       /* selection_statement  */
  YYSYMBOL_iteration_statement = 94,       /* iteration_statement  */
  YYSYMBOL_jump_statement = 95,            /* jump_statement  */
  YYSYMBOL_translation_unit = 96,          /* translation_unit  */
  YYSYMBOL_external_declaration = 97,      /* external_declaration  */
  YYSYMBOL_function_definition = 98,       /* function_definition  */
  YYSYMBOL_function_prototype = 99,        /* function_prototype  */
  YYSYMBOL_declaration_list = 100          /* declaration_list  */
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
#define YYFINAL  19
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   436

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  114
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  210

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   310


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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   105,   105,   111,   119,   126,   136,   145,   155,   159,
     165,   168,   182,   202,   208,   214,   222,   233,   236,   296,
     299,   302,   305,   308,   311,   314,   317,   323,   344,   368,
     392,   418,   421,   446,   473,   476,   506,   539,   542,   571,
     600,   628,   659,   662,   692,   724,   727,   760,   763,   796,
     799,   832,   835,   845,   848,   858,   861,   887,   890,   908,
     914,   979,   983,   990,   994,  1001,  1004,  1007,  1010,  1016,
    1020,  1027,  1031,  1034,  1040,  1047,  1080,  1086,  1090,  1097,
    1100,  1106,  1121,  1128,  1134,  1137,  1140,  1143,  1146,  1152,
    1155,  1161,  1165,  1173,  1176,  1182,  1185,  1191,  1200,  1214,
    1225,  1232,  1244,  1250,  1256,  1261,  1271,  1274,  1280,  1283,
    1289,  1292,  1299,  1321,  1324
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
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER",
  "INTCONST", "FLOATCONST", "STRING", "CHARCONST", "RETURN", "VOID",
  "BOOL", "FLOAT", "INTEGER", "CHAR", "CONST", "DO", "WHILE", "IF", "ELSE",
  "FOR", "GOTO", "BREAK", "LSQRBRC", "RSQRBRC", "LPAREN", "RPAREN",
  "BLOCKBEGIN", "BLOCKEND", "DEREF", "INCR", "DECR", "LOGICALAND",
  "LOGICALOR", "BITAND", "BITXOR", "BITOR", "LOGICALNOT", "COMPLEMENT",
  "QUESTION", "COLON", "MULT", "ADD", "SUB", "DIV", "MOD", "LSHIFT",
  "RSHIFT", "LESSEQUAL", "GREATEREQUAL", "EQUALITY", "LESS", "GREATER",
  "NOTEQUAL", "ASSIGN", "SEMICOLON", "COMMA", "$accept", "M", "N",
  "primary_expression", "postfix_expression", "argument_expression_list",
  "unary_expression", "unary_operator", "multiplicative_expression",
  "additive_expression", "shift_expression", "relational_expression",
  "equality_expression", "AND_expression", "XOR_expression",
  "OR_expression", "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "expression",
  "declaration", "init_declarator_list", "init_declarator",
  "type_specifier", "declarator", "direct_declarator", "pointer",
  "parameter_list", "parameter_type_list_opt", "parameter_declaration",
  "initializer", "statement", "compound_statement", "block_item_list",
  "block_item", "expression_statement", "selection_statement",
  "iteration_statement", "jump_statement", "translation_unit",
  "external_declaration", "function_definition", "function_prototype",
  "declaration_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-124)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-113)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      60,  -124,  -124,  -124,  -124,  -124,     9,    32,  -124,  -124,
      21,  -124,     9,  -124,     2,  -124,     5,     6,    18,  -124,
    -124,   165,  -124,    10,  -124,     9,   394,  -124,     9,    13,
     340,    60,     6,  -124,  -124,  -124,  -124,  -124,   285,  -124,
    -124,    35,    50,    58,    22,   394,  -124,  -124,  -124,  -124,
    -124,  -124,  -124,  -124,  -124,  -124,  -124,    24,    28,   394,
      11,    37,    48,    40,   -12,    51,    55,    65,    64,    -9,
    -124,  -124,    69,  -124,  -124,  -124,    75,  -124,  -124,  -124,
    -124,  -124,  -124,  -124,    66,  -124,  -124,  -124,  -124,  -124,
     103,     9,    76,   105,  -124,  -124,    78,   245,   109,   394,
     300,    80,  -124,   110,   394,   354,   134,   394,  -124,   394,
     394,   394,   394,   394,   394,   394,   394,   394,   394,   394,
     394,   394,   394,   394,   394,  -124,  -124,   100,  -124,  -124,
     205,  -124,  -124,    60,  -124,  -124,  -124,   394,  -124,  -124,
    -124,  -124,   116,  -124,    -5,  -124,  -124,  -124,  -124,  -124,
    -124,  -124,    11,    11,    37,    37,    48,    48,    48,    48,
      40,    40,   -12,    51,    55,   394,   394,  -124,  -124,  -124,
     124,   119,   121,   300,  -124,  -124,   394,    65,    64,   394,
     123,  -124,  -124,  -124,  -124,  -124,   394,   245,   245,  -124,
     113,   128,  -124,  -124,   394,  -124,   102,   136,  -124,   394,
    -124,  -124,   132,  -124,   245,  -124,  -124,   245,  -124,  -124
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    65,    68,    67,    66,   109,     0,     0,   106,   108,
       0,    71,     0,    76,     0,    61,    63,    70,     0,     1,
     107,     0,   111,     0,    60,     0,     0,   113,     0,     0,
       0,    80,    69,     4,     5,     6,     8,     7,     0,     2,
       2,     0,     0,     0,     0,     0,    89,    21,    22,    19,
      26,    25,    20,    23,    24,    96,    10,    17,    27,     0,
      31,    34,    37,    42,    45,    47,    49,    51,    53,    55,
      57,    59,     0,    93,    94,    84,     2,    91,    85,    86,
      87,    88,    72,    62,    63,    83,    64,   114,   110,    73,
       0,    82,    79,     0,    77,   102,     0,     0,     0,     0,
       0,     0,   104,     0,     0,     0,     0,     0,    18,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     2,     2,     0,    95,    90,
       0,    74,    81,     0,    75,   103,     2,     0,     3,     2,
     105,     9,     0,    13,     0,    15,    14,    58,    28,    29,
      30,    27,    32,    33,    35,    36,    40,    41,    38,    39,
      43,    44,    46,    48,    50,     0,     0,     2,    92,    78,
       0,     0,     0,     0,    11,    12,     0,    52,    54,     0,
       0,     2,     2,     3,    16,     3,     0,     0,     0,     2,
       0,     0,   101,     3,     0,     2,     0,    97,     3,     0,
     100,     2,     0,    56,     0,     2,     3,     0,    98,    99
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -124,   -40,  -123,  -124,  -124,  -124,    -6,  -124,   -15,     7,
     -52,     4,    41,    39,    42,    -1,    17,  -124,   -32,   -25,
     -36,   -10,  -124,   150,     3,     1,   161,  -124,  -124,  -124,
      54,  -124,   -59,    -2,  -124,    67,   -96,  -124,  -124,  -124,
    -124,   181,  -124,  -124,  -124
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    97,   127,    56,    57,   144,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,     5,    14,    15,    28,    84,    17,    18,    92,    93,
      94,    86,    74,    75,    76,    77,    78,    79,    80,    81,
       7,     8,     9,    10,    29
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      98,    85,    96,     6,   139,    90,    27,    16,    22,   103,
       6,    73,    11,    23,     1,   172,     2,     3,     4,    87,
     175,    11,     1,   126,     2,     3,     4,    88,    30,    -3,
      31,  -112,    19,    12,    91,    82,   130,   120,   136,    21,
     121,     1,    12,     2,     3,     4,   104,    21,   105,    13,
     176,   109,   106,   108,   110,   111,    24,    25,    26,    99,
     189,   101,   190,   138,   156,   157,   158,   159,   142,     1,
     197,     2,     3,     4,   100,   202,   102,   183,   112,   113,
     145,   107,   147,   208,   122,   165,   166,   116,   117,   123,
     118,   119,   132,   114,   115,   125,   170,   152,   153,   173,
     124,   171,   129,   148,   149,   150,   151,   151,   151,   151,
     151,   151,   151,   151,   151,   151,   151,   151,   151,    26,
      73,   154,   155,   128,   160,   161,   131,   179,   192,   193,
     134,   133,   135,   137,   140,   141,    91,   146,   167,   174,
     180,   187,   188,   185,   181,   206,   182,   186,   209,   194,
     191,   184,   195,   196,   201,   199,   200,   205,   198,   151,
     151,   204,   163,   162,   177,   207,   164,   203,    33,    34,
      35,    36,    37,    38,     1,    83,     2,     3,     4,    32,
      39,    40,    41,   178,    42,    43,    44,   169,    20,    45,
       0,    21,    46,   151,    47,    48,     0,   168,    49,     0,
       0,    50,    51,     0,     0,    52,    53,    54,    33,    34,
      35,    36,    37,    38,     1,     0,     2,     3,     4,    55,
      39,    40,    41,     0,    42,    43,    44,     0,     0,    45,
       0,    21,     0,     0,    47,    48,     0,     0,    49,     0,
       0,    50,    51,     0,     0,    52,    53,    54,    33,    34,
      35,    36,    37,    38,     0,     0,     0,     0,     0,    55,
      39,    40,    41,     0,    42,    43,    44,     0,     0,    45,
       0,    21,     0,     0,    47,    48,     0,     0,    49,     0,
       0,    50,    51,     0,     0,    52,    53,    54,    33,    34,
      35,    36,    37,     0,     0,     0,     0,     0,     0,    55,
       0,     0,     0,    33,    34,    35,    36,    37,     0,    45,
       0,     0,     0,     0,    47,    48,     0,     0,    49,     0,
       0,    50,    51,     0,    45,    52,    53,    54,     0,    47,
      48,     0,     0,    49,     0,     0,    50,    51,     0,    95,
      52,    53,    54,    33,    34,    35,    36,    37,     0,     0,
       0,     0,     0,     0,    55,     0,     0,    33,    34,    35,
      36,    37,     0,    89,    45,     0,     0,     0,     0,    47,
      48,     0,     0,    49,     0,     0,    50,    51,    45,   143,
      52,    53,    54,    47,    48,     0,     0,    49,     0,     0,
      50,    51,     0,     0,    52,    53,    54,    33,    34,    35,
      36,    37,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    45,     0,
       0,     0,     0,    47,    48,     0,     0,    49,     0,     0,
      50,    51,     0,     0,    52,    53,    54
};

static const yytype_int16 yycheck[] =
{
      40,    26,    38,     0,   100,    30,    16,     6,    10,    45,
       7,    21,     3,    12,     9,   138,    11,    12,    13,    29,
      25,     3,     9,    32,    11,    12,    13,    29,    22,    38,
      24,    26,     0,    24,    31,    25,    76,    49,    97,    26,
      52,     9,    24,    11,    12,    13,    22,    26,    24,    40,
      55,    40,    28,    59,    43,    44,    54,    55,    53,    24,
     183,     3,   185,    99,   116,   117,   118,   119,   104,     9,
     193,    11,    12,    13,    24,   198,    54,   173,    41,    42,
     105,    53,   107,   206,    33,   125,   126,    47,    48,    34,
      50,    51,    91,    45,    46,    31,   136,   112,   113,   139,
      35,   137,    27,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,    53,
     130,   114,   115,    54,   120,   121,    23,   167,   187,   188,
      25,    55,    54,    24,    54,    25,   133,     3,    38,    23,
      16,   181,   182,   179,    25,   204,    25,    24,   207,   189,
     186,   176,    39,    25,    18,   195,    54,    25,   194,   165,
     166,   201,   123,   122,   165,   205,   124,   199,     3,     4,
       5,     6,     7,     8,     9,    25,    11,    12,    13,    18,
      15,    16,    17,   166,    19,    20,    21,   133,     7,    24,
      -1,    26,    27,   199,    29,    30,    -1,   130,    33,    -1,
      -1,    36,    37,    -1,    -1,    40,    41,    42,     3,     4,
       5,     6,     7,     8,     9,    -1,    11,    12,    13,    54,
      15,    16,    17,    -1,    19,    20,    21,    -1,    -1,    24,
      -1,    26,    -1,    -1,    29,    30,    -1,    -1,    33,    -1,
      -1,    36,    37,    -1,    -1,    40,    41,    42,     3,     4,
       5,     6,     7,     8,    -1,    -1,    -1,    -1,    -1,    54,
      15,    16,    17,    -1,    19,    20,    21,    -1,    -1,    24,
      -1,    26,    -1,    -1,    29,    30,    -1,    -1,    33,    -1,
      -1,    36,    37,    -1,    -1,    40,    41,    42,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    -1,    -1,    -1,    54,
      -1,    -1,    -1,     3,     4,     5,     6,     7,    -1,    24,
      -1,    -1,    -1,    -1,    29,    30,    -1,    -1,    33,    -1,
      -1,    36,    37,    -1,    24,    40,    41,    42,    -1,    29,
      30,    -1,    -1,    33,    -1,    -1,    36,    37,    -1,    54,
      40,    41,    42,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    -1,    -1,    -1,    54,    -1,    -1,     3,     4,     5,
       6,     7,    -1,    23,    24,    -1,    -1,    -1,    -1,    29,
      30,    -1,    -1,    33,    -1,    -1,    36,    37,    24,    25,
      40,    41,    42,    29,    30,    -1,    -1,    33,    -1,    -1,
      36,    37,    -1,    -1,    40,    41,    42,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,
      -1,    -1,    -1,    29,    30,    -1,    -1,    33,    -1,    -1,
      36,    37,    -1,    -1,    40,    41,    42
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     9,    11,    12,    13,    77,    80,    96,    97,    98,
      99,     3,    24,    40,    78,    79,    81,    82,    83,     0,
      97,    26,    89,    81,    54,    55,    53,    77,    80,   100,
      22,    24,    82,     3,     4,     5,     6,     7,     8,    15,
      16,    17,    19,    20,    21,    24,    27,    29,    30,    33,
      36,    37,    40,    41,    42,    54,    59,    60,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    88,    89,    90,    91,    92,    93,
      94,    95,    25,    79,    81,    75,    87,    77,    89,    23,
      75,    80,    84,    85,    86,    54,    76,    57,    57,    24,
      24,     3,    54,    76,    22,    24,    28,    53,    62,    40,
      43,    44,    41,    42,    45,    46,    47,    48,    50,    51,
      49,    52,    33,    34,    35,    31,    32,    58,    54,    27,
      57,    23,    81,    55,    25,    54,    88,    24,    76,    92,
      54,    25,    76,    25,    61,    75,     3,    75,    62,    62,
      62,    62,    64,    64,    65,    65,    66,    66,    66,    66,
      67,    67,    68,    69,    70,    57,    57,    38,    91,    86,
      57,    76,    58,    57,    23,    25,    55,    71,    72,    57,
      16,    25,    25,    92,    75,    76,    24,    57,    57,    58,
      58,    76,    88,    88,    57,    39,    25,    58,    76,    57,
      54,    18,    58,    74,    57,    25,    88,    57,    58,    88
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    56,    57,    58,    59,    59,    59,    59,    59,    59,
      60,    60,    60,    60,    60,    61,    61,    62,    62,    63,
      63,    63,    63,    63,    63,    63,    63,    64,    64,    64,
      64,    65,    65,    65,    66,    66,    66,    67,    67,    67,
      67,    67,    68,    68,    68,    69,    69,    70,    70,    71,
      71,    72,    72,    73,    73,    74,    74,    75,    75,    76,
      77,    78,    78,    79,    79,    80,    80,    80,    80,    81,
      81,    82,    82,    82,    82,    82,    83,    84,    84,    85,
      85,    86,    86,    87,    88,    88,    88,    88,    88,    89,
      89,    90,    90,    91,    91,    92,    92,    93,    93,    94,
      94,    94,    95,    95,    95,    95,    96,    96,    97,    97,
      98,    98,    99,   100,   100
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     0,     1,     1,     1,     1,     1,     3,
       1,     4,     4,     3,     3,     1,     3,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     1,     3,     1,
       3,     1,     4,     1,     4,     1,     9,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     1,     1,     1,     2,
       1,     1,     3,     3,     4,     4,     1,     1,     3,     1,
       0,     2,     1,     1,     1,     1,     1,     1,     1,     2,
       3,     1,     3,     1,     1,     2,     1,     8,    12,    12,
       9,     7,     2,     3,     2,     3,     1,     2,     1,     1,
       4,     2,     2,     1,     2
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
  case 2: /* M: %empty  */
#line 105 "a9_220101002.y"
                 {
        (yyval.expr) = new Expression();
        (yyval.expr)->instr = nxtinst;
    }
#line 1494 "y.tab.c"
    break;

  case 3: /* N: %empty  */
#line 111 "a9_220101002.y"
                 {
        (yyval.expr) = new Expression();     
        (yyval.expr)->nextlist = makelist(nxtinst);
        emit("","","",Goto);
    }
#line 1504 "y.tab.c"
    break;

  case 4: /* primary_expression: IDENTIFIER  */
#line 119 "a9_220101002.y"
                 {     
        (yyval.expr) = new Expression();      	
        string str = *((yyvsp[0].str));

        symtab->lookup(str);
        (yyval.expr)->loc = str;
    }
#line 1516 "y.tab.c"
    break;

  case 5: /* primary_expression: INTCONST  */
#line 126 "a9_220101002.y"
               {
        (yyval.expr) = new Expression();	       	
        (yyval.expr)->loc = symtab->generatetemp(Integer);

        emit((yyval.expr)->loc, (yyvsp[0].intval), Assign);

        SymVal* val = new SymVal();
        val->SetInit((yyvsp[0].intval));
        symtab->lookup((yyval.expr)->loc)->initval = val;
    }
#line 1531 "y.tab.c"
    break;

  case 6: /* primary_expression: FLOATCONST  */
#line 136 "a9_220101002.y"
                 {
        (yyval.expr) = new Expression();                 
        (yyval.expr)->loc = symtab->generatetemp(Float);

        emit((yyval.expr)->loc, (yyvsp[0].floatval), Assign);
        SymVal* val = new SymVal();
        val->SetInit((yyvsp[0].floatval));                   
        symtab->lookup((yyval.expr)->loc)->initval = val;
    }
#line 1545 "y.tab.c"
    break;

  case 7: /* primary_expression: CHARCONST  */
#line 145 "a9_220101002.y"
                {
        (yyval.expr) = new Expression();                 
        (yyval.expr)->loc = symtab->generatetemp(Char);

        emit((yyval.expr)->loc, (yyvsp[0].charval), Assign);
        SymVal* val = new SymVal();
        val->SetInit((yyvsp[0].charval));
        // cout<<(val->p)<<" "<<(val->c)<<" "<<(val->i)<<" "<<(val->f)<<"\n";                  
        symtab->lookup((yyval.expr)->loc)->initval = val;    
    }
#line 1560 "y.tab.c"
    break;

  case 8: /* primary_expression: STRING  */
#line 155 "a9_220101002.y"
             {   
        (yyval.expr) = new Expression();
        (yyval.expr)->loc = ".LC" + to_string(strcnt++);
    }
#line 1569 "y.tab.c"
    break;

  case 9: /* primary_expression: LPAREN expression RPAREN  */
#line 159 "a9_220101002.y"
                               {
        (yyval.expr) = (yyvsp[-1].expr);  
    }
#line 1577 "y.tab.c"
    break;

  case 10: /* postfix_expression: primary_expression  */
#line 165 "a9_220101002.y"
                         {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 1585 "y.tab.c"
    break;

  case 11: /* postfix_expression: postfix_expression LSQRBRC expression RSQRBRC  */
#line 168 "a9_220101002.y"
                                                    {
        SymType t = symtab->lookup((yyvsp[-3].expr)->loc)->type;     
        string f = "";
        if(!((yyvsp[-3].expr)->fold)) {
            f = symtab->generatetemp(Integer);                      
            emit(f, 0, Assign);
            (yyvsp[-3].expr)->folder = new string(f);
        }
        string temp = symtab->generatetemp(Integer);
        emit(temp, (yyvsp[-1].expr)->loc, "", Assign);
        emit(temp, temp, "4", Mult);
        emit(f, temp, "", Assign);
        (yyval.expr) = (yyvsp[-3].expr);
    }
#line 1604 "y.tab.c"
    break;

  case 12: /* postfix_expression: postfix_expression LPAREN argument_expression_list RPAREN  */
#line 182 "a9_220101002.y"
                                                                {
        SymTable* funcTable = gsymtab.lookup((yyvsp[-3].expr)->loc)->nestedtable;
        vector<param*> parameters = *((yyvsp[-1].prmlist));                         
        vector<Sym*> paramsList = funcTable->symbols;

        for(int i = 0; i < (int)parameters.size(); i++) {
            emit(parameters[i]->name, "", "", Param);              
        }

        Datatype retType = funcTable->lookup("RETVAL")->type.datatype; 
        if(retType == Void)                                        
            emit((yyvsp[-3].expr)->loc, (int)parameters.size(), Call);
        else {                                                     
            string retVal = symtab->generatetemp(retType);
            emit((yyvsp[-3].expr)->loc, to_string(parameters.size()), retVal, Call);
            (yyval.expr) = new Expression();
            (yyval.expr)->loc = retVal;
            (yyval.expr)->type = Function;
        }
    }
#line 1629 "y.tab.c"
    break;

  case 13: /* postfix_expression: postfix_expression LPAREN RPAREN  */
#line 202 "a9_220101002.y"
                                       {
        SymTable* funcTable = gsymtab.lookup((yyvsp[-2].expr)->loc)->nestedtable;
        emit((yyvsp[-2].expr)->loc, "0", "", Call);
        (yyval.expr) = new Expression();
        (yyval.expr)->type = Function;
    }
#line 1640 "y.tab.c"
    break;

  case 14: /* postfix_expression: postfix_expression DEREF IDENTIFIER  */
#line 208 "a9_220101002.y"
                                          {
        (yyval.expr) = new Expression();
    }
#line 1648 "y.tab.c"
    break;

  case 15: /* argument_expression_list: assignment_expression  */
#line 214 "a9_220101002.y"
                            {
        param* first = new param();                
        first->name = (yyvsp[0].expr)->loc;
        first->type = symtab->lookup((yyvsp[0].expr)->loc)->type;
        (yyval.prmlist) = new vector<param*>;

        (yyval.prmlist)->push_back(first);  
    }
#line 1661 "y.tab.c"
    break;

  case 16: /* argument_expression_list: argument_expression_list COMMA assignment_expression  */
#line 222 "a9_220101002.y"
                                                           {
        param* next = new param();                 
        next->name = (yyvsp[0].expr)->loc;
        next->type = symtab->lookup(next->name)->type;
        (yyval.prmlist) = (yyvsp[-2].prmlist);

        (yyval.prmlist)->push_back(next); 
    }
#line 1674 "y.tab.c"
    break;

  case 17: /* unary_expression: postfix_expression  */
#line 233 "a9_220101002.y"
                         {
       
    }
#line 1682 "y.tab.c"
    break;

  case 18: /* unary_expression: unary_operator unary_expression  */
#line 236 "a9_220101002.y"
                                      {
        (yyval.expr) = new Expression();
        switch((yyvsp[-1].charval)){
            case 1: // &
                (yyval.expr) = new Expression();
                (yyval.expr)->loc = symtab->generatetemp(Pointer);
                emit((yyval.expr)->loc, (yyvsp[0].expr)->loc, "", Ref);         
                break;
            case 2: // *
                (yyval.expr) = new Expression();
                (yyval.expr)->loc = symtab->generatetemp(Integer);                    
                (yyval.expr)->fold = 1;
                (yyval.expr)->folder = new string((yyvsp[0].expr)->loc);
                emit((yyval.expr)->loc, (yyvsp[0].expr)->loc, "", Deref);
                break;
            case 3: // ++
                (yyval.expr) = new Expression();
                (yyval.expr)->loc = symtab->generatetemp();
                emit((yyval.expr)->loc, (yyvsp[0].expr)->loc, "1", Add);      
                emit((yyvsp[0].expr)->loc, (yyval.expr)->loc, "", Assign);   
                break;
            case 4: // --
                (yyval.expr) = new Expression();
                (yyval.expr)->loc = symtab->generatetemp();
                emit((yyval.expr)->loc, (yyvsp[0].expr)->loc, "1", Sub);    
                emit((yyvsp[0].expr)->loc, (yyval.expr)->loc, "", Assign);
                break;
            case 5: // + (unary)
                (yyval.expr) = new Expression();
                (yyval.expr) = (yyvsp[0].expr);
                break;
            case 6: // - (unary) 
                (yyval.expr) = new Expression();
                (yyval.expr)->loc = symtab->generatetemp();
                emit((yyval.expr)->loc, (yyvsp[0].expr)->loc, "", Uminus);
                break;
            case 7: // ~ (bitwise complement)
                (yyval.expr) = new Expression();
                (yyval.expr)->loc = symtab->generatetemp(Integer);
                emit((yyval.expr)->loc, (yyvsp[0].expr)->loc, "", Complement);
                break;
            case 8: // ! (logical not)
                (yyval.expr) = new Expression();
                (yyval.expr)->loc = symtab->generatetemp(Integer);
                int temp = nxtinst + 2;                               
                emit(to_string(temp), (yyvsp[0].expr)->loc, "0", Gotoeq);

                temp = nxtinst + 3;
                emit(to_string(temp), "", "" , Goto);
                emit((yyval.expr)->loc,"0","",Assign);

                temp = nxtinst + 2;
                emit(to_string(temp),"","",Goto);
                emit((yyval.expr)->loc,"0","",Assign);
                break;
        }
    }
#line 1744 "y.tab.c"
    break;

  case 19: /* unary_operator: BITAND  */
#line 296 "a9_220101002.y"
             {
        (yyval.charval) = 1;
    }
#line 1752 "y.tab.c"
    break;

  case 20: /* unary_operator: MULT  */
#line 299 "a9_220101002.y"
           {
        (yyval.charval) = 2;
    }
#line 1760 "y.tab.c"
    break;

  case 21: /* unary_operator: INCR  */
#line 302 "a9_220101002.y"
           {
        (yyval.charval) = 3;
    }
#line 1768 "y.tab.c"
    break;

  case 22: /* unary_operator: DECR  */
#line 305 "a9_220101002.y"
           {
        (yyval.charval) = 4;
    }
#line 1776 "y.tab.c"
    break;

  case 23: /* unary_operator: ADD  */
#line 308 "a9_220101002.y"
          {
        (yyval.charval) = 5;
    }
#line 1784 "y.tab.c"
    break;

  case 24: /* unary_operator: SUB  */
#line 311 "a9_220101002.y"
          {
        (yyval.charval) = 6;
    }
#line 1792 "y.tab.c"
    break;

  case 25: /* unary_operator: COMPLEMENT  */
#line 314 "a9_220101002.y"
                 {
        (yyval.charval) = 7;
    }
#line 1800 "y.tab.c"
    break;

  case 26: /* unary_operator: LOGICALNOT  */
#line 317 "a9_220101002.y"
                 {
        (yyval.charval) = 8;
    }
#line 1808 "y.tab.c"
    break;

  case 27: /* multiplicative_expression: unary_expression  */
#line 323 "a9_220101002.y"
                       {
        (yyval.expr) = new Expression();
        SymType tp = symtab->lookup((yyvsp[0].expr)->loc)->type;

        if(tp.datatype == Array) {
            string t = symtab->generatetemp(tp.nextdatatype);
            if((yyvsp[0].expr)->folder != NULL) {
                emit(t, (yyvsp[0].expr)->loc, *((yyvsp[0].expr)->folder), Array_Access);  
                (yyvsp[0].expr)->loc = t;
                (yyvsp[0].expr)->type = tp.nextdatatype;
                (yyval.expr) = (yyvsp[0].expr);
            }
            else{
                (yyval.expr) = (yyvsp[0].expr);
            }
                        
        }
        else {
            (yyval.expr) = (yyvsp[0].expr);  
        }               
    }
#line 1834 "y.tab.c"
    break;

  case 28: /* multiplicative_expression: multiplicative_expression MULT unary_expression  */
#line 344 "a9_220101002.y"
                                                      {
        (yyval.expr) = new Expression();

        Sym* one = symtab->lookup((yyvsp[-2].expr)->loc);                 
        Sym* two = symtab->lookup((yyvsp[0].expr)->loc);   

        if(two->type.datatype == Array) {
            string t = symtab->generatetemp(two->type.nextdatatype);
            emit(t, (yyvsp[0].expr)->loc, *((yyvsp[0].expr)->folder), Array_Access);
            (yyvsp[0].expr)->loc = t;
            (yyvsp[0].expr)->type = two->type.nextdatatype;
        }

        if(one->type.datatype == Array) {                      
            string t = symtab->generatetemp(one->type.nextdatatype);
            emit(t, (yyvsp[-2].expr)->loc, *((yyvsp[-2].expr)->folder), Array_Access);
            (yyvsp[-2].expr)->loc = t;
            (yyvsp[-2].expr)->type = one->type.nextdatatype;
        }

        Datatype final = ((one->type.datatype > two->type.datatype) ? (one->type.datatype) : (two->type.datatype));
        (yyval.expr)->loc = symtab->generatetemp(final);
        emit((yyval.expr)->loc, (yyvsp[-2].expr)->loc, (yyvsp[0].expr)->loc, Mult);   
    }
#line 1863 "y.tab.c"
    break;

  case 29: /* multiplicative_expression: multiplicative_expression DIV unary_expression  */
#line 368 "a9_220101002.y"
                                                     {
        (yyval.expr) = new Expression();

        Sym* one = symtab->lookup((yyvsp[-2].expr)->loc);                 
        Sym* two = symtab->lookup((yyvsp[0].expr)->loc);
           
        if(two->type.datatype == Array) {                      
            string t = symtab->generatetemp(two->type.nextdatatype);
            emit(t, (yyvsp[0].expr)->loc, *((yyvsp[0].expr)->folder), Array_Access);
            (yyvsp[0].expr)->loc = t;
            (yyvsp[0].expr)->type = two->type.nextdatatype;
        }
     
        if(one->type.datatype == Array) {                      
            string t = symtab->generatetemp(one->type.nextdatatype);
            emit(t, (yyvsp[-2].expr)->loc, *((yyvsp[-2].expr)->folder), Array_Access);
            (yyvsp[-2].expr)->loc = t;
            (yyvsp[-2].expr)->type = one->type.nextdatatype;
        }

        Datatype final = ((one->type.datatype > two->type.datatype) ? (one->type.datatype) : (two->type.datatype));
        (yyval.expr)->loc = symtab->generatetemp(final);
        emit((yyval.expr)->loc, (yyvsp[-2].expr)->loc, (yyvsp[0].expr)->loc, Div);
    }
#line 1892 "y.tab.c"
    break;

  case 30: /* multiplicative_expression: multiplicative_expression MOD unary_expression  */
#line 392 "a9_220101002.y"
                                                     {
        (yyval.expr) = new Expression();

        Sym* one = symtab->lookup((yyvsp[-2].expr)->loc);                 
        Sym* two = symtab->lookup((yyvsp[0].expr)->loc);       
          
        if(two->type.datatype == Array) {                      
            string t = symtab->generatetemp(two->type.nextdatatype);
            emit(t, (yyvsp[0].expr)->loc, *((yyvsp[0].expr)->folder), Array_Access);
            (yyvsp[0].expr)->loc = t;
            (yyvsp[0].expr)->type = two->type.nextdatatype;
        }
        if(one->type.datatype == Array) {                      
            string t = symtab->generatetemp(one->type.nextdatatype);
            emit(t, (yyvsp[-2].expr)->loc, *((yyvsp[-2].expr)->folder), Array_Access);
            (yyvsp[-2].expr)->loc = t;
            (yyvsp[-2].expr)->type = one->type.nextdatatype;
        }

        Datatype final = ((one->type.datatype > two->type.datatype) ? (one->type.datatype) : (two->type.datatype));
        (yyval.expr)->loc = symtab->generatetemp(final);   
        emit((yyval.expr)->loc, (yyvsp[-2].expr)->loc, (yyvsp[0].expr)->loc, Mod);
    }
#line 1920 "y.tab.c"
    break;

  case 31: /* additive_expression: multiplicative_expression  */
#line 418 "a9_220101002.y"
                                {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 1928 "y.tab.c"
    break;

  case 32: /* additive_expression: additive_expression ADD multiplicative_expression  */
#line 421 "a9_220101002.y"
                                                        {
        (yyval.expr) = new Expression();

        Sym* one = symtab->lookup((yyvsp[-2].expr)->loc);                 
        Sym* two = symtab->lookup((yyvsp[0].expr)->loc);
 
        if(two->type.datatype == Array) {                      
            string t = symtab->generatetemp(two->type.nextdatatype);
            emit(t, (yyvsp[0].expr)->loc, *((yyvsp[0].expr)->folder), Array_Access);
            (yyvsp[0].expr)->loc = t;
            (yyvsp[0].expr)->type = two->type.nextdatatype;
        }

        if(one->type.datatype == Array) {                      
            string t = symtab->generatetemp(one->type.nextdatatype);
            emit(t, (yyvsp[-2].expr)->loc, *((yyvsp[-2].expr)->folder), Array_Access);
            (yyvsp[-2].expr)->loc = t;
            (yyvsp[-2].expr)->type = one->type.nextdatatype;
        }

        Datatype final = ((one->type.datatype > two->type.datatype) ? (one->type.datatype) : (two->type.datatype));
        (yyval.expr)->loc = symtab->generatetemp(final);

        emit((yyval.expr)->loc, (yyvsp[-2].expr)->loc, (yyvsp[0].expr)->loc, Add);
    }
#line 1958 "y.tab.c"
    break;

  case 33: /* additive_expression: additive_expression SUB multiplicative_expression  */
#line 446 "a9_220101002.y"
                                                        {
        (yyval.expr) = new Expression();
        Sym* one = symtab->lookup((yyvsp[-2].expr)->loc);                 
        Sym* two = symtab->lookup((yyvsp[0].expr)->loc);         
    
        if(two->type.datatype == Array) {                      
            string t = symtab->generatetemp(two->type.nextdatatype);
            emit(t, (yyvsp[0].expr)->loc, *((yyvsp[0].expr)->folder), Array_Access);
            (yyvsp[0].expr)->loc = t;
            (yyvsp[0].expr)->type = two->type.nextdatatype;
        }

        if(one->type.datatype == Array) {                      
            string t = symtab->generatetemp(one->type.nextdatatype);
            emit(t, (yyvsp[-2].expr)->loc, *((yyvsp[-2].expr)->folder), Array_Access);
            (yyvsp[-2].expr)->loc = t;
            (yyvsp[-2].expr)->type = one->type.nextdatatype;
        }

        Datatype final = ((one->type.datatype > two->type.datatype) ? (one->type.datatype) : (two->type.datatype));
        (yyval.expr)->loc = symtab->generatetemp(final);                      
        
        emit((yyval.expr)->loc, (yyvsp[-2].expr)->loc, (yyvsp[0].expr)->loc, Sub);
    }
#line 1987 "y.tab.c"
    break;

  case 34: /* shift_expression: additive_expression  */
#line 473 "a9_220101002.y"
                          {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 1995 "y.tab.c"
    break;

  case 35: /* shift_expression: shift_expression LSHIFT additive_expression  */
#line 476 "a9_220101002.y"
                                                  {
        // Check if first operand is an array and handle it
        Sym* one = symtab->lookup((yyvsp[-2].expr)->loc);
        if(one->type.datatype == Array) {
            string t = symtab->generatetemp(one->type.nextdatatype);
            emit(t, (yyvsp[-2].expr)->loc, *((yyvsp[-2].expr)->folder), Array_Access);
            (yyvsp[-2].expr)->loc = t;
            (yyvsp[-2].expr)->type = one->type.nextdatatype;
        }
        
        // Check if second operand is an array and handle it
        Sym* two = symtab->lookup((yyvsp[0].expr)->loc);
        if(two->type.datatype == Array) {
            string t = symtab->generatetemp(two->type.nextdatatype);
            emit(t, (yyvsp[0].expr)->loc, *((yyvsp[0].expr)->folder), Array_Access);
            (yyvsp[0].expr)->loc = t;
            (yyvsp[0].expr)->type = two->type.nextdatatype;
        }
        
        // Check if both operands are integers
        if(one->type.datatype != Integer || two->type.datatype != Integer) {
            cout<<"Error: Shift operation requires integer operands\n";
        }
        else {
            (yyval.expr) = new Expression();
            (yyval.expr)->loc = symtab->generatetemp(Integer);
            (yyval.expr)->type = Integer;
            emit((yyval.expr)->loc, (yyvsp[-2].expr)->loc, (yyvsp[0].expr)->loc, Lshift);
        }
    }
#line 2030 "y.tab.c"
    break;

  case 36: /* shift_expression: shift_expression RSHIFT additive_expression  */
#line 506 "a9_220101002.y"
                                                  {
        // Check if first operand is an array and handle it
        Sym* one = symtab->lookup((yyvsp[-2].expr)->loc);
        if(one->type.datatype == Array) {
            string t = symtab->generatetemp(one->type.nextdatatype);
            emit(t, (yyvsp[-2].expr)->loc, *((yyvsp[-2].expr)->folder), Array_Access);
            (yyvsp[-2].expr)->loc = t;
            (yyvsp[-2].expr)->type = one->type.nextdatatype;
        }
        
        // Check if second operand is an array and handle it
        Sym* two = symtab->lookup((yyvsp[0].expr)->loc);
        if(two->type.datatype == Array) {
            string t = symtab->generatetemp(two->type.nextdatatype);
            emit(t, (yyvsp[0].expr)->loc, *((yyvsp[0].expr)->folder), Array_Access);
            (yyvsp[0].expr)->loc = t;
            (yyvsp[0].expr)->type = two->type.nextdatatype;
        }
        
        // Check if both operands are integers
        if(one->type.datatype != Integer || two->type.datatype != Integer) {
            cout<<"Error: Shift operation requires integer operands\n";
        }
        else {
            (yyval.expr) = new Expression();
            (yyval.expr)->loc = symtab->generatetemp(Integer);
            (yyval.expr)->type = Integer;
            emit((yyval.expr)->loc, (yyvsp[-2].expr)->loc, (yyvsp[0].expr)->loc, Rshift);
        }
    }
#line 2065 "y.tab.c"
    break;

  case 37: /* relational_expression: shift_expression  */
#line 539 "a9_220101002.y"
                       {
        
    }
#line 2073 "y.tab.c"
    break;

  case 38: /* relational_expression: relational_expression LESS shift_expression  */
#line 542 "a9_220101002.y"
                                                  {
        (yyval.expr) = new Expression();

        Sym* one = symtab->lookup((yyvsp[-2].expr)->loc);                 
        Sym* two = symtab->lookup((yyvsp[0].expr)->loc); 
              
        if(two->type.datatype == Array) {                      
            string t = symtab->generatetemp(two->type.nextdatatype);
            emit(t, (yyvsp[0].expr)->loc, *((yyvsp[0].expr)->folder), Array_Access);
            (yyvsp[0].expr)->loc = t;
            (yyvsp[0].expr)->type = two->type.nextdatatype;
        }
        if(one->type.datatype == Array) {                      
            string t = symtab->generatetemp(one->type.nextdatatype);
            emit(t, (yyvsp[-2].expr)->loc, *((yyvsp[-2].expr)->folder), Array_Access);
            (yyvsp[-2].expr)->loc = t;
            (yyvsp[-2].expr)->type = one->type.nextdatatype;
        }

        (yyval.expr)->loc = symtab->generatetemp();
        (yyval.expr)->type = Bool;

        emit((yyval.expr)->loc, "1", "", Assign);
        (yyval.expr)->truelist = makelist(nxtinst);
        emit("", (yyvsp[-2].expr)->loc, (yyvsp[0].expr)->loc, If_Lt_goto);
        emit((yyval.expr)->loc, "0", "", Assign);
        (yyval.expr)->falselist = makelist(nxtinst);
        emit("", "", "", Goto);   
    }
#line 2107 "y.tab.c"
    break;

  case 39: /* relational_expression: relational_expression GREATER shift_expression  */
#line 571 "a9_220101002.y"
                                                     {
        (yyval.expr) = new Expression();

        Sym* one = symtab->lookup((yyvsp[-2].expr)->loc);                 
        Sym* two = symtab->lookup((yyvsp[0].expr)->loc); 
  
        if(two->type.datatype == Array) {                      
            string t = symtab->generatetemp(two->type.nextdatatype);
            emit(t, (yyvsp[0].expr)->loc, *((yyvsp[0].expr)->folder), Array_Access);
            (yyvsp[0].expr)->loc = t;
            (yyvsp[0].expr)->type = two->type.nextdatatype;
        }
        if(one->type.datatype == Array) {                      
            string t = symtab->generatetemp(one->type.nextdatatype);
            emit(t, (yyvsp[-2].expr)->loc, *((yyvsp[-2].expr)->folder), Array_Access);
            (yyvsp[-2].expr)->loc = t;
            (yyvsp[-2].expr)->type = one->type.nextdatatype;
        }

        (yyval.expr)->loc = symtab->generatetemp();
        (yyval.expr)->type = Bool;

        emit((yyval.expr)->loc, "1", "", Assign);
        (yyval.expr)->truelist = makelist(nxtinst);   
        emit("", (yyvsp[-2].expr)->loc, (yyvsp[0].expr)->loc, If_Gt_goto);               
        emit((yyval.expr)->loc, "0", "", Assign);
        (yyval.expr)->falselist = makelist(nxtinst);               
        emit("", "", "", Goto); 
    }
#line 2141 "y.tab.c"
    break;

  case 40: /* relational_expression: relational_expression LESSEQUAL shift_expression  */
#line 600 "a9_220101002.y"
                                                       {
        (yyval.expr) = new Expression();

        Sym* one = symtab->lookup((yyvsp[-2].expr)->loc);                 
        Sym* two = symtab->lookup((yyvsp[0].expr)->loc);
   
        if(two->type.datatype == Array) {                      
            string t = symtab->generatetemp(two->type.nextdatatype);
            emit(t, (yyvsp[0].expr)->loc, *((yyvsp[0].expr)->folder), Array_Access);
            (yyvsp[0].expr)->loc = t;
            (yyvsp[0].expr)->type = two->type.nextdatatype;
        }   
        if(one->type.datatype == Array) {                      
            string t = symtab->generatetemp(one->type.nextdatatype);
            emit(t, (yyvsp[-2].expr)->loc, *((yyvsp[-2].expr)->folder), Array_Access);
            (yyvsp[-2].expr)->loc = t;
            (yyvsp[-2].expr)->type = one->type.nextdatatype;
        }
        (yyval.expr)->loc = symtab->generatetemp();
        (yyval.expr)->type = Bool;           

        emit((yyval.expr)->loc, "1", "", Assign);
        (yyval.expr)->truelist = makelist(nxtinst); 
        emit("", (yyvsp[-2].expr)->loc, (yyvsp[0].expr)->loc, If_Le_goto);              
        emit((yyval.expr)->loc, "0", "", Assign);
        (yyval.expr)->falselist = makelist(nxtinst);               
        emit("", "", "", Goto); 
    }
#line 2174 "y.tab.c"
    break;

  case 41: /* relational_expression: relational_expression GREATEREQUAL shift_expression  */
#line 628 "a9_220101002.y"
                                                          {
        (yyval.expr) = new Expression();

        Sym* one = symtab->lookup((yyvsp[-2].expr)->loc);                 
        Sym* two = symtab->lookup((yyvsp[0].expr)->loc);    
         
        if(two->type.datatype == Array) {                      
            string t = symtab->generatetemp(two->type.nextdatatype);
            emit(t, (yyvsp[0].expr)->loc, *((yyvsp[0].expr)->folder), Array_Access);
            (yyvsp[0].expr)->loc = t;
            (yyvsp[0].expr)->type = two->type.nextdatatype;
        }  
        if(one->type.datatype == Array) {                      
            string t = symtab->generatetemp(one->type.nextdatatype);
            emit(t, (yyvsp[-2].expr)->loc, *((yyvsp[-2].expr)->folder), Array_Access);
            (yyvsp[-2].expr)->loc = t;
            (yyvsp[-2].expr)->type = one->type.nextdatatype;
        }
        (yyval.expr)->loc = symtab->generatetemp();
        (yyval.expr)->type = Bool;        

        emit((yyval.expr)->loc, "1", "", Assign);
        (yyval.expr)->truelist = makelist(nxtinst);
        emit("", (yyvsp[-2].expr)->loc, (yyvsp[0].expr)->loc, If_Ge_goto);              
        emit((yyval.expr)->loc, "0", "", Assign);
        (yyval.expr)->falselist = makelist(nxtinst);               
        emit("", "", "", Goto);
    }
#line 2207 "y.tab.c"
    break;

  case 42: /* equality_expression: relational_expression  */
#line 659 "a9_220101002.y"
                            {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 2215 "y.tab.c"
    break;

  case 43: /* equality_expression: equality_expression EQUALITY relational_expression  */
#line 662 "a9_220101002.y"
                                                         {
        (yyval.expr) = new Expression();

        Sym* one = symtab->lookup((yyvsp[-2].expr)->loc);                 
        Sym* two = symtab->lookup((yyvsp[0].expr)->loc);

        if(two->type.datatype == Array) {                      
            string t = symtab->generatetemp(two->type.nextdatatype);
            emit(t, (yyvsp[0].expr)->loc, *((yyvsp[0].expr)->folder), Array_Access);
            (yyvsp[0].expr)->loc = t;
            (yyvsp[0].expr)->type = two->type.nextdatatype;
        }
        if(one->type.datatype == Array) {                      
            string t = symtab->generatetemp(one->type.nextdatatype);
            emit(t, (yyvsp[-2].expr)->loc, *((yyvsp[-2].expr)->folder), Array_Access);
            (yyvsp[-2].expr)->loc = t;
            (yyvsp[-2].expr)->type = one->type.nextdatatype;
        }

        (yyval.expr)->loc = symtab->generatetemp();
        (yyval.expr)->type = Bool;                                   
        emit((yyval.expr)->loc, "1", "", Assign);

        (yyval.expr)->truelist = makelist(nxtinst);                
        emit("", (yyvsp[-2].expr)->loc, (yyvsp[0].expr)->loc, If_Eq_goto);               
        emit((yyval.expr)->loc, "0", "", Assign);

        (yyval.expr)->falselist = makelist(nxtinst);               
        emit("", "", "", Goto);   
    }
#line 2250 "y.tab.c"
    break;

  case 44: /* equality_expression: equality_expression NOTEQUAL relational_expression  */
#line 692 "a9_220101002.y"
                                                         {
        (yyval.expr) = new Expression();

        Sym* one = symtab->lookup((yyvsp[-2].expr)->loc);                 
        Sym* two = symtab->lookup((yyvsp[0].expr)->loc);    

        if(two->type.datatype == Array) {
            string t = symtab->generatetemp(two->type.nextdatatype);
            emit(t, (yyvsp[0].expr)->loc, *((yyvsp[0].expr)->folder), Array_Access);
            (yyvsp[0].expr)->loc = t;
            (yyvsp[0].expr)->type = two->type.nextdatatype;
        }
        if(one->type.datatype == Array) {
            string t = symtab->generatetemp(one->type.nextdatatype);
            emit(t, (yyvsp[-2].expr)->loc, *((yyvsp[-2].expr)->folder), Array_Access);
            (yyvsp[-2].expr)->loc = t;
            (yyvsp[-2].expr)->type = one->type.nextdatatype;
        }

        (yyval.expr)->loc = symtab->generatetemp();
        (yyval.expr)->type = Bool;         

        emit((yyval.expr)->loc, "1", "", Assign);
        (yyval.expr)->truelist = makelist(nxtinst);      
        emit("", (yyvsp[-2].expr)->loc, (yyvsp[0].expr)->loc, If_Ne_goto);              
        emit((yyval.expr)->loc, "0", "", Assign);
        (yyval.expr)->falselist = makelist(nxtinst);               
        emit("", "", "", Goto);                            
    }
#line 2284 "y.tab.c"
    break;

  case 45: /* AND_expression: equality_expression  */
#line 724 "a9_220101002.y"
                          {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 2292 "y.tab.c"
    break;

  case 46: /* AND_expression: AND_expression BITAND equality_expression  */
#line 727 "a9_220101002.y"
                                                {
        Sym* one = symtab->lookup((yyvsp[-2].expr)->loc);
        Sym* two = symtab->lookup((yyvsp[0].expr)->loc);
        
        if(one->type.datatype == Integer && two->type.datatype == Integer) {
            if(two->type.datatype == Array) {
                string t = symtab->generatetemp(two->type.nextdatatype);
                emit(t, (yyvsp[0].expr)->loc, *((yyvsp[0].expr)->folder), Array_Access);
                (yyvsp[0].expr)->loc = t;
                (yyvsp[0].expr)->type = two->type.nextdatatype;
            }
            
            if(one->type.datatype == Array) {
                string t = symtab->generatetemp(one->type.nextdatatype);
                emit(t, (yyvsp[-2].expr)->loc, *((yyvsp[-2].expr)->folder), Array_Access);
                (yyvsp[-2].expr)->loc = t;
                (yyvsp[-2].expr)->type = one->type.nextdatatype;
            }
            
            Int2Bool((yyvsp[-2].expr));
            Int2Bool((yyvsp[0].expr));
            (yyval.expr) = new Expression();
            (yyval.expr)->type = Integer;
            (yyval.expr)->loc = symtab->generatetemp(Integer);
            emit((yyval.expr)->loc, (yyvsp[-2].expr)->loc, (yyvsp[0].expr)->loc, Bitand);
        } 
        else {
            cout << "Error: Incompatible datatype for AND\n";
        }
    }
#line 2327 "y.tab.c"
    break;

  case 47: /* XOR_expression: AND_expression  */
#line 760 "a9_220101002.y"
                     {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 2335 "y.tab.c"
    break;

  case 48: /* XOR_expression: XOR_expression BITXOR AND_expression  */
#line 763 "a9_220101002.y"
                                           {
        Sym* one = symtab->lookup((yyvsp[-2].expr)->loc);
        Sym* two = symtab->lookup((yyvsp[0].expr)->loc);
        
        if(one->type.datatype == Integer && two->type.datatype == Integer) {
            if(two->type.datatype == Array) {
                string t = symtab->generatetemp(two->type.nextdatatype);
                emit(t, (yyvsp[0].expr)->loc, *((yyvsp[0].expr)->folder), Array_Access);
                (yyvsp[0].expr)->loc = t;
                (yyvsp[0].expr)->type = two->type.nextdatatype;
            }
            
            if(one->type.datatype == Array) {
                string t = symtab->generatetemp(one->type.nextdatatype);
                emit(t, (yyvsp[-2].expr)->loc, *((yyvsp[-2].expr)->folder), Array_Access);
                (yyvsp[-2].expr)->loc = t;
                (yyvsp[-2].expr)->type = one->type.nextdatatype;
            }
            
            Int2Bool((yyvsp[-2].expr));
            Int2Bool((yyvsp[0].expr));
            (yyval.expr) = new Expression();
            (yyval.expr)->type = Integer;
            (yyval.expr)->loc = symtab->generatetemp(Integer);
            emit((yyval.expr)->loc, (yyvsp[-2].expr)->loc, (yyvsp[0].expr)->loc, Bitxor);
        } 
        else {
            cout << "Error: Incompatible datatype for XOR\n";
        }
    }
#line 2370 "y.tab.c"
    break;

  case 49: /* OR_expression: XOR_expression  */
#line 796 "a9_220101002.y"
                     {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 2378 "y.tab.c"
    break;

  case 50: /* OR_expression: OR_expression BITOR XOR_expression  */
#line 799 "a9_220101002.y"
                                         {
        Sym* one = symtab->lookup((yyvsp[-2].expr)->loc);
        Sym* two = symtab->lookup((yyvsp[0].expr)->loc);
        
        if(one->type.datatype == Integer && two->type.datatype == Integer) {
            if(two->type.datatype == Array) {
                string t = symtab->generatetemp(two->type.nextdatatype);
                emit(t, (yyvsp[0].expr)->loc, *((yyvsp[0].expr)->folder), Array_Access);
                (yyvsp[0].expr)->loc = t;
                (yyvsp[0].expr)->type = two->type.nextdatatype;
            }
            
            if(one->type.datatype == Array) {
                string t = symtab->generatetemp(one->type.nextdatatype);
                emit(t, (yyvsp[-2].expr)->loc, *((yyvsp[-2].expr)->folder), Array_Access);
                (yyvsp[-2].expr)->loc = t;
                (yyvsp[-2].expr)->type = one->type.nextdatatype;
            }
            
            Int2Bool((yyvsp[-2].expr));
            Int2Bool((yyvsp[0].expr));
            (yyval.expr) = new Expression();
            (yyval.expr)->type = Integer;
            (yyval.expr)->loc = symtab->generatetemp(Integer);
            emit((yyval.expr)->loc, (yyvsp[-2].expr)->loc, (yyvsp[0].expr)->loc, Bitor);
        } 
        else {
            cout << "Error: Incompatible datatype for OR\n";
        }
    }
#line 2413 "y.tab.c"
    break;

  case 51: /* logical_and_expression: OR_expression  */
#line 832 "a9_220101002.y"
                    {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 2421 "y.tab.c"
    break;

  case 52: /* logical_and_expression: logical_and_expression LOGICALAND M OR_expression  */
#line 835 "a9_220101002.y"
                                                        {
        backpatch((yyvsp[-3].expr)->truelist, (yyvsp[-1].expr)->instr);  
        (yyval.expr) = new Expression();
        (yyval.expr)->falselist = merge((yyvsp[-3].expr)->falselist, (yyvsp[0].expr)->falselist);   
        (yyval.expr)->truelist = (yyvsp[0].expr)->truelist;
        (yyval.expr)->type = Bool; 
    }
#line 2433 "y.tab.c"
    break;

  case 53: /* logical_or_expression: logical_and_expression  */
#line 845 "a9_220101002.y"
                             {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 2441 "y.tab.c"
    break;

  case 54: /* logical_or_expression: logical_or_expression LOGICALOR M logical_and_expression  */
#line 848 "a9_220101002.y"
                                                               {
        backpatch((yyvsp[-3].expr)->falselist, (yyvsp[-1].expr)->instr);   
        (yyval.expr) = new Expression();
        (yyval.expr)->truelist = merge((yyvsp[-3].expr)->truelist, (yyvsp[0].expr)->truelist);
        (yyval.expr)->falselist = (yyvsp[0].expr)->falselist;
        (yyval.expr)->type = Bool;  
    }
#line 2453 "y.tab.c"
    break;

  case 55: /* conditional_expression: logical_or_expression  */
#line 858 "a9_220101002.y"
                            {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 2461 "y.tab.c"
    break;

  case 56: /* conditional_expression: logical_or_expression N QUESTION M expression N COLON M conditional_expression  */
#line 861 "a9_220101002.y"
                                                                                     {
        list<int> temp = makelist(nxtinst);

        Sym* one = symtab->lookup((yyvsp[-4].expr)->loc);
        (yyval.expr) = new Expression();
        (yyval.expr)->loc = symtab->generatetemp(one->type.datatype);     
        (yyval.expr)->type = one->type.datatype;

        emit((yyval.expr)->loc, (yyvsp[0].expr)->loc, "", Assign);        
        emit("", "", "", Goto);

        backpatch((yyvsp[-3].expr)->nextlist, nxtinst);        
        emit((yyval.expr)->loc, (yyvsp[-4].expr)->loc, "", Assign);

        temp = merge(temp, makelist(nxtinst));
        emit("", "", "", Goto);                    
        backpatch((yyvsp[-7].expr)->nextlist, nxtinst);     

        Int2Bool((yyvsp[-8].expr));
        backpatch((yyvsp[-8].expr)->truelist, (yyvsp[-5].expr)->instr);      
        backpatch((yyvsp[-8].expr)->falselist, (yyvsp[-1].expr)->instr);
        backpatch((yyvsp[-7].expr)->nextlist, nxtinst);        
    }
#line 2489 "y.tab.c"
    break;

  case 57: /* assignment_expression: conditional_expression  */
#line 887 "a9_220101002.y"
                             {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 2497 "y.tab.c"
    break;

  case 58: /* assignment_expression: unary_expression ASSIGN assignment_expression  */
#line 890 "a9_220101002.y"
                                                    {
        Sym* sym1 = symtab->lookup((yyvsp[-2].expr)->loc); 
        Sym* sym2 = symtab->lookup((yyvsp[0].expr)->loc);        
        
        if((yyvsp[-2].expr)->fold == 0) {
            if(sym1->type.datatype != Array)
                emit((yyvsp[-2].expr)->loc, (yyvsp[0].expr)->loc, "", Assign);
            else
                emit((yyvsp[-2].expr)->loc, (yyvsp[0].expr)->loc, *((yyvsp[-2].expr)->folder), Array_Access);
        }
        else
            emit(*((yyvsp[-2].expr)->folder), (yyvsp[0].expr)->loc, "", Deref);

        (yyval.expr) = (yyvsp[-2].expr);    
    }
#line 2517 "y.tab.c"
    break;

  case 59: /* expression: assignment_expression  */
#line 908 "a9_220101002.y"
                            {
       (yyval.expr) = (yyvsp[0].expr);
    }
#line 2525 "y.tab.c"
    break;

  case 60: /* declaration: type_specifier init_declarator_list SEMICOLON  */
#line 914 "a9_220101002.y"
                                                    {
        Datatype currType = (yyvsp[-2].types);
        int currSize = -1;

        if(currType == Integer)
            currSize = 4; 
        else if(currType == Char)
            currSize = 1; 
        else if(currType == Float)
            currSize = 8;

        vector<Declaration*> decs = *((yyvsp[-1].declist));
        for(vector<Declaration*>::iterator it = decs.begin(); it != decs.end(); it++) {
            Declaration* currDec = *it;
            if(currDec->type == Function) {
                symtab = &gsymtab;
                emit(currDec->name, "", "", Fun_End);

                Sym* one = symtab->lookup(currDec->name);       
                Sym* two = one->nestedtable->lookup("RETVAL", currType, currDec->pointers);

                one->size = 0;
                one->initval = NULL;
                continue;
            }

            Sym* three = symtab->lookup(currDec->name, currType);       
            three->nestedtable = NULL;
            if(currDec->li.empty() && currDec->pointers == 0) {
                three->type.datatype = currType;
                three->size = currSize;

                if(currDec->initval != NULL) {
                    string rval = currDec->initval->loc;
                    emit(three->name, rval, "", Assign);
                    three->initval = symtab->lookup(rval)->initval;
                }
                else
                    three->initval = NULL;
            }
            else if(!currDec->li.empty()) {        
                three->type.datatype = Array;
                three->type.nextdatatype = currType;
                three->type.dims = currDec->li;
                vector<int> temp = three->type.dims;
                int sz = currSize;
                for(int i = 0; i < (int)temp.size(); i++)
                    sz *= temp[i];

                symtab->offset += sz;
                three->size = sz;
                symtab->offset -= 4;
            }
            else if(currDec->pointers != 0) {              
                three->type.datatype = Pointer;
                three->type.nextdatatype = currType;
                three->type.pointers = currDec->pointers;
                symtab->offset += (4 - currSize);
                three->size = 4; 
            }
        }
    }
#line 2592 "y.tab.c"
    break;

  case 61: /* init_declarator_list: init_declarator  */
#line 979 "a9_220101002.y"
                      {
        (yyval.declist) = new vector<Declaration*>;     
        (yyval.declist)->push_back((yyvsp[0].dec));
    }
#line 2601 "y.tab.c"
    break;

  case 62: /* init_declarator_list: init_declarator_list COMMA init_declarator  */
#line 983 "a9_220101002.y"
                                                 {\
        (yyvsp[-2].declist)->push_back((yyvsp[0].dec));
        (yyval.declist) = (yyvsp[-2].declist);
    }
#line 2610 "y.tab.c"
    break;

  case 63: /* init_declarator: declarator  */
#line 990 "a9_220101002.y"
                 {
        (yyval.dec) = (yyvsp[0].dec);
        (yyval.dec)->initval = NULL; 
    }
#line 2619 "y.tab.c"
    break;

  case 64: /* init_declarator: declarator ASSIGN initializer  */
#line 994 "a9_220101002.y"
                                    {
        (yyval.dec) = (yyvsp[-2].dec);
        (yyval.dec)->initval = (yyvsp[0].expr);
    }
#line 2628 "y.tab.c"
    break;

  case 65: /* type_specifier: VOID  */
#line 1001 "a9_220101002.y"
           {
        (yyval.types) = Void;
    }
#line 2636 "y.tab.c"
    break;

  case 66: /* type_specifier: CHAR  */
#line 1004 "a9_220101002.y"
           {
        (yyval.types) = Char;
    }
#line 2644 "y.tab.c"
    break;

  case 67: /* type_specifier: INTEGER  */
#line 1007 "a9_220101002.y"
              {
        (yyval.types) = Integer;
    }
#line 2652 "y.tab.c"
    break;

  case 68: /* type_specifier: FLOAT  */
#line 1010 "a9_220101002.y"
            {
        (yyval.types) = Float;
    }
#line 2660 "y.tab.c"
    break;

  case 69: /* declarator: pointer direct_declarator  */
#line 1016 "a9_220101002.y"
                                {
        (yyval.dec) = (yyvsp[0].dec);
        (yyval.dec)->pointers = (yyvsp[-1].intval);
    }
#line 2669 "y.tab.c"
    break;

  case 70: /* declarator: direct_declarator  */
#line 1020 "a9_220101002.y"
                        {
        (yyval.dec) = (yyvsp[0].dec);
        (yyval.dec)->pointers = 0;
    }
#line 2678 "y.tab.c"
    break;

  case 71: /* direct_declarator: IDENTIFIER  */
#line 1027 "a9_220101002.y"
                 {
        (yyval.dec) = new Declaration();
        (yyval.dec)->name = *((yyvsp[0].str));
    }
#line 2687 "y.tab.c"
    break;

  case 72: /* direct_declarator: LPAREN declarator RPAREN  */
#line 1031 "a9_220101002.y"
                               {
        (yyval.dec) = (yyvsp[-1].dec);
    }
#line 2695 "y.tab.c"
    break;

  case 73: /* direct_declarator: direct_declarator LSQRBRC RSQRBRC  */
#line 1034 "a9_220101002.y"
                                        {
        (yyvsp[-2].dec)->type = Array;
        (yyvsp[-2].dec)->nexttype = Integer;    
        (yyval.dec) = (yyvsp[-2].dec);
        (yyval.dec)->li.push_back(0);
    }
#line 2706 "y.tab.c"
    break;

  case 74: /* direct_declarator: direct_declarator LSQRBRC assignment_expression RSQRBRC  */
#line 1040 "a9_220101002.y"
                                                              {
        (yyvsp[-3].dec)->type = Array;
        (yyvsp[-3].dec)->nexttype = Integer;   
        (yyval.dec) = (yyvsp[-3].dec);
        int index = symtab->lookup((yyvsp[-1].expr)->loc)->initval->i;
        (yyval.dec)->li.push_back(index);
    }
#line 2718 "y.tab.c"
    break;

  case 75: /* direct_declarator: direct_declarator LPAREN parameter_type_list_opt RPAREN  */
#line 1047 "a9_220101002.y"
                                                              {
        (yyval.dec) = (yyvsp[-3].dec);
        (yyval.dec)->type = Function;

        Sym* funcData = symtab->lookup((yyval.dec)->name, (yyval.dec)->type);
        SymTable* funcTable = new SymTable();
        funcData->nestedtable = funcTable;

        vector<param*> paramList = *((yyvsp[-1].prmlist));  

        for(int i = 0; i < (int)paramList.size(); i++) {
            param* curParam = paramList[i];

            if(curParam->type.datatype == Array) {         
                funcTable->lookup(curParam->name, curParam->type.datatype);
                funcTable->lookup(curParam->name)->type.nextdatatype = Integer;
                funcTable->lookup(curParam->name)->type.dims.push_back(0);
            }
            else if(curParam->type.datatype == Pointer) {  
                funcTable->lookup(curParam->name, curParam->type.datatype);
                funcTable->lookup(curParam->name)->type.nextdatatype = Integer;
                funcTable->lookup(curParam->name)->type.dims.push_back(0);
            }
            else                                       
                funcTable->lookup(curParam->name, curParam->type.datatype);
        }

        symtab = funcTable;
        emit((yyval.dec)->name, "", "", Fun_Beg);
    }
#line 2753 "y.tab.c"
    break;

  case 76: /* pointer: MULT  */
#line 1080 "a9_220101002.y"
           {
        (yyval.intval) = 1;
    }
#line 2761 "y.tab.c"
    break;

  case 77: /* parameter_list: parameter_declaration  */
#line 1086 "a9_220101002.y"
                            {
        (yyval.prmlist) = new vector<param*>;
        (yyval.prmlist)->push_back((yyvsp[0].prm));
    }
#line 2770 "y.tab.c"
    break;

  case 78: /* parameter_list: parameter_list COMMA parameter_declaration  */
#line 1090 "a9_220101002.y"
                                                 {
        (yyvsp[-2].prmlist)->push_back((yyvsp[0].prm));             
        (yyval.prmlist) = (yyvsp[-2].prmlist);
    }
#line 2779 "y.tab.c"
    break;

  case 79: /* parameter_type_list_opt: parameter_list  */
#line 1097 "a9_220101002.y"
                     {
        (yyval.prmlist) = (yyvsp[0].prmlist);
    }
#line 2787 "y.tab.c"
    break;

  case 80: /* parameter_type_list_opt: %empty  */
#line 1100 "a9_220101002.y"
             {
        (yyval.prmlist) = new vector<param*>;
    }
#line 2795 "y.tab.c"
    break;

  case 81: /* parameter_declaration: type_specifier declarator  */
#line 1106 "a9_220101002.y"
                                {
        (yyval.prm) = new param();
        (yyval.prm)->name = (yyvsp[0].dec)->name;

        if((yyvsp[0].dec)->type == Array) {
            (yyval.prm)->type.datatype = Array;
            (yyval.prm)->type.nextdatatype = (yyvsp[-1].types);
        }
        else if((yyvsp[0].dec)->pointers != 0) {
            (yyval.prm)->type.datatype = Pointer;
            (yyval.prm)->type.nextdatatype = (yyvsp[-1].types);
        }
        else
            (yyval.prm)->type.datatype = (yyvsp[-1].types);
    }
#line 2815 "y.tab.c"
    break;

  case 82: /* parameter_declaration: type_specifier  */
#line 1121 "a9_220101002.y"
                     {
        (yyval.prm) = new param();
        (yyval.prm)->type.datatype = (yyvsp[0].types);
    }
#line 2824 "y.tab.c"
    break;

  case 83: /* initializer: assignment_expression  */
#line 1128 "a9_220101002.y"
                            {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 2832 "y.tab.c"
    break;

  case 84: /* statement: compound_statement  */
#line 1134 "a9_220101002.y"
                         {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 2840 "y.tab.c"
    break;

  case 85: /* statement: expression_statement  */
#line 1137 "a9_220101002.y"
                           {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 2848 "y.tab.c"
    break;

  case 86: /* statement: selection_statement  */
#line 1140 "a9_220101002.y"
                          {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 2856 "y.tab.c"
    break;

  case 87: /* statement: iteration_statement  */
#line 1143 "a9_220101002.y"
                          {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 2864 "y.tab.c"
    break;

  case 88: /* statement: jump_statement  */
#line 1146 "a9_220101002.y"
                     {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 2872 "y.tab.c"
    break;

  case 89: /* compound_statement: BLOCKBEGIN BLOCKEND  */
#line 1152 "a9_220101002.y"
                          {
        (yyval.expr) = new Expression();
    }
#line 2880 "y.tab.c"
    break;

  case 90: /* compound_statement: BLOCKBEGIN block_item_list BLOCKEND  */
#line 1155 "a9_220101002.y"
                                          {
        (yyval.expr) = (yyvsp[-1].expr);
    }
#line 2888 "y.tab.c"
    break;

  case 91: /* block_item_list: block_item  */
#line 1161 "a9_220101002.y"
                 {
        (yyval.expr) = (yyvsp[0].expr);
        backpatch((yyvsp[0].expr)->nextlist, nxtinst);
    }
#line 2897 "y.tab.c"
    break;

  case 92: /* block_item_list: block_item_list M block_item  */
#line 1165 "a9_220101002.y"
                                   {
        (yyval.expr) = new Expression();
        backpatch((yyvsp[-2].expr)->nextlist, (yyvsp[-1].expr)->instr);   
        (yyval.expr)->nextlist = (yyvsp[0].expr)->nextlist;
    }
#line 2907 "y.tab.c"
    break;

  case 93: /* block_item: declaration  */
#line 1173 "a9_220101002.y"
                  {
        (yyval.expr) = new Expression();
    }
#line 2915 "y.tab.c"
    break;

  case 94: /* block_item: statement  */
#line 1176 "a9_220101002.y"
                {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 2923 "y.tab.c"
    break;

  case 95: /* expression_statement: expression SEMICOLON  */
#line 1182 "a9_220101002.y"
                           {
        (yyval.expr) = (yyvsp[-1].expr);
    }
#line 2931 "y.tab.c"
    break;

  case 96: /* expression_statement: SEMICOLON  */
#line 1185 "a9_220101002.y"
                {
        (yyval.expr) = new Expression(); 
    }
#line 2939 "y.tab.c"
    break;

  case 97: /* selection_statement: IF LPAREN expression N RPAREN M statement N  */
#line 1191 "a9_220101002.y"
                                                  {
        backpatch((yyvsp[-4].expr)->nextlist, nxtinst);        
        Int2Bool((yyvsp[-5].expr));                      
        backpatch((yyvsp[-5].expr)->truelist, (yyvsp[-2].expr)->instr);        
        (yyval.expr) = new Expression();                     
    
        (yyvsp[-1].expr)->nextlist = merge((yyvsp[0].expr)->nextlist, (yyvsp[-1].expr)->nextlist);
        (yyval.expr)->nextlist = merge((yyvsp[-5].expr)->falselist, (yyvsp[-1].expr)->nextlist);
    }
#line 2953 "y.tab.c"
    break;

  case 98: /* selection_statement: IF LPAREN expression N RPAREN M statement N ELSE M statement N  */
#line 1200 "a9_220101002.y"
                                                                     {
        backpatch((yyvsp[-8].expr)->nextlist, nxtinst);        
        Int2Bool((yyvsp[-9].expr));
        backpatch((yyvsp[-9].expr)->truelist, (yyvsp[-6].expr)->instr);        
        backpatch((yyvsp[-9].expr)->falselist, (yyvsp[-2].expr)->instr);
        (yyval.expr) = new Expression();                     
    
        (yyval.expr)->nextlist = merge((yyvsp[-5].expr)->nextlist, (yyvsp[-4].expr)->nextlist);
        (yyval.expr)->nextlist = merge((yyval.expr)->nextlist, (yyvsp[-1].expr)->nextlist);
        (yyval.expr)->nextlist = merge((yyval.expr)->nextlist, (yyvsp[0].expr)->nextlist);
    }
#line 2969 "y.tab.c"
    break;

  case 99: /* iteration_statement: FOR LPAREN expression_statement M expression_statement N M expression N RPAREN M statement  */
#line 1214 "a9_220101002.y"
                                                                                                 {
        (yyval.expr) = new Expression();                  
        emit("", "", "", Goto);
        (yyvsp[0].expr)->nextlist = merge((yyvsp[0].expr)->nextlist, makelist(nxtinst - 1));
        backpatch((yyvsp[0].expr)->nextlist, (yyvsp[-5].expr)->instr);   
        backpatch((yyvsp[-3].expr)->nextlist, (yyvsp[-8].expr)->instr);     
        backpatch((yyvsp[-6].expr)->nextlist, nxtinst);     
        Int2Bool((yyvsp[-7].expr));                  
        backpatch((yyvsp[-7].expr)->truelist, (yyvsp[-1].expr)->instr);   
        (yyval.expr)->nextlist = (yyvsp[-7].expr)->falselist;    
    }
#line 2985 "y.tab.c"
    break;

  case 100: /* iteration_statement: DO M statement M WHILE LPAREN expression RPAREN SEMICOLON  */
#line 1225 "a9_220101002.y"
                                                                {
        (yyval.expr) = new Expression();
        Int2Bool((yyvsp[-2].expr));
        backpatch((yyvsp[-2].expr)->truelist, (yyvsp[-7].expr)->instr);  
        backpatch((yyvsp[-6].expr)->nextlist, (yyvsp[-5].expr)->instr);
        (yyval.expr)->nextlist = (yyvsp[-2].expr)->falselist; 
    }
#line 2997 "y.tab.c"
    break;

  case 101: /* iteration_statement: WHILE M LPAREN expression RPAREN M statement  */
#line 1232 "a9_220101002.y"
                                                   {
        (yyval.expr) = new Expression();
        emit("", "", "", Goto);
        (yyvsp[0].expr)->nextlist = merge((yyvsp[0].expr)->nextlist, makelist(nxtinst-1));
        backpatch((yyvsp[0].expr)->nextlist, (yyvsp[-5].expr)->instr);
        Int2Bool((yyvsp[-3].expr));
        backpatch((yyvsp[-3].expr)->truelist, (yyvsp[-1].expr)->instr);
        (yyval.expr)->nextlist = (yyvsp[-3].expr)->falselist;
    }
#line 3011 "y.tab.c"
    break;

  case 102: /* jump_statement: RETURN SEMICOLON  */
#line 1244 "a9_220101002.y"
                       {
        if(symtab->lookup("RETVAL")->type.datatype == Void) {
            emit("", "", "", Return);          
        }
        (yyval.expr) = new Expression();
    }
#line 3022 "y.tab.c"
    break;

  case 103: /* jump_statement: RETURN expression SEMICOLON  */
#line 1250 "a9_220101002.y"
                                  {
        if(symtab->lookup("RETVAL")->type.datatype == symtab->lookup((yyvsp[-1].expr)->loc)->type.datatype) {
            emit((yyvsp[-1].expr)->loc, "", "", Return);     
        }
        (yyval.expr) = new Expression();
    }
#line 3033 "y.tab.c"
    break;

  case 104: /* jump_statement: BREAK SEMICOLON  */
#line 1256 "a9_220101002.y"
                      {
        (yyval.expr) = new Expression();
        (yyval.expr)->nextlist = makelist(nxtinst);
        emit("", "", "", Goto);
    }
#line 3043 "y.tab.c"
    break;

  case 105: /* jump_statement: GOTO IDENTIFIER SEMICOLON  */
#line 1261 "a9_220101002.y"
                                {
        (yyval.expr) = new Expression();
        string label = *((yyvsp[-1].str));

        emit(label, "", "", Goto);
    }
#line 3054 "y.tab.c"
    break;

  case 106: /* translation_unit: external_declaration  */
#line 1271 "a9_220101002.y"
                           {
        
    }
#line 3062 "y.tab.c"
    break;

  case 107: /* translation_unit: translation_unit external_declaration  */
#line 1274 "a9_220101002.y"
                                            {
        
    }
#line 3070 "y.tab.c"
    break;

  case 108: /* external_declaration: function_definition  */
#line 1280 "a9_220101002.y"
                          {
        
    }
#line 3078 "y.tab.c"
    break;

  case 109: /* external_declaration: declaration  */
#line 1283 "a9_220101002.y"
                  {
        
    }
#line 3086 "y.tab.c"
    break;

  case 110: /* function_definition: type_specifier declarator declaration_list compound_statement  */
#line 1289 "a9_220101002.y"
                                                                    {
        symtab = &gsymtab;
    }
#line 3094 "y.tab.c"
    break;

  case 111: /* function_definition: function_prototype compound_statement  */
#line 1292 "a9_220101002.y"
                                            {
        symtab = &gsymtab;                    
        emit((yyvsp[-1].dec)->name, "", "", Fun_End);
    }
#line 3103 "y.tab.c"
    break;

  case 112: /* function_prototype: type_specifier declarator  */
#line 1299 "a9_220101002.y"
                              {
        Datatype currType = (yyvsp[-1].types);
        int currSize = -1;
        if(currType == Char)
            currSize = 1; 
        if(currType == Integer)
            currSize = 4; 
        if(currType == Float)
            currSize = 8;

        Declaration* currDec = (yyvsp[0].dec);
        Sym* sym = gsymtab.lookup(currDec->name);
        if(currDec->type == Function) {
            Sym* retval = sym->nestedtable->lookup("RETVAL", currType, currDec->pointers);  
            sym->size = 0;
            sym->initval = NULL;
        }
        (yyval.dec) = (yyvsp[0].dec);
    }
#line 3127 "y.tab.c"
    break;

  case 113: /* declaration_list: declaration  */
#line 1321 "a9_220101002.y"
                {
        
    }
#line 3135 "y.tab.c"
    break;

  case 114: /* declaration_list: declaration_list declaration  */
#line 1324 "a9_220101002.y"
                                   {
        
    }
#line 3143 "y.tab.c"
    break;


#line 3147 "y.tab.c"

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

#line 1328 "a9_220101002.y"


void yyerror(string s) {
    cout<<"Error : "<<s<<" at line no : "<<yylineno<<" : "<<yytext<<"\n";
}

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
#line 1 "parser.y"

#include <stdio.h>

void yyerror(const char * msg);

extern int yylex(void);

#line 79 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_AUTO = 3,                       /* AUTO  */
  YYSYMBOL_DOUBLE = 4,                     /* DOUBLE  */
  YYSYMBOL_INT = 5,                        /* INT  */
  YYSYMBOL_STRUCT = 6,                     /* STRUCT  */
  YYSYMBOL_BREAK = 7,                      /* BREAK  */
  YYSYMBOL_ELSE = 8,                       /* ELSE  */
  YYSYMBOL_LONG = 9,                       /* LONG  */
  YYSYMBOL_SWITCH = 10,                    /* SWITCH  */
  YYSYMBOL_CASE = 11,                      /* CASE  */
  YYSYMBOL_ENUM = 12,                      /* ENUM  */
  YYSYMBOL_REGISTER = 13,                  /* REGISTER  */
  YYSYMBOL_TYPEDEF = 14,                   /* TYPEDEF  */
  YYSYMBOL_CHAR = 15,                      /* CHAR  */
  YYSYMBOL_EXTERN = 16,                    /* EXTERN  */
  YYSYMBOL_RETURN = 17,                    /* RETURN  */
  YYSYMBOL_UNION = 18,                     /* UNION  */
  YYSYMBOL_CONST = 19,                     /* CONST  */
  YYSYMBOL_FLOAT = 20,                     /* FLOAT  */
  YYSYMBOL_SHORT = 21,                     /* SHORT  */
  YYSYMBOL_UNSIGNED = 22,                  /* UNSIGNED  */
  YYSYMBOL_CONTINUE = 23,                  /* CONTINUE  */
  YYSYMBOL_FOR = 24,                       /* FOR  */
  YYSYMBOL_SIGNED = 25,                    /* SIGNED  */
  YYSYMBOL_VOID = 26,                      /* VOID  */
  YYSYMBOL_DEFAULT = 27,                   /* DEFAULT  */
  YYSYMBOL_GOTO = 28,                      /* GOTO  */
  YYSYMBOL_SIZEOF = 29,                    /* SIZEOF  */
  YYSYMBOL_VOLATILE = 30,                  /* VOLATILE  */
  YYSYMBOL_DO = 31,                        /* DO  */
  YYSYMBOL_IF = 32,                        /* IF  */
  YYSYMBOL_STATIC = 33,                    /* STATIC  */
  YYSYMBOL_WHILE = 34,                     /* WHILE  */
  YYSYMBOL_IDENTIFIER = 35,                /* IDENTIFIER  */
  YYSYMBOL_INTEGER_CONSTANT = 36,          /* INTEGER_CONSTANT  */
  YYSYMBOL_FLOATING_CONSTANT = 37,         /* FLOATING_CONSTANT  */
  YYSYMBOL_ENUMERATION_CONSTANT = 38,      /* ENUMERATION_CONSTANT  */
  YYSYMBOL_CHARACTER_CONSTANT = 39,        /* CHARACTER_CONSTANT  */
  YYSYMBOL_STRING_LITERAL = 40,            /* STRING_LITERAL  */
  YYSYMBOL_LBRACKET = 41,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 42,                  /* RBRACKET  */
  YYSYMBOL_LPAREN = 43,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 44,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 45,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 46,                    /* RBRACE  */
  YYSYMBOL_COMMA = 47,                     /* COMMA  */
  YYSYMBOL_DOT = 48,                       /* DOT  */
  YYSYMBOL_ARROW = 49,                     /* ARROW  */
  YYSYMBOL_INCREMENT = 50,                 /* INCREMENT  */
  YYSYMBOL_DECREMENT = 51,                 /* DECREMENT  */
  YYSYMBOL_AND = 52,                       /* AND  */
  YYSYMBOL_STAR = 53,                      /* STAR  */
  YYSYMBOL_PLUS = 54,                      /* PLUS  */
  YYSYMBOL_MINUS = 55,                     /* MINUS  */
  YYSYMBOL_TILDE = 56,                     /* TILDE  */
  YYSYMBOL_EXCLAMATION = 57,               /* EXCLAMATION  */
  YYSYMBOL_SLASH = 58,                     /* SLASH  */
  YYSYMBOL_PERCENT = 59,                   /* PERCENT  */
  YYSYMBOL_LSHIFT = 60,                    /* LSHIFT  */
  YYSYMBOL_RSHIFT = 61,                    /* RSHIFT  */
  YYSYMBOL_LESS_THAN = 62,                 /* LESS_THAN  */
  YYSYMBOL_GREATER_THAN = 63,              /* GREATER_THAN  */
  YYSYMBOL_LESS_THAN_EQUAL = 64,           /* LESS_THAN_EQUAL  */
  YYSYMBOL_GREATER_THAN_EQUAL = 65,        /* GREATER_THAN_EQUAL  */
  YYSYMBOL_EQUAL = 66,                     /* EQUAL  */
  YYSYMBOL_NOT_EQUAL = 67,                 /* NOT_EQUAL  */
  YYSYMBOL_EQUAL_EQUAL = 68,               /* EQUAL_EQUAL  */
  YYSYMBOL_STAR_EQUAL = 69,                /* STAR_EQUAL  */
  YYSYMBOL_SLASH_EQUAL = 70,               /* SLASH_EQUAL  */
  YYSYMBOL_PERCENT_EQUAL = 71,             /* PERCENT_EQUAL  */
  YYSYMBOL_PLUS_EQUAL = 72,                /* PLUS_EQUAL  */
  YYSYMBOL_MINUS_EQUAL = 73,               /* MINUS_EQUAL  */
  YYSYMBOL_LSHIFT_EQUAL = 74,              /* LSHIFT_EQUAL  */
  YYSYMBOL_RSHIFT_EQUAL = 75,              /* RSHIFT_EQUAL  */
  YYSYMBOL_AND_EQUAL = 76,                 /* AND_EQUAL  */
  YYSYMBOL_XOR_EQUAL = 77,                 /* XOR_EQUAL  */
  YYSYMBOL_OR_EQUAL = 78,                  /* OR_EQUAL  */
  YYSYMBOL_PLUS_PLUS = 79,                 /* PLUS_PLUS  */
  YYSYMBOL_MINUS_MINUS = 80,               /* MINUS_MINUS  */
  YYSYMBOL_COLON = 81,                     /* COLON  */
  YYSYMBOL_QUESTION = 82,                  /* QUESTION  */
  YYSYMBOL_OR_OR = 83,                     /* OR_OR  */
  YYSYMBOL_AND_AND = 84,                   /* AND_AND  */
  YYSYMBOL_OR = 85,                        /* OR  */
  YYSYMBOL_XOR = 86,                       /* XOR  */
  YYSYMBOL_ELLIPSIS = 87,                  /* ELLIPSIS  */
  YYSYMBOL_SEMICOLON = 88,                 /* SEMICOLON  */
  YYSYMBOL_HASH = 89,                      /* HASH  */
  YYSYMBOL_HASH_HASH = 90,                 /* HASH_HASH  */
  YYSYMBOL_TYPEDEF_NAME = 91,              /* TYPEDEF_NAME  */
  YYSYMBOL_THEN = 92,                      /* THEN  */
  YYSYMBOL_YYACCEPT = 93,                  /* $accept  */
  YYSYMBOL_program = 94,                   /* program  */
  YYSYMBOL_95_primary_expression = 95,     /* primary-expression  */
  YYSYMBOL_96_postfix_expression = 96,     /* postfix-expression  */
  YYSYMBOL_97_unary_expression = 97,       /* unary-expression  */
  YYSYMBOL_98_unary_operator = 98,         /* unary-operator  */
  YYSYMBOL_99_cast_expression = 99,        /* cast-expression  */
  YYSYMBOL_100_multiplicative_expression = 100, /* multiplicative-expression  */
  YYSYMBOL_101_additive_expression = 101,  /* additive-expression  */
  YYSYMBOL_102_shift_expression = 102,     /* shift-expression  */
  YYSYMBOL_103_relational_expression = 103, /* relational-expression  */
  YYSYMBOL_104_equality_expression = 104,  /* equality-expression  */
  YYSYMBOL_105_AND_expression = 105,       /* AND-expression  */
  YYSYMBOL_106_exclusive_OR_expresion = 106, /* exclusive-OR-expresion  */
  YYSYMBOL_107_inclusive_OR_expression = 107, /* inclusive-OR-expression  */
  YYSYMBOL_108_logical_AND_expression = 108, /* logical-AND-expression  */
  YYSYMBOL_109_logical_OR_expression = 109, /* logical-OR-expression  */
  YYSYMBOL_110_conditional_expression = 110, /* conditional-expression  */
  YYSYMBOL_111_assignement_expression = 111, /* assignement-expression  */
  YYSYMBOL_112_assignement_operator = 112, /* assignement-operator  */
  YYSYMBOL_expression = 113,               /* expression  */
  YYSYMBOL_114_constant_expression = 114,  /* constant-expression  */
  YYSYMBOL_declaration = 115,              /* declaration  */
  YYSYMBOL_116_declaration_specifiers = 116, /* declaration-specifiers  */
  YYSYMBOL_117_init_declarator_list = 117, /* init-declarator-list  */
  YYSYMBOL_118_init_declarator = 118,      /* init-declarator  */
  YYSYMBOL_119_storage_class_specifier = 119, /* storage-class-specifier  */
  YYSYMBOL_120_type_specifier = 120,       /* type-specifier  */
  YYSYMBOL_121_struct_or_union_specifier = 121, /* struct-or-union-specifier  */
  YYSYMBOL_122_struct_or_union = 122,      /* struct-or-union  */
  YYSYMBOL_123_struct_declaration_list = 123, /* struct-declaration-list  */
  YYSYMBOL_124_struct_declaration = 124,   /* struct-declaration  */
  YYSYMBOL_125_struct_declarator_list = 125, /* struct-declarator-list  */
  YYSYMBOL_126_struct_declarator = 126,    /* struct-declarator  */
  YYSYMBOL_127_declaration_list = 127,     /* declaration-list  */
  YYSYMBOL_128_enum_specifier = 128,       /* enum-specifier  */
  YYSYMBOL_129_enumerator_list = 129,      /* enumerator-list  */
  YYSYMBOL_enumerator = 130,               /* enumerator  */
  YYSYMBOL_131_type_qualifier = 131,       /* type-qualifier  */
  YYSYMBOL_declarator = 132,               /* declarator  */
  YYSYMBOL_133_direct_declarator = 133,    /* direct-declarator  */
  YYSYMBOL_pointer = 134,                  /* pointer  */
  YYSYMBOL_135_type_qualifier_list = 135,  /* type-qualifier-list  */
  YYSYMBOL_136_parameter_type_list = 136,  /* parameter-type-list  */
  YYSYMBOL_137_parameter_list = 137,       /* parameter-list  */
  YYSYMBOL_138_parameter_declaration = 138, /* parameter-declaration  */
  YYSYMBOL_139_type_name = 139,            /* type-name  */
  YYSYMBOL_140_abstract_declarator = 140,  /* abstract-declarator  */
  YYSYMBOL_141_direct_abstract_declarator = 141, /* direct-abstract-declarator  */
  YYSYMBOL_constant = 142,                 /* constant  */
  YYSYMBOL_143_specifier_qualifier_list = 143, /* specifier-qualifier-list  */
  YYSYMBOL_144_typedef_name = 144,         /* typedef-name  */
  YYSYMBOL_145_identifier_list = 145,      /* identifier-list  */
  YYSYMBOL_initializer = 146,              /* initializer  */
  YYSYMBOL_statement = 147,                /* statement  */
  YYSYMBOL_148_statement_list = 148,       /* statement-list  */
  YYSYMBOL_149_labeled_statement = 149,    /* labeled-statement  */
  YYSYMBOL_150_compound_statement = 150,   /* compound-statement  */
  YYSYMBOL_151_expression_statement = 151, /* expression-statement  */
  YYSYMBOL_152_selection_statement = 152,  /* selection-statement  */
  YYSYMBOL_153_iteration_statement = 153,  /* iteration-statement  */
  YYSYMBOL_154_jump_statement = 154,       /* jump-statement  */
  YYSYMBOL_155_translation_unit = 155,     /* translation-unit  */
  YYSYMBOL_156_external_declaration = 156, /* external-declaration  */
  YYSYMBOL_157_function_definition = 157,  /* function-definition  */
  YYSYMBOL_158_initializer_list = 158,     /* initializer-list  */
  YYSYMBOL_159_argument_expression_list = 159 /* argument-expression-list  */
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
typedef yytype_int16 yy_state_t;

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

#if 1

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
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  46
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1429

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  93
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  67
/* YYNRULES -- Number of rules.  */
#define YYNRULES  217
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  353

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   347


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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    40,    40,    48,    49,    50,    51,    57,    58,    59,
      60,    61,    62,    63,    64,    70,    71,    72,    73,    74,
      75,    79,    80,    81,    82,    83,    84,    90,    91,    97,
      98,    99,   100,   106,   107,   108,   114,   115,   116,   122,
     123,   124,   125,   126,   132,   133,   134,   140,   141,   147,
     148,   154,   155,   161,   162,   168,   169,   175,   176,   182,
     183,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   203,   204,   210,   216,   217,   221,   222,   223,
     224,   225,   226,   230,   231,   235,   236,   242,   243,   244,
     245,   246,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   269,   270,   271,   275,   276,   280,
     281,   285,   289,   290,   294,   295,   296,   300,   301,   307,
     308,   309,   313,   314,   318,   319,   325,   326,   332,   333,
     337,   338,   339,   340,   341,   342,   343,   347,   348,   349,
     350,   354,   355,   359,   360,   364,   365,   369,   370,   371,
     377,   378,   382,   383,   384,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   403,   404,   405,   406,   411,   412,
     413,   414,   418,   422,   423,   427,   428,   429,   433,   434,
     435,   436,   437,   438,   442,   443,   447,   448,   449,   453,
     454,   455,   456,   460,   461,   465,   466,   467,   471,   472,
     473,   477,   478,   479,   480,   481,   485,   486,   490,   491,
     495,   496,   497,   498,   502,   503,   506,   507
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "AUTO", "DOUBLE",
  "INT", "STRUCT", "BREAK", "ELSE", "LONG", "SWITCH", "CASE", "ENUM",
  "REGISTER", "TYPEDEF", "CHAR", "EXTERN", "RETURN", "UNION", "CONST",
  "FLOAT", "SHORT", "UNSIGNED", "CONTINUE", "FOR", "SIGNED", "VOID",
  "DEFAULT", "GOTO", "SIZEOF", "VOLATILE", "DO", "IF", "STATIC", "WHILE",
  "IDENTIFIER", "INTEGER_CONSTANT", "FLOATING_CONSTANT",
  "ENUMERATION_CONSTANT", "CHARACTER_CONSTANT", "STRING_LITERAL",
  "LBRACKET", "RBRACKET", "LPAREN", "RPAREN", "LBRACE", "RBRACE", "COMMA",
  "DOT", "ARROW", "INCREMENT", "DECREMENT", "AND", "STAR", "PLUS", "MINUS",
  "TILDE", "EXCLAMATION", "SLASH", "PERCENT", "LSHIFT", "RSHIFT",
  "LESS_THAN", "GREATER_THAN", "LESS_THAN_EQUAL", "GREATER_THAN_EQUAL",
  "EQUAL", "NOT_EQUAL", "EQUAL_EQUAL", "STAR_EQUAL", "SLASH_EQUAL",
  "PERCENT_EQUAL", "PLUS_EQUAL", "MINUS_EQUAL", "LSHIFT_EQUAL",
  "RSHIFT_EQUAL", "AND_EQUAL", "XOR_EQUAL", "OR_EQUAL", "PLUS_PLUS",
  "MINUS_MINUS", "COLON", "QUESTION", "OR_OR", "AND_AND", "OR", "XOR",
  "ELLIPSIS", "SEMICOLON", "HASH", "HASH_HASH", "TYPEDEF_NAME", "THEN",
  "$accept", "program", "primary-expression", "postfix-expression",
  "unary-expression", "unary-operator", "cast-expression",
  "multiplicative-expression", "additive-expression", "shift-expression",
  "relational-expression", "equality-expression", "AND-expression",
  "exclusive-OR-expresion", "inclusive-OR-expression",
  "logical-AND-expression", "logical-OR-expression",
  "conditional-expression", "assignement-expression",
  "assignement-operator", "expression", "constant-expression",
  "declaration", "declaration-specifiers", "init-declarator-list",
  "init-declarator", "storage-class-specifier", "type-specifier",
  "struct-or-union-specifier", "struct-or-union",
  "struct-declaration-list", "struct-declaration",
  "struct-declarator-list", "struct-declarator", "declaration-list",
  "enum-specifier", "enumerator-list", "enumerator", "type-qualifier",
  "declarator", "direct-declarator", "pointer", "type-qualifier-list",
  "parameter-type-list", "parameter-list", "parameter-declaration",
  "type-name", "abstract-declarator", "direct-abstract-declarator",
  "constant", "specifier-qualifier-list", "typedef-name",
  "identifier-list", "initializer", "statement", "statement-list",
  "labeled-statement", "compound-statement", "expression-statement",
  "selection-statement", "iteration-statement", "jump-statement",
  "translation-unit", "external-declaration", "function-definition",
  "initializer-list", "argument-expression-list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-201)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     555,  -201,  -201,  -201,  -201,  -201,     6,  -201,  -201,  -201,
    -201,  -201,  -201,  -201,  -201,  -201,  -201,  -201,  -201,  -201,
    -201,    31,    42,  -201,    14,  -201,   -20,   271,   271,  -201,
      22,  -201,   271,   671,   109,    35,  -201,   555,  -201,  -201,
      48,    66,    68,  -201,  -201,    42,  -201,  -201,   -36,  -201,
     597,  -201,  -201,    77,   897,  -201,   302,  -201,   -20,   671,
    -201,  1146,   635,   109,  -201,    66,    64,    40,  -201,  -201,
    -201,  -201,    31,  -201,  1175,   671,  -201,   897,   897,   842,
    -201,   897,    -5,   108,    93,  1291,  1059,   112,   142,   137,
     194,  1320,  1030,   196,   208,   156,  -201,  -201,  -201,  -201,
    -201,   786,  -201,  -201,  -201,  -201,  -201,  -201,  -201,  1349,
    1349,  -201,  -201,   154,   294,  1291,  -201,    30,    91,   128,
      62,   158,   202,   171,   174,   176,   145,  -201,  -201,   -25,
     391,  -201,  -201,   914,  -201,  -201,  -201,  -201,  -201,  -201,
     192,  -201,  -201,  -201,  -201,  -201,  -201,   219,  -201,  -201,
     141,   220,   216,  -201,     9,   185,  1291,  -201,    66,  -201,
    1175,  -201,  -201,  -201,   874,  -201,  -201,  -201,  -201,  1291,
     -23,  -201,   184,  -201,  1291,   186,  -201,   -13,  -201,  1088,
    1030,   183,   786,  -201,   234,  1291,  1291,  1030,    97,   229,
      70,  1291,  -201,  -201,  1291,  1204,   243,   246,  -201,  -201,
    -201,  -201,  -201,  -201,  -201,  -201,  -201,  -201,  -201,  -201,
    -201,  1291,  -201,  1291,  1291,  1291,  1291,  1291,  1291,  1291,
    1291,  1291,  1291,  1291,  1291,  1291,  1291,  1291,  1291,  1291,
    1291,  1291,  1291,  -201,  -201,   972,  -201,  -201,  -201,  1233,
     471,  -201,    94,  -201,   165,  -201,   709,  -201,   247,  -201,
    -201,  -201,  -201,   187,  -201,  -201,    -5,  -201,  1291,   134,
    1030,  -201,  1088,  -201,  -201,   244,   251,   139,   146,  -201,
    -201,  1291,   513,   180,  -201,    60,  -201,  -201,   163,  -201,
    -201,  -201,  -201,  -201,  -201,    30,    30,    91,    91,   128,
     128,   128,   128,    62,    62,   158,   202,   171,   174,    -1,
     176,  -201,  -201,  -201,   253,  -201,   254,   255,   165,  1262,
     745,  -201,  -201,  -201,  -201,  1117,  -201,  -201,  1030,  -201,
     256,  -201,  1291,  1030,  1030,  -201,  -201,  -201,  1291,  1291,
    -201,  -201,  -201,  -201,   260,  -201,   259,  -201,  -201,  -201,
    1030,   173,   335,  -201,  -201,  -201,  -201,  -201,  -201,   258,
    1030,  -201,  -201
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    90,    98,    95,   107,    96,     0,    91,    87,    93,
      88,   108,   126,    97,    94,   100,    99,    92,   127,    89,
     130,     0,   137,   172,     0,   209,     0,    77,    79,   101,
       0,   102,    81,     0,   129,     0,   103,     2,   206,   208,
     121,     0,     0,   141,   138,   139,     1,    75,     0,    83,
      85,    78,    80,   105,     0,    82,     0,   117,     0,     0,
     213,     0,     0,   128,   207,     0,   124,     0,   122,   131,
     142,   140,     0,    76,     0,     0,   211,     0,   168,     0,
     109,   169,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     3,   164,   165,   166,   167,
       5,     0,   189,    21,    22,    23,    24,    25,    26,     0,
       0,   193,     7,    15,    27,     0,    29,    33,    36,    39,
      44,    47,    49,    51,    53,    55,    57,    59,    72,     0,
       0,     4,   184,     0,   178,   179,   180,   181,   182,   183,
      85,   118,   212,     3,   132,    27,    74,     0,   173,   135,
     149,     0,   143,   145,     0,     0,     0,   119,     0,    84,
       0,   175,    86,   210,     0,   170,   104,   110,   171,     0,
       0,   112,   114,   203,     0,     0,   204,     0,   202,     0,
       0,     0,     0,    19,     0,     0,     0,     0,     0,     0,
     151,     0,    16,    17,     0,     0,     0,     0,    13,    14,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,    18,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   194,   191,     0,   190,   185,   133,     0,
       0,   147,   152,   148,   154,   134,     0,   136,     0,   120,
     125,   123,   214,     0,   106,   115,     0,   111,     0,     0,
       0,   205,     0,   188,   201,     0,     0,     0,     0,   186,
       6,     0,     0,   152,   150,     0,     9,   216,     0,    11,
      12,    60,    30,    31,    32,    34,    35,    37,    38,    40,
      41,    42,    43,    46,    45,    48,    50,    52,    54,     0,
      56,    73,   192,   156,     0,   160,     0,     0,   153,     0,
       0,   144,   146,   174,   176,     0,   113,   116,     0,   187,
       0,    20,     0,     0,     0,    28,     8,    10,     0,     0,
     157,   161,   155,   158,     0,   162,     0,   177,   215,   197,
       0,     0,   195,   198,   217,    58,   159,   163,   200,     0,
       0,   199,   196
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -201,  -201,  -201,  -201,   -60,  -201,   -94,    25,    26,    -7,
      23,   118,   122,   123,   121,   130,  -201,   -59,   -62,  -201,
     -43,   -66,    10,     0,  -201,   280,  -201,    27,  -201,  -201,
     276,   -70,  -201,   117,    21,  -201,   309,   217,    37,   -18,
     -30,   -16,  -201,   -55,  -201,   131,   197,  -111,  -200,  -201,
     -65,  -201,  -201,  -140,   -88,   248,  -201,   -15,  -162,  -201,
    -201,  -201,  -201,   339,  -201,  -201,  -201
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    24,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   211,
     129,   147,    57,    58,    48,    49,    27,    28,    29,    30,
      79,    80,   170,   171,    59,    31,    67,    68,    32,    33,
      34,    35,    45,   306,   152,   153,   189,   307,   244,   131,
      82,    36,   154,   162,   132,   133,   134,   135,   136,   137,
     138,   139,    37,    38,    39,   253,   278
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      26,   145,   146,    42,   184,    63,    44,   151,    50,   167,
      25,    72,   161,   165,    46,    20,   168,   262,    60,   175,
     252,   212,   232,    21,   256,   145,   146,    51,    52,    71,
      20,   183,    55,    22,   232,    76,   190,    26,    21,   243,
     140,    40,   308,   177,   142,   237,   232,    25,    22,   192,
     193,    41,    73,   247,   140,   145,   248,    53,   188,    43,
     163,    12,   150,   233,   172,   257,    20,    54,    47,   141,
      20,    75,    18,   308,    21,   261,   169,   130,    21,   274,
     329,    78,    70,   213,    22,   141,   157,   158,   214,   215,
     250,    81,   263,    65,   167,    22,   145,   146,   161,   269,
     320,    66,   326,   255,    78,    78,    78,   232,    78,   145,
     146,   239,    69,   272,    81,    81,    81,   190,    81,   282,
     283,   284,    77,    22,   220,   221,   222,   223,    78,    20,
     156,   259,   241,   277,   242,   239,   174,   240,    81,   188,
     141,   270,   267,   268,   232,   216,   217,   237,   188,   281,
      61,   275,    62,   145,   145,   145,   145,   145,   145,   145,
     145,   145,   145,   145,   145,   145,   145,   145,   145,   145,
     301,   145,   319,   304,   273,   338,    20,   325,   318,   145,
     146,   232,   239,   323,   240,   179,   232,   299,   218,   219,
     324,    78,   317,   232,    22,   194,   173,   195,   145,   146,
     178,    81,   196,   197,   198,   199,   309,   327,   310,    78,
     328,   145,    63,   289,   290,   291,   292,   349,   180,    81,
     232,   239,    42,   272,   242,   224,   225,   230,   231,   181,
     339,   249,   158,   314,   315,   342,   343,   187,   172,   185,
     150,   285,   286,   334,   287,   288,   150,   293,   294,   145,
     146,   186,   348,   161,   226,   336,   273,   227,    74,   228,
     229,   238,   352,   246,   245,   258,   344,   260,   266,   145,
     345,   264,   150,   271,     1,     2,     3,     4,   279,   341,
       5,   280,   313,     6,     7,     8,     9,    10,   321,    11,
      12,    13,    14,    15,   322,   330,    16,    17,   331,   332,
     340,    18,   346,   347,    19,     1,     2,     3,     4,    83,
     150,     5,    84,    85,     6,     7,     8,     9,    10,    86,
      11,    12,    13,    14,    15,    87,    88,    16,    17,    89,
      90,    91,    18,    92,    93,    19,    94,    95,    96,    97,
      98,    99,   100,   350,   295,   101,   351,    56,   102,   296,
     298,   297,   159,   164,   103,   104,   105,   106,   107,   108,
     200,   300,    23,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   316,   155,   251,    64,   312,   235,   265,
       0,   109,   110,     0,     0,     0,     0,     0,     0,     0,
     111,     0,     0,    23,     1,     2,     3,     4,    83,     0,
       5,    84,    85,     6,     7,     8,     9,    10,    86,    11,
      12,    13,    14,    15,    87,    88,    16,    17,    89,    90,
      91,    18,    92,    93,    19,    94,    95,    96,    97,    98,
      99,   100,     0,     0,   101,     0,    56,   234,     0,     0,
       0,     0,     0,   103,   104,   105,   106,   107,   108,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     109,   110,     0,     0,     1,     2,     3,     4,     0,   111,
       5,     0,    23,     6,     7,     8,     9,    10,     0,    11,
      12,    13,    14,    15,     0,     0,    16,    17,     0,     0,
       0,    18,     0,     0,    19,     0,    20,     0,     0,     0,
       0,     0,   239,     0,   240,   305,     1,     2,     3,     4,
       0,     0,     5,     0,    22,     6,     7,     8,     9,    10,
       0,    11,    12,    13,    14,    15,     0,     0,    16,    17,
       0,     0,     0,    18,     0,     0,    19,     0,     0,     0,
       0,     0,     0,     0,   239,     0,   272,   305,     1,     2,
       3,     4,    23,     0,     5,     0,    22,     6,     7,     8,
       9,    10,     0,    11,    12,    13,    14,    15,     0,     0,
      16,    17,     0,     0,     0,    18,     0,     0,    19,     0,
      20,     0,     0,     0,     0,     0,     0,     0,    21,     0,
       1,     2,     3,     4,    23,     0,     5,     0,    22,     6,
       7,     8,     9,    10,     0,    11,    12,    13,    14,    15,
       0,     0,    16,    17,     0,     0,     0,    18,     0,     0,
      19,     0,     0,     0,     0,     0,     0,     0,     1,     2,
       3,     4,    56,     0,     5,     0,    23,     6,     7,     8,
       9,    10,     0,    11,    12,    13,    14,    15,     0,     0,
      16,    17,     0,    74,     0,    18,     0,     0,    19,     0,
     148,     0,     0,     0,     1,     2,     3,     4,     0,   149,
       5,     0,     0,     6,     7,     8,     9,    10,    23,    11,
      12,    13,    14,    15,     0,     0,    16,    17,     0,     0,
       0,    18,     0,     0,    19,     0,     0,     0,     0,     0,
       0,     0,     1,     2,     3,     4,    56,     0,     5,     0,
       0,     6,     7,     8,     9,    10,    23,    11,    12,    13,
      14,    15,     0,     0,    16,    17,     0,     0,     0,    18,
       0,     0,    19,     0,     0,     0,     0,     0,     1,     2,
       3,     4,     0,     0,     5,     0,     0,     6,     7,     8,
       9,    10,    23,    11,    12,    13,    14,    15,     0,     0,
      16,    17,     0,     0,     0,    18,     0,     0,    19,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   335,
       2,     3,     4,     0,     0,     5,   311,     0,     6,     0,
      23,     9,     0,     0,    11,    12,    13,    14,    15,     0,
       0,    16,    17,     0,     0,    91,    18,     0,     0,     0,
       0,   143,    96,    97,    98,    99,   100,     0,     0,   101,
       0,     0,     0,     0,     0,     0,    23,     0,   103,   104,
     105,   106,   107,   108,     0,     0,     2,     3,     4,     0,
       0,     5,     0,     0,     6,     0,     0,     9,     0,     0,
      11,    12,    13,    14,    15,   109,   110,    16,    17,     0,
       0,     0,    18,     0,     0,     0,     0,    23,     2,     3,
       4,     0,     0,     5,     0,     0,     6,     0,   166,     9,
       0,     0,    11,    12,    13,    14,    15,     0,     0,    16,
      17,     2,     3,     4,    18,     0,     5,     0,     0,     6,
       0,     0,     9,     0,     0,    11,    12,    13,    14,    15,
     254,    83,    16,    17,    84,    85,     0,    18,     0,     0,
       0,    86,     0,    23,     0,     0,     0,    87,    88,     0,
       0,    89,    90,    91,     0,    92,    93,     0,    94,    95,
      96,    97,    98,    99,   100,     0,     0,   101,     0,    56,
     236,     0,     0,     0,     0,    23,   103,   104,   105,   106,
     107,   108,     0,     0,     0,     0,     0,     0,     0,    83,
       0,     0,    84,    85,     0,     0,     0,     0,    23,    86,
       0,     0,     0,   109,   110,    87,    88,     0,     0,    89,
      90,    91,   111,    92,    93,     0,    94,    95,    96,    97,
      98,    99,   100,     0,     0,   101,     0,    56,   302,     0,
       0,     0,     0,     0,   103,   104,   105,   106,   107,   108,
       0,     0,     0,     0,     0,     0,     0,    83,     0,     0,
      84,    85,     0,     0,     0,     0,     0,    86,     0,     0,
       0,   109,   110,    87,    88,     0,     0,    89,    90,    91,
     111,    92,    93,     0,    94,    95,    96,    97,    98,    99,
     100,     0,     0,   101,     0,    56,     0,     0,     0,     0,
       0,     0,   103,   104,   105,   106,   107,   108,    91,     0,
       0,     0,     0,     0,   143,    96,    97,    98,    99,   100,
       0,     0,   101,     0,     0,     0,     0,     0,     0,   109,
     110,   103,   104,   105,   106,   107,   108,    91,   111,     0,
       0,     0,     0,   143,    96,    97,    98,    99,   100,     0,
       0,   101,     0,     0,     0,     0,     0,     0,   109,   110,
     103,   104,   105,   106,   107,   108,    91,   176,     0,     0,
       0,     0,   143,    96,    97,    98,    99,   100,     0,     0,
     101,     0,   160,   337,     0,     0,     0,   109,   110,   103,
     104,   105,   106,   107,   108,    91,   111,     0,     0,     0,
       0,   143,    96,    97,    98,    99,   100,     0,   144,   101,
       0,     0,     0,     0,     0,     0,   109,   110,   103,   104,
     105,   106,   107,   108,    91,     0,     0,     0,     0,     0,
     143,    96,    97,    98,    99,   100,     0,     0,   101,     0,
     160,     0,     0,     0,     0,   109,   110,   103,   104,   105,
     106,   107,   108,    91,     0,     0,     0,     0,     0,   143,
      96,    97,    98,    99,   100,     0,     0,   101,   276,     0,
       0,     0,     0,     0,   109,   110,   103,   104,   105,   106,
     107,   108,    91,     0,     0,     0,     0,     0,   143,    96,
      97,    98,    99,   100,     0,   303,   101,     0,     0,     0,
       0,     0,     0,   109,   110,   103,   104,   105,   106,   107,
     108,    91,     0,     0,     0,     0,     0,   143,    96,    97,
      98,    99,   100,     0,   333,   101,     0,     0,     0,     0,
       0,     0,   109,   110,   103,   104,   105,   106,   107,   108,
      91,     0,     0,     0,     0,     0,   143,    96,    97,    98,
      99,   100,     0,     0,   101,     0,     0,     0,     0,     0,
       0,   109,   110,   103,   104,   105,   106,   107,   108,    91,
       0,     0,     0,     0,     0,   143,    96,    97,    98,    99,
     100,     0,     0,   182,     0,     0,     0,     0,     0,     0,
     109,   110,   103,   104,   105,   106,   107,   108,    91,     0,
       0,     0,     0,     0,   143,    96,    97,    98,    99,   100,
       0,     0,   191,     0,     0,     0,     0,     0,     0,   109,
     110,   103,   104,   105,   106,   107,   108,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   109,   110
};

static const yytype_int16 yycheck[] =
{
       0,    61,    61,    21,    92,    35,    22,    62,    26,    79,
       0,    47,    74,    78,     0,    35,    81,   179,    33,    85,
     160,   115,    47,    43,    47,    85,    85,    27,    28,    45,
      35,    91,    32,    53,    47,    50,   101,    37,    43,   150,
      58,    35,   242,    86,    59,   133,    47,    37,    53,   109,
     110,    45,    88,    44,    72,   115,    47,    35,   101,    22,
      75,    19,    62,    88,    82,    88,    35,    45,    88,    59,
      35,    50,    30,   273,    43,    88,    81,    56,    43,   190,
      81,    54,    45,    53,    53,    75,    46,    47,    58,    59,
     156,    54,   180,    45,   164,    53,   156,   156,   160,   187,
     262,    35,    42,   169,    77,    78,    79,    47,    81,   169,
     169,    41,    44,    43,    77,    78,    79,   182,    81,   213,
     214,   215,    45,    53,    62,    63,    64,    65,   101,    35,
      66,   174,   150,   195,   150,    41,    43,    43,   101,   182,
     130,    44,   185,   186,    47,    54,    55,   235,   191,   211,
      41,   194,    43,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     232,   231,   260,   239,   190,   315,    35,   271,    44,   239,
     239,    47,    41,    44,    43,    43,    47,   230,    60,    61,
      44,   164,   258,    47,    53,    41,    88,    43,   258,   258,
      88,   164,    48,    49,    50,    51,    41,    44,    43,   182,
      47,   271,   242,   220,   221,   222,   223,    44,    81,   182,
      47,    41,   240,    43,   240,    67,    68,    82,    83,    35,
     318,    46,    47,    46,    47,   323,   324,    81,   256,    43,
     240,   216,   217,   309,   218,   219,   246,   224,   225,   309,
     309,    43,   340,   315,    52,   310,   272,    86,    66,    85,
      84,    42,   350,    47,    44,    81,   328,    81,    34,   329,
     329,    88,   272,    44,     3,     4,     5,     6,    35,   322,
       9,    35,    35,    12,    13,    14,    15,    16,    44,    18,
      19,    20,    21,    22,    43,    42,    25,    26,    44,    44,
      44,    30,    42,    44,    33,     3,     4,     5,     6,     7,
     310,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,     8,   226,    43,    88,    45,    46,   227,
     229,   228,    72,    77,    52,    53,    54,    55,    56,    57,
      66,   231,    91,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,   256,    65,   158,    37,   246,   130,   182,
      -1,    79,    80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      88,    -1,    -1,    91,     3,     4,     5,     6,     7,    -1,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    -1,    -1,    43,    -1,    45,    46,    -1,    -1,
      -1,    -1,    -1,    52,    53,    54,    55,    56,    57,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      79,    80,    -1,    -1,     3,     4,     5,     6,    -1,    88,
       9,    -1,    91,    12,    13,    14,    15,    16,    -1,    18,
      19,    20,    21,    22,    -1,    -1,    25,    26,    -1,    -1,
      -1,    30,    -1,    -1,    33,    -1,    35,    -1,    -1,    -1,
      -1,    -1,    41,    -1,    43,    44,     3,     4,     5,     6,
      -1,    -1,     9,    -1,    53,    12,    13,    14,    15,    16,
      -1,    18,    19,    20,    21,    22,    -1,    -1,    25,    26,
      -1,    -1,    -1,    30,    -1,    -1,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    41,    -1,    43,    44,     3,     4,
       5,     6,    91,    -1,     9,    -1,    53,    12,    13,    14,
      15,    16,    -1,    18,    19,    20,    21,    22,    -1,    -1,
      25,    26,    -1,    -1,    -1,    30,    -1,    -1,    33,    -1,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,
       3,     4,     5,     6,    91,    -1,     9,    -1,    53,    12,
      13,    14,    15,    16,    -1,    18,    19,    20,    21,    22,
      -1,    -1,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,
      33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,    45,    -1,     9,    -1,    91,    12,    13,    14,
      15,    16,    -1,    18,    19,    20,    21,    22,    -1,    -1,
      25,    26,    -1,    66,    -1,    30,    -1,    -1,    33,    -1,
      35,    -1,    -1,    -1,     3,     4,     5,     6,    -1,    44,
       9,    -1,    -1,    12,    13,    14,    15,    16,    91,    18,
      19,    20,    21,    22,    -1,    -1,    25,    26,    -1,    -1,
      -1,    30,    -1,    -1,    33,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,    45,    -1,     9,    -1,
      -1,    12,    13,    14,    15,    16,    91,    18,    19,    20,
      21,    22,    -1,    -1,    25,    26,    -1,    -1,    -1,    30,
      -1,    -1,    33,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,    -1,    -1,     9,    -1,    -1,    12,    13,    14,
      15,    16,    91,    18,    19,    20,    21,    22,    -1,    -1,
      25,    26,    -1,    -1,    -1,    30,    -1,    -1,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
       4,     5,     6,    -1,    -1,     9,    87,    -1,    12,    -1,
      91,    15,    -1,    -1,    18,    19,    20,    21,    22,    -1,
      -1,    25,    26,    -1,    -1,    29,    30,    -1,    -1,    -1,
      -1,    35,    36,    37,    38,    39,    40,    -1,    -1,    43,
      -1,    -1,    -1,    -1,    -1,    -1,    91,    -1,    52,    53,
      54,    55,    56,    57,    -1,    -1,     4,     5,     6,    -1,
      -1,     9,    -1,    -1,    12,    -1,    -1,    15,    -1,    -1,
      18,    19,    20,    21,    22,    79,    80,    25,    26,    -1,
      -1,    -1,    30,    -1,    -1,    -1,    -1,    91,     4,     5,
       6,    -1,    -1,     9,    -1,    -1,    12,    -1,    46,    15,
      -1,    -1,    18,    19,    20,    21,    22,    -1,    -1,    25,
      26,     4,     5,     6,    30,    -1,     9,    -1,    -1,    12,
      -1,    -1,    15,    -1,    -1,    18,    19,    20,    21,    22,
      46,     7,    25,    26,    10,    11,    -1,    30,    -1,    -1,
      -1,    17,    -1,    91,    -1,    -1,    -1,    23,    24,    -1,
      -1,    27,    28,    29,    -1,    31,    32,    -1,    34,    35,
      36,    37,    38,    39,    40,    -1,    -1,    43,    -1,    45,
      46,    -1,    -1,    -1,    -1,    91,    52,    53,    54,    55,
      56,    57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,
      -1,    -1,    10,    11,    -1,    -1,    -1,    -1,    91,    17,
      -1,    -1,    -1,    79,    80,    23,    24,    -1,    -1,    27,
      28,    29,    88,    31,    32,    -1,    34,    35,    36,    37,
      38,    39,    40,    -1,    -1,    43,    -1,    45,    46,    -1,
      -1,    -1,    -1,    -1,    52,    53,    54,    55,    56,    57,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,    -1,    -1,
      10,    11,    -1,    -1,    -1,    -1,    -1,    17,    -1,    -1,
      -1,    79,    80,    23,    24,    -1,    -1,    27,    28,    29,
      88,    31,    32,    -1,    34,    35,    36,    37,    38,    39,
      40,    -1,    -1,    43,    -1,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    52,    53,    54,    55,    56,    57,    29,    -1,
      -1,    -1,    -1,    -1,    35,    36,    37,    38,    39,    40,
      -1,    -1,    43,    -1,    -1,    -1,    -1,    -1,    -1,    79,
      80,    52,    53,    54,    55,    56,    57,    29,    88,    -1,
      -1,    -1,    -1,    35,    36,    37,    38,    39,    40,    -1,
      -1,    43,    -1,    -1,    -1,    -1,    -1,    -1,    79,    80,
      52,    53,    54,    55,    56,    57,    29,    88,    -1,    -1,
      -1,    -1,    35,    36,    37,    38,    39,    40,    -1,    -1,
      43,    -1,    45,    46,    -1,    -1,    -1,    79,    80,    52,
      53,    54,    55,    56,    57,    29,    88,    -1,    -1,    -1,
      -1,    35,    36,    37,    38,    39,    40,    -1,    42,    43,
      -1,    -1,    -1,    -1,    -1,    -1,    79,    80,    52,    53,
      54,    55,    56,    57,    29,    -1,    -1,    -1,    -1,    -1,
      35,    36,    37,    38,    39,    40,    -1,    -1,    43,    -1,
      45,    -1,    -1,    -1,    -1,    79,    80,    52,    53,    54,
      55,    56,    57,    29,    -1,    -1,    -1,    -1,    -1,    35,
      36,    37,    38,    39,    40,    -1,    -1,    43,    44,    -1,
      -1,    -1,    -1,    -1,    79,    80,    52,    53,    54,    55,
      56,    57,    29,    -1,    -1,    -1,    -1,    -1,    35,    36,
      37,    38,    39,    40,    -1,    42,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    79,    80,    52,    53,    54,    55,    56,
      57,    29,    -1,    -1,    -1,    -1,    -1,    35,    36,    37,
      38,    39,    40,    -1,    42,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    79,    80,    52,    53,    54,    55,    56,    57,
      29,    -1,    -1,    -1,    -1,    -1,    35,    36,    37,    38,
      39,    40,    -1,    -1,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    79,    80,    52,    53,    54,    55,    56,    57,    29,
      -1,    -1,    -1,    -1,    -1,    35,    36,    37,    38,    39,
      40,    -1,    -1,    43,    -1,    -1,    -1,    -1,    -1,    -1,
      79,    80,    52,    53,    54,    55,    56,    57,    29,    -1,
      -1,    -1,    -1,    -1,    35,    36,    37,    38,    39,    40,
      -1,    -1,    43,    -1,    -1,    -1,    -1,    -1,    -1,    79,
      80,    52,    53,    54,    55,    56,    57,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    79,    80
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     9,    12,    13,    14,    15,
      16,    18,    19,    20,    21,    22,    25,    26,    30,    33,
      35,    43,    53,    91,    94,   115,   116,   119,   120,   121,
     122,   128,   131,   132,   133,   134,   144,   155,   156,   157,
      35,    45,   132,   131,   134,   135,     0,    88,   117,   118,
     132,   116,   116,    35,    45,   116,    45,   115,   116,   127,
     150,    41,    43,   133,   156,    45,    35,   129,   130,    44,
     131,   134,    47,    88,    66,   127,   150,    45,   120,   123,
     124,   131,   143,     7,    10,    11,    17,    23,    24,    27,
      28,    29,    31,    32,    34,    35,    36,    37,    38,    39,
      40,    43,    46,    52,    53,    54,    55,    56,    57,    79,
      80,    88,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   113,
     127,   142,   147,   148,   149,   150,   151,   152,   153,   154,
     132,   115,   150,    35,    42,    97,   110,   114,    35,    44,
     116,   136,   137,   138,   145,   129,    66,    46,    47,   118,
      45,   111,   146,   150,   123,   143,    46,   124,   143,    81,
     125,   126,   132,    88,    43,   114,    88,   113,    88,    43,
      81,    35,    43,    97,   147,    43,    43,    81,   113,   139,
     143,    43,    97,    97,    41,    43,    48,    49,    50,    51,
      66,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,   112,    99,    53,    58,    59,    54,    55,    60,    61,
      62,    63,    64,    65,    67,    68,    52,    86,    85,    84,
      82,    83,    47,    88,    46,   148,    46,   147,    42,    41,
      43,   132,   134,   140,   141,    44,    47,    44,    47,    46,
     114,   130,   146,   158,    46,   114,    47,    88,    81,   113,
      81,    88,   151,   147,    88,   139,    34,   113,   113,   147,
      44,    44,    43,   134,   140,   113,    44,   111,   159,    35,
      35,   111,    99,    99,    99,   100,   100,   101,   101,   102,
     102,   102,   102,   103,   103,   104,   105,   106,   107,   113,
     108,   111,    46,    42,   114,    44,   136,   140,   141,    41,
      43,    87,   138,    35,    46,    47,   126,   114,    44,   147,
     151,    44,    43,    44,    44,    99,    42,    44,    47,    81,
      42,    44,    44,    42,   114,    44,   136,    46,   146,   147,
      44,   113,   147,   147,   111,   110,    42,    44,   147,    44,
       8,    88,   147
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    93,    94,    95,    95,    95,    95,    96,    96,    96,
      96,    96,    96,    96,    96,    97,    97,    97,    97,    97,
      97,    98,    98,    98,    98,    98,    98,    99,    99,   100,
     100,   100,   100,   101,   101,   101,   102,   102,   102,   103,
     103,   103,   103,   103,   104,   104,   104,   105,   105,   106,
     106,   107,   107,   108,   108,   109,   109,   110,   110,   111,
     111,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   113,   113,   114,   115,   115,   116,   116,   116,
     116,   116,   116,   117,   117,   118,   118,   119,   119,   119,
     119,   119,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   121,   121,   121,   122,   122,   123,
     123,   124,   125,   125,   126,   126,   126,   127,   127,   128,
     128,   128,   129,   129,   130,   130,   131,   131,   132,   132,
     133,   133,   133,   133,   133,   133,   133,   134,   134,   134,
     134,   135,   135,   136,   136,   137,   137,   138,   138,   138,
     139,   139,   140,   140,   140,   141,   141,   141,   141,   141,
     141,   141,   141,   141,   142,   142,   142,   142,   143,   143,
     143,   143,   144,   145,   145,   146,   146,   146,   147,   147,
     147,   147,   147,   147,   148,   148,   149,   149,   149,   150,
     150,   150,   150,   151,   151,   152,   152,   152,   153,   153,
     153,   154,   154,   154,   154,   154,   155,   155,   156,   156,
     157,   157,   157,   157,   158,   158,   159,   159
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     3,     1,     4,     3,
       4,     3,     3,     2,     2,     1,     2,     2,     2,     2,
       4,     1,     1,     1,     1,     1,     1,     1,     4,     1,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     5,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     2,     3,     1,     2,     1,
       2,     1,     2,     1,     3,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     2,     5,     1,     1,     1,
       2,     3,     1,     3,     1,     2,     3,     1,     2,     4,
       5,     2,     1,     3,     1,     3,     1,     1,     2,     1,
       1,     3,     3,     4,     4,     3,     4,     1,     2,     2,
       3,     1,     2,     1,     3,     1,     3,     2,     2,     1,
       2,     1,     1,     2,     1,     3,     2,     3,     3,     4,
       2,     3,     3,     4,     1,     1,     1,     1,     1,     1,
       2,     2,     1,     1,     3,     1,     3,     4,     1,     1,
       1,     1,     1,     1,     1,     2,     3,     4,     3,     2,
       3,     3,     4,     1,     2,     5,     7,     5,     5,     7,
       6,     3,     2,     2,     2,     3,     1,     2,     1,     1,
       4,     3,     3,     2,     1,     3,     1,     3
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

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
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
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
  YYLTYPE *yylloc;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
      yyerror_range[1] = yylloc;
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
  *++yylsp = yylloc;

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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {

#line 2106 "parser.tab.c"

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
  *++yylsp = yyloc;

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
      {
        yypcontext_t yyctx
          = {yyssp, yytoken, &yylloc};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  yyerror_range[1] = yylloc;
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
                      yytoken, &yylval, &yylloc);
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 510 "parser.y"


void yyerror(const char *msg) {
	fprintf(stderr, "Error: %s\n", msg);
}

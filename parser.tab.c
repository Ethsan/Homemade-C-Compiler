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

void yyerror (const char * msg);

#line 75 "parser.tab.c"

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
  YYSYMBOL_TYPEDEF_NAME = 89,              /* TYPEDEF_NAME  */
  YYSYMBOL_THEN = 90,                      /* THEN  */
  YYSYMBOL_YYACCEPT = 91,                  /* $accept  */
  YYSYMBOL_program = 92,                   /* program  */
  YYSYMBOL_93_primary_expression = 93,     /* primary-expression  */
  YYSYMBOL_constant = 94,                  /* constant  */
  YYSYMBOL_expression = 95,                /* expression  */
  YYSYMBOL_96_assignement_expression = 96, /* assignement-expression  */
  YYSYMBOL_97_assignement_operator = 97,   /* assignement-operator  */
  YYSYMBOL_98_unary_expression = 98,       /* unary-expression  */
  YYSYMBOL_99_unary_operator = 99,         /* unary-operator  */
  YYSYMBOL_100_conditional_expression = 100, /* conditional-expression  */
  YYSYMBOL_101_logical_OR_expression = 101, /* logical-OR-expression  */
  YYSYMBOL_102_logical_AND_expression = 102, /* logical-AND-expression  */
  YYSYMBOL_103_inclusive_OR_expression = 103, /* inclusive-OR-expression  */
  YYSYMBOL_104_exclusive_OR_expresion = 104, /* exclusive-OR-expresion  */
  YYSYMBOL_105_AND_expression = 105,       /* AND-expression  */
  YYSYMBOL_106_equality_expression = 106,  /* equality-expression  */
  YYSYMBOL_107_relational_expression = 107, /* relational-expression  */
  YYSYMBOL_108_shift_expression = 108,     /* shift-expression  */
  YYSYMBOL_109_additive_expression = 109,  /* additive-expression  */
  YYSYMBOL_110_multiplicative_expression = 110, /* multiplicative-expression  */
  YYSYMBOL_111_cast_expression = 111,      /* cast-expression  */
  YYSYMBOL_112_type_name = 112,            /* type-name  */
  YYSYMBOL_113_abstract_declarator = 113,  /* abstract-declarator  */
  YYSYMBOL_pointer = 114,                  /* pointer  */
  YYSYMBOL_115_type_qualifier_list = 115,  /* type-qualifier-list  */
  YYSYMBOL_116_type_qualifier = 116,       /* type-qualifier  */
  YYSYMBOL_117_direct_abstract_declarator = 117, /* direct-abstract-declarator  */
  YYSYMBOL_118_parameter_type_list = 118,  /* parameter-type-list  */
  YYSYMBOL_119_parameter_list = 119,       /* parameter-list  */
  YYSYMBOL_120_parameter_declaration = 120, /* parameter-declaration  */
  YYSYMBOL_121_specifier_qualifier_list = 121, /* specifier-qualifier-list  */
  YYSYMBOL_declaration = 122,              /* declaration  */
  YYSYMBOL_123_declaration_list = 123,     /* declaration-list  */
  YYSYMBOL_124_declaration_specifiers = 124, /* declaration-specifiers  */
  YYSYMBOL_125_init_declarator_list = 125, /* init-declarator-list  */
  YYSYMBOL_126_init_declarator = 126,      /* init-declarator  */
  YYSYMBOL_127_storage_class_specifier = 127, /* storage-class-specifier  */
  YYSYMBOL_128_type_specifier = 128,       /* type-specifier  */
  YYSYMBOL_129_typedef_name = 129,         /* typedef-name  */
  YYSYMBOL_130_struct_or_union_specifier = 130, /* struct-or-union-specifier  */
  YYSYMBOL_131_struct_or_union = 131,      /* struct-or-union  */
  YYSYMBOL_132_struct_declaration_list = 132, /* struct-declaration-list  */
  YYSYMBOL_133_struct_declaration = 133,   /* struct-declaration  */
  YYSYMBOL_134_struct_declarator_list = 134, /* struct-declarator-list  */
  YYSYMBOL_135_struct_declarator = 135,    /* struct-declarator  */
  YYSYMBOL_declarator = 136,               /* declarator  */
  YYSYMBOL_137_direct_declarator = 137,    /* direct-declarator  */
  YYSYMBOL_138_identifier_list = 138,      /* identifier-list  */
  YYSYMBOL_initializer = 139,              /* initializer  */
  YYSYMBOL_140_constant_expression = 140,  /* constant-expression  */
  YYSYMBOL_141_enum_specifier = 141,       /* enum-specifier  */
  YYSYMBOL_statement = 142,                /* statement  */
  YYSYMBOL_143_statement_list = 143,       /* statement-list  */
  YYSYMBOL_144_labeled_statement = 144,    /* labeled-statement  */
  YYSYMBOL_145_compound_statement = 145,   /* compound-statement  */
  YYSYMBOL_146_expression_statement = 146, /* expression-statement  */
  YYSYMBOL_147_selection_statement = 147,  /* selection-statement  */
  YYSYMBOL_148_iteration_statement = 148,  /* iteration-statement  */
  YYSYMBOL_149_jump_statement = 149,       /* jump-statement  */
  YYSYMBOL_150_translation_unit = 150,     /* translation-unit  */
  YYSYMBOL_151_external_declaration = 151, /* external-declaration  */
  YYSYMBOL_152_function_definition = 152,  /* function-definition  */
  YYSYMBOL_153_enumerator_list = 153,      /* enumerator-list  */
  YYSYMBOL_enumerator = 154,               /* enumerator  */
  YYSYMBOL_155_initializer_list = 155,     /* initializer-list  */
  YYSYMBOL_156_postfix_expression = 156,   /* postfix-expression  */
  YYSYMBOL_157_argument_expression_list = 157 /* argument-expression-list  */
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
#define YYFINAL  46
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1416

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  91
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  67
/* YYNRULES -- Number of rules.  */
#define YYNRULES  217
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  353

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   345


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
      85,    86,    87,    88,    89,    90
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    31,    31,    35,    36,    37,    38,    42,    43,    44,
      45,    49,    50,    54,    55,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    73,    74,    75,    76,
      77,    78,    82,    83,    84,    85,    86,    87,    91,    92,
      96,    97,   101,   102,   106,   107,   110,   111,   115,   116,
     120,   121,   122,   125,   126,   127,   128,   129,   133,   134,
     135,   139,   140,   141,   145,   146,   147,   148,   152,   153,
     157,   158,   162,   163,   164,   168,   169,   170,   171,   175,
     176,   180,   181,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   197,   198,   202,   203,   207,   208,   209,   213,
     214,   215,   216,   220,   221,   225,   226,   230,   231,   232,
     233,   234,   235,   239,   240,   244,   245,   249,   250,   251,
     252,   253,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   272,   276,   277,   278,   282,   283,
     287,   288,   292,   296,   297,   301,   302,   303,   307,   308,
     312,   313,   314,   315,   316,   317,   318,   322,   323,   327,
     328,   329,   333,   337,   338,   339,   343,   344,   345,   346,
     347,   348,   352,   353,   357,   358,   359,   363,   364,   365,
     366,   370,   371,   375,   376,   377,   381,   382,   383,   387,
     388,   389,   390,   391,   395,   396,   400,   401,   405,   406,
     407,   408,   412,   413,   417,   418,   422,   423,   426,   427,
     428,   429,   430,   431,   432,   433,   437,   438
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
  "ELLIPSIS", "SEMICOLON", "TYPEDEF_NAME", "THEN", "$accept", "program",
  "primary-expression", "constant", "expression", "assignement-expression",
  "assignement-operator", "unary-expression", "unary-operator",
  "conditional-expression", "logical-OR-expression",
  "logical-AND-expression", "inclusive-OR-expression",
  "exclusive-OR-expresion", "AND-expression", "equality-expression",
  "relational-expression", "shift-expression", "additive-expression",
  "multiplicative-expression", "cast-expression", "type-name",
  "abstract-declarator", "pointer", "type-qualifier-list",
  "type-qualifier", "direct-abstract-declarator", "parameter-type-list",
  "parameter-list", "parameter-declaration", "specifier-qualifier-list",
  "declaration", "declaration-list", "declaration-specifiers",
  "init-declarator-list", "init-declarator", "storage-class-specifier",
  "type-specifier", "typedef-name", "struct-or-union-specifier",
  "struct-or-union", "struct-declaration-list", "struct-declaration",
  "struct-declarator-list", "struct-declarator", "declarator",
  "direct-declarator", "identifier-list", "initializer",
  "constant-expression", "enum-specifier", "statement", "statement-list",
  "labeled-statement", "compound-statement", "expression-statement",
  "selection-statement", "iteration-statement", "jump-statement",
  "translation-unit", "external-declaration", "function-definition",
  "enumerator-list", "enumerator", "initializer-list",
  "postfix-expression", "argument-expression-list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-227)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     522,  -227,  -227,  -227,  -227,  -227,    62,  -227,  -227,  -227,
    -227,  -227,  -227,  -227,  -227,  -227,  -227,  -227,  -227,  -227,
    -227,    34,    13,  -227,    39,    73,   759,  -227,    33,   759,
     759,  -227,  -227,    85,   637,   -21,  -227,   522,  -227,  -227,
      22,    68,    27,  -227,    13,  -227,  -227,   -21,  -227,  -227,
     -41,  -227,   558,  -227,  -227,   102,   326,   270,  -227,   637,
      33,  -227,  1133,   601,  -227,    68,    18,    -6,  -227,  -227,
    -227,  -227,    34,  -227,  1162,   637,  -227,   326,   326,    -7,
     326,   846,  -227,    43,    96,  1278,  1046,    88,   135,   112,
     192,  1307,  1017,   194,   196,   114,  -227,  -227,  -227,  -227,
    -227,   790,  -227,  -227,  -227,  -227,  -227,  -227,  -227,  1336,
    1336,  -227,  -227,  -227,   -30,  -227,   113,  1278,  -227,   150,
     170,   158,   225,   226,   179,   141,   188,   203,    90,  -227,
     357,  -227,   893,  -227,  -227,  -227,  -227,  -227,  -227,   159,
    -227,  -227,   248,  -227,  -227,  -227,  -227,   277,  -227,  -227,
     276,   274,  -227,    29,    36,   214,  1278,  -227,    68,  -227,
    1162,  -227,  -227,  -227,   869,  -227,  1278,   -26,  -227,   247,
    -227,  -227,  -227,  -227,  1278,   252,  -227,   -13,  -227,  1075,
    1017,   241,   790,  -227,   300,  1278,  1278,  1017,   130,   292,
      12,  1278,  -227,  -227,  1278,  -227,  -227,  -227,  -227,  -227,
    -227,  -227,  -227,  -227,  -227,  -227,  -227,  1278,  -227,  1278,
    1278,  1278,  1278,  1278,  1278,  1278,  1278,  1278,  1278,  1278,
    1278,  1278,  1278,  1278,  1278,  1278,  1278,  1278,  -227,   959,
    -227,  -227,  1278,  1191,   302,   304,  -227,  -227,  -227,  -227,
     680,  1220,   435,  -227,    99,    61,  -227,  -227,   305,  -227,
    -227,  -227,  -227,   217,  -227,  -227,    -7,  -227,  1278,   169,
    1017,  -227,  1075,  -227,  -227,   298,   310,   171,   182,  -227,
    -227,  1278,   477,  -227,    86,  -227,  -227,    -2,   170,   158,
     225,   226,   179,   141,   141,   188,   188,   188,   188,   203,
     203,    90,    90,  -227,  -227,  -227,  -227,   152,  -227,  -227,
     187,  -227,  -227,  -227,  -227,  -227,   301,  -227,   311,   313,
      61,  1249,   715,  -227,  -227,  1104,  -227,  -227,  1017,  -227,
     321,  -227,  1278,  1017,  1017,  -227,  1278,  -227,  -227,  1278,
    -227,  -227,  -227,  -227,   312,  -227,   354,  -227,  -227,  -227,
    1017,   197,   391,  -227,  -227,  -227,  -227,  -227,  -227,   316,
    1017,  -227,  -227
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   120,   128,   125,   138,   126,     0,   121,   117,   123,
     118,   139,    81,   127,   124,   130,   129,   122,    82,   119,
     150,     0,    75,   134,     0,     0,   111,   197,     0,   107,
     109,   133,   131,     0,     0,   149,   132,     2,   194,   196,
     165,     0,     0,    76,    77,    79,     1,   148,   112,   103,
       0,   113,   115,   108,   110,   136,     0,     0,   105,     0,
       0,   201,     0,     0,   195,     0,   204,     0,   202,   151,
      78,    80,     0,   104,     0,     0,   199,     0,   100,     0,
      99,     0,   140,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     3,     7,     8,     9,    10,
       5,     0,   177,    32,    33,    34,    35,    36,    37,     0,
       0,   181,   208,     4,     0,    11,    68,     0,    13,    38,
      40,    42,    44,    46,    48,    50,    53,    58,    61,    64,
       0,   172,     0,   166,   167,   168,   169,   170,   171,    26,
     106,   200,   115,     3,   152,    68,   162,     0,   157,   155,
       0,    92,    94,    98,     0,     0,     0,   163,     0,   114,
       0,   159,   116,   198,     0,   102,     0,     0,   143,   145,
     101,   135,   141,   191,     0,     0,   192,     0,   190,     0,
       0,     0,     0,    30,     0,     0,     0,     0,     0,     0,
      71,     0,    27,    28,     0,   182,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,     0,    29,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   179,     0,
     178,   173,     0,     0,     0,     0,   214,   215,   153,   154,
       0,     0,     0,    97,    72,    74,    96,   156,     0,   164,
     205,   203,   206,     0,   137,   146,     0,   142,     0,     0,
       0,   193,     0,   176,   189,     0,     0,     0,     0,   174,
       6,     0,     0,    70,    72,    12,    14,     0,    41,    43,
      45,    47,    49,    52,    51,    54,    55,    56,    57,    59,
      60,    62,    63,    65,    66,    67,   180,     0,   210,   216,
       0,   212,   213,    93,    95,    84,     0,    88,     0,     0,
      73,     0,     0,   158,   160,     0,   144,   147,     0,   175,
       0,    31,     0,     0,     0,    69,     0,   209,   211,     0,
      85,    83,    89,    86,     0,    90,     0,   161,   207,   185,
       0,     0,   183,   186,    39,   217,    87,    91,   188,     0,
       0,   187,   184
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -227,  -227,  -227,  -227,   -63,   -62,  -227,   -60,  -227,   -61,
    -227,   191,   195,   193,   204,   202,    53,     3,    49,    94,
    -101,   236,  -138,   -17,  -227,    37,  -226,   -56,  -227,   167,
     -45,    14,   160,     0,  -227,   336,  -227,    32,  -227,  -227,
    -227,   342,   -73,  -227,   164,   -18,   -16,  -227,  -147,   -66,
    -227,   -88,   291,  -227,    26,  -168,  -227,  -227,  -227,  -227,
     385,  -227,   358,   266,  -227,  -227,  -227
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    24,   112,   113,   114,   115,   207,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   189,   308,    25,    44,    26,   245,   309,   151,   152,
      79,    58,    59,    60,    50,    51,    29,    30,    31,    32,
      33,    81,    82,   167,   168,    34,    35,   154,   162,   147,
      36,   131,   132,   133,   134,   135,   136,   137,   138,    37,
      38,    39,    67,    68,   253,   139,   300
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      28,   146,   145,    42,   184,    43,    72,   150,   172,    47,
      52,   262,   161,   252,    27,   243,   208,   194,   310,   175,
      62,   256,    63,   177,   146,   145,    48,    70,    20,    53,
      54,   183,    12,   165,   194,   170,    21,    28,   188,    46,
     157,   158,   142,    18,   231,   194,    22,    73,   310,   192,
     193,    27,   273,   241,   142,   272,   190,   145,   195,    45,
      61,   169,   257,   153,    20,    22,    22,    65,    20,    20,
     241,    69,   242,   140,   166,   261,    21,    21,    76,   326,
     247,    71,    22,   248,   156,   141,    22,    22,    80,   140,
     250,   172,   263,    78,   320,   146,   145,    40,   161,   269,
     255,   163,   311,    66,   312,   146,   145,    41,    20,    80,
      80,   259,    80,    80,    78,    78,    21,    78,    78,   188,
      55,    49,   267,   268,   293,   294,   295,   241,   188,   272,
      56,   173,   275,    80,    20,   246,   244,   190,    78,   174,
     241,   231,   242,   225,   140,   276,   277,    77,   226,   227,
     145,   145,   145,   145,   145,   145,   145,   145,   145,   145,
     145,   145,   145,   145,   145,   145,   145,   145,   338,   297,
     325,   299,   319,   274,   270,   306,   178,   194,   179,   196,
     146,   145,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   317,   180,   327,   187,    80,   146,   145,   194,
     232,    78,   233,   217,   218,   219,   220,   234,   235,   236,
     237,   145,    75,   318,    80,   323,   194,   130,   194,    78,
     285,   286,   287,   288,    42,   244,   324,   181,    47,   194,
     339,   328,   209,   210,   329,   342,   343,   185,   169,   186,
     153,   349,   153,   212,   194,   334,   215,   216,   221,   222,
     146,   145,   348,   161,   211,   274,   336,   223,   224,   341,
     249,   158,   352,   314,   315,   344,   145,   345,   283,   284,
     289,   290,   153,     1,     2,     3,     4,    83,   214,     5,
      84,    85,     6,     7,     8,     9,    10,    86,    11,    12,
      13,    14,    15,    87,    88,    16,    17,    89,    90,    91,
      18,    92,    93,    19,    94,    95,    96,    97,    98,    99,
     100,   213,   153,   101,    74,    57,   102,   291,   292,   238,
     239,   240,   103,   104,   105,   106,   107,   108,   258,   264,
       2,     3,     4,   260,   266,     5,   271,   301,     6,   302,
     313,     9,   321,   330,    11,    12,    13,    14,    15,   109,
     110,    16,    17,   322,   346,   331,    18,   332,   111,    23,
       1,     2,     3,     4,    83,   340,     5,    84,    85,     6,
       7,     8,     9,    10,    86,    11,    12,    13,    14,    15,
      87,    88,    16,    17,    89,    90,    91,    18,    92,    93,
      19,    94,    95,    96,    97,    98,    99,   100,   347,   350,
     101,   278,    57,   228,   351,   280,   279,   304,   159,   103,
     104,   105,   106,   107,   108,    23,   282,   281,   265,   164,
     316,   229,    64,   155,   251,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   109,   110,     1,     2,
       3,     4,     0,     0,     5,   111,    23,     6,     7,     8,
       9,    10,     0,    11,    12,    13,    14,    15,     0,     0,
      16,    17,     0,     0,     0,    18,     0,     0,    19,     0,
      20,     0,     0,     0,     0,     0,   241,     0,   242,   307,
       1,     2,     3,     4,     0,     0,     5,     0,    22,     6,
       7,     8,     9,    10,     0,    11,    12,    13,    14,    15,
       0,     0,    16,    17,     0,     0,     0,    18,     0,     0,
      19,     0,     0,     0,     0,     0,     0,     0,   241,     0,
     272,   307,     0,     0,    23,     1,     2,     3,     4,     0,
      22,     5,     0,     0,     6,     7,     8,     9,    10,     0,
      11,    12,    13,    14,    15,     0,     0,    16,    17,     0,
       0,     0,    18,     0,     0,    19,     0,    20,     0,     0,
       0,     1,     2,     3,     4,    21,    23,     5,     0,     0,
       6,     7,     8,     9,    10,    22,    11,    12,    13,    14,
      15,     0,     0,    16,    17,     0,     0,     0,    18,     0,
       0,    19,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    57,     1,     2,     3,     4,     0,     0,
       5,    23,     0,     6,     7,     8,     9,    10,     0,    11,
      12,    13,    14,    15,    74,     0,    16,    17,     0,     0,
       0,    18,     0,     0,    19,     0,   148,     0,     0,     0,
       1,     2,     3,     4,     0,   149,     5,    23,     0,     6,
       7,     8,     9,    10,     0,    11,    12,    13,    14,    15,
       0,     0,    16,    17,     0,     0,     0,    18,     0,     0,
      19,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    57,     1,     2,     3,     4,     0,     0,     5,
      23,     0,     6,     7,     8,     9,    10,     0,    11,    12,
      13,    14,    15,     0,     0,    16,    17,     0,     0,     0,
      18,     0,     0,    19,     0,     0,     0,     0,     1,     2,
       3,     4,     0,     0,     5,     0,    23,     6,     7,     8,
       9,    10,     0,    11,    12,    13,    14,    15,     0,     0,
      16,    17,     0,     0,     0,    18,     0,     0,    19,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   335,
       0,     0,     1,     2,     3,     4,     0,   303,     5,    23,
       0,     6,     7,     8,     9,    10,     0,    11,    12,    13,
      14,    15,     0,     0,    16,    17,     0,     0,     0,    18,
       0,     0,    19,     0,     2,     3,     4,     0,     0,     5,
       0,     0,     6,     0,    23,     9,     0,     0,    11,    12,
      13,    14,    15,     0,     0,    16,    17,     0,     0,    91,
      18,     0,     0,     0,     0,   143,    96,    97,    98,    99,
     100,     0,     0,   101,     0,     0,     0,     0,     0,     0,
       0,     0,   103,   104,   105,   106,   107,   108,    23,     0,
       2,     3,     4,     0,     0,     5,     0,     0,     6,     0,
       0,     9,     0,     0,    11,    12,    13,    14,    15,   109,
     110,    16,    17,     2,     3,     4,    18,     0,     5,    23,
       0,     6,     0,     0,     9,     0,     0,    11,    12,    13,
      14,    15,   171,     0,    16,    17,     0,     0,     0,    18,
      83,     0,     0,    84,    85,     0,     0,     0,     0,     0,
      86,     0,     0,     0,     0,   254,    87,    88,     0,     0,
      89,    90,    91,     0,    92,    93,     0,    94,    95,    96,
      97,    98,    99,   100,     0,    23,   101,     0,    57,   230,
       0,     0,     0,     0,     0,   103,   104,   105,   106,   107,
     108,     0,     0,     0,     0,     0,     0,     0,    23,     0,
       0,     0,     0,     0,     0,     0,    83,     0,     0,    84,
      85,     0,   109,   110,     0,     0,    86,     0,     0,     0,
       0,   111,    87,    88,     0,     0,    89,    90,    91,     0,
      92,    93,     0,    94,    95,    96,    97,    98,    99,   100,
       0,     0,   101,     0,    57,   296,     0,     0,     0,     0,
       0,   103,   104,   105,   106,   107,   108,     0,     0,     0,
       0,     0,     0,     0,    83,     0,     0,    84,    85,     0,
       0,     0,     0,     0,    86,     0,     0,     0,   109,   110,
      87,    88,     0,     0,    89,    90,    91,   111,    92,    93,
       0,    94,    95,    96,    97,    98,    99,   100,     0,     0,
     101,     0,    57,     0,     0,     0,     0,     0,     0,   103,
     104,   105,   106,   107,   108,    91,     0,     0,     0,     0,
       0,   143,    96,    97,    98,    99,   100,     0,     0,   101,
       0,     0,     0,     0,     0,     0,   109,   110,   103,   104,
     105,   106,   107,   108,    91,   111,     0,     0,     0,     0,
     143,    96,    97,    98,    99,   100,     0,     0,   101,     0,
       0,     0,     0,     0,     0,   109,   110,   103,   104,   105,
     106,   107,   108,    91,   176,     0,     0,     0,     0,   143,
      96,    97,    98,    99,   100,     0,     0,   101,     0,   160,
     337,     0,     0,     0,   109,   110,   103,   104,   105,   106,
     107,   108,    91,   111,     0,     0,     0,     0,   143,    96,
      97,    98,    99,   100,     0,   144,   101,     0,     0,     0,
       0,     0,     0,   109,   110,   103,   104,   105,   106,   107,
     108,    91,     0,     0,     0,     0,     0,   143,    96,    97,
      98,    99,   100,     0,     0,   101,     0,   160,     0,     0,
       0,     0,   109,   110,   103,   104,   105,   106,   107,   108,
      91,     0,     0,     0,     0,     0,   143,    96,    97,    98,
      99,   100,     0,     0,   101,   298,     0,     0,     0,     0,
       0,   109,   110,   103,   104,   105,   106,   107,   108,    91,
       0,     0,     0,     0,     0,   143,    96,    97,    98,    99,
     100,     0,   305,   101,     0,     0,     0,     0,     0,     0,
     109,   110,   103,   104,   105,   106,   107,   108,    91,     0,
       0,     0,     0,     0,   143,    96,    97,    98,    99,   100,
       0,   333,   101,     0,     0,     0,     0,     0,     0,   109,
     110,   103,   104,   105,   106,   107,   108,    91,     0,     0,
       0,     0,     0,   143,    96,    97,    98,    99,   100,     0,
       0,   101,     0,     0,     0,     0,     0,     0,   109,   110,
     103,   104,   105,   106,   107,   108,    91,     0,     0,     0,
       0,     0,   143,    96,    97,    98,    99,   100,     0,     0,
     182,     0,     0,     0,     0,     0,     0,   109,   110,   103,
     104,   105,   106,   107,   108,    91,     0,     0,     0,     0,
       0,   143,    96,    97,    98,    99,   100,     0,     0,   191,
       0,     0,     0,     0,     0,     0,   109,   110,   103,   104,
     105,   106,   107,   108,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   109,   110
};

static const yytype_int16 yycheck[] =
{
       0,    62,    62,    21,    92,    22,    47,    63,    81,    25,
      28,   179,    74,   160,     0,   153,   117,    47,   244,    85,
      41,    47,    43,    86,    85,    85,    26,    44,    35,    29,
      30,    91,    19,    78,    47,    80,    43,    37,   101,     0,
      46,    47,    60,    30,   132,    47,    53,    88,   274,   109,
     110,    37,   190,    41,    72,    43,   101,   117,    88,    22,
      34,    79,    88,    63,    35,    53,    53,    45,    35,    35,
      41,    44,    43,    59,    81,    88,    43,    43,    52,    81,
      44,    44,    53,    47,    66,    59,    53,    53,    56,    75,
     156,   164,   180,    56,   262,   156,   156,    35,   160,   187,
     166,    75,    41,    35,    43,   166,   166,    45,    35,    77,
      78,   174,    80,    81,    77,    78,    43,    80,    81,   182,
      35,    88,   185,   186,   225,   226,   227,    41,   191,    43,
      45,    88,   194,   101,    35,   153,   153,   182,   101,    43,
      41,   229,    43,    53,   130,   207,   209,    45,    58,    59,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   315,   232,
     271,   233,   260,   190,    44,   241,    88,    47,    43,    66,
     241,   241,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,   258,    81,    42,    81,   164,   258,   258,    47,
      41,   164,    43,    62,    63,    64,    65,    48,    49,    50,
      51,   271,    52,    44,   182,    44,    47,    57,    47,   182,
     217,   218,   219,   220,   242,   242,    44,    35,   244,    47,
     318,    44,    82,    83,    47,   323,   324,    43,   256,    43,
     240,    44,   242,    85,    47,   311,    67,    68,    60,    61,
     311,   311,   340,   315,    84,   272,   312,    54,    55,   322,
      46,    47,   350,    46,    47,   326,   326,   329,   215,   216,
     221,   222,   272,     3,     4,     5,     6,     7,    52,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    86,   312,    43,    66,    45,    46,   223,   224,    42,
      44,    47,    52,    53,    54,    55,    56,    57,    81,    88,
       4,     5,     6,    81,    34,     9,    44,    35,    12,    35,
      35,    15,    44,    42,    18,    19,    20,    21,    22,    79,
      80,    25,    26,    43,    42,    44,    30,    44,    88,    89,
       3,     4,     5,     6,     7,    44,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    44,     8,
      43,   210,    45,    46,    88,   212,   211,   240,    72,    52,
      53,    54,    55,    56,    57,    89,   214,   213,   182,    77,
     256,   130,    37,    65,   158,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    79,    80,     3,     4,
       5,     6,    -1,    -1,     9,    88,    89,    12,    13,    14,
      15,    16,    -1,    18,    19,    20,    21,    22,    -1,    -1,
      25,    26,    -1,    -1,    -1,    30,    -1,    -1,    33,    -1,
      35,    -1,    -1,    -1,    -1,    -1,    41,    -1,    43,    44,
       3,     4,     5,     6,    -1,    -1,     9,    -1,    53,    12,
      13,    14,    15,    16,    -1,    18,    19,    20,    21,    22,
      -1,    -1,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,
      33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,    -1,
      43,    44,    -1,    -1,    89,     3,     4,     5,     6,    -1,
      53,     9,    -1,    -1,    12,    13,    14,    15,    16,    -1,
      18,    19,    20,    21,    22,    -1,    -1,    25,    26,    -1,
      -1,    -1,    30,    -1,    -1,    33,    -1,    35,    -1,    -1,
      -1,     3,     4,     5,     6,    43,    89,     9,    -1,    -1,
      12,    13,    14,    15,    16,    53,    18,    19,    20,    21,
      22,    -1,    -1,    25,    26,    -1,    -1,    -1,    30,    -1,
      -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,     3,     4,     5,     6,    -1,    -1,
       9,    89,    -1,    12,    13,    14,    15,    16,    -1,    18,
      19,    20,    21,    22,    66,    -1,    25,    26,    -1,    -1,
      -1,    30,    -1,    -1,    33,    -1,    35,    -1,    -1,    -1,
       3,     4,     5,     6,    -1,    44,     9,    89,    -1,    12,
      13,    14,    15,    16,    -1,    18,    19,    20,    21,    22,
      -1,    -1,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,
      33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45,     3,     4,     5,     6,    -1,    -1,     9,
      89,    -1,    12,    13,    14,    15,    16,    -1,    18,    19,
      20,    21,    22,    -1,    -1,    25,    26,    -1,    -1,    -1,
      30,    -1,    -1,    33,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,    -1,    -1,     9,    -1,    89,    12,    13,    14,
      15,    16,    -1,    18,    19,    20,    21,    22,    -1,    -1,
      25,    26,    -1,    -1,    -1,    30,    -1,    -1,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      -1,    -1,     3,     4,     5,     6,    -1,    87,     9,    89,
      -1,    12,    13,    14,    15,    16,    -1,    18,    19,    20,
      21,    22,    -1,    -1,    25,    26,    -1,    -1,    -1,    30,
      -1,    -1,    33,    -1,     4,     5,     6,    -1,    -1,     9,
      -1,    -1,    12,    -1,    89,    15,    -1,    -1,    18,    19,
      20,    21,    22,    -1,    -1,    25,    26,    -1,    -1,    29,
      30,    -1,    -1,    -1,    -1,    35,    36,    37,    38,    39,
      40,    -1,    -1,    43,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    52,    53,    54,    55,    56,    57,    89,    -1,
       4,     5,     6,    -1,    -1,     9,    -1,    -1,    12,    -1,
      -1,    15,    -1,    -1,    18,    19,    20,    21,    22,    79,
      80,    25,    26,     4,     5,     6,    30,    -1,     9,    89,
      -1,    12,    -1,    -1,    15,    -1,    -1,    18,    19,    20,
      21,    22,    46,    -1,    25,    26,    -1,    -1,    -1,    30,
       7,    -1,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,
      17,    -1,    -1,    -1,    -1,    46,    23,    24,    -1,    -1,
      27,    28,    29,    -1,    31,    32,    -1,    34,    35,    36,
      37,    38,    39,    40,    -1,    89,    43,    -1,    45,    46,
      -1,    -1,    -1,    -1,    -1,    52,    53,    54,    55,    56,
      57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     7,    -1,    -1,    10,
      11,    -1,    79,    80,    -1,    -1,    17,    -1,    -1,    -1,
      -1,    88,    23,    24,    -1,    -1,    27,    28,    29,    -1,
      31,    32,    -1,    34,    35,    36,    37,    38,    39,    40,
      -1,    -1,    43,    -1,    45,    46,    -1,    -1,    -1,    -1,
      -1,    52,    53,    54,    55,    56,    57,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     7,    -1,    -1,    10,    11,    -1,
      -1,    -1,    -1,    -1,    17,    -1,    -1,    -1,    79,    80,
      23,    24,    -1,    -1,    27,    28,    29,    88,    31,    32,
      -1,    34,    35,    36,    37,    38,    39,    40,    -1,    -1,
      43,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,    52,
      53,    54,    55,    56,    57,    29,    -1,    -1,    -1,    -1,
      -1,    35,    36,    37,    38,    39,    40,    -1,    -1,    43,
      -1,    -1,    -1,    -1,    -1,    -1,    79,    80,    52,    53,
      54,    55,    56,    57,    29,    88,    -1,    -1,    -1,    -1,
      35,    36,    37,    38,    39,    40,    -1,    -1,    43,    -1,
      -1,    -1,    -1,    -1,    -1,    79,    80,    52,    53,    54,
      55,    56,    57,    29,    88,    -1,    -1,    -1,    -1,    35,
      36,    37,    38,    39,    40,    -1,    -1,    43,    -1,    45,
      46,    -1,    -1,    -1,    79,    80,    52,    53,    54,    55,
      56,    57,    29,    88,    -1,    -1,    -1,    -1,    35,    36,
      37,    38,    39,    40,    -1,    42,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    79,    80,    52,    53,    54,    55,    56,
      57,    29,    -1,    -1,    -1,    -1,    -1,    35,    36,    37,
      38,    39,    40,    -1,    -1,    43,    -1,    45,    -1,    -1,
      -1,    -1,    79,    80,    52,    53,    54,    55,    56,    57,
      29,    -1,    -1,    -1,    -1,    -1,    35,    36,    37,    38,
      39,    40,    -1,    -1,    43,    44,    -1,    -1,    -1,    -1,
      -1,    79,    80,    52,    53,    54,    55,    56,    57,    29,
      -1,    -1,    -1,    -1,    -1,    35,    36,    37,    38,    39,
      40,    -1,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,
      79,    80,    52,    53,    54,    55,    56,    57,    29,    -1,
      -1,    -1,    -1,    -1,    35,    36,    37,    38,    39,    40,
      -1,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    79,
      80,    52,    53,    54,    55,    56,    57,    29,    -1,    -1,
      -1,    -1,    -1,    35,    36,    37,    38,    39,    40,    -1,
      -1,    43,    -1,    -1,    -1,    -1,    -1,    -1,    79,    80,
      52,    53,    54,    55,    56,    57,    29,    -1,    -1,    -1,
      -1,    -1,    35,    36,    37,    38,    39,    40,    -1,    -1,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    79,    80,    52,
      53,    54,    55,    56,    57,    29,    -1,    -1,    -1,    -1,
      -1,    35,    36,    37,    38,    39,    40,    -1,    -1,    43,
      -1,    -1,    -1,    -1,    -1,    -1,    79,    80,    52,    53,
      54,    55,    56,    57,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    79,    80
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     9,    12,    13,    14,    15,
      16,    18,    19,    20,    21,    22,    25,    26,    30,    33,
      35,    43,    53,    89,    92,   114,   116,   122,   124,   127,
     128,   129,   130,   131,   136,   137,   141,   150,   151,   152,
      35,    45,   136,   114,   115,   116,     0,   137,   124,    88,
     125,   126,   136,   124,   124,    35,    45,    45,   122,   123,
     124,   145,    41,    43,   151,    45,    35,   153,   154,    44,
     114,   116,    47,    88,    66,   123,   145,    45,   116,   121,
     128,   132,   133,     7,    10,    11,    17,    23,    24,    27,
      28,    29,    31,    32,    34,    35,    36,    37,    38,    39,
      40,    43,    46,    52,    53,    54,    55,    56,    57,    79,
      80,    88,    93,    94,    95,    96,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     123,   142,   143,   144,   145,   146,   147,   148,   149,   156,
     122,   145,   136,    35,    42,    98,   100,   140,    35,    44,
     118,   119,   120,   124,   138,   153,    66,    46,    47,   126,
      45,    96,   139,   145,   132,   121,    81,   134,   135,   136,
     121,    46,   133,    88,    43,   140,    88,    95,    88,    43,
      81,    35,    43,    98,   142,    43,    43,    81,    95,   112,
     121,    43,    98,    98,    47,    88,    66,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    97,   111,    82,
      83,    84,    85,    86,    52,    67,    68,    62,    63,    64,
      65,    60,    61,    54,    55,    53,    58,    59,    46,   143,
      46,   142,    41,    43,    48,    49,    50,    51,    42,    44,
      47,    41,    43,   113,   114,   117,   136,    44,    47,    46,
     140,   154,   139,   155,    46,   140,    47,    88,    81,    95,
      81,    88,   146,   142,    88,   112,    34,    95,    95,   142,
      44,    44,    43,   113,   114,    96,    96,    95,   102,   103,
     104,   105,   106,   107,   107,   108,   108,   108,   108,   109,
     109,   110,   110,   111,   111,   111,    46,    95,    44,    96,
     157,    35,    35,    87,   120,    42,   140,    44,   113,   118,
     117,    41,    43,    35,    46,    47,   135,   140,    44,   142,
     146,    44,    43,    44,    44,   111,    81,    42,    44,    47,
      42,    44,    44,    42,   140,    44,   118,    46,   139,   142,
      44,    95,   142,   142,   100,    96,    42,    44,   142,    44,
       8,    88,   142
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    91,    92,    93,    93,    93,    93,    94,    94,    94,
      94,    95,    95,    96,    96,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    98,    98,    98,    98,
      98,    98,    99,    99,    99,    99,    99,    99,   100,   100,
     101,   101,   102,   102,   103,   103,   104,   104,   105,   105,
     106,   106,   106,   107,   107,   107,   107,   107,   108,   108,
     108,   109,   109,   109,   110,   110,   110,   110,   111,   111,
     112,   112,   113,   113,   113,   114,   114,   114,   114,   115,
     115,   116,   116,   117,   117,   117,   117,   117,   117,   117,
     117,   117,   118,   118,   119,   119,   120,   120,   120,   121,
     121,   121,   121,   122,   122,   123,   123,   124,   124,   124,
     124,   124,   124,   125,   125,   126,   126,   127,   127,   127,
     127,   127,   128,   128,   128,   128,   128,   128,   128,   128,
     128,   128,   128,   128,   129,   130,   130,   130,   131,   131,
     132,   132,   133,   134,   134,   135,   135,   135,   136,   136,
     137,   137,   137,   137,   137,   137,   137,   138,   138,   139,
     139,   139,   140,   141,   141,   141,   142,   142,   142,   142,
     142,   142,   143,   143,   144,   144,   144,   145,   145,   145,
     145,   146,   146,   147,   147,   147,   148,   148,   148,   149,
     149,   149,   149,   149,   150,   150,   151,   151,   152,   152,
     152,   152,   153,   153,   154,   154,   155,   155,   156,   156,
     156,   156,   156,   156,   156,   156,   157,   157
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     3,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     2,
       2,     4,     1,     1,     1,     1,     1,     1,     1,     5,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     1,     4,
       2,     1,     1,     2,     1,     1,     2,     2,     3,     1,
       2,     1,     1,     3,     2,     3,     3,     4,     2,     3,
       3,     4,     1,     3,     1,     3,     2,     2,     1,     1,
       1,     2,     2,     2,     3,     1,     2,     1,     2,     1,
       2,     1,     2,     1,     3,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     2,     5,     1,     1,
       1,     2,     3,     1,     3,     1,     2,     3,     2,     1,
       1,     3,     3,     4,     4,     3,     4,     1,     3,     1,
       3,     4,     1,     4,     5,     2,     1,     1,     1,     1,
       1,     1,     1,     2,     3,     4,     3,     2,     3,     3,
       4,     1,     2,     5,     7,     5,     5,     7,     6,     3,
       2,     2,     2,     3,     1,     2,     1,     1,     4,     3,
       3,     2,     1,     3,     1,     3,     1,     3,     1,     4,
       3,     4,     3,     3,     2,     2,     1,     3
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

#line 1710 "parser.tab.c"

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

#line 441 "parser.y"


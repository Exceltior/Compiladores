/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ID = 258,
     INTLIT = 259,
     REALLIT = 260,
     STRING = 261,
     ASSIGN = 262,
     BEGIN1 = 263,
     COLON = 264,
     COMMA = 265,
     DO = 266,
     DOT = 267,
     ELSE = 268,
     END = 269,
     FORWARD = 270,
     FUNCTION = 271,
     IF = 272,
     LBRAC = 273,
     NOT = 274,
     OUTPUT = 275,
     PARAMSTR = 276,
     PROGRAM = 277,
     RBRAC = 278,
     REPEAT = 279,
     SEMIC = 280,
     THEN = 281,
     UNTIL = 282,
     VAL = 283,
     VAR = 284,
     WHILE = 285,
     WRITELN = 286,
     AND = 287,
     OR = 288,
     OP2 = 289,
     OP3 = 290,
     OP4 = 291,
     RESERVED = 292
   };
#endif
/* Tokens.  */
#define ID 258
#define INTLIT 259
#define REALLIT 260
#define STRING 261
#define ASSIGN 262
#define BEGIN1 263
#define COLON 264
#define COMMA 265
#define DO 266
#define DOT 267
#define ELSE 268
#define END 269
#define FORWARD 270
#define FUNCTION 271
#define IF 272
#define LBRAC 273
#define NOT 274
#define OUTPUT 275
#define PARAMSTR 276
#define PROGRAM 277
#define RBRAC 278
#define REPEAT 279
#define SEMIC 280
#define THEN 281
#define UNTIL 282
#define VAL 283
#define VAR 284
#define WHILE 285
#define WRITELN 286
#define AND 287
#define OR 288
#define OP2 289
#define OP3 290
#define OP4 291
#define RESERVED 292




/* Copy the first part of user declarations.  */
#line 1 "mpaparser.y"
/* --- C Variables Definition --- */
#line 4 "mpaparser.y"


	#include <stdio.h>
	#include <string.h>
	#include "functions.h"
	#include "structs.h"
	#include "y.tab.h"

	extern int linha;
	extern int coluna;
	extern char * yytext;

	void yyerror(char * s);
	int yylex();

	start * program_start = NULL;
	


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 23 "mpaparser.y"
{
    
    int value;
    char * id;

    start * node_start;
    prog * node_prog;
	prog_heading * node_prog_heading;
	prog_block * node_prog_block;
	var_part * node_var_part;
	aditional_var_part * next_var_part;
	var_decl * node_var_decl;
	id_list * node_id_list;
	aditional_id_list * next_id;
	func_part * node_func_part;
	func_decl * node_func_decl;
	func_heading * node_func_heading;
	func_ident * node_func_ident;
	formal_params_list * node_formal_params_list;
	aditional_formal_params * next_formal_params;
	formal_params * node_formal_params;
	func_block * node_func_block;
	stat_part * node_stat_part;
	comp_stat * node_comp_stat;
	stat_list * node_stat_list;
	aditional_stat_list * next_stat_list;
	stat * node_stat;
	writeln_list * node_writeln_list;
	aditional_writeln * next_writeln;
	expression * node_expr;
	simple_expression * node_simple_expression;
	terminal * node_terminal;
	factor * node_factor;
	func_design * node_func_design;
	param_list * node_param_list;
	aditional_params * next_param;
	
}
/* Line 193 of yacc.c.  */
#line 230 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 243 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   167

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  66
/* YYNRULES -- Number of states.  */
#define YYNSTATES  146

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   292

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
      35,    36,    37
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,    10,    16,    20,    25,    26,    30,
      31,    35,    38,    42,    43,    47,    48,    52,    56,    60,
      65,    71,    74,    79,    83,    84,    88,    93,    96,    98,
     102,   105,   109,   110,   112,   119,   124,   129,   134,   144,
     148,   150,   153,   154,   159,   164,   168,   172,   173,   175,
     179,   183,   187,   190,   192,   196,   200,   202,   204,   206,
     208,   210,   214,   217,   220,   225,   229
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      39,     0,    -1,    40,    -1,    41,    25,    42,    12,    -1,
      22,     3,    18,    20,    23,    -1,    43,    48,    56,    -1,
      29,    45,    25,    44,    -1,    -1,    45,    25,    44,    -1,
      -1,    46,     9,     3,    -1,     3,    47,    -1,    10,     3,
      47,    -1,    -1,    49,    25,    48,    -1,    -1,    50,    25,
      15,    -1,    51,    25,    55,    -1,    50,    25,    55,    -1,
      16,     3,     9,     3,    -1,    16,     3,    52,     9,     3,
      -1,    16,     3,    -1,    18,    54,    53,    23,    -1,    25,
      54,    53,    -1,    -1,    46,     9,     3,    -1,    29,    46,
       9,     3,    -1,    43,    56,    -1,    57,    -1,     8,    58,
      14,    -1,    60,    59,    -1,    25,    60,    59,    -1,    -1,
      57,    -1,    17,    63,    26,    60,    13,    60,    -1,    17,
      63,    26,    60,    -1,    30,    63,    11,    60,    -1,    24,
      58,    27,    63,    -1,    28,    18,    21,    18,    63,    23,
      10,     3,    23,    -1,     3,     7,    63,    -1,    31,    -1,
      31,    61,    -1,    -1,    18,    63,    62,    23,    -1,    18,
       6,    62,    23,    -1,    10,    63,    62,    -1,    10,     6,
      62,    -1,    -1,    64,    -1,    64,    34,    64,    -1,    64,
      35,    65,    -1,    64,    33,    65,    -1,    35,    65,    -1,
      65,    -1,    65,    36,    65,    -1,    65,    32,    65,    -1,
      66,    -1,     3,    -1,     4,    -1,     5,    -1,    67,    -1,
      18,    63,    23,    -1,    19,    66,    -1,     3,    68,    -1,
      18,    63,    69,    23,    -1,    10,    63,    69,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   143,   143,   145,   147,   149,   151,   152,   154,   155,
     157,   159,   161,   162,   164,   165,   167,   168,   169,   171,
     172,   174,   176,   178,   179,   181,   182,   184,   186,   188,
     190,   192,   193,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   206,   207,   209,   210,   211,   213,   214,
     216,   217,   218,   219,   221,   222,   223,   226,   227,   228,
     229,   230,   231,   233,   235,   237,   238
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "INTLIT", "REALLIT", "STRING",
  "ASSIGN", "BEGIN1", "COLON", "COMMA", "DO", "DOT", "ELSE", "END",
  "FORWARD", "FUNCTION", "IF", "LBRAC", "NOT", "OUTPUT", "PARAMSTR",
  "PROGRAM", "RBRAC", "REPEAT", "SEMIC", "THEN", "UNTIL", "VAL", "VAR",
  "WHILE", "WRITELN", "AND", "OR", "OP2", "OP3", "OP4", "RESERVED",
  "$accept", "Start", "Program", "ProgramHeading", "ProgramBlock",
  "VarPart", "AditionalVarPart", "VarDecl", "IdList", "AditionalIds",
  "FuncPart", "FuncDecl", "FuncHeading", "FuncIdent", "FormalParamsList",
  "AditionalFormalParams", "FormalParams", "FuncBlock", "StatPart",
  "CompStat", "StatList", "AditionalStatList", "Statement", "Writeln",
  "AditionalWriteln", "Expression", "SimpleExpression", "Terminal",
  "Factor", "FuncDesign", "ParamList", "AditionalParams", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    38,    39,    40,    41,    42,    43,    43,    44,    44,
      45,    46,    47,    47,    48,    48,    49,    49,    49,    50,
      50,    51,    52,    53,    53,    54,    54,    55,    56,    57,
      58,    59,    59,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    61,    61,    62,    62,    62,    63,    63,
      64,    64,    64,    64,    65,    65,    65,    66,    66,    66,
      66,    66,    66,    67,    68,    69,    69
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     4,     5,     3,     4,     0,     3,     0,
       3,     2,     3,     0,     3,     0,     3,     3,     3,     4,
       5,     2,     4,     3,     0,     3,     4,     2,     1,     3,
       2,     3,     0,     1,     6,     4,     4,     4,     9,     3,
       1,     2,     0,     4,     4,     3,     3,     0,     1,     3,
       3,     3,     2,     1,     3,     3,     1,     1,     1,     1,
       1,     3,     2,     2,     4,     3,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     0,     0,     1,     7,     0,     0,
       0,    15,     0,    13,     0,     0,     3,     0,     0,     0,
       0,     0,     4,     0,    11,     9,     0,    21,    42,     5,
      28,    15,     7,     7,    13,     6,     0,    10,     0,     0,
       0,     0,     0,    42,     0,     0,    40,    33,     0,    32,
      14,    16,     0,    18,    17,    12,     9,    19,     0,     0,
      24,     0,     0,    57,    58,    59,     0,     0,     0,     0,
      48,    53,    56,    60,     0,     0,     0,     0,    41,    29,
      42,    30,    27,     8,     0,     0,     0,     0,    20,    39,
       0,    63,     0,    62,    52,    42,     0,     0,     0,     0,
       0,     0,     0,    42,    47,    47,    32,     0,    25,    24,
      22,    66,    61,    35,    51,    49,    50,    55,    54,    37,
       0,    36,     0,     0,     0,    31,    26,    23,     0,     0,
      42,     0,    47,    47,    44,    43,    66,    64,    34,     0,
      46,    45,    65,     0,     0,    38
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,    10,    52,    35,    36,    15,    24,
      18,    19,    20,    21,    40,    87,    60,    53,    29,    47,
      48,    81,    49,    78,   123,    69,    70,    71,    72,    73,
      91,   129
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -87
static const yytype_int8 yypact[] =
{
      -7,    17,    57,   -87,    36,    44,   -87,    34,    46,    65,
      60,    63,    53,    72,    48,    77,   -87,    84,    80,    64,
      67,    68,   -87,    87,   -87,    65,    88,    -4,    50,   -87,
     -87,    63,   -11,    34,    72,   -87,    69,   -87,    92,    35,
      89,    90,    30,    50,    78,    30,    81,   -87,    86,    76,
     -87,   -87,    80,   -87,   -87,   -87,    65,   -87,    65,    93,
      79,   100,    30,    91,   -87,   -87,    30,    66,    66,    82,
     -27,    -9,   -87,   -87,    83,    85,    94,     7,   -87,   -87,
      50,   -87,   -87,   -87,    98,   108,    35,    95,   -87,   -87,
      30,   -87,    96,   -87,    -9,    50,    66,    30,    66,    66,
      66,    30,    97,    50,   102,   102,    76,   110,   -87,    79,
     -87,   104,   -87,   103,    -9,    19,    -9,    23,   -87,   -87,
      30,   -87,    25,    99,   101,   -87,   -87,   -87,    30,   105,
      50,   106,   102,   102,   -87,   -87,   104,   -87,   -87,   107,
     -87,   -87,   -87,   117,   109,   -87
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -87,   -87,   -87,   -87,   -87,   114,    70,   116,   -36,   111,
     112,   -87,   -87,   -87,   -87,    14,    41,   113,   115,   -16,
     118,    24,   -79,   -87,   -86,   -45,    37,   -59,    71,   -87,
     -87,    -5
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_int16 yytable[] =
{
      76,   106,    30,    59,    51,    38,    96,    97,    98,    94,
      63,    64,    65,   104,    39,     1,   113,    89,     9,   124,
       5,    92,    84,    99,   121,    66,    67,   100,    63,    64,
      65,   132,   105,    63,    64,    65,    30,   114,    13,   116,
     117,   118,    68,    66,    67,   111,   140,   141,    66,    67,
      59,   138,    96,    41,    98,    -1,   119,     6,    28,   100,
      68,     7,     8,     9,    58,    68,    12,    42,    13,    63,
      64,    65,    16,    25,    43,   131,    22,   133,    44,    17,
      45,    46,    23,   136,    66,    67,    26,    27,    28,    31,
      34,    37,    32,    33,    56,    57,    75,    62,    61,    77,
      79,    80,    85,    88,    86,   103,   102,   107,    95,    90,
     101,   108,   122,   126,   128,   120,   130,   143,   110,   112,
     144,    11,   134,   127,   135,    14,    83,   109,   137,   139,
     125,   142,   145,     0,   115,     0,     0,     0,    93,     0,
       0,     0,     0,    50,     0,    55,    54,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    74,     0,     0,     0,     0,     0,    82
};

static const yytype_int16 yycheck[] =
{
      45,    80,    18,    39,    15,     9,    33,    34,    35,    68,
       3,     4,     5,     6,    18,    22,    95,    62,    29,   105,
       3,    66,    58,    32,   103,    18,    19,    36,     3,     4,
       5,     6,    77,     3,     4,     5,    52,    96,     3,    98,
      99,   100,    35,    18,    19,    90,   132,   133,    18,    19,
      86,   130,    33,     3,    35,    32,   101,     0,     8,    36,
      35,    25,    18,    29,    29,    35,    20,    17,     3,     3,
       4,     5,    12,    25,    24,   120,    23,   122,    28,    16,
      30,    31,    10,   128,    18,    19,     9,     3,     8,    25,
       3,     3,    25,    25,    25,     3,    18,     7,     9,    18,
      14,    25,     9,     3,    25,    11,    21,     9,    26,    18,
      27,     3,    10,     3,    10,    18,    13,    10,    23,    23,
       3,     7,    23,   109,    23,     9,    56,    86,    23,    23,
     106,   136,    23,    -1,    97,    -1,    -1,    -1,    67,    -1,
      -1,    -1,    -1,    31,    -1,    34,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    -1,    -1,    -1,    -1,    -1,    52
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    22,    39,    40,    41,     3,     0,    25,    18,    29,
      42,    43,    20,     3,    45,    46,    12,    16,    48,    49,
      50,    51,    23,    10,    47,    25,     9,     3,     8,    56,
      57,    25,    25,    25,     3,    44,    45,     3,     9,    18,
      52,     3,    17,    24,    28,    30,    31,    57,    58,    60,
      48,    15,    43,    55,    55,    47,    25,     3,    29,    46,
      54,     9,     7,     3,     4,     5,    18,    19,    35,    63,
      64,    65,    66,    67,    58,    18,    63,    18,    61,    14,
      25,    59,    56,    44,    46,     9,    25,    53,     3,    63,
      18,    68,    63,    66,    65,    26,    33,    34,    35,    32,
      36,    27,    21,    11,     6,    63,    60,     9,     3,    54,
      23,    63,    23,    60,    65,    64,    65,    65,    65,    63,
      18,    60,    10,    62,    62,    59,     3,    53,    10,    69,
      13,    63,     6,    63,    23,    23,    63,    23,    60,    23,
      62,    62,    69,    10,     3,    23
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
	    /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 143 "mpaparser.y"
    {(yyval.node_start) = program_start = insert_start((yyvsp[(1) - (1)].node_prog));}
    break;

  case 3:
#line 145 "mpaparser.y"
    {(yyval.node_prog) = insert_program((yyvsp[(1) - (4)].node_prog_heading),(yyvsp[(3) - (4)].node_prog_block));}
    break;

  case 4:
#line 147 "mpaparser.y"
    {(yyval.node_prog_heading) = insert_program_heading((yyvsp[(2) - (5)].id));}
    break;

  case 5:
#line 149 "mpaparser.y"
    {(yyval.node_prog_block) = insert_program_block((yyvsp[(1) - (3)].node_var_part), (yyvsp[(2) - (3)].node_func_part), (yyvsp[(3) - (3)].node_stat_part));}
    break;

  case 6:
#line 151 "mpaparser.y"
    {(yyval.node_var_part) = insert_var_part((yyvsp[(2) - (4)].node_var_decl), (yyvsp[(4) - (4)].next_var_part));}
    break;

  case 7:
#line 152 "mpaparser.y"
    {(yyval.node_var_part) = insert_var_part(NULL, NULL);}
    break;

  case 8:
#line 154 "mpaparser.y"
    {(yyval.next_var_part) = insert_aditional_var_part((yyvsp[(1) - (3)].node_var_decl), (yyvsp[(3) - (3)].next_var_part));}
    break;

  case 9:
#line 155 "mpaparser.y"
    {(yyval.next_var_part) = insert_aditional_var_part(NULL, NULL);}
    break;

  case 10:
#line 157 "mpaparser.y"
    {(yyval.node_var_decl) = insert_var_decl((yyvsp[(1) - (3)].node_id_list), (yyvsp[(3) - (3)].id));}
    break;

  case 11:
#line 159 "mpaparser.y"
    {(yyval.node_id_list) = insert_id_list((yyvsp[(1) - (2)].id), (yyvsp[(2) - (2)].next_id));}
    break;

  case 12:
#line 161 "mpaparser.y"
    {(yyval.next_id) = insert_aditional_id_list((yyvsp[(2) - (3)].id), (yyvsp[(3) - (3)].next_id));}
    break;

  case 13:
#line 162 "mpaparser.y"
    {(yyval.next_id) = insert_aditional_id_list(NULL, NULL);}
    break;

  case 14:
#line 164 "mpaparser.y"
    {(yyval.node_func_part) = insert_func_part((yyvsp[(1) - (3)].node_func_decl));}
    break;

  case 15:
#line 165 "mpaparser.y"
    {(yyval.node_func_part) = insert_func_part(NULL);}
    break;

  case 16:
#line 167 "mpaparser.y"
    {(yyval.node_func_decl) = insert_func_decl((yyvsp[(1) - (3)].node_func_heading), NULL, NULL);}
    break;

  case 17:
#line 168 "mpaparser.y"
    {(yyval.node_func_decl) = insert_func_decl(NULL, (yyvsp[(3) - (3)].node_func_block), (yyvsp[(1) - (3)].node_func_ident));}
    break;

  case 18:
#line 169 "mpaparser.y"
    {(yyval.node_func_decl) = insert_func_decl((yyvsp[(1) - (3)].node_func_heading), (yyvsp[(3) - (3)].node_func_block), NULL);}
    break;

  case 19:
#line 171 "mpaparser.y"
    {(yyval.node_func_heading) = insert_func_heading((yyvsp[(2) - (4)].id), NULL, (yyvsp[(4) - (4)].id));}
    break;

  case 20:
#line 172 "mpaparser.y"
    {(yyval.node_func_heading) = insert_func_heading((yyvsp[(2) - (5)].id), (yyvsp[(3) - (5)].node_formal_params_list), (yyvsp[(5) - (5)].id));}
    break;

  case 21:
#line 174 "mpaparser.y"
    {(yyval.node_func_ident) = insert_func_ident((yyvsp[(2) - (2)].id));}
    break;

  case 22:
#line 176 "mpaparser.y"
    {(yyval.node_formal_params_list) = insert_formal_params_list((yyvsp[(2) - (4)].node_formal_params), (yyvsp[(3) - (4)].next_formal_params));}
    break;

  case 23:
#line 178 "mpaparser.y"
    {(yyval.next_formal_params) = insert_aditional_formal_params((yyvsp[(2) - (3)].node_formal_params), (yyvsp[(3) - (3)].next_formal_params));}
    break;

  case 24:
#line 179 "mpaparser.y"
    {(yyval.next_formal_params) = insert_aditional_formal_params(NULL, NULL);}
    break;

  case 25:
#line 181 "mpaparser.y"
    {(yyval.node_formal_params) = insert_formal_params((yyvsp[(1) - (3)].node_id_list), (yyvsp[(3) - (3)].id), 2);}
    break;

  case 26:
#line 182 "mpaparser.y"
    {(yyval.node_formal_params) = insert_formal_params((yyvsp[(2) - (4)].node_id_list), (yyvsp[(4) - (4)].id), 1);}
    break;

  case 27:
#line 184 "mpaparser.y"
    {(yyval.node_func_block) = insert_func_block((yyvsp[(1) - (2)].node_var_part), (yyvsp[(2) - (2)].node_stat_part));}
    break;

  case 28:
#line 186 "mpaparser.y"
    {(yyval.node_stat_part) = insert_stat_part((yyvsp[(1) - (1)].node_comp_stat));}
    break;

  case 29:
#line 188 "mpaparser.y"
    {(yyval.node_comp_stat) = insert_comp_stat((yyvsp[(2) - (3)].node_stat_list));}
    break;

  case 30:
#line 190 "mpaparser.y"
    {(yyval.node_stat_list) = insert_stat_list((yyvsp[(1) - (2)].node_stat), (yyvsp[(2) - (2)].next_stat_list));}
    break;

  case 31:
#line 192 "mpaparser.y"
    {(yyval.next_stat_list) = insert_aditional_stat_list((yyvsp[(2) - (3)].node_stat), (yyvsp[(3) - (3)].next_stat_list));}
    break;

  case 32:
#line 193 "mpaparser.y"
    {(yyval.next_stat_list) = insert_aditional_stat_list(NULL, NULL);}
    break;

  case 33:
#line 195 "mpaparser.y"
    {(yyval.node_stat) = insert_statment((yyvsp[(1) - (1)].node_comp_stat), NULL, NULL, NULL, NULL, NULL, NULL, 1);}
    break;

  case 34:
#line 196 "mpaparser.y"
    {(yyval.node_stat) = insert_statment(NULL, (yyvsp[(2) - (6)].node_expr), (yyvsp[(4) - (6)].node_stat), (yyvsp[(6) - (6)].node_stat), NULL, NULL, NULL, 3);}
    break;

  case 35:
#line 197 "mpaparser.y"
    {(yyval.node_stat) = insert_statment(NULL, (yyvsp[(2) - (4)].node_expr), (yyvsp[(4) - (4)].node_stat), NULL, NULL, NULL, NULL, 2);}
    break;

  case 36:
#line 198 "mpaparser.y"
    {(yyval.node_stat) = insert_statment(NULL, (yyvsp[(2) - (4)].node_expr), (yyvsp[(4) - (4)].node_stat), NULL, NULL, NULL, NULL, 4);}
    break;

  case 37:
#line 199 "mpaparser.y"
    {(yyval.node_stat) = insert_statment(NULL, (yyvsp[(4) - (4)].node_expr), NULL, NULL, (yyvsp[(2) - (4)].node_stat_list), NULL, NULL, 5);}
    break;

  case 38:
#line 200 "mpaparser.y"
    {(yyval.node_stat) = insert_statment(NULL, (yyvsp[(5) - (9)].node_expr), NULL, NULL, NULL, (yyvsp[(8) - (9)].id), NULL, 6);}
    break;

  case 39:
#line 201 "mpaparser.y"
    {(yyval.node_stat) = insert_statment(NULL, (yyvsp[(3) - (3)].node_expr), NULL, NULL, NULL, (yyvsp[(1) - (3)].id), NULL, 7);}
    break;

  case 40:
#line 202 "mpaparser.y"
    {(yyval.node_stat) = insert_statment(NULL, NULL, NULL, NULL, NULL, NULL, NULL, 8);}
    break;

  case 41:
#line 203 "mpaparser.y"
    {(yyval.node_stat) = insert_statment(NULL, NULL, NULL, NULL, NULL, NULL, (yyvsp[(2) - (2)].node_writeln_list), 8);}
    break;

  case 42:
#line 204 "mpaparser.y"
    {(yyval.node_stat) = insert_statment(NULL, NULL, NULL, NULL, NULL, NULL, NULL, -1);}
    break;

  case 43:
#line 206 "mpaparser.y"
    {(yyval.node_writeln_list) = insert_writeln((yyvsp[(2) - (4)].node_expr), (yyvsp[(3) - (4)].next_writeln), NULL);}
    break;

  case 44:
#line 207 "mpaparser.y"
    {(yyval.node_writeln_list) = insert_writeln(NULL, (yyvsp[(3) - (4)].next_writeln), (yyvsp[(2) - (4)].id));}
    break;

  case 45:
#line 209 "mpaparser.y"
    {(yyval.next_writeln) = insert_aditional_writeln((yyvsp[(2) - (3)].node_expr), (yyvsp[(3) - (3)].next_writeln), NULL);}
    break;

  case 46:
#line 210 "mpaparser.y"
    {(yyval.next_writeln) = insert_aditional_writeln(NULL, (yyvsp[(3) - (3)].next_writeln), (yyvsp[(2) - (3)].id));}
    break;

  case 47:
#line 211 "mpaparser.y"
    {(yyval.next_writeln) = insert_aditional_writeln(NULL, NULL, NULL);}
    break;

  case 48:
#line 213 "mpaparser.y"
    {(yyval.node_expr) = insert_expression((yyvsp[(1) - (1)].node_simple_expression), NULL, NULL, 1);}
    break;

  case 49:
#line 214 "mpaparser.y"
    {(yyval.node_expr) = insert_expression((yyvsp[(1) - (3)].node_simple_expression), (yyvsp[(3) - (3)].node_simple_expression), (yyvsp[(2) - (3)].id), 2);}
    break;

  case 50:
#line 216 "mpaparser.y"
    {(yyval.node_simple_expression) = insert_simple_expression((yyvsp[(1) - (3)].node_simple_expression), (yyvsp[(3) - (3)].node_terminal), (yyvsp[(2) - (3)].id), 1);}
    break;

  case 51:
#line 217 "mpaparser.y"
    {(yyval.node_simple_expression) = insert_simple_expression((yyvsp[(1) - (3)].node_simple_expression), (yyvsp[(3) - (3)].node_terminal), NULL, 2);}
    break;

  case 52:
#line 218 "mpaparser.y"
    {(yyval.node_simple_expression) = insert_simple_expression(NULL, (yyvsp[(2) - (2)].node_terminal), (yyvsp[(1) - (2)].id), 3);}
    break;

  case 53:
#line 219 "mpaparser.y"
    {(yyval.node_simple_expression) = insert_simple_expression(NULL, (yyvsp[(1) - (1)].node_terminal), NULL, 4);}
    break;

  case 54:
#line 221 "mpaparser.y"
    {(yyval.node_terminal) = insert_terminal((yyvsp[(1) - (3)].node_terminal), (yyvsp[(3) - (3)].node_terminal), NULL, (yyvsp[(2) - (3)].id), 1);}
    break;

  case 55:
#line 222 "mpaparser.y"
    {(yyval.node_terminal) = insert_terminal((yyvsp[(1) - (3)].node_terminal), (yyvsp[(3) - (3)].node_terminal), NULL, NULL, 2);}
    break;

  case 56:
#line 223 "mpaparser.y"
    {(yyval.node_terminal) = insert_terminal(NULL, NULL, (yyvsp[(1) - (1)].node_factor), NULL, 3);}
    break;

  case 57:
#line 226 "mpaparser.y"
    {(yyval.node_factor) = insert_factor((yyvsp[(1) - (1)].id), NULL, NULL, NULL, (char *)"id");}
    break;

  case 58:
#line 227 "mpaparser.y"
    {(yyval.node_factor) = insert_factor((yyvsp[(1) - (1)].id), NULL, NULL, NULL, (char *)"int");}
    break;

  case 59:
#line 228 "mpaparser.y"
    {(yyval.node_factor) = insert_factor((yyvsp[(1) - (1)].id), NULL, NULL, NULL, (char *)"real");}
    break;

  case 60:
#line 229 "mpaparser.y"
    {(yyval.node_factor) = insert_factor(NULL, NULL, NULL, (yyvsp[(1) - (1)].node_func_design), (char *)"func");}
    break;

  case 61:
#line 230 "mpaparser.y"
    {(yyval.node_factor) = insert_factor(NULL, (yyvsp[(2) - (3)].node_expr), NULL, NULL, (char *)"expr");}
    break;

  case 62:
#line 231 "mpaparser.y"
    {(yyval.node_factor) = insert_factor(NULL, NULL, (yyvsp[(2) - (2)].node_factor), NULL, (char *)"fact");}
    break;

  case 63:
#line 233 "mpaparser.y"
    {(yyval.node_func_design) = insert_func_design((yyvsp[(1) - (2)].id), (yyvsp[(2) - (2)].node_param_list));}
    break;

  case 64:
#line 235 "mpaparser.y"
    {(yyval.node_param_list) = insert_params_list((yyvsp[(2) - (4)].node_expr), (yyvsp[(3) - (4)].next_param));}
    break;

  case 65:
#line 237 "mpaparser.y"
    {(yyval.next_param) = insert_aditional_params((yyvsp[(2) - (3)].node_expr), (yyvsp[(3) - (3)].next_param));}
    break;

  case 66:
#line 238 "mpaparser.y"
    {(yyval.next_param) = insert_aditional_params(NULL, NULL);}
    break;


/* Line 1267 of yacc.c.  */
#line 1890 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 240 "mpaparser.y"


/* --- C code Section --- */

int main(int argc, char *argv[]){

	//Arvore
	if(yyparse() == 0){

 		int i;

		for(i = 0; i < argc; i++){
			if(strcmp(argv[i],"-t") == 0) {
				print_all(program_start->node_program);
			}
		}

 	}
 	else{
 		return 0;
 	}





 	

	return 0;

}


void yyerror (char *s) {

	coluna = coluna - strlen(yytext);
	printf("Line %d, col %d: %s: %s\n", linha, coluna, s, yytext);

}


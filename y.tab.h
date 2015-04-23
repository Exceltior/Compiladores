/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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
/* Line 1529 of yacc.c.  */
#line 162 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;


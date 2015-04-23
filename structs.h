//
//  Structs.h
//  Compiladores
//
//  Created by Miguel Veloso on 11/04/15.
//  Copyright (c) 2015 Miguel Veloso. All rights reserved.
//

#ifndef _STRUCTSH_
#define _STRUCTSH_

typedef struct no_start start;
typedef struct no_prog prog;
typedef struct no_prog_heading prog_heading;
typedef struct no_prog_block prog_block;
typedef struct no_var_part var_part;
typedef struct no_aditional_var_part aditional_var_part;
typedef struct no_var_decl var_decl;
typedef struct no_id_list id_list;
typedef struct no_aditional_id_list aditional_id_list;
typedef struct no_func_part func_part;
typedef struct no_func_decl func_decl;
typedef struct no_func_heading func_heading;
typedef struct no_func_ident func_ident;
typedef struct no_formal_params_list formal_params_list;
typedef struct no_aditional_formal_params aditional_formal_params;
typedef struct no_formal_params formal_params;
typedef struct no_func_block func_block;
typedef struct no_stat_part stat_part;
typedef struct no_comp_stat comp_stat;
typedef struct no_stat_list stat_list;
typedef struct no_aditional_stat_list aditional_stat_list;
typedef struct no_stat stat;
typedef struct no_aditional_stat aditional_stat;
typedef struct no_writeln_p_list writeln_list;
typedef struct no_aditional_writeln aditional_writeln;
typedef struct no_expression expression;
typedef struct no_simple_expression simple_expression;
typedef struct no_terminal terminal;
typedef struct no_factor factor;
typedef struct no_func_design func_design;
typedef struct no_param_list param_list;
typedef struct no_aditional_param aditional_params;

struct no_start{
    prog * node_program;
};

struct no_prog{
    prog_heading * node_prog_heading;
    prog_block * node_prog_block;
};

struct no_prog_heading{
    char * id;
};

struct no_prog_block{
    var_part * node_var_part;
    func_part * node_func_part;
    stat_part * node_stat_part;
};

struct no_var_part{
    var_decl * node_var_decl;
    aditional_var_part * next_var_part;
};

struct no_aditional_var_part{
    var_decl * node_var_decl;
    aditional_var_part * next_var_part;
};

struct no_var_decl{
    id_list * node_id_list;
    char * id_type;
};

struct no_id_list{
    char * id;
    aditional_id_list * next_id;
};

struct no_aditional_id_list{
    char * id;
    aditional_id_list * next_id;
};

struct no_func_part{
    func_decl * node_func_decl;
};

struct no_func_decl{
    func_heading * node_func_heading;
    func_ident * node_func_ident;
    func_block * node_func_block;
};

struct no_func_heading{
    char * id_func;
    char * id_type;
    formal_params_list * node_formal_params_list;
};

struct no_func_ident{
    char * id_func;
};

struct no_formal_params_list{
    formal_params * node_formal_params;
    aditional_formal_params * next_formal_params;
};

struct no_aditional_formal_params{
    formal_params * node_formal_params;
    aditional_formal_params * next_formal_params;
};

struct no_formal_params{
    id_list * node_id_list;
    char * id_type;
    int type_var;
};

struct no_func_block{
    var_part * node_var_part;
    stat_part * node_stat_part;
};

struct no_stat_part{
    comp_stat * node_comp_stat;
};

struct no_comp_stat{
    stat_list * node_stat_list;
};

struct no_stat_list{
    stat * node_stat;
    aditional_stat_list * next_stat_list;
};

struct no_aditional_stat_list{
    stat * node_stat;
    aditional_stat_list * next_stat_list;
};

struct no_stat{
    comp_stat * node_comp_stat;
    expression * node_expr;
    stat * node_stat;
    stat * node_stat2;
    stat_list * node_stat_list;
    writeln_list * node_writeln_list;
    char * id;
    int operation_type;
    /*
        1 - CompStat
        2 - IF
        3 - IF - ELSE
        4 - WHILE
        5 - REPEAT
        6 - VAL PARAMSTER
        7 - ASSIGN
        8 - WRITELN
    */
};

struct no_writeln_p_list{
    expression * node_expr;
    char * string;
    aditional_writeln * next;
};

struct no_aditional_writeln{
    expression * node_expr;
    char * string;
    aditional_writeln * next;
};

struct no_expression{
    simple_expression * node_simple_expr;
    simple_expression * node_simple_expr2;
    char * id;
    int operation_type;
    /*
        1 - Simple
        2 - OP2
    */
};

struct no_simple_expression{
    simple_expression * node_simple_expr;
    terminal * node_terminal;
    char * id;
    int operation_type;
    /*
        1 - OP3
        2 - OR
        3 - OP3 Terminal
        4 - Terminal
    */
};

struct no_terminal{
    terminal * node_terminal;
    terminal * node_terminal2;
    factor * node_factor;
    char * id;
    int operation_type;
    /*
        1 - OP4
        2 - AND
        3 - Factor
    */
};

struct no_factor{
    char * type;
    char * id;
    func_design * node_func_design;
    factor * node_factor;
    expression * node_expr;
    /*
        1 - ID
        2 - INTLIT
        3 - REALLIT
        4 - FuncDesign
        5 - Expr
        6 - NOT
    */
};

struct no_func_design{
    char * id;
    param_list * param_list;
};

struct no_param_list{
    expression * node_expr;
    aditional_params * next_param;
};

struct no_aditional_param{
    expression * node_expr;
    aditional_params * next_param;
};










#endif



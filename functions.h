//
//  Structs.h
//  Compiladores
//
//  Created by Miguel Veloso on 11/04/15.
//  Copyright (c) 2015 Miguel Veloso. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "structs.h"

start * insert_start(prog * program);
prog * insert_program(prog_heading * heading, prog_block * block);
prog_heading * insert_program_heading(char * id);
prog_block * insert_program_block(var_part * var_Part, func_part * func_Part, stat_part * stat_Part);
var_part * insert_var_part(var_decl * var_Decl, aditional_var_part * var_Part);
aditional_var_part * insert_aditional_var_part(var_decl * var_Decl, aditional_var_part * var_Part);
var_decl * insert_var_decl(id_list * id_List, char * id_Type);
id_list * insert_id_list(char * id, aditional_id_list * id_List);
aditional_id_list * insert_aditional_id_list(char * id, aditional_id_list * id_List);
func_part * insert_func_part(func_decl * func_Decl);
func_decl * insert_func_decl(func_heading * func_Heading, func_block * func_Block, func_ident * func_Ident);
func_heading * insert_func_heading(char * id_func, formal_params_list * formal_Params_List, char * id_type);
func_ident * insert_func_ident(char * id);
formal_params_list * insert_formal_params_list(formal_params * formal_Params, aditional_formal_params * aditional_params);
aditional_formal_params * insert_aditional_formal_params(formal_params * formal_Params, aditional_formal_params * aditional_params);
formal_params * insert_formal_params(id_list * id_List, char * id, int type);
func_block * insert_func_block(var_part * var_Part, stat_part * stat_Part);
stat_part * insert_stat_part(comp_stat * comp_Stat);
comp_stat * insert_comp_stat(stat_list * stat_List);
stat_list * insert_stat_list(stat * statement, aditional_stat_list * aditional_Stat_List);
aditional_stat_list * insert_aditional_stat_list(stat * statement, aditional_stat_list * aditional_Stat_List);
stat * insert_statment(comp_stat * comp_Stat, expression * expr, stat * statement, stat * else_stat, stat_list * stat_List, char * id, writeln_list * writeln, int operation);
writeln_list * insert_writeln(expression * expr, aditional_writeln * aditional_Writeln, char * string);
aditional_writeln * insert_aditional_writeln(expression * expr, aditional_writeln * aditional_Writeln, char * string);
expression * insert_expression(simple_expression * expr, simple_expression * expr2, char * id, int operation);
simple_expression * insert_simple_expression(simple_expression * expr, terminal * term, char * id, int operation);
terminal * insert_terminal(terminal * term1, terminal * term2, factor * node_factor, char * id, int operation);
factor * insert_factor(char * id, expression * expr, factor * node_factor, func_design * design, char * type);
func_design * insert_func_design(char * id, param_list * params);
param_list * insert_params_list(expression * expr, aditional_params * aditional_Params);
aditional_params * insert_aditional_params(expression * expr, aditional_params * aditional_Params);

void alignment();
void print_all(prog * node_program);
void print_prog_heading(prog_heading * node_prog_heading);
void print_prog_block(prog_block * node_prog_block);
void print_var_part(var_part * func_var_part);
void print_aditional_var_part(aditional_var_part * temp);
void print_var_decl(var_decl * node_var_decl);
void print_id_list(id_list * node_id_list);
void print_aditional_id_list(aditional_id_list * temp);
void print_func_part(func_part * node_func_part);
void print_func_heading(func_heading * node_func_heading);
void print_formal_params(formal_params * node_formal_params);
void print_aditional_formal_params(aditional_formal_params * temp);
void print_func_block(func_block * node_func_block);
void print_stat_part(stat_part * node_stat_part);
void print_comp_stat(comp_stat * node_comp_stat);
void print_stat_list(stat_list * node_stat_list);
void print_aditional_stat_list(aditional_stat_list * temp);
void print_stat(stat * node_stat);
void print_writeln(writeln_list * node_writeln_list);
void print_expression(expression * node_expr);
void print_simple_expression(simple_expression * node_simple_expr);
void print_terminal(terminal * node_terminal);
void print_factor(factor * node_factor);
void print_aditional_params(aditional_params * temp);
void print_aditional_writeln(aditional_writeln * temp);



























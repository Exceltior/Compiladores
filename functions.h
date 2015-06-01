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

start * insert_start(prog * program, int linha, int coluna);
prog * insert_program(prog_heading * heading, prog_block * block, int linha, int coluna);
prog_heading * insert_program_heading(char * id, int linha, int coluna);
prog_block * insert_program_block(var_part * var_Part, func_part * func_Part, stat_part * stat_Part, int linha, int coluna);
var_part * insert_var_part(var_decl * var_Decl, aditional_var_part * var_Part, int linha, int coluna);
aditional_var_part * insert_aditional_var_part(var_decl * var_Decl, aditional_var_part * var_Part, int linha, int coluna);
var_decl * insert_var_decl(id_list * id_List, char * id_Type, int linha, int coluna);
id_list * insert_id_list(char * id, aditional_id_list * id_List, int linha, int coluna);
aditional_id_list * insert_aditional_id_list(char * id, aditional_id_list * id_List, int linha, int coluna);
func_part * insert_func_part(func_decl * func_Decl, func_part * func_Part, int linha, int coluna);
func_decl * insert_func_decl(func_heading * func_Heading, func_block * func_Block, func_ident * func_Ident, int linha, int coluna);
func_heading * insert_func_heading(char * id_func, formal_params_list * formal_Params_List, char * id_type, int linha, int coluna);
func_ident * insert_func_ident(char * id, int linha, int coluna);
formal_params_list * insert_formal_params_list(formal_params * formal_Params, aditional_formal_params * aditional_params, int linha, int coluna);
aditional_formal_params * insert_aditional_formal_params(formal_params * formal_Params, aditional_formal_params * aditional_params, int linha, int coluna);
formal_params * insert_formal_params(id_list * id_List, char * id, char * type, int linha, int coluna);
func_block * insert_func_block(var_part * var_Part, stat_part * stat_Part, int linha, int coluna);
stat_part * insert_stat_part(comp_stat * comp_Stat, int linha, int coluna);
comp_stat * insert_comp_stat(stat_list * stat_List, int linha, int coluna);
stat_list * insert_stat_list(stat * statement, aditional_stat_list * aditional_Stat_List, int linha, int coluna);
aditional_stat_list * insert_aditional_stat_list(stat * statement, aditional_stat_list * aditional_Stat_List, int linha, int coluna);
stat * insert_statment(comp_stat * comp_Stat, expression * expr, stat * statement, stat * else_stat, stat_list * stat_List, char * id, writeln_list * writeln, char * operation, int linha, int coluna);
writeln_list * insert_writeln(expression * expr, aditional_writeln * aditional_Writeln, char * string, int linha, int coluna);
aditional_writeln * insert_aditional_writeln(expression * expr, aditional_writeln * aditional_Writeln, char * string, int linha, int coluna);
expression * insert_expression(simple_expression * expr, simple_expression * expr2, char * id, char * operation, int linha, int coluna);
simple_expression * insert_simple_expression(simple_expression * expr, terminal * term, char * id, char * operation, int linha, int coluna);
terminal * insert_terminal(terminal * term1, terminal * term2, factor * node_factor, char * id, char * operation, int linha, int coluna);
factor * insert_factor(char * id, expression * expr, factor * node_factor, func_design * design, char * type, int linha, int coluna);
func_design * insert_func_design(char * id, param_list * params, int linha, int coluna);
param_list * insert_params_list(expression * expr, aditional_params * aditional_Params, int linha, int coluna);
aditional_params * insert_aditional_params(expression * expr, aditional_params * aditional_Params, int linha, int coluna);

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
void print_func_decl(func_decl * temp);
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
void print_func_design(func_design * node_func_design);
void print_aditional_params(aditional_params * temp);
void print_aditional_writeln(aditional_writeln * temp);

void print_symbol_table(symbol_table * symbols);
char * strtolower(char * str);
void checkifpossible(char * id, factor * node_factor);

void build_symbol_table(prog * node_program, symbol_table * symbols);
void symbol_aditional_var_part(aditional_var_part * temp, symbol_table * symbols);
void symbol_var_decl(var_decl * node_var_decl, symbol_entry * symbol_Entry);
void symbol_id_list(id_list * node_id_list, char * type, symbol_entry * symbol_Entry, char * second_type);
void symbol_aditional_id_list(aditional_id_list * temp, char * type, symbol_entry * new_entry, char * second_type);
void symbol_func_part(func_part * node_func_part, symbol_table * symbols);
void symbol_func_decl(func_decl * temp, symbol_table * symbols);
void symbol_func_heading(func_heading * node_func_heading, symbol_table * symbols);
void symbol_aditional_formal_params(aditional_formal_params * temp, symbol_entry * entries);
void symbol_formal_params(formal_params * node_formal_params, symbol_entry * new_entry);
void symbol_func_block(func_block * node_func_block, symbol_table * symbols);
void symbol_stat_part(stat_part * node_stat_part);
void symbol_comp_stat(comp_stat * node_comp_stat);
void symbol_stat_list(stat_list * node_stat_list);
void symbol_aditional_stat_list(aditional_stat_list * temp);
void symbol_stat(stat * node_stat);
void symbol_writeln(writeln_list * node_writeln_list);
void symbol_aditional_writeln(aditional_writeln * temp);
void symbol_expression(expression * node_expr);
void symbol_simple_expression(simple_expression * node_simple_expr);
void symbol_terminal(terminal * node_terminal);
void symbol_factor(factor * node_factor);
void symbol_func_design(func_design * node_func_design);
void symbol_aditional_params(aditional_params * temp);

void llvm_all(prog * node_program, symbol_table * llvm_symbols);
void llvm_prog_heading(prog_heading * node_prog_heading);
void llvm_prog_block(prog_block * node_prog_block);
void llvm_var_part(var_part * func_var_part);
void llvm_aditional_var_part(aditional_var_part * temp);
void llvm_var_decl(var_decl * node_var_decl);
void llvm_id_list(id_list * node_id_list, char * id_type);
void llvm_aditional_id_list(aditional_id_list * temp, char * id_type);
void llvm_func_part(func_part * node_func_part);
void llvm_func_decl(func_decl * temp);
void llvm_func_heading(func_heading * node_func_heading);
void llvm_aditional_formal_params_parametros(aditional_formal_params * temp);
void llvm_formal_params_parametros(formal_params * node_formal_params);
void llvm_id_list_parametros(id_list * node_id_list, char * id_type);
void llvm_aditional_id_list_parametros(aditional_id_list * temp, char * id_type);
void llvm_aditional_formal_params(aditional_formal_params * temp);
void llvm_formal_params(formal_params * node_formal_params);
void llvm_func_block(func_block * node_func_block);
void llvm_stat_part(stat_part * node_stat_part);
void llvm_comp_stat(comp_stat * node_comp_stat);
void llvm_stat_list(stat_list * node_stat_list);
void llvm_aditional_stat_list(aditional_stat_list * temp);
void llvm_stat(stat * node_stat);
void llvm_writeln(writeln_list * node_writeln_list);
void llvm_aditional_writeln(aditional_writeln * temp);
void llvm_expression(expression * node_expr);
int llvm_simple_expression(simple_expression * node_simple_expr);
int llvm_terminal(terminal * node_terminal);
int llvm_factor(factor * node_factor);
void llvm_func_design(func_design * node_func_design);
void llvm_aditional_params(aditional_params * temp);

int get_type(char * id);



























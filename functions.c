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
#include <assert.h>
#include "functions.h"

symbol_table * original_node;
int flag = 0;

start * insert_start(prog * program, int linha, int coluna){
	
	start * data = (start *) malloc(sizeof(start));

	if(program != NULL) data->node_program = program;
	else data->node_program = NULL;
	data->posicao = (code_position *) malloc(sizeof(code_position));
	data->posicao->linha = linha;
	data->posicao->coluna = coluna;

	return data;

}

prog * insert_program(prog_heading * heading, prog_block * block, int linha, int coluna){
	
	prog * data = (prog *) malloc(sizeof(prog));

	if(heading != NULL) data->node_prog_heading = heading;
	else data->node_prog_heading = NULL;
	if(block != NULL) data->node_prog_block = block;
	else data->node_prog_block = NULL;

	data->posicao = (code_position *) malloc(sizeof(code_position));
	data->posicao->linha = linha;
	data->posicao->coluna = coluna;

	return data;
}

prog_heading * insert_program_heading(char * id, int linha, int coluna){
	
	prog_heading * data = (prog_heading *) malloc(sizeof(prog_heading));

	if(id != NULL) data->id = id;
	else data->id = NULL;
	data->posicao = (code_position *) malloc(sizeof(code_position));
	data->posicao->linha = linha;
	data->posicao->coluna = coluna;

	return data;
}

prog_block * insert_program_block(var_part * var_Part, func_part * func_Part, stat_part * stat_Part, int linha, int coluna){

	prog_block * data = (prog_block *) malloc(sizeof(prog_block));

	if(var_Part != NULL) data->node_var_part = var_Part;
	if(func_Part != NULL) data->node_func_part = func_Part;
	if(stat_Part != NULL) data->node_stat_part = stat_Part;
	data->posicao = (code_position *) malloc(sizeof(code_position));
	data->posicao->linha = linha;
	data->posicao->coluna = coluna;

	return data;

}

var_part * insert_var_part(var_decl * var_Decl, aditional_var_part * var_Part, int linha, int coluna){

	if(var_Decl == NULL && var_Part == NULL){
		var_part * data = NULL;
		return data;
	}

	var_part * data = (var_part *) malloc(sizeof(var_part));
	
	if(var_Decl != NULL) data->node_var_decl = var_Decl;
	else data->node_var_decl = NULL;
	if(var_Part != NULL) data->next_var_part = var_Part;
	else data->next_var_part = NULL;
	data->posicao = (code_position *) malloc(sizeof(code_position));
	data->posicao->linha = linha;
	data->posicao->coluna = coluna;

	return data;

}

aditional_var_part * insert_aditional_var_part(var_decl * var_Decl, aditional_var_part * var_Part, int linha, int coluna){

	if(var_Decl == NULL && var_Part == NULL){
		aditional_var_part * data = NULL;
		return data;
	}

	aditional_var_part * data = (aditional_var_part *) malloc(sizeof(aditional_var_part));
	
	if(var_Decl != NULL) data->node_var_decl = var_Decl;
	else data->node_var_decl = NULL;
	if(var_Part != NULL) data->next_var_part = var_Part;
	else data->next_var_part = NULL;
	data->posicao = (code_position *) malloc(sizeof(code_position));
	data->posicao->linha = linha;
	data->posicao->coluna = coluna;

	return data;

}

var_decl * insert_var_decl(id_list * id_List, char * id_Type, int linha, int coluna){

	var_decl * data = (var_decl *) malloc(sizeof(var_decl));

	if(id_List != NULL) data->node_id_list = id_List;
	else data->node_id_list = NULL;
	if(id_Type != NULL) data->id_type = id_Type;
	else data->id_type = NULL;
	data->posicao = (code_position *) malloc(sizeof(code_position));
	data->posicao->linha = linha;
	data->posicao->coluna = coluna;

	return data;

}

id_list * insert_id_list(char * id, aditional_id_list * id_List, int linha, int coluna){

	id_list * data = (id_list *) malloc(sizeof(id_list));

	if(id != NULL) data->id = id;
	if(id_List != NULL) data->next_id = id_List;
	else data->next_id = NULL;
	data->posicao = (code_position *) malloc(sizeof(code_position));
	data->posicao->linha = linha;
	data->posicao->coluna = coluna;

	return data;

}

aditional_id_list * insert_aditional_id_list(char * id, aditional_id_list * id_List, int linha, int coluna){

	aditional_id_list * data = (aditional_id_list *) malloc(sizeof(aditional_id_list));

	if(id != NULL) data->id = id;
	else data->id = NULL;
	if(id_List != NULL) data->next_id = id_List;
	else data->next_id = NULL;
	data->posicao = (code_position *) malloc(sizeof(code_position));
	data->posicao->linha = linha;
	data->posicao->coluna = coluna;

	return data;

}

func_part * insert_func_part(func_decl * func_Decl, func_part * func_Part, int linha, int coluna){

	if(func_Decl == NULL) return NULL;

	func_part * data = (func_part *) malloc(sizeof(func_part));

	if(func_Decl != NULL) data->node_func_decl = func_Decl;
	else data->node_func_decl = NULL;
	if(func_Part != NULL) data->node_func_part = func_Part;
	else data->node_func_part = NULL;
	data->posicao = (code_position *) malloc(sizeof(code_position));
	data->posicao->linha = linha;
	data->posicao->coluna = coluna;

	return data;

}

func_decl * insert_func_decl(func_heading * func_Heading, func_block * func_Block, func_ident * func_Ident, int linha, int coluna){

	func_decl * data = (func_decl *) malloc(sizeof(func_decl));

	if(func_Heading != NULL) data->node_func_heading = func_Heading;
	else data->node_func_heading = NULL;
	if(func_Block != NULL) data->node_func_block = func_Block;
	else data->node_func_block = NULL;
	if(func_Ident != NULL) data->node_func_ident = func_Ident;
	else data->node_func_ident = NULL;
	data->posicao = (code_position *) malloc(sizeof(code_position));
	data->posicao->linha = linha;
	data->posicao->coluna = coluna;

	return data;

}

func_heading * insert_func_heading(char * id_func, formal_params_list * formal_Params_List, char * id_type, int linha, int coluna){

	func_heading * data = (func_heading *) malloc(sizeof(func_heading));

	if(id_func != NULL) data->id_func = id_func;
	if(formal_Params_List != NULL) data->node_formal_params_list = formal_Params_List;
	else data->node_formal_params_list = NULL;
	if(id_type != NULL) data->id_type = id_type;
	data->posicao = (code_position *) malloc(sizeof(code_position));
	data->posicao->linha = linha;
	data->posicao->coluna = coluna;

	return data;

}

func_ident * insert_func_ident(char * id, int linha, int coluna){

	func_ident * data = (func_ident *) malloc(sizeof(func_ident));

	if(id != NULL) data->id_func = id;
	data->posicao = (code_position *) malloc(sizeof(code_position));
	data->posicao->linha = linha;
	data->posicao->coluna = coluna;

	return data;

}

formal_params_list * insert_formal_params_list(formal_params * formal_Params, aditional_formal_params * aditional_params, int linha, int coluna){

	formal_params_list * data = (formal_params_list *) malloc(sizeof(formal_params_list));

	if(formal_Params != NULL) data->node_formal_params = formal_Params;
	else data->node_formal_params = NULL;
	if(aditional_params != NULL) data->next_formal_params = aditional_params;
	else data->next_formal_params = NULL;
	data->posicao = (code_position *) malloc(sizeof(code_position));
	data->posicao->linha = linha;
	data->posicao->coluna = coluna;

	return data;

}

aditional_formal_params * insert_aditional_formal_params(formal_params * formal_Params, aditional_formal_params * aditional_params, int linha, int coluna){

	if(formal_Params == NULL && aditional_params == NULL) return NULL;

	aditional_formal_params * data = (aditional_formal_params *) malloc(sizeof(aditional_formal_params));

	if(formal_Params != NULL) data->node_formal_params = formal_Params;
	else data->node_formal_params = NULL;
	if(aditional_params != NULL) data->next_formal_params = aditional_params;
	else data->next_formal_params = NULL;
	data->posicao = (code_position *) malloc(sizeof(code_position));
	data->posicao->linha = linha;
	data->posicao->coluna = coluna;

	return data;

}

formal_params * insert_formal_params(id_list * id_List, char * id, char * type, int linha, int coluna){

	formal_params * data = (formal_params *) malloc(sizeof(formal_params));

	if(id_List != NULL) data->node_id_list = id_List;
	else data->node_id_list = NULL;
	if(id != NULL) data->id_type = id;
	if(type != NULL) data->type_var = type;
	data->posicao = (code_position *) malloc(sizeof(code_position));
	data->posicao->linha = linha;
	data->posicao->coluna = coluna;

	return data;

}

func_block * insert_func_block(var_part * var_Part, stat_part * stat_Part, int linha, int coluna){

	func_block * data = (func_block *) malloc(sizeof(func_block));

	if(var_Part != NULL) data->node_var_part = var_Part;
	else data->node_var_part = NULL;
	if(stat_Part != NULL) data->node_stat_part = stat_Part;
	else data->node_stat_part = NULL;
	data->posicao = (code_position *) malloc(sizeof(code_position));
	data->posicao->linha = linha;
	data->posicao->coluna = coluna;

	return data;

}

stat_part * insert_stat_part(comp_stat * comp_Stat, int linha, int coluna){

	stat_part * data = (stat_part *) malloc(sizeof(stat_part));

	if(comp_Stat != NULL) data->node_comp_stat = comp_Stat;
	else data->node_comp_stat = NULL;
	data->posicao = (code_position *) malloc(sizeof(code_position));
	data->posicao->linha = linha;
	data->posicao->coluna = coluna;

	return data;

}

comp_stat * insert_comp_stat(stat_list * stat_List, int linha, int coluna){

	comp_stat * data = (comp_stat *) malloc(sizeof(comp_stat));

	if(stat_List != NULL) data->node_stat_list = stat_List;
	else data->node_stat_list = NULL;
	data->posicao = (code_position *) malloc(sizeof(code_position));
	data->posicao->linha = linha;
	data->posicao->coluna = coluna;

	return data;

}

stat_list * insert_stat_list(stat * statement, aditional_stat_list * aditional_Stat_List, int linha, int coluna){

	stat_list * data = (stat_list *) malloc(sizeof(stat_list));

	if(statement != NULL) data->node_stat = statement;
	else data->node_stat = NULL;
	if(aditional_Stat_List != NULL) data->next_stat_list = aditional_Stat_List;
	else data->next_stat_list = NULL;
	data->posicao = (code_position *) malloc(sizeof(code_position));
	data->posicao->linha = linha;
	data->posicao->coluna = coluna;

	return data;

}

aditional_stat_list * insert_aditional_stat_list(stat * statement, aditional_stat_list * aditional_Stat_List, int linha, int coluna){

	if(statement == NULL && aditional_Stat_List == NULL) return NULL;

	aditional_stat_list * data = (aditional_stat_list *) malloc(sizeof(aditional_stat_list));

	if(statement != NULL) data->node_stat = statement;
	else data->node_stat = NULL;
	if(aditional_Stat_List != NULL) data->next_stat_list = aditional_Stat_List;
	else data->next_stat_list = NULL;
	data->posicao = (code_position *) malloc(sizeof(code_position));
	data->posicao->linha = linha;
	data->posicao->coluna = coluna;

	return data;

}

stat * insert_statment(comp_stat * comp_Stat, expression * expr, stat * statement, stat * else_stat, stat_list * stat_List, char * id, writeln_list * writeln, char * operation, int linha, int coluna){
	
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

	if(strcmp(operation, "s-1") == 0) return NULL;

	stat * data = (stat *) malloc(sizeof(stat));

	if(comp_Stat != NULL) data->node_comp_stat = comp_Stat;
	if(expr != NULL) data->node_expr = expr;
	else data->node_expr = NULL;
	if(else_stat != NULL) data->node_stat2 = else_stat;
	if(statement != NULL) data->node_stat = statement;
	else data->node_stat = NULL;
	if(stat_List != NULL) data->node_stat_list = stat_List;
	if(id != NULL) data->id = id;
	if(writeln != NULL) data->node_writeln_list = writeln;
	if(operation != NULL) data->operation_type = operation;
	data->posicao = (code_position *) malloc(sizeof(code_position));
	data->posicao->linha = linha;
	data->posicao->coluna = coluna;

	return data;

}

writeln_list * insert_writeln(expression * expr, aditional_writeln * aditional_Writeln, char * string, int linha, int coluna){

	writeln_list * data = (writeln_list *) malloc(sizeof(writeln_list));

	if(expr != NULL) data->node_expr = expr;
	if(aditional_Writeln != NULL) data->next = aditional_Writeln;
	else data->next = NULL;
	if(string != NULL) data->string = string;
	data->posicao = (code_position *) malloc(sizeof(code_position));
	data->posicao->linha = linha;
	data->posicao->coluna = coluna;

	return data;

}

aditional_writeln * insert_aditional_writeln(expression * expr, aditional_writeln * aditional_Writeln, char * string, int linha, int coluna){

	if(expr == NULL && aditional_Writeln == NULL && string == NULL) return NULL;

	aditional_writeln * data = (aditional_writeln *) malloc(sizeof(aditional_writeln));

	if(expr != NULL) data->node_expr = expr;
	else data->node_expr = NULL;
	if(aditional_Writeln != NULL) data->next = aditional_Writeln;
	else data->next = NULL;
	if(string != NULL) data->string = string;
	data->posicao = (code_position *) malloc(sizeof(code_position));
	data->posicao->linha = linha;
	data->posicao->coluna = coluna;

	return data;

}

expression * insert_expression(simple_expression * expr, simple_expression * expr2, char * id, char * operation, int linha, int coluna){

	/*
        1 - Simple
        2 - OP2
    */

	expression * data = (expression *) malloc(sizeof(expression));

	if(id != NULL) data->id = id;
	if(operation != NULL) data->operation_type = operation;
	if(expr != NULL) data->node_simple_expr = expr;
	else data->node_simple_expr = NULL;
	if(expr2 != NULL) data->node_simple_expr2 = expr2;
	else data->node_simple_expr2 = NULL;
	data->posicao = (code_position *) malloc(sizeof(code_position));
	data->posicao->linha = linha;
	data->posicao->coluna = coluna;

	return data;

}

simple_expression * insert_simple_expression(simple_expression * expr, terminal * term, char * id, char * operation, int linha, int coluna){

	/*
        1 - OP3
        2 - OR
        3 - OP3 Terminal
        4 - Terminal
    */

	simple_expression * data = (simple_expression *) malloc(sizeof(simple_expression));

	if(expr != NULL) data->node_simple_expr = expr;
	else data->node_simple_expr = NULL;
	if(term != NULL) data->node_terminal = term;
	else data->node_terminal = NULL;
	if(id != NULL) data->id = id;
	if(operation != NULL) data->operation_type = operation;
	data->posicao = (code_position *) malloc(sizeof(code_position));
	data->posicao->linha = linha;
	data->posicao->coluna = coluna;

	return data;

}

terminal * insert_terminal(terminal * term1, terminal * term2, factor * node_factor, char * id, char * operation, int linha, int coluna){

	/*
        1 - OP4
        2 - AND
        3 - Factor
    */

	terminal * data = (terminal *) malloc(sizeof(terminal));

	if(term1 != NULL) data->node_terminal = term1;
	else data->node_terminal = NULL;
	if(term2 != NULL) data->node_terminal2 = term2;
	else data->node_terminal2 = NULL;
	if(node_factor != NULL) data->node_factor = node_factor;
	else data->node_factor = NULL;
	if(id != NULL) data->id = id;
	if(operation != NULL) data->operation_type = operation;
	data->posicao = (code_position *) malloc(sizeof(code_position));
	data->posicao->linha = linha;
	data->posicao->coluna = coluna;

	return data;

}



factor * insert_factor(char * id, expression * expr, factor * node_factor, func_design * design, char * type, int linha, int coluna){

	/*
        1 - ID
        2 - INTLIT
        3 - REALLIT
        4 - FuncDesign
        5 - Expr
        6 - NOT
    */

	factor * data = (factor *) malloc(sizeof(factor *));

	//if(type != NULL) data->type = type;
	if(id != NULL) data->id = id;
	if(node_factor != NULL) data->node_factor = node_factor;
	else data->node_factor = NULL;
	if(expr != NULL) data->node_expr = expr;
	else data->node_expr = NULL;
	if(design != NULL){ 
		data->node_func_design = design;
		//data->node_func_design2 = design;
	}
	else{
		data->node_func_design = NULL;
		//data->node_func_design2 = NULL;
	}
	if(type != NULL) data->type2 = type;
	data->posicao = (code_position *) malloc(sizeof(code_position));
	data->posicao->linha = linha;
	data->posicao->coluna = coluna;

	data->posicao2 = (code_position *) malloc(sizeof(code_position));
	data->posicao2->linha = linha;
	data->posicao2->coluna = coluna;


	return data;

}

func_design * insert_func_design(char * id, param_list * params, int linha, int coluna){

	func_design * data = (func_design *) malloc(sizeof(func_design));

	if(id != NULL) data->id = id;
	if(params != NULL) data->param_list = params;
	else data->param_list = NULL;

	return data;

}

param_list * insert_params_list(expression * expr, aditional_params * aditional_Params, int linha, int coluna){

	param_list * data = (param_list *) malloc(sizeof(param_list));

	if(expr != NULL) data->node_expr = expr;
	else data->node_expr = NULL;
	if(aditional_Params != NULL) data->next_param = aditional_Params;
	else data->next_param = NULL;
	data->posicao = (code_position *) malloc(sizeof(code_position));
	data->posicao->linha = linha;
	data->posicao->coluna = coluna;

	return data;

}

aditional_params * insert_aditional_params(expression * expr, aditional_params * aditional_Params, int linha, int coluna){

	if(expr == NULL && aditional_Params == NULL) return NULL;

	aditional_params * data = (aditional_params *) malloc(sizeof(aditional_params));

	if(expr != NULL) data->node_expr = expr;
	else data->node_expr = NULL;
	if(aditional_Params != NULL) data->next_param = aditional_Params;
	else data->next_param = NULL;
	data->posicao = (code_position *) malloc(sizeof(code_position));
	data->posicao->linha = linha;
	data->posicao->coluna = coluna;

	return data;

}


int advance = 0;

void alignment(){

	int i;
	for(i = 0; i < advance; i++) printf("..");

}

void print_all(prog * node_program){

	flag = 1;

	if(node_program != NULL){
		
		alignment();

		printf("Program\n");

		advance++;

		print_prog_heading(node_program->node_prog_heading);
		print_prog_block(node_program->node_prog_block);

		advance--;

	}

}

void print_prog_heading(prog_heading * node_prog_heading){ /**/

	if(node_prog_heading != NULL){

		alignment();

		printf("Id(%s)\n", node_prog_heading->id);

	}

}

void print_prog_block(prog_block * node_prog_block){

	if(node_prog_block != NULL){

		alignment();

		printf("VarPart\n"); /**/

		if(node_prog_block->node_var_part != NULL){

			advance++;

			print_var_part(node_prog_block->node_var_part);

			advance--;

		}

		alignment();

		printf("FuncPart\n");
		
		if(node_prog_block->node_func_part != NULL){

			advance++;

			print_func_part(node_prog_block->node_func_part);

			advance--;

		}

		if(node_prog_block->node_stat_part->node_comp_stat->node_stat_list->node_stat != NULL){

			if(node_prog_block->node_stat_part->node_comp_stat->node_stat_list->next_stat_list != NULL){

				alignment();

				printf("StatList\n");

				advance++;

				print_stat_part(node_prog_block->node_stat_part);

				advance--;

			}
			else
				print_stat_part(node_prog_block->node_stat_part);

		}
		else{

			alignment();

			printf("StatList\n");

		}

	}
	else{

		alignment();

		printf("StatList\n");

	}

}

void print_var_part(var_part * func_var_part){ /**/

	if(func_var_part != NULL){

		var_part * temp = func_var_part;

		if(temp->node_var_decl != NULL){

			alignment();

			printf("VarDecl\n");

			advance++;

			print_var_decl(temp->node_var_decl);
			
			advance--;

		}

		if(temp->next_var_part != NULL){

			print_aditional_var_part(temp->next_var_part);


		}

	}

}

void print_aditional_var_part(aditional_var_part * temp){ /**/

	alignment();

	printf("VarDecl\n");

	advance++;

	print_var_decl(temp->node_var_decl);

	advance--;

	if(temp->next_var_part != NULL)
		print_aditional_var_part(temp->next_var_part);

}

void print_var_decl(var_decl * node_var_decl){ /**/

	if(node_var_decl != NULL){

		print_id_list(node_var_decl->node_id_list);

		alignment();

		printf("Id(%s)\n", node_var_decl->id_type);

	}

}

void print_id_list(id_list * node_id_list){/**/

	if(node_id_list != NULL){

		alignment();

		printf("Id(%s)\n", node_id_list->id);

		if(node_id_list->next_id != NULL){

			print_aditional_id_list(node_id_list->next_id);

		}

	}

}

void print_aditional_id_list(aditional_id_list * temp){/**/

	if(temp->id != NULL){

		alignment();

		printf("Id(%s)\n", temp->id);

		if(temp->next_id != NULL && temp->next_id->id != NULL){

			temp = temp->next_id;

			print_aditional_id_list(temp);

		}

	}

}

void print_func_part(func_part * node_func_part){

	if(node_func_part != NULL){

		if(node_func_part->node_func_decl != NULL){

			print_func_decl(node_func_part->node_func_decl);

		}

	}

	if(node_func_part->node_func_part != NULL) print_func_part(node_func_part->node_func_part);

}

void print_func_decl(func_decl * temp){

	alignment();

	if(temp->node_func_heading != NULL){
		
		if(temp->node_func_block != NULL){

			printf("FuncDef\n");

			advance++;

			print_func_heading(temp->node_func_heading);

			if(temp->node_func_block != NULL)
				print_func_block(temp->node_func_block);
			else {

				alignment();

				printf("VarPart\n");	

				alignment();

				printf("StatList\n");

			}

			advance--;

		}
		else{

			printf("FuncDecl\n");

			advance++;

			print_func_heading(temp->node_func_heading);

			advance--;
		}

	}

	if(temp->node_func_ident != NULL){
		
		if(temp->node_func_block != NULL){

			printf("FuncDef2\n");

			advance++;

			alignment();

			if(temp->node_func_ident->id_func != NULL) printf("Id(%s)\n", temp->node_func_ident->id_func);

			if(temp->node_func_block != NULL)
				print_func_block(temp->node_func_block);
			else {

				alignment();

				printf("StatList\n");

			}

			advance--;

		}

	}

}

void print_func_heading(func_heading * node_func_heading){

	if(node_func_heading->id_func != NULL){

		alignment();

		printf("Id(%s)\n", node_func_heading->id_func);

	}

	if(node_func_heading->node_formal_params_list != NULL){

		alignment();

		printf("FuncParams\n");

		advance++;

		if(node_func_heading->node_formal_params_list->node_formal_params != NULL){

			print_formal_params(node_func_heading->node_formal_params_list->node_formal_params);

		}	

		if(node_func_heading->node_formal_params_list->next_formal_params != NULL){

			print_aditional_formal_params(node_func_heading->node_formal_params_list->next_formal_params);

		}

		advance--;

	}
	else{

		alignment();

		printf("FuncParams\n");

	}

	if(node_func_heading->id_type != NULL){

		alignment();

		printf("Id(%s)\n", node_func_heading->id_type);

	}

}

void print_aditional_formal_params(aditional_formal_params * temp){

	if(temp->node_formal_params != NULL)
		print_formal_params(temp->node_formal_params);

	if(temp->next_formal_params != NULL)
		print_aditional_formal_params(temp->next_formal_params);

}

void print_formal_params(formal_params * node_formal_params){

	if(strcmp(node_formal_params->type_var, "fp1") == 0){

		alignment();

		printf("VarParams\n");

		advance++;

		print_id_list(node_formal_params->node_id_list);

		alignment();

		printf("Id(%s)\n", node_formal_params->id_type);

		advance--;

	}
	else if(strcmp(node_formal_params->type_var, "fp2") == 0){

		alignment();

		printf("Params\n");

		advance++;

		print_id_list(node_formal_params->node_id_list);

		alignment();

		printf("Id(%s)\n", node_formal_params->id_type);

		advance--;

	}

}

void print_func_block(func_block * node_func_block){

	if(node_func_block->node_var_part != NULL){

		alignment();

		printf("VarPart\n");

		advance++;

		print_var_part(node_func_block->node_var_part);

		advance--;

	}
	else{

		alignment();

		printf("VarPart\n");

	}

	if(node_func_block->node_stat_part->node_comp_stat->node_stat_list->node_stat != NULL){

		if(node_func_block->node_stat_part->node_comp_stat->node_stat_list->next_stat_list != NULL){

			alignment();

			printf("StatList\n");

			advance++;

			print_stat_part(node_func_block->node_stat_part);

			advance--;

		}
		else{

			print_stat_part(node_func_block->node_stat_part);

		}

	}
	else{

		alignment();

		printf("StatList\n");

	}

}

void print_stat_part(stat_part * node_stat_part){

	if(node_stat_part->node_comp_stat != NULL)
		print_comp_stat(node_stat_part->node_comp_stat);

}

void print_comp_stat(comp_stat * node_comp_stat){

	if(node_comp_stat->node_stat_list != NULL)
		print_stat_list(node_comp_stat->node_stat_list);

}

void print_stat_list(stat_list * node_stat_list){

	if(node_stat_list->node_stat != NULL){

		print_stat(node_stat_list->node_stat);

	}
	else{
		alignment();
		printf("StatList\n");
	}

	if(node_stat_list->next_stat_list != NULL){

		print_aditional_stat_list(node_stat_list->next_stat_list);


	}

}

void print_aditional_stat_list(aditional_stat_list * temp){

	if(temp->node_stat != NULL)
		print_stat(temp->node_stat);
	else{
		alignment();
		printf("StatList\n");
	}

	if(temp->next_stat_list != NULL){

		print_aditional_stat_list(temp->next_stat_list);

	}

}

void print_stat(stat * node_stat){

	if(strcmp(node_stat->operation_type, "s-1") == 0) return;

	if(strcmp(node_stat->operation_type, "s1") == 0){

		if(node_stat->node_comp_stat->node_stat_list->next_stat_list != NULL){

			if(node_stat->node_comp_stat->node_stat_list->next_stat_list->node_stat != NULL){

				/*

					FUNCAO CHECK

				*/

				alignment();

				printf("StatList\n");

				advance++;

				print_comp_stat(node_stat->node_comp_stat);

				advance--;

			}

		}
		else{

			print_comp_stat(node_stat->node_comp_stat);

		}
		
	}
	else if(strcmp(node_stat->operation_type, "s2") == 0){

		alignment();

		printf("IfElse\n");

		advance++;

		print_expression(node_stat->node_expr);
		
		if(node_stat->node_stat != NULL)
			print_stat(node_stat->node_stat);
		else{
			alignment();
			printf("StatList\n");
		}

		if(node_stat->node_stat2 != NULL)
			print_stat(node_stat->node_stat2);
		else{
			alignment();
			printf("StatList\n");
		}

		advance--;

	}
	else if(strcmp(node_stat->operation_type, "s3") == 0){

		alignment();

		printf("IfElse\n");

		advance++;

		print_expression(node_stat->node_expr);
		
		if(node_stat->node_stat != NULL)
			print_stat(node_stat->node_stat);
		else{
			alignment();
			printf("StatList\n");
		}

		if(node_stat->node_stat2 != NULL)
			print_stat(node_stat->node_stat2);
		else{
			alignment();
			printf("StatList\n");
		}

		advance--;

	}
	else if(strcmp(node_stat->operation_type, "s4") == 0){

		alignment();

		printf("While\n");

		advance++;

		print_expression(node_stat->node_expr);

		if(node_stat->node_stat != NULL){
			print_stat(node_stat->node_stat);
		}
		else{
			alignment();
			printf("StatList\n");
		}

		advance--;

	}
	else if(strcmp(node_stat->operation_type, "s5") == 0){

		alignment();

		printf("Repeat\n");

		advance++;

		if(node_stat->node_stat_list != NULL){
			print_stat_list(node_stat->node_stat_list);
		}
		else{
			alignment();
			printf("StatList\n");
		}
		
		print_expression(node_stat->node_expr);

		advance--;

	}
	else if(strcmp(node_stat->operation_type, "s6") == 0){

		alignment();

		printf("ValParam\n");

		advance++;
		
		print_expression(node_stat->node_expr);
		
		alignment();
		printf("Id(%s)\n", node_stat->id);

		advance--;

	}
	else if(strcmp(node_stat->operation_type, "s7") == 0){

		alignment();

		printf("Assign\n");

		advance++;

		alignment();
		printf("Id(%s)\n", node_stat->id);
		
		print_expression(node_stat->node_expr);

		advance--;

	}
	else if(strcmp(node_stat->operation_type, "s8") == 0){

		alignment();

		printf("WriteLn\n");

		advance++;

		if(node_stat->node_writeln_list != NULL)
			print_writeln(node_stat->node_writeln_list);

		advance--;
		
	}

}

void print_writeln(writeln_list * node_writeln_list){

	if(node_writeln_list->node_expr != NULL)
		print_expression(node_writeln_list->node_expr);
	else if(node_writeln_list->string != NULL){

		alignment();

		printf("String(%s)\n", node_writeln_list->string);

	}

	if(node_writeln_list->next != NULL)
		print_aditional_writeln(node_writeln_list->next);

}

void print_aditional_writeln(aditional_writeln * temp){

	if(temp->node_expr != NULL)
		print_expression(temp->node_expr);
	else if(temp->string != NULL){

		alignment();

		printf("String(%s)\n", temp->string);

	}

	if(temp->next != NULL)
		print_aditional_writeln(temp->next);

}

void print_expression(expression * node_expr){

	if(strcmp(node_expr->operation_type, "e1") == 0){
		print_simple_expression(node_expr->node_simple_expr);
	}
	else if(strcmp(node_expr->operation_type, "e2") == 0){
		
		alignment();

		if(strcmp(node_expr->id, "<") == 0){

			printf("Lt\n");

			advance++;

			print_simple_expression(node_expr->node_simple_expr);

			print_simple_expression(node_expr->node_simple_expr2);

			advance--;

		}
		else if(strcmp(node_expr->id, ">") == 0){

			printf("Gt\n");

			advance++;

			print_simple_expression(node_expr->node_simple_expr);

			print_simple_expression(node_expr->node_simple_expr2);

			advance--;

		}
		else if(strcmp(node_expr->id, "<=") == 0){

			printf("Leq\n");

			advance++;

			print_simple_expression(node_expr->node_simple_expr);

			print_simple_expression(node_expr->node_simple_expr2);

			advance--;

		}
		else if(strcmp(node_expr->id, ">=") == 0){

			printf("Geq\n");

			advance++;

			print_simple_expression(node_expr->node_simple_expr);

			print_simple_expression(node_expr->node_simple_expr2);

			advance--;

		}
		else if(strcmp(node_expr->id, "=") == 0){

			printf("Eq\n");

			advance++;

			print_simple_expression(node_expr->node_simple_expr);

			print_simple_expression(node_expr->node_simple_expr2);

			advance--;

		}
		else if(strcmp(node_expr->id, "<>") == 0){

			printf("Neq\n");

			advance++;

			print_simple_expression(node_expr->node_simple_expr);

			print_simple_expression(node_expr->node_simple_expr2);

			advance--;

		}

	}

}

void print_simple_expression(simple_expression * node_simple_expr){

	if(strcmp(node_simple_expr->operation_type, "se1") == 0){

		alignment();

		if(strcmp(node_simple_expr->id, "+") == 0){

			printf("Add\n");

			advance++;

			print_simple_expression(node_simple_expr->node_simple_expr);

			print_terminal(node_simple_expr->node_terminal);

			advance--;

		}
		else if(strcmp(node_simple_expr->id, "-") == 0){

			printf("Sub\n");

			advance++;

			print_simple_expression(node_simple_expr->node_simple_expr);

			print_terminal(node_simple_expr->node_terminal);

			advance--;

		}

	}
	else if(strcmp(node_simple_expr->operation_type, "se2") == 0){

		alignment();

		printf("Or\n");

		advance++;

		print_simple_expression(node_simple_expr->node_simple_expr);

		print_terminal(node_simple_expr->node_terminal);

		advance--;

	}
	else if(strcmp(node_simple_expr->operation_type, "se3") == 0){

		alignment();

		if(strcmp(node_simple_expr->id, "+") == 0){

			printf("Plus\n");

			advance++;

			print_terminal(node_simple_expr->node_terminal);

			advance--;

		}
		else if(strcmp(node_simple_expr->id, "-") == 0){

			printf("Minus\n");

			advance++;

			print_terminal(node_simple_expr->node_terminal);

			advance--;

		}

	}
	else if(strcmp(node_simple_expr->operation_type, "se4") == 0){

		print_terminal(node_simple_expr->node_terminal);

	}

}

void print_terminal(terminal * node_terminal){

	if(strcmp(node_terminal->operation_type, "t1") == 0){

		alignment();

		if(strcmp(node_terminal->id, "*") == 0){

			printf("Mul\n");

			advance++;

			print_terminal(node_terminal->node_terminal);

			print_terminal(node_terminal->node_terminal2);

			advance--;

		}
		else if(strcmp(node_terminal->id, "/") == 0){

			printf("RealDiv\n");

			advance++;

			print_terminal(node_terminal->node_terminal);

			print_terminal(node_terminal->node_terminal2);

			advance--;

		}
		else if(strcmp(node_terminal->id, "mod") == 0){

			printf("Mod\n");

			advance++;

			print_terminal(node_terminal->node_terminal);

			print_terminal(node_terminal->node_terminal2);

			advance--;

		}
		else if(strcmp(node_terminal->id, "div") == 0){

			printf("Div\n");

			advance++;

			print_terminal(node_terminal->node_terminal);

			print_terminal(node_terminal->node_terminal2);

			advance--;

		}

	}
	else if(strcmp(node_terminal->operation_type, "t2") == 0){

		alignment();

		printf("And\n");

		advance++;

		print_terminal(node_terminal->node_terminal);

		print_terminal(node_terminal->node_terminal2);

		advance--;

	}
	else if(strcmp(node_terminal->operation_type, "t3") == 0){

		print_factor(node_terminal->node_factor);

	}

}

void print_factor(factor * node_factor){

	if(strcmp(node_factor->type2, "id") == 0){

		alignment();

		printf("Id(%s)\n", node_factor->id);

	}
	else if(strcmp(node_factor->type2, "int") == 0){

		alignment();

		printf("IntLit(%s)\n", node_factor->id);

	}
	else if(strcmp(node_factor->type2, "real") == 0){

		alignment();

		printf("RealLit(%s)\n", node_factor->id);

	}
	else if(strcmp(node_factor->type2, "func") == 0){
		
		if(node_factor->node_func_design != NULL){

			print_func_design(node_factor->node_func_design);

		}
		
	}
	else if(strcmp(node_factor->type2, "expr") == 0){

		if(node_factor->node_expr != NULL){
			print_expression(node_factor->node_expr);
		} 
		
	}
	else if(strcmp(node_factor->type2, "fact") == 0){

		alignment();

		printf("Not\n");

		advance++;

		if(node_factor->node_factor != NULL)
			print_factor(node_factor->node_factor);

		advance--;
		
	}

}

void print_func_design(func_design * node_func_design){

	alignment();

	printf("Call\n");

	advance++;

	alignment();

	printf("Id(%s)\n", node_func_design->id);

	if(node_func_design->param_list != NULL){

		if(node_func_design->param_list->node_expr != NULL){

			print_expression(node_func_design->param_list->node_expr);

		}

		if(node_func_design->param_list->next_param != NULL){

			print_aditional_params(node_func_design->param_list->next_param);

		}

	}

	advance--;


}

void print_aditional_params(aditional_params * temp){

	if(temp->node_expr != NULL)
		print_expression(temp->node_expr);

	if(temp->next_param != NULL)
		print_aditional_params(temp->next_param);

}

char * error_type = NULL;
char * operation = NULL;
char * previous_type = NULL;
char * assignment_token = NULL;
symbol_table * table_state = NULL;
symbol_entry * entry_state = NULL;
symbol_entry * global_variables = NULL;

char * strtolower(char * str){
  
	char * string = str;

	if(str){
    	for(; *str; ++str)
      		*str = tolower(*str);
  	}

  	return string;

}

void print_symbol_table(symbol_table * symbols){

	if(flag == 1) printf("\n");

	printf("===== Outer Symbol Table =====\n");
	printf("boolean\t_type_\tconstant\t_boolean_\n");
	printf("integer\t_type_\tconstant\t_integer_\n");
	printf("real\t_type_\tconstant\t_real_\n");
	printf("false\t_boolean_\tconstant\t_false_\n");
	printf("true\t_boolean_\tconstant\t_true_\n");
	printf("paramcount\t_function_\n");
	printf("program\t_program_\n");

	printf("\n");

	printf("===== Function Symbol Table =====\n");
	printf("paramcount\t_integer_\treturn\n");

	printf("\n");

	symbol_entry * temp = symbols->node_symbol_entry;

	printf("===== Program Symbol Table =====\n");

	while(temp != NULL){
		if(temp->id != NULL && temp->type != NULL){
			char * id_print = strtolower(temp->id);
			printf("%s\t_%s_\n", id_print, temp->type);
		}
		temp = temp->next_symbol_entry;
	}

	symbol_table * aux = symbols->next_symbol_table;

	while(aux != NULL){

		if(aux->node_symbol_entry != NULL){
			printf("\n");
			printf("===== Function Symbol Table =====\n");
		}

		symbol_entry * bla = aux->node_symbol_entry;

		while(bla != NULL){
			if(bla->id != NULL && bla->type != NULL && bla->second_type != NULL){
				char * id_print = strtolower(bla->id);
				printf("%s\t_%s_\t%s\n", id_print, bla->type, bla->second_type);
			}
			else if(bla->id != NULL && bla->type != NULL){
				char * id_print = strtolower(bla->id);
				printf("%s\t_%s_\n", id_print, bla->type);
			}
			bla = bla->next_symbol_entry;
		}

		aux = aux->next_symbol_table;

	}

}

void build_symbol_table(prog * node_program, symbol_table * symbols){

	original_node = symbols;

	if(node_program->node_prog_block != NULL){

		if(node_program->node_prog_block->node_var_part != NULL){

			if(node_program->node_prog_block->node_var_part != NULL){

				var_part * temp = node_program->node_prog_block->node_var_part;

				if(temp != NULL){

					if(temp->node_var_decl != NULL){

						symbols->type = "global";

						symbol_entry * aux = (symbol_entry *) malloc(sizeof(symbol_entry));

						symbols->node_symbol_entry = aux;

						global_variables = symbols->node_symbol_entry;

						symbol_var_decl(temp->node_var_decl, symbols->node_symbol_entry);

					}

					if(temp->next_var_part != NULL){

						symbol_aditional_var_part(temp->next_var_part, symbols);

					}

				}

			}

		}
		
		if(node_program->node_prog_block->node_func_part != NULL){

			error_type = "function";

			symbols->next_symbol_table = (symbol_table *) malloc(sizeof(symbol_table));

			symbol_func_part(node_program->node_prog_block->node_func_part, symbols->next_symbol_table);

			symbol_entry * temp = symbols->node_symbol_entry;

			symbol_table * aux = symbols->next_symbol_table;

			int flagp = 0;

			if(temp != NULL){

				while(temp->next_symbol_entry != NULL) temp = temp->next_symbol_entry;

			}
			else flagp = 1;

			while(aux != NULL){

				if(aux->node_symbol_entry != NULL){

					if(flagp == 0){

						temp->next_symbol_entry = (symbol_entry *) malloc(sizeof(symbol_entry));

						temp->next_symbol_entry->id = aux->node_symbol_entry->id;
						temp->next_symbol_entry->type = "function";

						temp = temp->next_symbol_entry;

					}
					else{

						symbol_entry * blaa = (symbol_entry *) malloc(sizeof(symbol_entry));

						blaa->id = aux->node_symbol_entry->id;
						blaa->type = "function";

						symbols->node_symbol_entry = blaa;

						temp = symbols->node_symbol_entry;

						flagp = 0;

					}

				}

				aux = aux->next_symbol_table;

			}

		}

		if(node_program->node_prog_block->node_stat_part != NULL){

			error_type = "global";

			if(node_program->node_prog_block->node_stat_part->node_comp_stat->node_stat_list->node_stat != NULL){

				if(node_program->node_prog_block->node_stat_part->node_comp_stat->node_stat_list->next_stat_list != NULL){

					symbol_stat_part(node_program->node_prog_block->node_stat_part);

				}
				else
					symbol_stat_part(node_program->node_prog_block->node_stat_part);

				

			}

		}

	}

}

void symbol_aditional_var_part(aditional_var_part * temp, symbol_table * symbols){ /**/

	operation = "vardecl";

	symbol_entry * aux = symbols->node_symbol_entry;

	while(aux->next_symbol_entry != NULL) aux = aux->next_symbol_entry;

	aux->next_symbol_entry = (symbol_entry *) malloc(sizeof(symbol_entry));

	symbol_var_decl(temp->node_var_decl, aux->next_symbol_entry);

	if(temp->next_var_part != NULL)
		symbol_aditional_var_part(temp->next_var_part, symbols);

	operation = NULL;

}

var_decl * state_var_decl = NULL;

void symbol_var_decl(var_decl * node_var_decl, symbol_entry * symbol_Entry){ /**/

	operation = "vardecl";

	state_var_decl = node_var_decl;

	if(node_var_decl != NULL){

		symbol_id_list(node_var_decl->node_id_list, node_var_decl->id_type, symbol_Entry, NULL);

	}

	operation = NULL;

}

void symbol_id_list(id_list * node_id_list, char * type, symbol_entry * symbol_Entry, char * second_type){/**/

	if(node_id_list != NULL){

		if(error_type != NULL){
			if(strcmp(error_type, "function") == 0){
				if(operation != NULL){
					if(strcmp(operation, "vardecl") == 0){
						if(entry_state != NULL){

							symbol_entry * temp = entry_state;

							while(temp != NULL){

								if(temp->id != NULL)
									if(strcmp(temp->id, node_id_list->id) == 0){
										int j = node_id_list->posicao->coluna - strlen(node_id_list->id);
										//printf("Line %d, col %d: Symbol %s already defined\n", node_id_list->posicao->linha, j, node_id_list->id);
										//exit(0);
										break;
									}

								temp = temp->next_symbol_entry;

							}
						}
					}
				}
			}
			else if(strcmp(error_type, "global") == 0){
				if(operation != NULL){
					if(strcmp(operation, "vardecl") == 0){
						if(global_variables != NULL){
							if(global_variables != NULL){

								symbol_entry * temp = global_variables;

								while(temp != NULL){

									if(temp->id != NULL)
										if(strcmp(temp->id, node_id_list->id) == 0){ 
											int j = node_id_list->posicao->coluna - strlen(node_id_list->id);
											//printf("Line %d, col %d: Symbol %s already defined\n", node_id_list->posicao->linha, j, node_id_list->id);
											//exit(0);
											break;
										}

									temp = temp->next_symbol_entry;

								}
							}
						}
					}
				}
			}
		}

		symbol_Entry->id = node_id_list->id;
		symbol_Entry->type = strtolower(type);
		if(second_type != NULL) symbol_Entry->second_type = second_type;

		if(strcmp(symbol_Entry->type, "integer") != 0 && strcmp(symbol_Entry->type, "real") != 0 && strcmp(symbol_Entry->type, "string") != 0 && strcmp(symbol_Entry->type, "boolean") != 0 && strcmp(symbol_Entry->type, "false") != 0 && strcmp(symbol_Entry->type, "true") != 0){
			if(state_var_decl != NULL){
				int j = state_var_decl->posicao->coluna-strlen(symbol_Entry->type)-1;
				//printf("Line %d, col %d: Type identifier expected\n", state_var_decl->posicao->linha, j);
				//exit(0);
			}
		}

		if(node_id_list->next_id != NULL){

			symbol_Entry->next_symbol_entry = (symbol_entry *) malloc(sizeof(symbol_entry));

			symbol_aditional_id_list(node_id_list->next_id, type, symbol_Entry->next_symbol_entry, second_type);

		}

	}

}

void symbol_aditional_id_list(aditional_id_list * temp, char * type, symbol_entry * new_entry, char * second_type){/**/

	if(temp->id != NULL){

		new_entry->id = temp->id;
		new_entry->type = strtolower(type);
		if(second_type != NULL) new_entry->second_type = second_type;

		if(strcmp(new_entry->type, "integer") != 0 && strcmp(new_entry->type, "real") != 0 && strcmp(new_entry->type, "string") != 0 && strcmp(new_entry->type, "boolean") != 0 && strcmp(new_entry->type, "false") != 0 && strcmp(new_entry->type, "true") != 0){
			if(state_var_decl != NULL){
				int j = state_var_decl->posicao->coluna - strlen(new_entry->type)-1;
				//printf("Line %d, col %d: Type identifier expected\n", state_var_decl->posicao->linha, j);
				//exit(0);
			}
		}

		if(temp->next_id != NULL && temp->next_id->id != NULL){

			new_entry->next_symbol_entry = (symbol_entry *) malloc(sizeof(symbol_entry));

			temp = temp->next_id;

			symbol_aditional_id_list(temp, type, new_entry->next_symbol_entry, second_type);

		}

	}

}

void symbol_func_part(func_part * node_func_part, symbol_table * symbols){

	if(node_func_part != NULL){

		if(node_func_part->node_func_decl != NULL){

			symbol_func_decl(node_func_part->node_func_decl, symbols);

		}

	}

	if(node_func_part->node_func_part != NULL){

		symbol_table * temp = (symbol_table *) malloc(sizeof(symbol_table));

		symbols->next_symbol_table = temp;

		symbol_func_part(node_func_part->node_func_part, symbols->next_symbol_table);

	}

}

void symbol_func_decl(func_decl * temp, symbol_table * symbols){

	symbols->type = "function";

	if(temp->node_func_heading != NULL){
		
		if(temp->node_func_block != NULL){

			symbol_func_heading(temp->node_func_heading, symbols);

			if(temp->node_func_block != NULL){
				table_state = symbols;
				entry_state = symbols->node_symbol_entry;
				error_type = "function";
				symbol_func_block(temp->node_func_block, symbols);
			}

		}
		else{

			symbol_func_heading(temp->node_func_heading, symbols);

		}

	}

	int flagf = 0;
	
	if(temp->node_func_ident != NULL){
			
		if(temp->node_func_block != NULL){

			symbol_entry * first = NULL;
			symbol_table * table = NULL;

			if(temp->node_func_ident->id_func != NULL){

				symbol_table * origin = original_node;

				while(origin != NULL){

					if(origin->node_symbol_entry != NULL){

						if(origin->node_symbol_entry->id != NULL){

							if(strcmp(origin->node_symbol_entry->id, temp->node_func_ident->id_func) == 0){

								first = origin->node_symbol_entry;
								table = origin;
								flagf = 1;

							}

						}

					}

					origin = origin->next_symbol_table;
				}

				/*if(flagf == 0){
					printf("Line %d, col %d: Function identifier expected\n", temp->node_func_ident->posicao->linha-1, temp->node_func_ident->posicao->coluna-1);
					exit(0);
				}*/

			}

			table_state = table;
			entry_state = first;
			error_type = "function";

			if(temp->node_func_block != NULL){

				if(table != NULL) 
					symbol_func_block(temp->node_func_block, table);

			}

		}

	}

}

void symbol_func_heading(func_heading * node_func_heading, symbol_table * symbols){

	if(node_func_heading->id_func == NULL && node_func_heading->id_type == NULL) return;

	symbols->node_symbol_entry = (symbol_entry *) malloc(sizeof(symbol_entry));
	symbol_entry * temp = symbols->node_symbol_entry;

	if(node_func_heading->id_func != NULL){

		temp->id = node_func_heading->id_func;

	}

	if(node_func_heading->id_type != NULL){

		temp->type = strtolower(node_func_heading->id_type);

	}

	temp->second_type = "return";

	if(node_func_heading->node_formal_params_list != NULL){

		if(node_func_heading->node_formal_params_list->node_formal_params != NULL){

			temp->next_symbol_entry = (symbol_entry *) malloc(sizeof(symbol_entry));

			symbol_formal_params(node_func_heading->node_formal_params_list->node_formal_params, temp->next_symbol_entry);

		}	

		if(node_func_heading->node_formal_params_list->next_formal_params != NULL){

			symbol_aditional_formal_params(node_func_heading->node_formal_params_list->next_formal_params, temp);

		}

	}

}

void symbol_aditional_formal_params(aditional_formal_params * temp, symbol_entry * entries){

	symbol_entry * aux = entries;

	while(aux->next_symbol_entry != NULL) aux = aux->next_symbol_entry;

	aux->next_symbol_entry = (symbol_entry *) malloc(sizeof(symbol_entry));

	if(temp->node_formal_params != NULL)
		symbol_formal_params(temp->node_formal_params, aux->next_symbol_entry);

	if(temp->next_formal_params != NULL)
		symbol_aditional_formal_params(temp->next_formal_params, entries);

}

void symbol_formal_params(formal_params * node_formal_params, symbol_entry * new_entry){

	if(node_formal_params->node_id_list != NULL && node_formal_params->id_type != NULL){

		if(strcmp(node_formal_params->type_var, "fp1") == 0){

			new_entry->second_type = "varparam";

			symbol_id_list(node_formal_params->node_id_list, node_formal_params->id_type, new_entry, "varparam");

		}
		else if(strcmp(node_formal_params->type_var, "fp2") == 0){

			new_entry->second_type = "param";

			symbol_id_list(node_formal_params->node_id_list, node_formal_params->id_type, new_entry, "param");

		}

	}

}


void symbol_func_block(func_block * node_func_block, symbol_table * symbols){

	if(node_func_block->node_var_part != NULL){

		if(node_func_block->node_var_part != NULL){

			var_part * temp = node_func_block->node_var_part;

			if(temp->node_var_decl != NULL){

				symbol_entry * aux = symbols->node_symbol_entry;

				while(aux->next_symbol_entry != NULL) aux = aux->next_symbol_entry;

				aux->next_symbol_entry = (symbol_entry *) malloc(sizeof(symbol_entry));

				symbol_var_decl(temp->node_var_decl, aux->next_symbol_entry);

			}

			if(temp->next_var_part != NULL){

				symbol_aditional_var_part(temp->next_var_part, symbols);

			}

		}

	}

	if(node_func_block->node_stat_part->node_comp_stat->node_stat_list->node_stat != NULL){

		if(node_func_block->node_stat_part->node_comp_stat->node_stat_list->next_stat_list != NULL){

			symbol_stat_part(node_func_block->node_stat_part);

		}
		else{

			symbol_stat_part(node_func_block->node_stat_part);

		}

	}

}

void symbol_stat_part(stat_part * node_stat_part){

	if(node_stat_part->node_comp_stat != NULL)
		symbol_comp_stat(node_stat_part->node_comp_stat);

}

void symbol_comp_stat(comp_stat * node_comp_stat){

	if(node_comp_stat->node_stat_list != NULL)
		symbol_stat_list(node_comp_stat->node_stat_list);

}

void symbol_stat_list(stat_list * node_stat_list){

	if(node_stat_list->node_stat != NULL) 
		symbol_stat(node_stat_list->node_stat);

	if(node_stat_list->next_stat_list != NULL)
		symbol_aditional_stat_list(node_stat_list->next_stat_list);

}

void symbol_aditional_stat_list(aditional_stat_list * temp){

	if(temp->node_stat != NULL)
		symbol_stat(temp->node_stat);

	if(temp->next_stat_list != NULL)
		symbol_aditional_stat_list(temp->next_stat_list);

}

void symbol_stat(stat * node_stat){

	if(strcmp(node_stat->operation_type, "s-1") == 0) return;

	if(strcmp(node_stat->operation_type, "s1") == 0){

		if(node_stat->node_comp_stat->node_stat_list->next_stat_list != NULL){

			if(node_stat->node_comp_stat->node_stat_list->next_stat_list->node_stat != NULL){

				/*

					FUNCAO CHECK

				*/

				symbol_comp_stat(node_stat->node_comp_stat);

			}

		}
		else{

			symbol_comp_stat(node_stat->node_comp_stat);

		}
		
	}
	else if(strcmp(node_stat->operation_type, "s2") == 0){

		symbol_expression(node_stat->node_expr);
		
		if(node_stat->node_stat != NULL)
			symbol_stat(node_stat->node_stat);

		if(node_stat->node_stat2 != NULL)
			symbol_stat(node_stat->node_stat2);

	}
	else if(strcmp(node_stat->operation_type, "s3") == 0){

		symbol_expression(node_stat->node_expr);
		
		if(node_stat->node_stat != NULL)
			symbol_stat(node_stat->node_stat);

		if(node_stat->node_stat2 != NULL)
			symbol_stat(node_stat->node_stat2);

	}
	else if(strcmp(node_stat->operation_type, "s4") == 0){

		symbol_expression(node_stat->node_expr);

		if(node_stat->node_stat != NULL){
			symbol_stat(node_stat->node_stat);
		}

	}
	else if(strcmp(node_stat->operation_type, "s5") == 0){

		if(node_stat->node_stat_list != NULL){
			symbol_stat_list(node_stat->node_stat_list);
		}
		
		symbol_expression(node_stat->node_expr);

	}
	else if(strcmp(node_stat->operation_type, "s6") == 0){

		if(node_stat->node_expr != NULL)
			symbol_expression(node_stat->node_expr);
		
	}
	else if(strcmp(node_stat->operation_type, "s7") == 0){

		symbol_entry * temp;
		int flagx = 0;

		if(error_type != NULL){

			if(strcmp(error_type, "function") == 0 && entry_state != NULL)
				temp = entry_state;
			else if(strcmp(error_type, "global") == 0 && global_variables != NULL) 
				temp = global_variables;
			else temp = NULL;

		}
		else temp = NULL;

		if(temp != NULL){

			while(temp != NULL){

				if(temp->id != NULL){

					if(strcmp(temp->id, node_stat->id) == 0){
						flagx = 1;
						break;
					}

				}

				temp = temp->next_symbol_entry;

			}

		}


		if(flagx == 1){
			previous_type = temp->type;
			assignment_token = temp->id;
		}
		else{
			int j = node_stat->posicao->coluna-strlen(node_stat->id);
			//printf("Line %d, col %d: Symbol %s not defined\n", node_stat->posicao->linha, j, node_stat->id);
			//exit(0);
		}

		operation = "assign";
		
		symbol_expression(node_stat->node_expr);

		operation = NULL;

	}
	else if(strcmp(node_stat->operation_type, "s8") == 0){

		operation = "writeln";

		if(node_stat->node_writeln_list != NULL)
			symbol_writeln(node_stat->node_writeln_list);

		operation = NULL;
		
	}

}

void symbol_writeln(writeln_list * node_writeln_list){

	if(node_writeln_list->node_expr != NULL)
		symbol_expression(node_writeln_list->node_expr);
	else if(node_writeln_list->string != NULL){

	}

	if(node_writeln_list->next != NULL)
		symbol_aditional_writeln(node_writeln_list->next);

}

void symbol_aditional_writeln(aditional_writeln * temp){

	if(temp->node_expr != NULL){
		symbol_expression(temp->node_expr);
	}

	else if(temp->string != NULL){

	}

	if(temp->next != NULL)
		symbol_aditional_writeln(temp->next);

}

void symbol_expression(expression * node_expr){

	if(strcmp(node_expr->operation_type, "e1") == 0){
		symbol_simple_expression(node_expr->node_simple_expr);
	}
	else if(strcmp(node_expr->operation_type, "e2") == 0){

		if(strcmp(node_expr->id, "<") == 0){

			symbol_simple_expression(node_expr->node_simple_expr);

			symbol_simple_expression(node_expr->node_simple_expr2);

		}
		else if(strcmp(node_expr->id, ">") == 0){

			symbol_simple_expression(node_expr->node_simple_expr);

			symbol_simple_expression(node_expr->node_simple_expr2);

		}
		else if(strcmp(node_expr->id, "<=") == 0){

			symbol_simple_expression(node_expr->node_simple_expr);

			symbol_simple_expression(node_expr->node_simple_expr2);

		}
		else if(strcmp(node_expr->id, ">=") == 0){

			symbol_simple_expression(node_expr->node_simple_expr);

			symbol_simple_expression(node_expr->node_simple_expr2);

		}
		else if(strcmp(node_expr->id, "=") == 0){

			symbol_simple_expression(node_expr->node_simple_expr);

			symbol_simple_expression(node_expr->node_simple_expr2);

		}
		else if(strcmp(node_expr->id, "<>") == 0){

			symbol_simple_expression(node_expr->node_simple_expr);

			symbol_simple_expression(node_expr->node_simple_expr2);

		}

	}

}

void symbol_simple_expression(simple_expression * node_simple_expr){

	if(strcmp(node_simple_expr->operation_type, "se1") == 0){

		if(strcmp(node_simple_expr->id, "+") == 0){

			symbol_simple_expression(node_simple_expr->node_simple_expr);

			symbol_terminal(node_simple_expr->node_terminal);

		}
		else if(strcmp(node_simple_expr->id, "-") == 0){

			symbol_simple_expression(node_simple_expr->node_simple_expr);

			symbol_terminal(node_simple_expr->node_terminal);

		}

	}
	else if(strcmp(node_simple_expr->operation_type, "se2") == 0){

		symbol_simple_expression(node_simple_expr->node_simple_expr);

		symbol_terminal(node_simple_expr->node_terminal);

	}
	else if(strcmp(node_simple_expr->operation_type, "se3") == 0){

		if(strcmp(node_simple_expr->id, "+") == 0){

			symbol_terminal(node_simple_expr->node_terminal);

		}
		else if(strcmp(node_simple_expr->id, "-") == 0){

			symbol_terminal(node_simple_expr->node_terminal);

		}

	}
	else if(strcmp(node_simple_expr->operation_type, "se4") == 0){

		symbol_terminal(node_simple_expr->node_terminal);

	}

}

void symbol_terminal(terminal * node_terminal){

	if(strcmp(node_terminal->operation_type, "t1") == 0){

		if(strcmp(node_terminal->id, "*") == 0){

			symbol_terminal(node_terminal->node_terminal);

			symbol_terminal(node_terminal->node_terminal2);

		}
		else if(strcmp(node_terminal->id, "/") == 0){

			symbol_terminal(node_terminal->node_terminal);

			symbol_terminal(node_terminal->node_terminal2);

		}
		else if(strcmp(node_terminal->id, "mod") == 0){

			symbol_terminal(node_terminal->node_terminal);

			symbol_terminal(node_terminal->node_terminal2);

		}
		else if(strcmp(node_terminal->id, "div") == 0){

			symbol_terminal(node_terminal->node_terminal);

			symbol_terminal(node_terminal->node_terminal2);

		}

	}
	else if(strcmp(node_terminal->operation_type, "t2") == 0){

		symbol_terminal(node_terminal->node_terminal);

		symbol_terminal(node_terminal->node_terminal2);

	}
	else if(strcmp(node_terminal->operation_type, "t3") == 0){

		symbol_factor(node_terminal->node_factor);

	}

}

void symbol_factor(factor * node_factor){

	int flagx = 0;

	//printf("BBBBBBB: %s\n", node_factor->type2);

	/*if(strcmp(node_factor->type2, "id") == 0){

		if(operation != NULL){

			printf("AHAHAHAHAHAHAHAHAHAHAHAHAHAH\n");
			
			if(strcmp(operation, "writeln") == 0){

				symbol_entry * temp;

				if(strcmp(error_type, "function") == 0 && entry_state != NULL)
					temp = entry_state;
				else if(strcmp(error_type, "global") == 0 && global_variables != NULL) 
					temp = global_variables;
				else temp = NULL;

				while(temp != NULL){

					if(temp->id != NULL){

						if(strcmp(temp->id, node_factor->id) == 0){
							flagx = 1;
							break;
						}

					}

					temp = temp->next_symbol_entry;

				}


				if(flagx == 1){
					if(strcmp(temp->type, "string") != 0 && strcmp(temp->type, "integer") != 0 && strcmp(temp->type, "false") != 0 && strcmp(temp->type, "real") != 0 && strcmp(temp->type, "true") != 0){
						int j = node_factor->posicao2->coluna-strlen(node_factor->id);
						//printf("Line %d, col %d: Cannot write values of type %s\n", node_factor->posicao2->linha, j, temp->type);
						//exit(0);
					}
				}
				else{
					int j = node_factor->posicao2->coluna-strlen(node_factor->id);
					printf("Line %d, col %d: Symbol %s not defined\n", node_factor->posicao2->linha, j, node_factor->id);
					exit(0);
				}
			}
			else if(strcmp(operation, "assign") == 0){

				symbol_entry * temp = NULL;

				if(error_type != NULL){
					if(strcmp(error_type, "function") == 0 && entry_state != NULL)
						temp = entry_state;
					else if(strcmp(error_type, "global") == 0 && global_variables != NULL) 
						temp = global_variables;
					else temp = NULL;
				}

				if(temp != NULL){
					while(temp != NULL){

						if(temp->id != NULL){

							if(strcmp(temp->id, node_factor->id) == 0){
								flagx = 1;
								break;
							}

						}

						temp = temp->next_symbol_entry;

					}
				}


				if(flagx == 1){
					if(strcmp(temp->type, previous_type) != 0){
						int j = node_factor->posicao2->coluna-strlen(node_factor->id);
						//printf("Line %d, col %d: Incompatible type in assignment to %s (got %s, expected %s)\n", node_factor->posicao2->linha, j, assignment_token, temp->type, previous_type);
						//exit(0);
					}
				}
				else{
					int j = node_factor->posicao2->coluna-strlen(node_factor->id);
					printf("Line %d, col %d: Symbol %s not defined\n", node_factor->posicao2->linha, j, node_factor->id);
					exit(0);
				}

			}


		}

	}
	else if(strcmp(node_factor->type2, "int") == 0){
		
		if(operation != NULL)
			if(strcmp(operation, "assign") == 0)
				if(strcmp(previous_type, "integer") != 0){
					int j = node_factor->posicao2->coluna-strlen(node_factor->id);
					//printf("Line %d, col %d: Incompatible type in assignment to %s (got integer, expected %s)\n", node_factor->posicao2->linha, j, assignment_token, previous_type);
					//exit(0);
				}

	}
	else if(strcmp(node_factor->type2, "real") == 0){

		if(operation != NULL)
			if(strcmp(operation, "assign") == 0)
				if(strcmp(previous_type, "double") != 0){
					int j = node_factor->posicao2->coluna-strlen(node_factor->id);
					//printf("Line %d, col %d: Incompatible type in assignment to %s (got real, expected %s)\n", node_factor->posicao2->linha, j, assignment_token, previous_type);
					//exit(0);
				}

	}
	else if(strcmp(node_factor->type2, "func") == 0){
		
		if(node_factor->node_func_design != NULL){

			symbol_func_design(node_factor->node_func_design);

		}
		
	}
	else if(strcmp(node_factor->type2, "expr") == 0){

		if(node_factor->node_expr != NULL){
			symbol_expression(node_factor->node_expr);
		} 
		
	}
	else if(strcmp(node_factor->type2, "fact") == 0){

		if(node_factor->node_factor != NULL){ 
			symbol_factor(node_factor->node_factor);
		}
		
	}*/

}



void symbol_func_design(func_design * node_func_design){

	if(node_func_design->param_list != NULL){

		if(node_func_design->param_list->node_expr != NULL){

			symbol_expression(node_func_design->param_list->node_expr);

		}

		if(node_func_design->param_list->next_param != NULL){

			symbol_aditional_params(node_func_design->param_list->next_param);

		}

	}

}


void symbol_aditional_params(aditional_params * temp){

	if(temp->node_expr != NULL)
		symbol_expression(temp->node_expr);

	if(temp->next_param != NULL)
		symbol_aditional_params(temp->next_param);

}

void checkifpossible(char * id, factor * node_factor){

	if(strcmp(error_type, "function") == 0){
		printf("BBBBBBBBB\n");
	}
	else{
		printf("AAAAAAA\n");
	}

}

/************************
*************************
*************************
*************************
*************************
*************************
*************************
*************************
*************************
*************************
*************************
*************************
*************************
*************************
*************************
*************************
*************************
*************************
*************************
*************************
*************************
*************************
*************************
*************************
*************************
*************************
*************************
*************************
*************************
*************************
*************************
*************************
*************************
*************************
*************************
*************************
*************************
*************************
*************************
*************************
*************************
*************************
*************************
*************************
*************************
*************************
*************************
*************************
*************************
*************************
*************************
*************************
*************************
*************************
*************************
*************************
*************************
*************************
*************************
*************************
*************************
*************************
*************************
*************************
*************************
************************/

int is_global = -1;
symbol_table * llvm_symb;
int cont = 0;
char * last_func;
int iteracao = 0;
char * op_type = NULL;
char * sub_op = NULL;
char * type_in_use = NULL;
strings_to_print * strings;
int num_strings = 0;
int function_type = -1;
int cont_var_op = 0;

void llvm_all(prog * node_program, symbol_table * llvm_symbols){

	strings = (strings_to_print *) malloc(sizeof(strings_to_print)); 

	llvm_symb = llvm_symbols;

	flag = 1;

	if(node_program != NULL){

		printf("@.str_true = private unnamed_addr constant [7 x i8] c\"true\\0A\\00\\00\"\n");
		printf("@.str_false = private unnamed_addr constant [7 x i8] c\"false\\0A\\00\"\n");
		printf("@.str_bol = private unnamed_addr constant [2 x i8*] [i8* getelementptr inbounds ([7 x i8]* @.str_false, i32 0, i32 0), i8* getelementptr inbounds ([7 x i8]* @.str_true, i32 0, i32 0)]\n");
		printf("@.str_int = private unnamed_addr constant [4 x i8] c\"%%d\\0A\\00\"\n");
		printf("@.str_double = private unnamed_addr constant [6 x i8] c\"%%12e\\0A\\00\"\n");
		printf("declare i32 @atoi(i8*)\n");
		printf("declare i32 @printf(i8*, ...)\n\n");

		llvm_prog_heading(node_program->node_prog_heading);
		llvm_prog_block(node_program->node_prog_block);

		strings = strings->next;

		printf("\n");

		int cont = 0;

		while(strings != NULL){
			cont++;
			printf("@.str%d = private unnamed_addr constant [%lu x i8] c\"%s\\0A\\00\", align 1\n", cont, strlen(strings->string)+2, strings->string);
			//printf("%s\n", strings->string);
			strings = strings->next;
		}

	}

}

void llvm_prog_heading(prog_heading * node_prog_heading){ /**/

	if(node_prog_heading != NULL){

		//alignment();

		//printf("Id(%s)\n", node_prog_heading->id);

	}

}

void llvm_prog_block(prog_block * node_prog_block){

	if(node_prog_block != NULL){

		//alignment();

		//printf("VarPart\n"); /**/

		if(node_prog_block->node_var_part != NULL){

			advance++;

			is_global = 1;

			llvm_var_part(node_prog_block->node_var_part);

			is_global = -1;

			advance--;

		}

		//alignment();

		//printf("FuncPart\n");
		
		if(node_prog_block->node_func_part != NULL){

			//advance++;

			llvm_func_part(node_prog_block->node_func_part);

			//advance--;

		}

		last_func = "main";
		iteracao = 0;

		if(node_prog_block->node_stat_part->node_comp_stat->node_stat_list->node_stat != NULL){

			printf("\ndefine i32 @main(i32 %%argc, i8** %%argv){\n\n");

			if(node_prog_block->node_stat_part->node_comp_stat->node_stat_list->next_stat_list != NULL){

				//alignment();

				//advance++;

				llvm_stat_part(node_prog_block->node_stat_part);

				//advance--;

			}
			else
				llvm_stat_part(node_prog_block->node_stat_part);

			printf("ret i32 0\n");

			printf("\n}\n");



		}

	}

}

void llvm_var_part(var_part * func_var_part){ /**/

	if(func_var_part != NULL){

		var_part * temp = func_var_part;

		if(temp->node_var_decl != NULL){

			//alignment();

			//printf("VarDecl\n");

			//advance++;

			llvm_var_decl(temp->node_var_decl);
			
			//advance--;

		}

		if(temp->next_var_part != NULL){

			llvm_aditional_var_part(temp->next_var_part);


		}

	}

}

void llvm_aditional_var_part(aditional_var_part * temp){ /**/

	//alignment();

	//printf("VarDecl\n");

	//advance++;

	llvm_var_decl(temp->node_var_decl);

	//advance--;

	if(temp->next_var_part != NULL)
		llvm_aditional_var_part(temp->next_var_part);

}

void llvm_var_decl(var_decl * node_var_decl){ /**/

	if(node_var_decl != NULL){

		llvm_id_list(node_var_decl->node_id_list, node_var_decl->id_type);

		//alignment();

		//printf("Id(%s)\n", node_var_decl->id_type);

	}

}

void llvm_id_list(id_list * node_id_list, char * id_type){/**/

	if(node_id_list != NULL){

		if(strcmp(id_type, "integer") == 0){

			//alignment();

			if(is_global == 1)
				printf("@%s = common global i32 0, align 4\n", node_id_list->id);
			else{
				if(is_global == 2){
					iteracao++;
					printf("%%%d = alloca i32, align 4\n", iteracao);
					printf("store i32 %%%s, i32* %%%d, align 4\n", node_id_list->id, iteracao);
				}
				else printf("%%%s = alloca i32, align 4\n", node_id_list->id);
			}

		}
		else if(strcmp(id_type, "real") == 0){

			//alignment();

			if(is_global == 1)
				printf("@%s = common global double 0.000000e+00, align 8\n", node_id_list->id);
			else{ 
				if(is_global == 2){
					iteracao++;
					printf("%%%d = alloca double, align 8\n", iteracao);
					printf("store double %%%s, double* %%%d, align 8\n", node_id_list->id, iteracao);
				}
				else printf("%%%s = alloca double, align 8\n", node_id_list->id);
			}

		}
		else if(strcmp(id_type, "true") == 0){

			//alignment();

			if(is_global == 1)
				printf("@%s = global i1 0, align 1\n", node_id_list->id);
			else{
				if(is_global == 2){
					iteracao++;
					printf("%%%d = alloca i1\n", iteracao);
					printf("store i1 %%%s, i1* %%%d\n", node_id_list->id, iteracao);
				}
				else printf("%%%s = alloca i1, align 1\nstore i1 1, i1* %%%s, align 1\n", node_id_list->id, node_id_list->id);
			}

		}
		else if(strcmp(id_type, "false") == 0){

			//alignment();

			if(is_global == 1)
				printf("@%s = global i1 1, align 1\n", node_id_list->id);
			else{
				if(is_global == 2){
					iteracao++;
					printf("%%%d = alloca i1\n", iteracao);
					printf("store i1 %%%s, i1* %%%d\n", node_id_list->id, iteracao);
				}
				else printf("%%%s = alloca i1, align 1\nstore i1 0, i1* %%%s, align 1\n", node_id_list->id, node_id_list->id);
			}

		}
		else if(strcmp(id_type, "boolean") == 0){

			//alignment();

			if(is_global == 1)
				printf("@%s = common global i1 0, align 1\n", node_id_list->id);
			else{
				if(is_global == 2){
					iteracao++;
					printf("%%%d = alloca i1\n", iteracao);
					printf("store i1 %%%s, i1* %%%d\n", node_id_list->id, iteracao);
				}
				else printf("%%%s = alloca i1, align 1\n", node_id_list->id);
			}

		}

		//alignment();

		//printf("Id(%s)\n", node_id_list->id);

		if(node_id_list->next_id != NULL){

			llvm_aditional_id_list(node_id_list->next_id, id_type);

		}

	}

}

void llvm_aditional_id_list(aditional_id_list * temp, char * id_type){/**/

	if(temp->id != NULL){

		if(strcmp(id_type, "integer") == 0){

			//alignment();

			if(is_global == 1)
				printf("@%s = common global i32 0, align 4\n", temp->id);
			else{
				if(is_global == 2){
					iteracao++;
					printf("%%%d = alloca i32, align 4\n", iteracao);
					printf("store i32 %%%s, i32* %%%d, align 4\n", temp->id, iteracao);
				}
				else printf("%%%s = alloca i32, align 4\n", temp->id);
			}

		}
		else if(strcmp(id_type, "real") == 0){

			//alignment();

			if(is_global == 1)
				printf("@%s = common global double 0.000000e+00, align 8\n", temp->id);
			else{
				if(is_global == 2){
					iteracao++;
					printf("%%%d = alloca double, align 8\n", iteracao);
					printf("store double %%%s, double* %%%d, align 8\n", temp->id, iteracao);
				}
				else printf("%%%s = alloca double, align 8\n", temp->id);
			}

		}
		else if(strcmp(id_type, "true") == 0){

			//alignment();

			if(is_global == 1)
				printf("@%s = global i1 0, align 1\n", temp->id);
			else{
				if(is_global == 2){
					iteracao++;
					printf("%%%d = alloca i1\n", iteracao);
					printf("store i1 %%%s, i1* %%%d\n", temp->id, iteracao);
				}
				else printf("%%%s = alloca i1, align 1\nstore i1 1, i1* %%%s, align 1\n", temp->id, temp->id);
			}

		}
		else if(strcmp(id_type, "false") == 0){

			//alignment();

			if(is_global == 1)
				printf("@%s = global i1 1, align 1\n", temp->id);
			else{
				if(is_global == 2){
					iteracao++;
					printf("%%%d = alloca i1\n", iteracao);
					printf("store i1 %%%s, i1* %%%d\n", temp->id, iteracao);
				}
				else printf("%%%s = alloca i1, align 1\nstore i1 0, i1* %%%s, align 1\n", temp->id, temp->id);
			}

		}
		else if(strcmp(id_type, "boolean") == 0){

			//alignment();

			if(is_global == 1)
				printf("@%s = common global i1 0, align 1\n", temp->id);
			else{
				if(is_global == 2){
					iteracao++;
					printf("%%%d = alloca i1\n", iteracao);
					printf("store i1 %%%s, i1* %%%d\n", temp->id, iteracao);
				}
				else printf("%%%s = alloca i1, align 1\n", temp->id);
			}

		}

		//alignment();

		//printf("Id(%s)\n", temp->id);

		if(temp->next_id != NULL && temp->next_id->id != NULL){

			temp = temp->next_id;

			llvm_aditional_id_list(temp, id_type);

		}

	}

}

void llvm_func_part(func_part * node_func_part){

	if(node_func_part != NULL){

		if(node_func_part->node_func_decl != NULL){

			iteracao = 0;

			llvm_func_decl(node_func_part->node_func_decl);

		}

	}

	if(node_func_part->node_func_part != NULL) llvm_func_part(node_func_part->node_func_part);

}

void llvm_func_decl(func_decl * temp){

	if(temp->node_func_heading != NULL){
		
		if(temp->node_func_block != NULL){

			llvm_func_heading(temp->node_func_heading);

			if(temp->node_func_block != NULL)
				llvm_func_block(temp->node_func_block);

			if(function_type == 1) printf("ret i32 0\n");
			else if(function_type == 2) printf("ret double 0.0\n");
			else if(function_type == 3) printf("ret i1 true\n");
			
			printf("\n}\n");

		}
		/*else{

			printf("FuncDecl\n");

			advance++;

			llvm_func_heading(temp->node_func_heading);

			advance--;
		}*/

	}

	if(temp->node_func_ident != NULL){
		
		if(temp->node_func_block != NULL){

			symbol_table * tempp = NULL;

			if(llvm_symb != NULL)
				tempp = llvm_symb->next_symbol_table;
			symbol_entry * entries = NULL;

			while(tempp->next_symbol_table != NULL){

				if(strcmp(tempp->node_symbol_entry->id, temp->node_func_ident->id_func) == 0){

					last_func = tempp->node_symbol_entry->id;

					if(strcmp(tempp->node_symbol_entry->type, "integer") == 0){

						printf("\ndefine i32 @%s(", tempp->node_symbol_entry->id);
						entries = tempp->node_symbol_entry;

						function_type = 1;

					}
					else if(strcmp(tempp->node_symbol_entry->type, "real") == 0){

						printf("\ndefine double @%s(", tempp->node_symbol_entry->id);
						entries = tempp->node_symbol_entry;

						function_type = 2;

					}
					else if(strcmp(tempp->node_symbol_entry->type, "boolean") == 0){

						printf("\ndefine zeroext i1 @%s(", tempp->node_symbol_entry->id);
						entries = tempp->node_symbol_entry;

						function_type = 3;

					}

					break;
				}

				tempp = tempp->next_symbol_table;
			}

			int aux = 0;
			symbol_entry * start_entry;
			start_entry = entries;

			if(entries != NULL){
				
				if(entries->next_symbol_entry != NULL){

					entries = entries->next_symbol_entry;

					while(entries->next_symbol_entry != NULL){

						if(entries->id != NULL && entries->second_type != NULL && (strcmp(entries->second_type, "param") == 0 || strcmp(entries->second_type, "varparam") == 0)){

							if(strcmp(entries->type, "integer") == 0){

								if(aux == 0) printf("i32 %%%s", entries->id);
								else printf(", i32 %%%s", entries->id);
								aux++;

							}
							else if(strcmp(entries->type, "real") == 0){

								if(aux == 0) printf("double %%%s", entries->id);
								else printf(", double %%%s", entries->id);
								aux++;

							}
							else if(strcmp(entries->type, "true") == 0){

								if(aux == 0) printf("i1 %%%s", entries->id);
								printf(", i1 %%%s", entries->id);
								aux++;

							}
							else if(strcmp(entries->type, "false") == 0){

								if(aux == 0) printf("i1 %%%s", entries->id);
								else printf(", i1 %%%s", entries->id);
								aux++;

							}
							else if(strcmp(entries->type, "boolean") == 0){

								if(aux == 0) printf("i1 %%%s", entries->id);
								else printf(", i1 %%%s", entries->id);
								aux++;

							}

						}

						entries = entries->next_symbol_entry;
					}

				}

			}

			printf(") {\n\n");

			if(start_entry != NULL){

				while(start_entry->next_symbol_entry != NULL){

					if(start_entry->id != NULL && start_entry->second_type != NULL && (strcmp(start_entry->second_type, "param") == 0 || strcmp(start_entry->second_type, "varparam") == 0)){

						if(strcmp(start_entry->type, "integer") == 0){

							iteracao++;
							printf("%%%d = alloca i32, align 4\n", iteracao);
							printf("store i32 %%%s, i32* %%%d, align 4\n", start_entry->id, iteracao);

						}
						else if(strcmp(start_entry->type, "real") == 0){

							iteracao++;
							printf("%%%d = alloca double, align 8\n", iteracao);
							printf("store double %%%s, double* %%%d, align 8\n", start_entry->id, iteracao);

						}
						else if(strcmp(start_entry->type, "true") == 0){

							iteracao++;
							printf("%%%d = alloca i1\n", iteracao);
							printf("store i1 %%%s, i1* %%%d\n", start_entry->id, iteracao);

						}
						else if(strcmp(start_entry->type, "false") == 0){

							iteracao++;
							printf("%%%d = alloca i1\n", iteracao);
							printf("store i1 %%%s, i1* %%%d\n", start_entry->id, iteracao);

						}
						else if(strcmp(start_entry->type, "boolean") == 0){

							iteracao++;
							printf("%%%d = alloca i1\n", iteracao);
							printf("store i1 %%%s, i1* %%%d\n", start_entry->id, iteracao);

						}

					}

					start_entry = start_entry->next_symbol_entry;

				}

				printf("\n");

			}

			if(temp->node_func_block != NULL)
				llvm_func_block(temp->node_func_block);

			if(function_type == 1) printf("ret i32 0\n");
			else if(function_type == 2) printf("ret double 0.0\n");
			else if(function_type == 3) printf("ret i1 true\n");

			printf("\n}\n");

		}

	}

}

void llvm_func_heading(func_heading * node_func_heading){

	if(node_func_heading->id_func != NULL && node_func_heading->id_type != NULL){

		last_func = node_func_heading->id_func;

		if(strcmp(node_func_heading->id_type, "integer") == 0){

			alignment();

			printf("\ndefine i32 @%s(", node_func_heading->id_func);

			function_type = 1;

		}
		else if(strcmp(node_func_heading->id_type, "real") == 0){

			alignment();

			printf("\ndefine double @%s(", node_func_heading->id_func);

			function_type = 2;
			
		}
		else if(strcmp(node_func_heading->id_type, "boolean") == 0){
			
			alignment();

			printf("\ndefine zeroext i1 @%s(", node_func_heading->id_func);

			function_type = 3;
			
		}


	}

	if(node_func_heading->node_formal_params_list != NULL){

		if(node_func_heading->node_formal_params_list->node_formal_params != NULL){

			llvm_formal_params_parametros(node_func_heading->node_formal_params_list->node_formal_params);

		}	

		if(node_func_heading->node_formal_params_list->next_formal_params != NULL){

			llvm_aditional_formal_params_parametros(node_func_heading->node_formal_params_list->next_formal_params);

		}

		cont = 0;

		printf(") {\n\n");

		is_global = 2;

		if(node_func_heading->node_formal_params_list->node_formal_params != NULL){

			llvm_formal_params(node_func_heading->node_formal_params_list->node_formal_params);

		}	

		if(node_func_heading->node_formal_params_list->next_formal_params != NULL){

			llvm_aditional_formal_params(node_func_heading->node_formal_params_list->next_formal_params);

		}

		printf("\n");

		is_global = -1;

	}
	else{

		printf(") {\n\n");

	}

}

void llvm_aditional_formal_params_parametros(aditional_formal_params * temp){

	if(temp->node_formal_params != NULL)
		llvm_formal_params_parametros(temp->node_formal_params);

	if(temp->next_formal_params != NULL)
		llvm_aditional_formal_params_parametros(temp->next_formal_params);

}

void llvm_formal_params_parametros(formal_params * node_formal_params){

	if(strcmp(node_formal_params->type_var, "fp1") == 0){

		llvm_id_list_parametros(node_formal_params->node_id_list, node_formal_params->id_type);

	}
	else if(strcmp(node_formal_params->type_var, "fp2") == 0){

		llvm_id_list_parametros(node_formal_params->node_id_list, node_formal_params->id_type);

	}

}

void llvm_id_list_parametros(id_list * node_id_list, char * id_type){/**/

	if(node_id_list != NULL){

		if(strcmp(id_type, "integer") == 0){

			if(cont == 0) printf("i32 %%%s", node_id_list->id);
			else printf(", i32 %%%s", node_id_list->id);
			cont++;

		}
		else if(strcmp(id_type, "real") == 0){

			if(cont == 0) printf("double %%%s", node_id_list->id);
			else printf(", double %%%s", node_id_list->id);
			cont++;

		}
		else if(strcmp(id_type, "true") == 0){

			if(cont == 0) printf("i1 %%%s", node_id_list->id);
			printf(", i1 %%%s", node_id_list->id);
			cont++;

		}
		else if(strcmp(id_type, "false") == 0){

			if(cont == 0) printf("i1 %%%s", node_id_list->id);
			else printf(", i1 %%%s", node_id_list->id);
			cont++;

		}
		else if(strcmp(id_type, "boolean") == 0){

			if(cont == 0) printf("i1 %%%s", node_id_list->id);
			else printf(", i1 %%%s", node_id_list->id);
			cont++;

		}

		if(node_id_list->next_id != NULL){

			llvm_aditional_id_list_parametros(node_id_list->next_id, id_type);

		}

	}

}

void llvm_aditional_id_list_parametros(aditional_id_list * temp, char * id_type){/**/

	if(temp->id != NULL){

		if(strcmp(id_type, "integer") == 0){

			printf(", i32 %%%s", temp->id);
			cont++;

		}
		else if(strcmp(id_type, "real") == 0){

			printf(", double %%%s", temp->id);
			cont++;

		}
		else if(strcmp(id_type, "true") == 0){

			printf(", i1 %%%s", temp->id);
			cont++;

		}
		else if(strcmp(id_type, "false") == 0){

			printf(", i1 %%%s", temp->id);
			cont++;

		}
		else if(strcmp(id_type, "boolean") == 0){

			printf(", i1 %%%s", temp->id);
			cont++;

		}

		if(temp->next_id != NULL && temp->next_id->id != NULL){

			temp = temp->next_id;

			llvm_aditional_id_list_parametros(temp, id_type);

		}

	}

}

void llvm_aditional_formal_params(aditional_formal_params * temp){

	if(temp->node_formal_params != NULL)
		llvm_formal_params(temp->node_formal_params);

	if(temp->next_formal_params != NULL)
		llvm_aditional_formal_params(temp->next_formal_params);

}

void llvm_formal_params(formal_params * node_formal_params){

	if(strcmp(node_formal_params->type_var, "fp1") == 0){

		//advance++;

		llvm_id_list(node_formal_params->node_id_list, node_formal_params->id_type);

		//alignment();

		//printf("Id(%s)\n", node_formal_params->id_type);

		//advance--;

	}
	else if(strcmp(node_formal_params->type_var, "fp2") == 0){

		//advance++;

		llvm_id_list(node_formal_params->node_id_list, node_formal_params->id_type);

		//alignment();

		//printf("Id(%s)\n", node_formal_params->id_type);

		//advance--;

	}

}

void llvm_func_block(func_block * node_func_block){

	if(node_func_block->node_var_part != NULL){

		//alignment();

		//printf("VarPart\n");

		//advance++;

		llvm_var_part(node_func_block->node_var_part);

		//advance--;

	}
	/*else{

		alignment();

		printf("VarPart\n");

	}*/

	if(node_func_block->node_stat_part->node_comp_stat->node_stat_list->node_stat != NULL){

		if(node_func_block->node_stat_part->node_comp_stat->node_stat_list->next_stat_list != NULL){

			//alignment();

			//printf("StatList\n");

			//advance++;

			llvm_stat_part(node_func_block->node_stat_part);

			//advance--;

		}
		else{

			llvm_stat_part(node_func_block->node_stat_part);

		}

	}
	/*else{

		alignment();

		printf("StatList\n");

	}*/

}

void llvm_stat_part(stat_part * node_stat_part){

	if(node_stat_part->node_comp_stat != NULL)
		llvm_comp_stat(node_stat_part->node_comp_stat);

}

void llvm_comp_stat(comp_stat * node_comp_stat){

	if(node_comp_stat->node_stat_list != NULL)
		llvm_stat_list(node_comp_stat->node_stat_list);

}

void llvm_stat_list(stat_list * node_stat_list){

	if(node_stat_list->node_stat != NULL){

		llvm_stat(node_stat_list->node_stat);

	}
	/*else{
		alignment();
		printf("StatList\n");
	}*/

	if(node_stat_list->next_stat_list != NULL){

		llvm_aditional_stat_list(node_stat_list->next_stat_list);


	}

}

void llvm_aditional_stat_list(aditional_stat_list * temp){

	if(temp->node_stat != NULL)
		llvm_stat(temp->node_stat);
	/*else{
		alignment();
		printf("StatList\n");
	}*/

	if(temp->next_stat_list != NULL){

		llvm_aditional_stat_list(temp->next_stat_list);

	}

}

void llvm_stat(stat * node_stat){

	if(strcmp(node_stat->operation_type, "s-1") == 0) return;

	if(strcmp(node_stat->operation_type, "s1") == 0){

		if(node_stat->node_comp_stat->node_stat_list->next_stat_list != NULL){

			if(node_stat->node_comp_stat->node_stat_list->next_stat_list->node_stat != NULL){

				/*

					FUNCAO CHECK

				*/

				/*alignment();

				printf("StatList\n");

				advance++;*/

				llvm_comp_stat(node_stat->node_comp_stat);

				//advance--;

			}

		}
		else{

			llvm_comp_stat(node_stat->node_comp_stat);

		}
		
	}
	else if(strcmp(node_stat->operation_type, "s2") == 0){

		/*alignment();

		printf("IfElse\n");

		advance++;*/

		llvm_expression(node_stat->node_expr);
		
		if(node_stat->node_stat != NULL)
			llvm_stat(node_stat->node_stat);
		/*else{
			alignment();
			printf("StatList\n");
		}*/

		if(node_stat->node_stat2 != NULL)
			llvm_stat(node_stat->node_stat2);
		/*else{
			alignment();
			printf("StatList\n");
		}

		advance--;*/

	}
	else if(strcmp(node_stat->operation_type, "s3") == 0){

		/*alignment();

		printf("IfElse\n");

		advance++;*/

		llvm_expression(node_stat->node_expr);
		
		if(node_stat->node_stat != NULL)
			llvm_stat(node_stat->node_stat);
		/*else{
			alignment();
			printf("StatList\n");
		}*/

		if(node_stat->node_stat2 != NULL)
			llvm_stat(node_stat->node_stat2);
		/*else{
			alignment();
			printf("StatList\n");
		}

		advance--;*/

	}
	else if(strcmp(node_stat->operation_type, "s4") == 0){

		/*alignment();

		printf("While\n");

		advance++;*/

		llvm_expression(node_stat->node_expr);

		if(node_stat->node_stat != NULL){
			llvm_stat(node_stat->node_stat);
		}
		/*else{
			alignment();
			printf("StatList\n");
		}

		advance--;*/

	}
	else if(strcmp(node_stat->operation_type, "s5") == 0){

		/*alignment();

		printf("Repeat\n");

		advance++;*/

		if(node_stat->node_stat_list != NULL){
			llvm_stat_list(node_stat->node_stat_list);
		}
		/*else{
			alignment();
			printf("StatList\n");
		}*/
		
		llvm_expression(node_stat->node_expr);

		//advance--;

	}
	else if(strcmp(node_stat->operation_type, "s6") == 0){

		//alignment();

		//printf("ValParam\n");

		iteracao++;

		printf("%%%d = alloca i32, align 4\n", iteracao);

		iteracao++;

		printf("%%%d = alloca i8**, align 8\n", iteracao);
		printf("store i32 %%argc, i32* %%%d, align 4\n", iteracao-1);
		printf("store i8** %%argv, i8*** %%%d, align 8\n", iteracao);

		iteracao++;

		printf("%%%d = load i8*** %%%d, align 8\n", iteracao, iteracao-1);

		op_type = "valparam";

		advance++;
		
		llvm_expression(node_stat->node_expr);

		iteracao++;

		printf("%%%d = load i8** %%%d, align 8\n", iteracao, iteracao-1);

		iteracao++;

		printf("%%%d = call i32 (i8*)* @atoi(i8* %%%d)\n", iteracao, iteracao-1);

		int i = get_type(node_stat->id);

		if(i == 32) printf("store i32 %%%d, i32* @%s, align 4\n", iteracao, node_stat->id);
		else if(i == 322) printf("store double %%%d, double* @%s, align 4\n", iteracao, node_stat->id);
		else if(i == 332) printf("store i32 %%%d, i32* %%%s, align 4\n", iteracao, node_stat->id);
		else if(i == 3322) printf("store double %%%d, double* %%%s, align 4\n", iteracao, node_stat->id);
		else if(i == 1) type_in_use = "boolean";
		else if(i == 11) type_in_use = "boolean";

		//store i8* %6, i8** %i, align 8

		op_type = NULL;
		
		//alignment();
		//printf("Id(%s)\n", node_stat->id);

		//advance--;

	}
	else if(strcmp(node_stat->operation_type, "s7") == 0){

		/*alignment();

		printf("Assign\n");

		advance++;

		alignment();
		printf("Id(%s)\n", node_stat->id);*/

		op_type = "assign";

		cont_var_op = 0;

		int type = get_type(node_stat->id);

		if(type == 32) type_in_use = "integer";
		else if(type == 322) type_in_use = "double";
		else if(type == 332) type_in_use = "integer";
		else if(type == 3322) type_in_use = "double";
		else if(type == 1) type_in_use = "boolean";
		else if(type == 11) type_in_use = "boolean";
		
		llvm_expression(node_stat->node_expr);

		if(type == 32){

			//GLOBAL

			//iteracao++;
			printf("store i32 %%%d, i32* @%s, align 4\n", iteracao, node_stat->id);

		}
		else if(type == 322){

			//GLOBAL

			//iteracao++;
			printf("store double %%%d, double* @%s, align 8\n", iteracao, node_stat->id);

		}
		else if(type == 332){

			//LOCAL

			//iteracao++;
			printf("store i32 %%%d, i32* %%%s, align 4\n", iteracao, node_stat->id);

		}
		else if(type == 3322){

			//LOCAL

			//iteracao++;
			printf("store double %%%d, double* %%%s, align 8\n", iteracao, node_stat->id);

		}
		else if(type == 1){

			//GLOBAL

			//iteracao++;
			printf("store i1 %%%d, i1* @%s, align 1\n", iteracao, node_stat->id);

		}
		else if(type == 11){

			//LOCAL

			//iteracao++;
			printf("store i1 %%%d, i1* %%%s, align 1\n", iteracao, node_stat->id);

		}

		//advance--;

		op_type = NULL;
		type_in_use = NULL;

	}
	else if(strcmp(node_stat->operation_type, "s8") == 0){

		/*alignment();

		printf("WriteLn\n");*/

		op_type = "print";

		//advance++;

		if(node_stat->node_writeln_list != NULL)
			llvm_writeln(node_stat->node_writeln_list);

		//advance--;

		op_type = NULL;
		
	}

}

int get_type(char * id){

	symbol_table * temp = llvm_symb;
	int flag = 0;

	if(llvm_symb != NULL){

		if(strcmp(last_func, "main") != 0){

			temp = temp->next_symbol_table;

			if(temp != NULL){

				while(temp->next_symbol_table != NULL){

					if(strcmp(temp->node_symbol_entry->id, last_func) == 0){

						symbol_entry * aux = temp->node_symbol_entry;

						if(aux->next_symbol_entry != NULL){

							aux = aux->next_symbol_entry;

							while(aux->next_symbol_entry != NULL){

								//printf("DEBUG: %s - %s\n", aux->id, id);

								if(aux->id != NULL && strcmp(aux->id, id) == 0){
									if(strcmp(aux->type, "integer") == 0) return 332;
									if(strcmp(aux->type, "real") == 0) return 3322;
									if(strcmp(aux->type, "boolean") == 0) return 11;
									if(strcmp(aux->type, "true") == 0) return 11;
									if(strcmp(aux->type, "false") == 0)	return 11;

									flag = 1;

									break;
								}

								aux = aux->next_symbol_entry;

							}

						}

					}

					temp = temp->next_symbol_table;

				}

				if(flag == 0){

					temp = llvm_symb;

					symbol_entry * aux = temp->node_symbol_entry;

					if(aux->next_symbol_entry != NULL){

						//aux = aux->next_symbol_entry;

						while(aux->next_symbol_entry != NULL){

							//printf("DEBUG: %s - %s\n", aux->id, id);

							if(aux->id != NULL && strcmp(aux->id, id) == 0){
								if(strcmp(aux->type, "integer") == 0) return 32;
								if(strcmp(aux->type, "real") == 0) return 322;
								if(strcmp(aux->type, "boolean") == 0) return 1;
								if(strcmp(aux->type, "true") == 0) return 1;
								if(strcmp(aux->type, "false") == 0)	return 1;
								break;
							}

							aux = aux->next_symbol_entry;

						}

					}


				}

			}

		}
		else{

			symbol_entry * aux = temp->node_symbol_entry;

			if(aux->next_symbol_entry != NULL){

				//aux = aux->next_symbol_entry;

				while(aux->next_symbol_entry != NULL){

					//printf("DEBUG: %s - %s\n", aux->id, id);

					if(aux->id != NULL && strcmp(aux->id, id) == 0){
						if(strcmp(aux->type, "integer") == 0) return 32;
						if(strcmp(aux->type, "real") == 0) return 322;
						if(strcmp(aux->type, "boolean") == 0) return 1;
						if(strcmp(aux->type, "true") == 0) return 1;
						if(strcmp(aux->type, "false") == 0)	return 1;
						break;
					}

					aux = aux->next_symbol_entry;

				}

			}

		}

	}

	return -1;

}

void llvm_writeln(writeln_list * node_writeln_list){

	if(node_writeln_list->node_expr != NULL)
		llvm_expression(node_writeln_list->node_expr);
	else if(node_writeln_list->string != NULL){

		//alignment();

		strings_to_print * temp = strings;

		while(temp->next != NULL){
			temp = temp->next;
		}

		num_strings++;

		temp->next = (strings_to_print *) malloc(sizeof(strings_to_print));
		char * bla;
		bla = strtok (node_writeln_list->string, "'");
		temp->next->string = bla;

		//printf("String(%s)\n", node_writeln_list->string);

		iteracao++;

		printf("%%%d = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([%lu x i8]* @.str%d, i32 0, i32 0))\n", iteracao, strlen(bla)+2, num_strings);

	}

	if(node_writeln_list->next != NULL)
		llvm_aditional_writeln(node_writeln_list->next);

}

void llvm_aditional_writeln(aditional_writeln * temp){

	if(temp->node_expr != NULL)
		llvm_expression(temp->node_expr);
	else if(temp->string != NULL){

		//alignment();

		strings_to_print * tempp = strings;

		while(tempp->next != NULL){
			tempp = tempp->next;
		}

		num_strings++;

		tempp->next = (strings_to_print *) malloc(sizeof(strings_to_print));
		char * bla;
		bla = strtok (temp->string, "'");
		tempp->next->string = bla;

		//printf("String(%s)\n", temp->string);

		iteracao++;

		printf("%%%d = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([%lu x i8]* @.str%d, i32 0, i32 0))\n", iteracao, strlen(bla)+2, num_strings);

	}

	if(temp->next != NULL)
		llvm_aditional_writeln(temp->next);

}

void llvm_expression(expression * node_expr){

	if(strcmp(node_expr->operation_type, "e1") == 0){
		llvm_simple_expression(node_expr->node_simple_expr);
	}
	else if(strcmp(node_expr->operation_type, "e2") == 0){
		
		//alignment();

		if(strcmp(node_expr->id, "<") == 0){

			//printf("Lt\n");

			//advance++;

			llvm_simple_expression(node_expr->node_simple_expr);

			llvm_simple_expression(node_expr->node_simple_expr2);

			//advance--;

		}
		else if(strcmp(node_expr->id, ">") == 0){

			//printf("Gt\n");

			//advance++;

			llvm_simple_expression(node_expr->node_simple_expr);

			llvm_simple_expression(node_expr->node_simple_expr2);

			//advance--;

		}
		else if(strcmp(node_expr->id, "<=") == 0){

			//printf("Leq\n");

			//advance++;

			llvm_simple_expression(node_expr->node_simple_expr);

			llvm_simple_expression(node_expr->node_simple_expr2);

			//advance--;

		}
		else if(strcmp(node_expr->id, ">=") == 0){

			//printf("Geq\n");

			//advance++;

			llvm_simple_expression(node_expr->node_simple_expr);

			llvm_simple_expression(node_expr->node_simple_expr2);

			//advance--;

		}
		else if(strcmp(node_expr->id, "=") == 0){

			//printf("Eq\n");

			//advance++;

			llvm_simple_expression(node_expr->node_simple_expr);

			llvm_simple_expression(node_expr->node_simple_expr2);

			//advance--;

		}
		else if(strcmp(node_expr->id, "<>") == 0){

			//printf("Neq\n");

			//advance++;

			llvm_simple_expression(node_expr->node_simple_expr);

			llvm_simple_expression(node_expr->node_simple_expr2);

			//advance--;

		}

	}

}

int llvm_simple_expression(simple_expression * node_simple_expr){

	if(node_simple_expr != NULL){

		if(strcmp(node_simple_expr->operation_type, "se1") == 0){

			//alignment();

			if(strcmp(node_simple_expr->id, "+") == 0){

				//printf("Add\n");

				advance++;

				int num_1 = llvm_simple_expression(node_simple_expr->node_simple_expr);

				int num_2 = llvm_terminal(node_simple_expr->node_terminal);

				iteracao++;
				if(num_1 == -1){
					if(strcmp(type_in_use, "integer") == 0){
						if(cont_var_op > 2){
							printf("%%%d = load i32* %%%d, align 4\n", iteracao, iteracao-1);
							printf("%%%d = add nsw i32 %%%d, %%%d\n", iteracao, num_2-2, num_2);
						}
						else{
							if(strcmp(sub_op, "id") == 0) printf("%%%d = add nsw i32 %%%d, %%%d\n", iteracao, num_2-1, num_2);
							else printf("%%%d = add nsw i32 %%%d, %%%d\n", iteracao, num_2-2, num_2);
						}
					}
					if(strcmp(type_in_use, "double") == 0){
						if(cont_var_op > 2){
							printf("%%%d = load double* %%%d, align 8\n", iteracao, iteracao-1);
							printf("%%%d = fadd double %%%d, %%%d\n", iteracao, num_2-2, num_2);
						}
						else{
							if(strcmp(sub_op, "id") == 0) printf("%%%d = fadd double %%%d, %%%d\n", iteracao, num_2-1, num_2);
							else printf("%%%d = fadd double %%%d, %%%d\n", iteracao, num_2-2, num_2);
						}
					}
					//if(strcmp(type_in_use, "boolean") == 0)

					//printf("%%%d Add %d - %d\n", iteracao, num_2-1, num_2);
				}
				else if(num_2 == -1){
					if(strcmp(type_in_use, "integer") == 0) printf("%%%d = add nsw i32 %%%d, %%%d\n", iteracao, num_1, iteracao-1);
					if(strcmp(type_in_use, "double") == 0) printf("%%%d = fadd double %%%d, %%%d\n", iteracao, num_1, iteracao-1);
					//printf("%%%d Add %d - %d\n", iteracao, num_1, iteracao-1);
				}
				else if(num_1 != -1 && num_2 != -1){
					if(strcmp(type_in_use, "integer") == 0) printf("%%%d = add nsw i32 %%%d, %%%d\n", iteracao, num_1, num_2);
					if(strcmp(type_in_use, "double") == 0) printf("%%%d = fadd double %%%d, %%%d\n", iteracao, num_1, num_2);
					//printf("%%%d Add %d - %d\n", iteracao, num_1, num_2);
				}

				return iteracao;

			}
			else if(strcmp(node_simple_expr->id, "-") == 0){

				//printf("Sub\n");

				int num_1 = llvm_simple_expression(node_simple_expr->node_simple_expr);

				int num_2 = llvm_terminal(node_simple_expr->node_terminal);

				iteracao++;
				if(num_1 == -1){
					if(strcmp(type_in_use, "integer") == 0){
						if(cont_var_op > 2){
							printf("%%%d = load i32* %%%d, align 4\n", iteracao, iteracao-1);
							printf("%%%d = sub nsw i32 %%%d, %%%d\n", iteracao, num_2-2, num_2);
						}
						else{
							if(strcmp(sub_op, "id") == 0) printf("%%%d = sub nsw i32 %%%d, %%%d\n", iteracao, num_2-1, num_2);
							else printf("%%%d = sub nsw i32 %%%d, %%%d\n", iteracao, num_2-2, num_2);
						}
					}
					if(strcmp(type_in_use, "double") == 0){
						if(cont_var_op > 2){
							printf("%%%d = load double* %%%d, align 8\n", iteracao, iteracao-1);
							printf("%%%d = fsub double %%%d, %%%d\n", iteracao, num_2-1, num_2);
						}
						else{
							if(strcmp(sub_op, "id") == 0) printf("%%%d = fsub double %%%d, %%%d\n", iteracao, num_2-1, num_2);
							else printf("%%%d = fsub double %%%d, %%%d\n", iteracao, num_2-1, num_2);
						}
					}
					//printf("%%%d Sub %d - %d\n", iteracao, num_2-1, num_2);
				}
				else if(num_2 == -1){
					if(strcmp(type_in_use, "integer") == 0) printf("%%%d = sub nsw i32 %%%d, %%%d\n", iteracao, num_1, iteracao-1);
					if(strcmp(type_in_use, "double") == 0) printf("%%%d = fsub double %%%d, %%%d\n", iteracao, num_1, iteracao-1);
					//printf("%%%d Sub %d - %d\n", iteracao, num_1, iteracao-1);
				}
				else if(num_1 != -1 && num_2 != -1){
					if(strcmp(type_in_use, "integer") == 0) printf("%%%d = sub nsw i32 %%%d, %%%d\n", iteracao, num_1, num_2);
					if(strcmp(type_in_use, "double") == 0) printf("%%%d = fsub double %%%d, %%%d\n", iteracao, num_1, num_2);
					//printf("%%%d Sub %d - %d\n", iteracao, num_1, num_2);
				}

				return iteracao;

			}

		}
		else if(strcmp(node_simple_expr->operation_type, "se2") == 0){

			//alignment();

			//printf("Or\n");

			//advance++;

			llvm_simple_expression(node_simple_expr->node_simple_expr);

			llvm_terminal(node_simple_expr->node_terminal);

			//advance--;

		}
		else if(strcmp(node_simple_expr->operation_type, "se3") == 0){

			//alignment();

			if(strcmp(node_simple_expr->id, "+") == 0){

				//printf("Plus\n");

				//advance++;

				llvm_terminal(node_simple_expr->node_terminal);

				//advance--;

			}
			else if(strcmp(node_simple_expr->id, "-") == 0){

				//printf("Minus\n");

				//advance++;

				llvm_terminal(node_simple_expr->node_terminal);

				//advance--;

			}

		}
		else if(strcmp(node_simple_expr->operation_type, "se4") == 0){

			sub_op = "terminal";

			llvm_terminal(node_simple_expr->node_terminal);

			sub_op = NULL;

		}

	}

	return -1;

}

int llvm_terminal(terminal * node_terminal){

	if(strcmp(node_terminal->operation_type, "t1") == 0){

		//alignment();

		if(strcmp(node_terminal->id, "*") == 0){

			//advance++;

			int num_1 = llvm_terminal(node_terminal->node_terminal);

			int num_2 = llvm_terminal(node_terminal->node_terminal2);

			//advance--;

			iteracao++;
			if(num_1 == -1){
				if(strcmp(type_in_use, "integer") == 0){
					if(cont_var_op > 2){
						printf("%%%d = load i32* %%%d, align 4\n", iteracao, iteracao-1);
						printf("%%%d = mul nsw i32 %%%d, %%%d\n", iteracao, num_2-2, num_2);
					}
					else{
						if(strcmp(sub_op, "id") == 0) printf("%%%d = mul nsw i32 %%%d, %%%d\n", iteracao, num_2-1, num_2);
						else printf("%%%d = mul nsw i32 %%%d, %%%d\n", iteracao, num_2-2, num_2);
					}
				}
				if(strcmp(type_in_use, "double") == 0){
					if(cont_var_op > 2){
						printf("%%%d = load double* %%%d, align 8\n", iteracao, iteracao-1);
						printf("%%%d = fmul double %%%d, %%%d\n", iteracao, num_2-2, num_2);
					}
					else{
						if(strcmp(sub_op, "id") == 0) printf("%%%d = fmul double %%%d, %%%d\n", iteracao, num_2-1, num_2);
						else printf("%%%d = fmul double %%%d, %%%d\n", iteracao, num_2-2, num_2);
					}
				}
				//printf("%%%d Mul %d - %d\n", iteracao, num_2-1, num_2);
			}
			else if(num_2 == -1){
				if(strcmp(type_in_use, "integer") == 0) printf("%%%d = mul nsw i32 %%%d, %%%d\n", iteracao, num_1, iteracao-1);
				if(strcmp(type_in_use, "double") == 0) printf("%%%d = fmul double %%%d, %%%d\n", iteracao, num_1, iteracao-1);
				//printf("%%%d Mul %d - %d\n", iteracao, num_1, iteracao-1);
			}
			else if(num_1 != -1 && num_2 != -1){
				if(strcmp(type_in_use, "integer") == 0) printf("%%%d = mul nsw i32 %%%d, %%%d\n", iteracao, num_1, num_2);
				if(strcmp(type_in_use, "double") == 0) printf("%%%d = fmul double %%%d, %%%d\n", iteracao, num_1, num_2);
				//printf("%%%d Mul %d - %d\n", iteracao, num_1, num_2);
			}

			return iteracao;

		}
		else if(strcmp(node_terminal->id, "/") == 0){

			//advance++;

			int num_1 = llvm_terminal(node_terminal->node_terminal);

			int num_2 = llvm_terminal(node_terminal->node_terminal2);

			//advance--;

			iteracao++;
			if(num_1 == -1){
				if(strcmp(type_in_use, "integer") == 0){
					if(cont_var_op > 2){
						printf("%%%d = load i32* %%%d, align 4\n", iteracao, iteracao-1);
						printf("%%%d = sdiv nsw i32 %%%d, %%%d\n", iteracao, num_2-2, num_2);
					}
					else{
						if(strcmp(sub_op, "id") == 0) printf("%%%d = sdiv nsw i32 %%%d, %%%d\n", iteracao, num_2-1, num_2);
						else printf("%%%d = sdiv nsw i32 %%%d, %%%d\n", iteracao, num_2-2, num_2);
					}
				}
				if(strcmp(type_in_use, "double") == 0){
					if(cont_var_op > 2){
						printf("%%%d = load double* %%%d, align 8\n", iteracao, iteracao-1);
						printf("%%%d = fdiv double %%%d, %%%d\n", iteracao, num_2-2, num_2);
					}
					else{
						if(strcmp(sub_op, "id") == 0) printf("%%%d = fdiv double %%%d, %%%d\n", iteracao, num_2-1, num_2);
						else printf("%%%d = fdiv double %%%d, %%%d\n", iteracao, num_2-2, num_2);
					}
				}
				//printf("%%%d Div %d - %d\n", iteracao, num_2-1, num_2);
			}
			else if(num_2 == -1){
				if(strcmp(type_in_use, "integer") == 0) printf("%%%d = sdiv nsw i32 %%%d, %%%d\n", iteracao, num_1, iteracao-1);
				if(strcmp(type_in_use, "double") == 0) printf("%%%d = fdiv double %%%d, %%%d\n", iteracao, num_1, iteracao-1);
				//printf("%%%d Div %d - %d\n", iteracao, num_1, iteracao-1);
			}
			else if(num_1 != -1 && num_2 != -1){
				if(strcmp(type_in_use, "integer") == 0) printf("%%%d = sdiv nsw i32 %%%d, %%%d\n", iteracao, num_1, num_2);
				if(strcmp(type_in_use, "double") == 0) printf("%%%d = fdiv double %%%d, %%%d\n", iteracao, num_1, num_2);
				//printf("%%%d Div %d - %d\n", iteracao, num_1, num_2);
			}

			return iteracao;

		}
		else if(strcmp(node_terminal->id, "mod") == 0){

			//printf("Mod\n");

			//advance++;

			llvm_terminal(node_terminal->node_terminal);

			llvm_terminal(node_terminal->node_terminal2);

			//advance--;

		}
		else if(strcmp(node_terminal->id, "div") == 0){

			//printf("Div\n");

			//advance++;

			llvm_terminal(node_terminal->node_terminal);

			llvm_terminal(node_terminal->node_terminal2);

			//advance--;

		}

	}
	else if(strcmp(node_terminal->operation_type, "t2") == 0){

		//alignment();

		//printf("And\n");

		//advance++;

		llvm_terminal(node_terminal->node_terminal);

		llvm_terminal(node_terminal->node_terminal2);

		//advance--;

	}
	else if(strcmp(node_terminal->operation_type, "t3") == 0){

		int num = llvm_factor(node_terminal->node_factor);

		return num;

	}

	return -1;

}

int llvm_factor(factor * node_factor){

	if(strcmp(node_factor->type2, "id") == 0){

		sub_op = "id";

		//alignment();

		//printf("Id(%s)\n", node_factor->id);

		int type = get_type(node_factor->id);

		if(op_type !=NULL && strcmp(op_type, "assign") == 0){

			cont_var_op++;

			if(type == 32){

				//GLOBAL

				iteracao++;
				printf("%%%d = load i32* @%s, align 4\n", iteracao, node_factor->id);

			}
			else if(type == 322){

				//GLOBAL

				iteracao++;
				printf("%%%d = load double* @%s, align 8\n", iteracao, node_factor->id);

			}
			else if(type == 332){

				//LOCAL

				iteracao++;
				printf("%%%d = load i32* %%%s, align 4\n", iteracao, node_factor->id);

			}
			else if(type == 3322){

				//LOCAL

				iteracao++;
				printf("%%%d = load double* %%%s, align 8\n", iteracao, node_factor->id);

			}
			else if(type == 1){

				//GLOBAL

				iteracao++;
				printf("%%%d = load i1* @%s\n", iteracao, node_factor->id);

			}
			else if(type == 11){

				//LOCAL

				iteracao++;
				printf("%%%d = load i1* %%%s\n", iteracao, node_factor->id);

			}

			return iteracao;

		}
		else if(op_type !=NULL && strcmp(op_type, "print") == 0){

			int type = get_type(node_factor->id);

			if(type == 32){

				//GLOBAL

				iteracao++;
				printf("%%%d = load i32* @%s, align 4\n", iteracao, node_factor->id);

				iteracao++;
				printf("%%%d = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str_int, i32 0, i32 0), i32 %%%d)\n", iteracao, iteracao-1);

			}
			else if(type == 322){

				//GLOBAL

				iteracao++;
				printf("%%%d = load double* @%s, align 8\n", iteracao, node_factor->id);

				iteracao++;
				printf("%%%d = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([6 x i8]* @.str_double, i32 0, i32 0), double %%%d)\n", iteracao, iteracao-1);

			}
			else if(type == 332){

				//LOCAL

				iteracao++;
				printf("%%%d = load i32* %%%s, align 4\n", iteracao, node_factor->id);

				iteracao++;
				printf("%%%d = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str_int, i32 0, i32 0), i32 %%%d)", iteracao, iteracao-1);

			}
			else if(type == 3322){

				//LOCAL

				iteracao++;
				printf("%%%d = load double* %%%s, align 8\n", iteracao, node_factor->id);

				iteracao++;
				printf("%%%d = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([6 x i8]* @.str_double, i32 0, i32 0), double %%%d)\n", iteracao, iteracao-1);

			}
			else if(type == 1){

				//GLOBAL

				iteracao++;
				printf("%%%d = load i1* @%s\n", iteracao, node_factor->id);

				iteracao++;
				printf("%%%d = zext i1 %%%d to i32\n", iteracao, iteracao-1);
				iteracao++;
				printf("%%%d = getelementptr inbounds [2 x i8*]* @.str_bol, i32 0, i32 %%%d\n", iteracao, iteracao-1);
				iteracao++;
	  			printf("%%%d = load i8** %%tmp%d\n", iteracao, iteracao-1);
	  			iteracao++;
	  			printf("%%%d = call i32 (i8*, ...)* @printf(i8* %%%d)\n", iteracao, iteracao-1);

			}
			else if(type == 11){

				//LOCAL

				iteracao++;
				printf("%%%d = load i1* %%%s\n", iteracao, node_factor->id);

				iteracao++;
				printf("%%%d = zext i1 %%%d to i32\n", iteracao, iteracao-1);
				iteracao++;
				printf("%%%d = getelementptr inbounds [2 x i8*]* @.str_bol, i32 0, i32 %%%d\n", iteracao, iteracao-1);
				iteracao++;
	  			printf("%%%d = load i8** %%tmp%d\n", iteracao, iteracao-1);
	  			iteracao++;
	  			printf("%%%d = call i32 (i8*, ...)* @printf(i8* %%%d)\n", iteracao, iteracao-1);

			}

		}

	}
	else if(strcmp(node_factor->type2, "int") == 0){

		sub_op = "int";
		cont_var_op++;

		//alignment();

		//printf("IntLit(%s)\n", node_factor->id);

		if(op_type != NULL && strcmp(op_type, "valparam") == 0){
			iteracao++;
			printf("%%%d = getelementptr inbounds i8** %%%d, i64 %s\n", iteracao, iteracao-1, node_factor->id);
		}
		else if(op_type !=NULL && strcmp(op_type, "print") == 0){
			iteracao++;
			printf("%%%d = alloca i32, align 4\n", iteracao);
			printf("store i32 %s, i32* %%%d, align 4\n", node_factor->id, iteracao);
			iteracao++;
			printf("%%%d = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str_int, i32 0, i32 0), i32 %%%d)\n", iteracao, iteracao-1);
		}
		else{
			iteracao++;
			printf("%%%d = alloca i32, align 4\n", iteracao);
			printf("store i32 %s, i32* %%%d, align 4\n", node_factor->id, iteracao);
			iteracao++;
			printf("%%%d = load i32* %%%d, align 4\n", iteracao, iteracao-1);
		}

		return iteracao;

	}
	else if(op_type != NULL && strcmp(node_factor->type2, "real") == 0){

		sub_op = "double";
		cont_var_op++;

		//alignment();

		//printf("RealLit(%s)\n", node_factor->id);

		if(strcmp(op_type, "valparam") == 0){
			iteracao++;
			printf("%%%d = getelementptr inbounds i8** %%%d, i64 %s\n", iteracao, iteracao-1, node_factor->id);
		}
		else if(op_type !=NULL && strcmp(op_type, "print") == 0){
			iteracao++;
			printf("%%%d = alloca double, align 8\n", iteracao);
			printf("store double %s, double* %%%d, align 8\n", node_factor->id, iteracao);
			iteracao++;
			printf("%%%d = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([6 x i8]* @.str_double, i32 0, i32 0), double %%%d)\n", iteracao, iteracao-1);
		}
		else{
			iteracao++;
			printf("%%%d = alloca double, align 8\n", iteracao);
			printf("store double %s, double* %%%d, align 8\n", node_factor->id, iteracao);
			iteracao++;
			printf("%%%d = load double* %%%d, align 4\n", iteracao, iteracao-1);
		}

		return iteracao;

	}
	else if(strcmp(node_factor->type2, "func") == 0){
		
		if(node_factor->node_func_design != NULL){

			llvm_func_design(node_factor->node_func_design);

		}
		
	}
	else if(strcmp(node_factor->type2, "expr") == 0){

		if(node_factor->node_expr != NULL){
			llvm_expression(node_factor->node_expr);
		} 
		
	}
	else if(strcmp(node_factor->type2, "fact") == 0){

		//alignment();

		//printf("Not\n");

		//advance++;

		if(node_factor->node_factor != NULL)
			llvm_factor(node_factor->node_factor);

		//advance--;
		
	}

	return -1;

}

void llvm_func_design(func_design * node_func_design){

	//alignment();

	//printf("Call\n");

	//advance++;

	//alignment();

	//printf("Id(%s)\n", node_func_design->id);

	if(node_func_design->param_list != NULL){

		if(node_func_design->param_list->node_expr != NULL){

			llvm_expression(node_func_design->param_list->node_expr);

		}

		if(node_func_design->param_list->next_param != NULL){

			llvm_aditional_params(node_func_design->param_list->next_param);

		}

	}

	//advance--;


}

void llvm_aditional_params(aditional_params * temp){

	if(temp->node_expr != NULL)
		print_expression(temp->node_expr);

	if(temp->next_param != NULL)
		print_aditional_params(temp->next_param);

}






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

#include "functions.h"

start * insert_start(prog * program){
	
	start * data = (start *) malloc(sizeof(start));

	if(program != NULL) data->node_program = program;

	return data;

}

prog * insert_program(prog_heading * heading, prog_block * block){
	
	prog * data = (prog *) malloc(sizeof(prog));

	if(heading != NULL) data->node_prog_heading = heading;
	if(block != NULL) data->node_prog_block = block;

	return data;
}

prog_heading * insert_program_heading(char * id){
	
	prog_heading * data = (prog_heading *) malloc(sizeof(prog_heading));

	if(id != NULL) data->id = id;

	return data;
}

prog_block * insert_program_block(var_part * var_Part, func_part * func_Part, stat_part * stat_Part){

	prog_block * data = (prog_block *) malloc(sizeof(prog_block));

	if(var_Part != NULL) data->node_var_part = var_Part;
	if(func_Part != NULL) data->node_func_part = func_Part;
	if(stat_Part != NULL) data->node_stat_part = stat_Part;

	return data;

}

var_part * insert_var_part(var_decl * var_Decl, aditional_var_part * var_Part){

	if(var_Decl == NULL && var_Part == NULL) return NULL;

	var_part * data = (var_part *) malloc(sizeof(var_part));
	
	if(var_Decl != NULL) data->node_var_decl = var_Decl;
	if(var_Part != NULL) data->next_var_part = var_Part;

	return data;

}

aditional_var_part * insert_aditional_var_part(var_decl * var_Decl, aditional_var_part * var_Part){

	if(var_Decl == NULL && var_Part == NULL) return NULL;

	aditional_var_part * data = (aditional_var_part *) malloc(sizeof(aditional_var_part));
	
	if(var_Decl != NULL) data->node_var_decl = var_Decl;
	if(var_Part != NULL) data->next_var_part = var_Part;

	return data;

}

var_decl * insert_var_decl(id_list * id_List, char * id_Type){

	var_decl * data = (var_decl *) malloc(sizeof(var_decl));

	if(id_List != NULL) data->node_id_list = id_List;
	if(id_Type != NULL) data->id_type = id_Type;

	return data;

}

id_list * insert_id_list(char * id, aditional_id_list * id_List){

	id_list * data = (id_list *) malloc(sizeof(id_list));

	if(id != NULL) data->id = id;
	if(id_List != NULL) data->next_id = id_List;

	return data;

}

aditional_id_list * insert_aditional_id_list(char * id, aditional_id_list * id_List){

	aditional_id_list * data = (aditional_id_list *) malloc(sizeof(aditional_id_list));

	if(id != NULL) data->id = id;
	else data->id = NULL;
	if(id_List != NULL) data->next_id = id_List;

	return data;

}

func_part * insert_func_part(func_decl * func_Decl){

	if(func_Decl == NULL) return NULL;

	func_part * data = (func_part *) malloc(sizeof(func_part));

	if(func_Decl != NULL) data->node_func_decl = func_Decl;

	return data;

}

func_decl * insert_func_decl(func_heading * func_Heading, func_block * func_Block, func_ident * func_Ident){

	func_decl * data = (func_decl *) malloc(sizeof(func_decl));

	if(func_Heading != NULL) data->node_func_heading = func_Heading;
	if(func_Block != NULL) data->node_func_block = func_Block;
	if(func_Ident != NULL) data->node_func_ident = func_Ident;

	return data;

}

func_heading * insert_func_heading(char * id_func, formal_params_list * formal_Params_List, char * id_type){

	func_heading * data = (func_heading *) malloc(sizeof(func_heading));

	if(id_func != NULL) data->id_func = id_func;
	if(formal_Params_List != NULL) data->node_formal_params_list = formal_Params_List;
	if(id_type != NULL) data->id_type = id_type;

	return data;

}

func_ident * insert_func_ident(char * id){

	func_ident * data = (func_ident *) malloc(sizeof(func_ident));

	if(id != NULL) data->id_func = id;

	return data;

}

formal_params_list * insert_formal_params_list(formal_params * formal_Params, aditional_formal_params * aditional_params){

	formal_params_list * data = (formal_params_list *) malloc(sizeof(formal_params_list));

	if(formal_Params != NULL) data->node_formal_params = formal_Params;
	if(aditional_params != NULL) data->next_formal_params = aditional_params;

	return data;

}

aditional_formal_params * insert_aditional_formal_params(formal_params * formal_Params, aditional_formal_params * aditional_params){

	if(formal_Params == NULL && aditional_params == NULL) return NULL;

	aditional_formal_params * data = (aditional_formal_params *) malloc(sizeof(aditional_formal_params));

	if(formal_Params != NULL) data->node_formal_params = formal_Params;
	if(aditional_params != NULL) data->next_formal_params = aditional_params;

	return data;

}

formal_params * insert_formal_params(id_list * id_List, char * id, int type){

	formal_params * data = (formal_params *) malloc(sizeof(formal_params));

	if(id_List != NULL) data->node_id_list = id_List;
	if(id != NULL) data->id_type = id;
	data->type_var = type;

	return data;

}

func_block * insert_func_block(var_part * var_Part, stat_part * stat_Part){

	func_block * data = (func_block *) malloc(sizeof(func_block));

	if(var_Part != NULL) data->node_var_part = var_Part;
	if(stat_Part != NULL) data->node_stat_part = stat_Part;

	return data;

}

stat_part * insert_stat_part(comp_stat * comp_Stat){

	stat_part * data = (stat_part *) malloc(sizeof(stat_part));

	if(comp_Stat != NULL) data->node_comp_stat = comp_Stat;

	return data;

}

comp_stat * insert_comp_stat(stat_list * stat_List){

	comp_stat * data = (comp_stat *) malloc(sizeof(comp_stat));

	if(stat_List != NULL) data->node_stat_list = stat_List;

	return data;

}

stat_list * insert_stat_list(stat * statement, aditional_stat_list * aditional_Stat_List){

	stat_list * data = (stat_list *) malloc(sizeof(stat_list));

	if(statement != NULL) data->node_stat = statement;
	if(aditional_Stat_List != NULL) data->next_stat_list = aditional_Stat_List;

	return data;

}

aditional_stat_list * insert_aditional_stat_list(stat * statement, aditional_stat_list * aditional_Stat_List){

	if(statement == NULL && aditional_Stat_List == NULL) return NULL;

	aditional_stat_list * data = (aditional_stat_list *) malloc(sizeof(aditional_stat_list));

	if(statement != NULL) data->node_stat = statement;
	if(aditional_Stat_List != NULL) data->next_stat_list = aditional_Stat_List;

	return data;

}

stat * insert_statment(comp_stat * comp_Stat, expression * expr, stat * statement, stat * else_stat, stat_list * stat_List, char * id, writeln_list * writeln, int operation){
	
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

	if(operation == (-1)) return NULL;

	stat * data = (stat *) malloc(sizeof(stat));

	if(comp_Stat != NULL) data->node_comp_stat = comp_Stat;
	if(expr != NULL) data->node_expr = expr;
	if(else_stat != NULL) data->node_stat2 = else_stat;
	if(statement != NULL) data->node_stat = statement;
	if(stat_List != NULL) data->node_stat_list = stat_List;
	if(id != NULL) data->id = id;
	if(writeln != NULL) data->node_writeln_list = writeln;
	data->operation_type = operation;

	return data;

}

writeln_list * insert_writeln(expression * expr, aditional_writeln * aditional_Writeln, char * string){

	writeln_list * data = (writeln_list *) malloc(sizeof(writeln_list));

	if(expr != NULL) data->node_expr = expr;
	if(aditional_Writeln != NULL) data->next = aditional_Writeln;
	if(string != NULL) data->string = string;

	return data;

}

aditional_writeln * insert_aditional_writeln(expression * expr, aditional_writeln * aditional_Writeln, char * string){

	if(expr == NULL && aditional_Writeln == NULL && string == NULL) return NULL;

	aditional_writeln * data = (aditional_writeln *) malloc(sizeof(aditional_writeln));

	if(expr != NULL) data->node_expr = expr;
	if(aditional_Writeln != NULL) data->next = aditional_Writeln;
	if(string != NULL) data->string = string;

	return data;

}

expression * insert_expression(simple_expression * expr, simple_expression * expr2, char * id, int operation){

	/*
        1 - Simple
        2 - OP2
    */

	expression * data = (expression *) malloc(sizeof(expression));

	if(expr != NULL) data->node_simple_expr = expr;
	if(expr2 != NULL) data->node_simple_expr2 = expr2;
	if(id != NULL) data->id = id;
	data->operation_type = operation;

	return data;

}

simple_expression * insert_simple_expression(simple_expression * expr, terminal * term, char * id, int operation){

	/*
        1 - OP3
        2 - OR
        3 - OP3 Terminal
        4 - Terminal
    */

	simple_expression * data = (simple_expression *) malloc(sizeof(simple_expression));

	if(expr != NULL) data->node_simple_expr = expr;
	if(term != NULL) data->node_terminal = term;
	if(id != NULL) data->id = id;
	data->operation_type = operation;

	return data;

}

terminal * insert_terminal(terminal * term1, terminal * term2, factor * node_factor, char * id, int operation){

	/*
        1 - OP4
        2 - AND
        3 - Factor
    */

	terminal * data = (terminal *) malloc(sizeof(terminal));

	if(term1 != NULL) data->node_terminal = term1;
	if(term2 != NULL) data->node_terminal2 = term2;
	if(node_factor != NULL) data->node_factor = node_factor;
	if(id != NULL) data->id = id;
	data->operation_type = operation;

	return data;

}

factor * insert_factor(char * id, expression * expr, factor * node_factor, func_design * design, char * type){

	/*
        1 - ID
        2 - INTLIT
        3 - REALLIT
        4 - FuncDesign
        5 - Expr
        6 - NOT
    */

	factor * data = (factor *) malloc(sizeof(factor *));

	if(id != NULL) data->id = id;
	if(expr != NULL) data->node_expr = expr;
	if(node_factor != NULL) data->node_factor = node_factor;
	if(design != NULL) data->node_func_design = design;
	if(type != NULL) data->type = type;

	return data;

}

func_design * insert_func_design(char * id, param_list * params){

	func_design * data = (func_design *) malloc(sizeof(func_design));

	if(id != NULL) data->id = id;
	if(params != NULL) data->param_list = params;

	return data;

}

param_list * insert_params_list(expression * expr, aditional_params * aditional_Params){

	param_list * data = (param_list *) malloc(sizeof(param_list));

	if(expr != NULL) data->node_expr = expr;
	if(aditional_Params != NULL) data->next_param = aditional_Params;

	return data;

}

aditional_params * insert_aditional_params(expression * expr, aditional_params * aditional_Params){

	if(expr == NULL && aditional_Params == NULL) return NULL;

	aditional_params * data = (aditional_params *) malloc(sizeof(aditional_params));

	if(expr != NULL) data->node_expr = expr;
	if(aditional_Params != NULL) data->next_param = aditional_Params;

	return data;

}


int advance = 0;

void alignment(){

	int i;
	for(i = 0; i < advance; i++) printf("..");

}

void print_all(prog * node_program){

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

		alignment();

		printf("StatList\n");

		if(node_prog_block->node_stat_part != NULL){

			advance++;

			print_stat_part(node_prog_block->node_stat_part);

			advance--;

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

		//advance++;

		if(node_func_part->node_func_decl != NULL){

			alignment();

			if(node_func_part->node_func_decl->node_func_heading != NULL){
				
				if(node_func_part->node_func_decl->node_func_block != NULL){

					printf("FuncDef\n");

					advance++;

					print_func_heading(node_func_part->node_func_decl->node_func_heading);

					if(node_func_part->node_func_decl->node_func_block != NULL)
						print_func_block(node_func_part->node_func_decl->node_func_block);
					else {

						alignment();

						printf("StatList\n");

					}

					advance--;

				}
				else{

					printf("FuncDecl\n");

					advance++;

					print_func_heading(node_func_part->node_func_decl->node_func_heading);

					advance--;
				}

			}

			if(node_func_part->node_func_decl->node_func_ident != NULL){
				
				if(node_func_part->node_func_decl->node_func_block != NULL){

					printf("FuncDef2\n");

					advance++;

					alignment();

					if(node_func_part->node_func_decl->node_func_ident->id_func != NULL) printf("Id(%s)\n", node_func_part->node_func_decl->node_func_ident->id_func);

					if(node_func_part->node_func_decl->node_func_block != NULL)
						print_func_block(node_func_part->node_func_decl->node_func_block);
					else {

						alignment();

						printf("StatList\n");

					}

					advance--;

				}

			}

		}

		//advance--;

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

	if(node_formal_params->type_var == 1){

		alignment();

		printf("VarParams\n");

		advance++;

		print_id_list(node_formal_params->node_id_list);

		alignment();

		printf("Id(%s)\n", node_formal_params->id_type);

		advance--;

	}
	else if(node_formal_params->type_var == 2){

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

	if(node_func_block->node_stat_part != NULL){

		alignment();

		printf("StatList\n");

		advance++;

		print_stat_part(node_func_block->node_stat_part);

		advance--;

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

	if(node_stat_list->next_stat_list != NULL){

		print_aditional_stat_list(node_stat_list->next_stat_list);


	}

}

void print_aditional_stat_list(aditional_stat_list * temp){

	print_stat(temp->node_stat);

	if(temp->next_stat_list != NULL){

		print_aditional_stat_list(temp->next_stat_list);

	}

}

void print_stat(stat * node_stat){

	alignment();

	if(node_stat->operation_type == 1){

		printf("StatList\n");

		advance++;

		print_comp_stat(node_stat->node_comp_stat);

		advance--;
		
	}
	else if(node_stat->operation_type == 2){

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
	else if(node_stat->operation_type == 3){

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
	else if(node_stat->operation_type == 4){

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
	else if(node_stat->operation_type == 5){

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
	else if(node_stat->operation_type == 6){

		printf("ValParam\n");

		advance++;
		
		print_expression(node_stat->node_expr);
		
		alignment();
		printf("Id(%s)\n", node_stat->id);

		advance--;

	}
	else if(node_stat->operation_type == 7){

		printf("Assign\n");

		advance++;

		alignment();
		printf("Id(%s)\n", node_stat->id);
		
		print_expression(node_stat->node_expr);

		advance--;

	}
	else if(node_stat->operation_type == 8){

		printf("WriteLn\n");

		advance++;

		print_writeln(node_stat->node_writeln_list);

		advance--;
		
	}

}

void print_writeln(writeln_list * node_writeln_list){

	if(node_writeln_list->node_expr != NULL)
		print_expression(node_writeln_list->node_expr);

	if(node_writeln_list->next != NULL)
		print_aditional_writeln(node_writeln_list->next);

}

void print_aditional_writeln(aditional_writeln * temp){

	if(temp->node_expr != NULL)
		print_expression(temp->node_expr);

	if(temp->next != NULL)
		print_aditional_writeln(temp->next);

}


void print_expression(expression * node_expr){

	if(node_expr->operation_type == 1){
		print_simple_expression(node_expr->node_simple_expr);
	}
	else if(node_expr->operation_type == 2){
		
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

	if(node_simple_expr->operation_type == 1){

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
	else if(node_simple_expr->operation_type == 2){

		alignment();

		printf("Or\n");

		advance++;

		print_simple_expression(node_simple_expr->node_simple_expr);

		print_terminal(node_simple_expr->node_terminal);

		advance--;

	}
	else if(node_simple_expr->operation_type == 3){

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
	else if(node_simple_expr->operation_type == 4){

		print_terminal(node_simple_expr->node_terminal);

	}

}

void print_terminal(terminal * node_terminal){

	if(node_terminal->operation_type == 1){

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
	else if(node_terminal->operation_type == 2){

		alignment();

		printf("And\n");

		advance++;

		print_terminal(node_terminal->node_terminal);

		print_terminal(node_terminal->node_terminal2);

		advance--;

	}
	else if(node_terminal->operation_type == 3){

		print_factor(node_terminal->node_factor);

	}

}

void print_factor(factor * node_factor){

	if(strcmp(node_factor->type, "id") == 0){

		alignment();

		printf("Id(%s)\n", node_factor->id);

	}
	else if(strcmp(node_factor->type, "int") == 0){

		alignment();

		printf("IntLit(%s)\n", node_factor->id);

	}
	else if(strcmp(node_factor->type, "real") == 0){

		alignment();

		printf("RealLit(%s)\n", node_factor->id);

	}
	else if(strcmp(node_factor->type, "func") == 0){

		if(node_factor->node_func_design != NULL){

			alignment();

			printf("Id(%s)\n", node_factor->node_func_design->id);

			advance++;

			if(node_factor->node_func_design->param_list != NULL){

				if(node_factor->node_func_design->param_list->node_expr != NULL){

					print_expression(node_factor->node_func_design->param_list->node_expr);

				}

				if(node_factor->node_func_design->param_list->next_param != NULL){

					print_aditional_params(node_factor->node_func_design->param_list->next_param);

				}

			}

			advance--;

		}
		
	}
	else if(strcmp(node_factor->type, "expr") == 0){

		print_expression(node_factor->node_expr);
		
	}
	else if(strcmp(node_factor->type, "fact") == 0){

		alignment();

		printf("Not\n");

		advance++;

		alignment();

		print_factor(node_factor->node_factor);

		advance--;
		
	}

}


void print_aditional_params(aditional_params * temp){

	if(temp->node_expr != NULL)
		print_expression(temp->node_expr);

	if(temp->next_param != NULL)
		print_aditional_params(temp->next_param);

}











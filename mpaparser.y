%{/* --- C Variables Definition --- */
%}

%{

	#include <stdio.h>
	#include <string.h>
	#include "functions.h"
	#include "structs.h"
	#include "y.tab.h"

	extern int linha;
	extern int coluna;
	extern char * yytext;

	char * line = "sajsa";
	char * column = "sadsa";

	void yyerror(char * s);
	int yylex();

	start * program_start = NULL;
	symbol_table * symbols = NULL;
	
%}

%union{
    
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

%token <id> ID
%token <id> INTLIT
%token <id> REALLIT
%token <id> STRING
%token ASSIGN
%token BEGIN1
%token COLON
%token COMMA
%token DO
%token DOT
%token ELSE
%token END
%token FORWARD
%token FUNCTION 
%token IF
%token LBRAC
%token NOT
%token OUTPUT
%token PARAMSTR
%token PROGRAM
%token RBRAC
%token REPEAT
%token SEMIC
%token THEN
%token UNTIL
%token VAL
%token VAR 
%token WHILE 
%token WRITELN 
%token AND
%token OR
%token <id> OP2
%token <id> OP3
%token <id> OP4
%token RESERVED


%nonassoc THEN
%nonassoc ELSE
%nonassoc IF
%left LBRAC RBRAC
%left OP4 AND
%left OR OP3
%left OP2
%right ASSIGN
%right NOT 


%type <node_start> Start
%type <node_prog> Program
%type <node_prog_heading> ProgramHeading
%type <node_prog_block> ProgramBlock
%type <node_var_part> VarPart
%type <next_var_part> AditionalVarPart
%type <node_var_decl> VarDecl
%type <node_id_list> IdList
%type <next_id> AditionalIds
%type <node_func_part> FuncPart
%type <node_func_decl> FuncDecl
%type <node_func_heading> FuncHeading
%type <node_func_ident> FuncIdent
%type <node_formal_params_list> FormalParamsList
%type <next_formal_params> AditionalFormalParams
%type <node_formal_params> FormalParams
%type <node_func_block> FuncBlock
%type <node_stat_part> StatPart
%type <node_comp_stat> CompStat
%type <node_stat_list> StatList
%type <next_stat_list> AditionalStatList
%type <node_stat> Statement
%type <node_writeln_list> Writeln
%type <next_writeln> AditionalWriteln
%type <node_expr> Expression
%type <node_simple_expression> SimpleExpression
%type <node_terminal> Terminal
%type <node_factor> Factor
%type <node_func_design> FuncDesign
%type <node_param_list> ParamList
%type <next_param> AditionalParams

%%
Start : Program 															{$$ = program_start = insert_start($1, linha, coluna);};

Program : ProgramHeading SEMIC ProgramBlock DOT 							{$$ = insert_program($1,$3, linha, coluna);};

ProgramHeading : PROGRAM ID LBRAC OUTPUT RBRAC								{$$ = insert_program_heading($2, linha, coluna);};

ProgramBlock : VarPart FuncPart StatPart 									{$$ = insert_program_block($1, $2, $3, linha, coluna);};

VarPart : VAR VarDecl SEMIC AditionalVarPart 								{$$ = insert_var_part($2, $4, linha, coluna);}
		 |																	{$$ = insert_var_part(NULL, NULL, -1, -1);};

AditionalVarPart : VarDecl SEMIC AditionalVarPart 							{$$ = insert_aditional_var_part($1, $3, linha, coluna);}
		 		  | 														{$$ = insert_aditional_var_part(NULL, NULL, -1, -1);};

VarDecl : IdList COLON ID 													{$$ = insert_var_decl($1, $3, linha, coluna);};

IdList : ID AditionalIds													{$$ = insert_id_list($1, $2, linha, coluna);};

AditionalIds : COMMA ID AditionalIds										{$$ = insert_aditional_id_list($2, $3, linha, coluna);}
			  | 															{$$ = insert_aditional_id_list(NULL, NULL, -1, -1);};

FuncPart : FuncDecl SEMIC FuncPart											{$$ = insert_func_part($1, $3, linha, coluna);}
		  | 																{$$ = insert_func_part(NULL, NULL, -1, -1);};

FuncDecl : FuncHeading SEMIC FORWARD 										{$$ = insert_func_decl($1, NULL, NULL, linha, coluna);}
		  | FuncIdent SEMIC FuncBlock 										{$$ = insert_func_decl(NULL, $3, $1, linha, coluna);}
		  | FuncHeading SEMIC FuncBlock 									{$$ = insert_func_decl($1, $3, NULL, linha, coluna);};

FuncHeading : FUNCTION ID COLON ID 											{$$ = insert_func_heading($2, NULL, $4, linha, coluna);}
			 | FUNCTION ID FormalParamsList COLON ID 						{$$ = insert_func_heading($2, $3, $5, linha, coluna);};

FuncIdent : FUNCTION ID 													{$$ = insert_func_ident($2, linha, coluna);};

FormalParamsList : LBRAC FormalParams AditionalFormalParams RBRAC 			{$$ = insert_formal_params_list($2, $3, linha, coluna);};

AditionalFormalParams : SEMIC FormalParams AditionalFormalParams 			{$$ = insert_aditional_formal_params($2, $3, linha, coluna);}
				  	   | 													{$$ = insert_aditional_formal_params(NULL, NULL, -1, -1);};

FormalParams : IdList COLON ID												{$$ = insert_formal_params($1, $3, "fp2", linha, coluna);}
			  | VAR IdList COLON ID 										{$$ = insert_formal_params($2, $4, "fp1", linha, coluna);};

FuncBlock : VarPart StatPart 												{$$ = insert_func_block($1, $2, linha, coluna);};

StatPart : CompStat 														{$$ = insert_stat_part($1, linha, coluna);};

CompStat : BEGIN1 StatList END 												{$$ = insert_comp_stat($2, linha, coluna);};

StatList : Statement AditionalStatList 										{$$ = insert_stat_list($1, $2, linha, coluna);};

AditionalStatList : SEMIC Statement AditionalStatList						{$$ = insert_aditional_stat_list($2, $3, linha, coluna);}
		  		  | 														{$$ = insert_aditional_stat_list(NULL, NULL, -1, -1);};

Statement : CompStat 														{$$ = insert_statment($1, NULL, NULL, NULL, NULL, NULL, NULL, "s1", linha, coluna);}
		   | IF Expression THEN Statement ELSE Statement 					{$$ = insert_statment(NULL, $2, $4, $6, NULL, NULL, NULL, "s3", linha, coluna);}
		   | IF Expression THEN Statement 									{$$ = insert_statment(NULL, $2, $4, NULL, NULL, NULL, NULL, "s2", linha, coluna);}
		   | WHILE Expression DO Statement 									{$$ = insert_statment(NULL, $2, $4, NULL, NULL, NULL, NULL, "s4", linha, coluna);}
		   | REPEAT StatList UNTIL Expression								{$$ = insert_statment(NULL, $4, NULL, NULL, $2, NULL, NULL, "s5", linha, coluna);}
		   | VAL LBRAC PARAMSTR LBRAC Expression RBRAC COMMA ID RBRAC 		{$$ = insert_statment(NULL, $5, NULL, NULL, NULL, $8, NULL, "s6", linha, coluna);}
		   | ID ASSIGN Expression 											{$$ = insert_statment(NULL, $3, NULL, NULL, NULL, $1, NULL, "s7", linha, coluna);}
		   | WRITELN 														{$$ = insert_statment(NULL, NULL, NULL, NULL, NULL, NULL, NULL, "s8", linha, coluna);}
		   | WRITELN Writeln 												{$$ = insert_statment(NULL, NULL, NULL, NULL, NULL, NULL, $2, "s8", linha, coluna);}
		   | 																{$$ = insert_statment(NULL, NULL, NULL, NULL, NULL, NULL, NULL, "s-1", -1, -1);};

Writeln : LBRAC Expression AditionalWriteln RBRAC 							{$$ = insert_writeln($2, $3, NULL, linha, coluna);}
		 | LBRAC STRING AditionalWriteln RBRAC 								{$$ = insert_writeln(NULL, $3, $2, linha, coluna);};

AditionalWriteln : COMMA Expression AditionalWriteln 						{$$ = insert_aditional_writeln($2, $3, NULL, linha, coluna);}
				  | COMMA STRING AditionalWriteln 							{$$ = insert_aditional_writeln(NULL, $3, $2, linha, coluna);}
				  | 														{$$ = insert_aditional_writeln(NULL, NULL, NULL, -1, -1);};

Expression : SimpleExpression 												{$$ = insert_expression($1, NULL, NULL, "e1", linha, coluna);}
			| SimpleExpression OP2 SimpleExpression 						{$$ = insert_expression($1, $3, $2, "e2", linha, coluna);};

SimpleExpression : SimpleExpression OP3 Terminal 							{$$ = insert_simple_expression($1, $3, $2, "se1", linha, coluna);}
				  | SimpleExpression OR Terminal 							{$$ = insert_simple_expression($1, $3, NULL, "se2", linha, coluna);}
				  | OP3 Terminal 											{$$ = insert_simple_expression(NULL, $2, $1, "se3", linha, coluna);}
				  | Terminal 												{$$ = insert_simple_expression(NULL, $1, NULL, "se4", linha, coluna);};

Terminal : Terminal OP4 Terminal 											{$$ = insert_terminal($1, $3, NULL, $2, "t1", linha, coluna);}
		  | Terminal AND Terminal 											{$$ = insert_terminal($1, $3, NULL, NULL, "t2", linha, coluna);}
		  | Factor 															{$$ = insert_terminal(NULL, NULL, $1, NULL, "t3", linha, coluna);};


Factor : ID 																{$$ = insert_factor($1, NULL, NULL, NULL, (char *)"id", linha, coluna);}
		| INTLIT 															{$$ = insert_factor($1, NULL, NULL, NULL, (char *)"int", linha, coluna);}
		| REALLIT 															{$$ = insert_factor($1, NULL, NULL, NULL, (char *)"real", linha, coluna);}
		| FuncDesign 														{$$ = insert_factor(NULL, NULL, NULL, $1, (char *)"func", linha, coluna);}
		| LBRAC Expression RBRAC 											{$$ = insert_factor(NULL, $2, NULL, NULL, (char *)"expr", linha, coluna);}
		| NOT Factor 														{$$ = insert_factor(NULL, NULL, $2, NULL, (char *)"fact", linha, coluna);};

FuncDesign : ID ParamList 													{$$ = insert_func_design($1, $2, linha, coluna);};
 
ParamList : LBRAC Expression AditionalParams RBRAC 							{$$ = insert_params_list($2, $3, linha, coluna);};

AditionalParams : COMMA Expression AditionalParams 							{$$ = insert_aditional_params($2, $3, linha, coluna);}
		   		 | 															{$$ = insert_aditional_params(NULL, NULL, -1, -1);};

%%

/* --- C code Section --- */

int main(int argc, char *argv[]){

	//Arvore
	if(yyparse() == 0){

 		int i, result;

		for(i = 0; i < argc; i++){
			if(strcmp(argv[i], "-t") == 0) {
				print_all(program_start->node_program);
			}
		}

		symbols = (symbol_table *) malloc(sizeof(symbol_table));

		build_symbol_table(program_start->node_program, symbols);

		for(i = 0; i < argc; i++){
			if(strcmp(argv[i], "-s") == 0){
				print_symbol_table(symbols);
			}
		}

		llvm_all(program_start->node_program, symbols);

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

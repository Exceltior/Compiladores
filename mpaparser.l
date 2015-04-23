%option caseless
%x COMENTARIOS
%{


	#include <stdio.h>
	#include <string.h>
	#include "structs.h"
	#include "y.tab.h"


	int coluna = 1, linha = 1, colunaTemp, linhaTemp;
	

%}

INTLIT 		[0-9]+
REALLIT 	[0-9]+(("."[0-9]+)|(("."[0-9]+)*"e"(("+"|"-")*[0-9]+)+))+
STRING 		"'"("''"|[^\n'])*"'"
NOTSTRING 	"'"("''"|[^\n'])*
ID 			[a-zA-Z]+([0-9a-zA-Z])*
ASSIGN 		":="
BEGIN1 		"begin"
COLON 		":"
COMMA 		","
DO 			"do"
DOT 		"."
ELSE 		"else"
END 		"end"
FORWARD 	"forward"
FUNCTION 	"function"
IF 			"if"
LBRAC 		"("
NOT 		"not"
OUTPUT 		"output"
PARAMSTR 	"paramstr"
PROGRAM 	"program"
RBRAC 		")"
REPEAT 		"repeat"
SEMIC 		";"
THEN 		"then"
UNTIL 		"until"
VAL 		"val"
VAR 		"var"
WHILE 		"while"
WRITELN 	"writeln"
AND 		"and"
OR 			"or"
OP2 		"<"|">"|"="|"<>"|"<="|">="
OP3 		"+"|"-"
OP4 		"*"|"/"|"mod"|"div"
RESERVED  	"abs"|"arctan"|"array"|"case"|"char"|"chr"|"const"|"cos"|"dispose"|"downto"|"eof"|"eoln"|"exp"|"file"|"for"|"get"|"goto"|"in"|"input"|"label"|"ln"|"maxint"|"new"|"nil"|"odd"|"of"|"ord"|"pack"|"packed"|"page"|"pred"|"procedure"|"put"|"read"|"readln"|"record"|"reset"|"rewrite"|"round"|"set"|"sin"|"sqr"|"sqrt"|"succ"|"text"|"to"|"trunc"|"type"|"unpack"|"with"|"write"

%%

"(*"|"{"				{BEGIN COMENTARIOS; colunaTemp = coluna; linhaTemp = linha; coluna+=strlen(yytext);}
<COMENTARIOS>\n			{linha++; coluna=1;}
<COMENTARIOS>"*)"|"}"	{coluna+=strlen(yytext); BEGIN 0;}
<COMENTARIOS>.			{coluna+=strlen(yytext);}
<COMENTARIOS><<EOF>>	{printf("Line %d, col %d: unterminated comment\n", linhaTemp, colunaTemp); coluna+=strlen(yytext); return 0;}

{ASSIGN}				{coluna+=strlen(yytext);return ASSIGN;}
{BEGIN1}				{coluna+=strlen(yytext);return BEGIN1;}
{COLON}					{coluna+=strlen(yytext);return COLON;}
{COMMA}					{coluna+=strlen(yytext);return COMMA;}
{DO}					{coluna+=strlen(yytext);return DO;}
{DOT}					{coluna+=strlen(yytext);return DOT;}
{ELSE}					{coluna+=strlen(yytext);return ELSE;}
{END}					{coluna+=strlen(yytext);return END;}
{FORWARD}				{coluna+=strlen(yytext);return FORWARD;}
{FUNCTION}				{coluna+=strlen(yytext);return FUNCTION;}
{IF}					{coluna+=strlen(yytext);return IF;}
{LBRAC}					{coluna+=strlen(yytext);return LBRAC;}
{NOT}					{coluna+=strlen(yytext);return NOT;}
{OUTPUT}				{coluna+=strlen(yytext);return OUTPUT;}
{PARAMSTR}				{coluna+=strlen(yytext);return PARAMSTR;}
{PROGRAM}				{coluna+=strlen(yytext);return PROGRAM;}
{RBRAC}					{coluna+=strlen(yytext);return RBRAC;}
{REPEAT}				{coluna+=strlen(yytext);return REPEAT;}
{SEMIC}					{coluna+=strlen(yytext);return SEMIC;}
{THEN}					{coluna+=strlen(yytext);return THEN;}
{UNTIL}					{coluna+=strlen(yytext);return UNTIL;}
{VAL}					{coluna+=strlen(yytext);return VAL;}
{VAR}					{coluna+=strlen(yytext);return VAR;}
{WHILE}					{coluna+=strlen(yytext);return WHILE;}
{WRITELN} 				{coluna+=strlen(yytext);return WRITELN;}

{AND}					{coluna+=strlen(yytext);return AND;}
{OR}					{coluna+=strlen(yytext);return OR;}
{OP2}					{yylval.id=(char*)strdup(yytext); coluna+=strlen(yytext);return OP2;}
{OP3}					{yylval.id=(char*)strdup(yytext); coluna+=strlen(yytext);return OP3;}
{OP4}					{yylval.id=(char*)strdup(yytext); coluna+=strlen(yytext);return OP4;}

{RESERVED}				{coluna += strlen(yytext);return RESERVED;}

{ID}					{yylval.id=(char*)strdup(yytext); coluna += strlen(yytext);return ID;}
{INTLIT}				{yylval.id=(char*)strdup(yytext); coluna += strlen(yytext);return INTLIT;}
{REALLIT}				{yylval.id=(char*)strdup(yytext); coluna += strlen(yytext);return REALLIT;}
{STRING}				{yylval.id=(char*)strdup(yytext); coluna += strlen(yytext);return STRING;}
{NOTSTRING}				{printf("Line %d, col %d: unterminated string\n", linha, coluna);}

" "						{coluna+=strlen(yytext);}
"\t"					{coluna+=strlen(yytext);}
"\n"					{linha++; coluna = 1;}

.						{printf("Line %d, col %d: illegal character ('%s')\n", linha, coluna, yytext); coluna+=strlen(yytext);}
<<EOF>>					{coluna+=strlen(yytext); yyterminate();}

%%

int yywrap(){
	return 1;
}

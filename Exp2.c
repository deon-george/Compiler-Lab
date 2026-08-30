##Lexical Analyser Using Lex Tool
%{
#include<stdio.h>
%}

%% 
"if"|"else"|"int"|"switch"|"char"          { printf("%s is a keyword\n", yytext); }
[a-z_][a-z0-9_]*             	       { printf("%s is an identifier\n", yytext); }
[0-9]+           			       { printf("%s is a number\n", yytext); }
[=+*/<>]                             	       { printf("%s is an operator\n", yytext); }
[(){}[]]          		     	       { printf("%s is a separator\n", yytext); }
[ \t]+                              	        ;
\n                                   	       { return 0; }
.                                    	       { printf("%s is invalid\n", yytext); }
%%

int main() { 
	printf("Enter the input:\n"); 
	yylex(); 
	return 0; 
}
int yywrap() 
{ 	
	return 1; 
}

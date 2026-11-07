%{
#include<stdio.h>
#include<stdlib.h>
int yylex();
int yyerror(char *s);
%}

%token DIGIT ID NL

%left '+' '-'
%left '*' '/'

%%


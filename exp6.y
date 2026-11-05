%{
#include <stdio.h>
#include <stdlib.h>

int yylex();
int yyerror(char *s);
%}

%token DIGIT ID NL

%left '+' '-'
%left '*' '/'

%%

stmt : exp NL
     {
         printf("Valid Expression\n");
         return 0;
     }
     ;

exp  : exp '+' exp
     | exp '-' exp
     | exp '*' exp
     | exp '/' exp
     | DIGIT
     | ID
     ;

%%

int main()
{
    printf("Enter an expression: ");
    yyparse();
    return 0;
}

int yyerror(char *s)
{
    printf("Invalid Expression\n");
    return 0;
}
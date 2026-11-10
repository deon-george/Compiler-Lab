%{
#include <stdio.h>
#include <stdlib.h>
%}

%token DIGIT ID NL

%left '+' '-'
%left '*' '/'

%%

stmt : exp NL
     {
         printf("Result = %d\n", $1);
     }
     ;

exp  : exp '+' exp
     {
         $$ = $1 + $3;
     }
     | exp '-' exp
     {
         $$ = $1 - $3;
     }
     | exp '*' exp
     {
         $$ = $1 * $3;
     }
     | exp '/' exp
     {
         if ($3 == 0)
         {
             yyerror("Division by zero");
             YYABORT;
         }
         else
             $$ = $1 / $3;
     }
     | DIGIT
     {
         $$ = $1;
     }
     ;

%%

int main()
{
    printf("Enter an arithmetic expression: ");
    yyparse();
    return 0;
}

int yyerror(char *s)
{
    printf("Invalid: %s\n", s);
    return 0;
}

%{
#include <stdio.h>
%}

%token ID NL

%%

stmt : exp NL
     {
         printf("Valid Identifier\n");
     }
     ;

exp : ID
    ;

%%

int main()
{
    printf("Enter an identifier: ");
    yyparse();
    return 0;
}

int yyerror()
{
    printf("Invalid Identifier\n");
    return 0;
}


%{
    //Convert abc to ABC in a substring Using Lex
#include <stdio.h>
%}

%%

abc     { printf("ABC"); }
.|\n    { printf("%s", yytext); }

%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("Enter a string:\n");
    yylex();
    return 0;
}	

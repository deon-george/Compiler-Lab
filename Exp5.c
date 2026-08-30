##Count Vowels and Consonants in a String Using Lex 
%{
#include <stdio.h>
int vow = 0, cons = 0;
%}

%%

[AEIOUaeiou]   { vow++; }
[A-Za-z]       { cons++; }
\n             { return 0; }
.              ;

%%

int yywrap(){
    return 1;
}

int main(){
    printf("Enter a string: ");
    yylex();
    printf("Number of vowels = %d\n", vow);
    printf("Number of consonants = %d\n", cons);
    return 0;
}

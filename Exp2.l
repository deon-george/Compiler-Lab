%{
	#include<stdio.h>
%}

%%
"if"|"else"|"int"|"switch"|"char"       { printf("%s is a keyword\n",yytext); }
[a-z_][a-z0-9_]*                        { printf("%s is a identifier\n",yytext); }
[0-9]+                                  { printf("%s is a number\n",yytext); } 
[-=+*/<>]                               { printf("%s is a operator\n",yytext); }
[{}()\[\]]				{ printf("%s is a separator\n",yytext); }
[\t]+					;
\n					{ return 0; }
.					{ printf("%s is invaild\n",yytext); } 
%%

int main(){
 printf("enter the input\n");
 yylex();
 return 0;
 }
 int yywrap()
 {
 return 1;
 }

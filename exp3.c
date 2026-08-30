
%{
    //Count Lines, Words and Characters Using Lex
#include<stdio.h>
	int lines = 0, words = 0, chars = 0;
%}

%%

[ \t]+          { chars += yyleng; }
\n              { lines++; chars++; }
[a-zA-Z0-9]+    { words++; chars += yyleng; }
.               { chars++; }
 
%%

int yywrap()
{
    return 1;
}

int main()
{
    char fname[100];

    printf("Enter the input file name: ");
    scanf("%s", fname);

    yyin = fopen(fname, "r");

    if (yyin == NULL)
    {
        printf("Cannot open file.\n");
        return 1;
    }

    yylex();
    printf("\nNumber of Lines      : %d\n", lines);
    printf("Number of Words      : %d\n", words);
    printf("Number of Characters : %d\n", chars);
    fclose(yyin);
    return 0;
}

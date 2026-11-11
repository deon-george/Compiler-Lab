#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    FILE *fp = fopen("input.txt", "r");

    int ch;
    char word[100];
    int i = 0;

    if (fp == NULL)
    {
        printf("File not found\n");
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF)
    {
        // Identify operators
        if (ch == '=' || ch == '+' || ch == '-' ||
            ch == '/' || ch == '*' || ch == '<' || ch == '>')
        {
            printf("%c : Operator\n", ch);
        }

        // Identify separators
        else if (ch == '{' || ch == '}' || ch == '(' ||
                 ch == ')' || ch == ';' || ch == ',')
        {
            printf("%c : Separator\n", ch);
        }

        // Identify numbers
        else if (isdigit(ch))
        {
            printf("%c : Number\n", ch);
        }

        // Identify identifiers and keywords
        else if (isalpha(ch) || ch == '_')
        {
            word[i++] = ch;

            while ((ch = fgetc(fp)) != EOF &&
                   (isalnum(ch) || ch == '_'))
            {
                word[i++] = ch;
            }

            word[i] = '\0';

            if (strcmp(word, "int") == 0 ||
                strcmp(word, "float") == 0 ||
                strcmp(word, "char") == 0 ||
                strcmp(word, "if") == 0 ||
                strcmp(word, "else") == 0 ||
                strcmp(word, "while") == 0 ||
                strcmp(word, "for") == 0 ||
                strcmp(word, "return") == 0 ||
                strcmp(word, "void") == 0)
            {
                printf("%s : Keyword\n", word);
            }
            else
            {
                printf("%s : Identifier\n", word);
            }

            i = 0;

            if (ch != EOF)
                ungetc(ch, fp);
        }
    }

    fclose(fp);

    return 0;
}

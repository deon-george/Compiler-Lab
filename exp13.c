
#include <stdio.h>
#include <string.h>

char expr[100];

void generate(char op)
{
    int i;
    for (i = 0; expr[i] != '\0'; i++)
    {
        if (expr[i] == op)
        {
            printf("t = %c %c %c\n",expr[i-1], op, expr[i+1]);

            expr[i-1] = 't';
            for (int j = i; expr[j] != '\0'; j++)
                expr[j] = expr[j+2];

            i = 0;
        }
    }
}

int main()
{
    printf("Enter an expression: ");
    scanf("%s", expr);

    generate('/');
    generate('*');
    generate('+');
    generate('-');

    printf("Final Result: %s\n", expr);

    return 0;
}

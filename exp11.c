#include <stdio.h>
#include <string.h>

char stack[50], input[50];
int top = -1, i = 0;

void check()
{
    // Reduce id to E
    if (stack[top] == 'd' && stack[top - 1] == 'i')
    {
        stack[top - 1] = 'E';
        top--;
        printf("$%.*s\t%.*s$\tREDUCE E->id\n",
               top + 1, stack, (int)strlen(input) - i, input + i);
    }

    // Reduce E+E to E
    if (top >= 2 &&
        stack[top] == 'E' &&
        stack[top - 1] == '+' &&
        stack[top - 2] == 'E')
    {
        top -= 2;
        stack[top] = 'E';
        printf("$%.*s\t%.*s$\tREDUCE E->E+E\n",
               top + 1, stack, (int)strlen(input) - i, input + i);
    }

    // Reduce E*E to E
    else if (top >= 2 &&
             stack[top] == 'E' &&
             stack[top - 1] == '*' &&
             stack[top - 2] == 'E')
    {
        top -= 2;
        stack[top] = 'E';
        printf("$%.*s\t%.*s$\tREDUCE E->E*E\n",
               top + 1, stack, (int)strlen(input) - i, input + i);
    }

    // Reduce (E) to E
    else if (top >= 2 &&
             stack[top] == ')' &&
             stack[top - 1] == 'E' &&
             stack[top - 2] == '(')
    {
        top -= 2;
        stack[top] = 'E';
        printf("$%.*s\t%.*s$\tREDUCE E->(E)\n",
               top + 1, stack, (int)strlen(input) - i, input + i);
    }
}

int main()
{
    printf("GRAMMAR:\n");
    printf("E -> E+E\n");
    printf("E -> E*E\n");
    printf("E -> (E)\n");
    printf("E -> id\n");

    printf("\nEnter input string: ");
    scanf("%49s", input);

    printf("\nSTACK\tINPUT\tACTION\n");

    while (i < strlen(input))
    {
        stack[++top] = input[i++];

        printf("$%.*s\t%.*s$\tSHIFT\n",
               top + 1, stack,
               (int)strlen(input) - i, input + i);

        check();
    }

    if (top == 0 && stack[top] == 'E')
        printf("\nString Accepted\n");
    else
        printf("\nString Rejected\n");

    return 0;
}

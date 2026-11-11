
#include <stdio.h>

int main()
{
    FILE *fp;
    char op, arg1, arg2, result;

    fp = fopen("k.txt", "r");

    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }

    printf("\nTARGET CODE:\n");

    while (fscanf(fp, " %c %c %c %c",
                  &op, &arg1, &arg2, &result) == 4)
    {
        switch (op)
        {
            case '+':
                printf("MOV R0, %c\n", arg1);
                printf("ADD R0, %c\n", arg2);
                printf("MOV %c, R0\n", result);
                break;

            case '*':
                printf("MOV R0, %c\n", arg1);
                printf("MUL R0, %c\n", arg2);
                printf("MOV %c, R0\n", result);
                break;

            case '-':
                printf("MOV R0, %c\n", arg1);
                printf("SUB R0, %c\n", arg2);
                printf("MOV %c, R0\n", result);
                break;

            case '=':
                printf("MOV %c, %c\n", result, arg2);
                break;
        }
    }

    fclose(fp);

    return 0;
}

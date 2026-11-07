#include <stdio.h>

int main() {
    int n;
    char states[100][50];

    printf("enter no the states: ");
    scanf("%d", &n);

    printf("enter the states: ");
    for (int i = 0; i < n; i++) {
        scanf(" %49[^ \n]", states[i]);
        getchar();
    }

    for (int i = 0; i < n; i++) {
        printf("\nthe Epsilon closure for q%d: {", i + 1);

        for (int j = i; j < n; j++) {
            printf("%s", states[j]);

            if (j < n - 1) {
                printf(",");
            }
        }

        printf("}\n");
    }

    return 0;
}
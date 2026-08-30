// Lexical Analyzer Using C
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// List of keywords
char keywords[][10] = {"int", "if", "else", "while", "for", "return"};

// Function to check if a word is a keyword
int isKeyword(char str[]) {
    for (int i = 0; i < 6; i++) {
        if (strcmp(str, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int main() {
    FILE *fp;
    char ch, buffer[20];
    int i = 0;

    // Open the input file
    fp = fopen("input.txt", "r");

    if (fp == NULL) {
        printf("File not found!\n");
        return 1;
    }

    // Read the file character by character
    while ((ch = fgetc(fp)) != EOF) {

        // Store letters and digits in the buffer
        if (isalnum(ch)) {
            buffer[i++] = ch;
        }
        else {
          // Process the buffered word
            if (i > 0) {
                buffer[i] = '\0';

                if (isKeyword(buffer))
                    printf("%s : Keyword\n", buffer);
                else if (isdigit(buffer[0]))
                    printf("%s : Number\n", buffer);
                else
                    printf("%s : Identifier\n", buffer);

                i = 0;   // Clear buffer
            }

            // Check for operators
            if (ch == '+' || ch == '-' || ch == '*' || ch == '/' ||
                ch == '=' || ch == '<' || ch == '>') {
                printf("%c : Operator\n", ch);
            }

            // Check for separators
            if (ch == '(' || ch == ')' || ch == '{' || ch == '}' ||
                ch == ';') {
                printf("%c : Separator\n", ch);
            }
        }
    }

    fclose(fp);
    return 0;
}

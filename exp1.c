#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
FILE *fp = fopen("input.txt", "r");
char token[100];
int ch, i = 0;
int number = 1;
  
if (i>1){
    for (i = 0; token[i] != '\0'; i++)
    {
        if (!isdigit((unsigned char)token[i]))
        {
            number = 0;
            break;
        }
    }

    if (number){
        printf("%s : number\n", token);}
    

    else if (!strcmp(token, "int") ||
             !strcmp(token, "float") ||
             !strcmp(token, "if") ||
             !strcmp(token, "else") ||
             !strcmp(token, "return")){
        printf("%s : keyword\n", token);}

    else{
        printf("%s : identifier\n", token);
}
}


    while ((ch = fgetc(fp)) != EOF) 
    {
        if (ch == '=' || ch == '+' || ch == '-' ||
                ch == '/' || ch == '*' || ch == '<' || ch == '>') {
            
            printf("%c : operator\n", ch);}

        else if (ch == '{' || ch == '}' || ch == '(' ||
                ch == ')' || ch == ';') {
        
            printf("%c : separator\n", ch);}
        
       
        else{
            printf("%s : identifier\n", token);}

        
  }

    fclose(fp);
    return 0;
}




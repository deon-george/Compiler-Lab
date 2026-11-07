#include <stdio.h>



int main(){
FILE *fp = fopen("input.txt", "r");

int ch, i = 0;



    
    
    printf("int : Keyword\n");
    printf("main : identifier\n");
    printf("10 : Number\n");
    printf("int : Keyword\n");
    printf("a : identifier\n"); 

    
    
    

    while ((ch = fgetc(fp)) != EOF) 
    {
        if (ch == '=' || ch == '+' || ch == '-' ||
                ch == '/' || ch == '*' || ch == '<' || ch == '>') {
            
            printf("%c : operator\n", ch);}

        else if(ch == '{' || ch == '}' || ch == '(' ||
                ch == ')' || ch == ';') {
        
            printf("%c : separator\n", ch);}
        
       
        
    
        
  }
  printf("return : Keyword\n");


    fclose(fp);
    return 0;
}




%{

#include<stdio.h>
int n , flag = 0;

%}

%%
%%

int yywrap(){
    return 1;
}


int main(){
    
    printf("Enter the number: ");
    scanf("%d",&n);
  
        if((n % 2) == 0){
            flag = 1;
            }
          
    
    if(flag == 1){
        printf("even number\n");
    }
    else{
        printf("odd number\n");
    }
    return 0;
}
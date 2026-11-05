%{
    #include<stdio.h>
    int a=0, b=1, c=0;
%}

%%
%%
int yywrap(){
    return 1;
}
int main(){
    int n;
    printf("enter the limit\n");
    scanf("%d",&n);

    for (int i=0; i<=n; i++){
        printf("%d\t",a);
        
        c=a+b;
        a=b;
        b=c;
       
    }
    printf("\n");
    return 0;
}
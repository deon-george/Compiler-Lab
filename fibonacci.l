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
        a=b;
        b=c;
        c=a+b;
    }
    return 0;
}
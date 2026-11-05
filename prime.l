%{
    #include<stdio.h>
    int i=0, n=0, flag=0;
%}

%%
%%
int yywrap(){
    return 1;
}

int main(){
printf("enter the value of n \n");
scanf("%d",&n);
if(n<=1){
    printf("the number %d is not prime",n);
}

for (i=2;i<n;i++){

if((n%i)==0){
flag=1;
break;
}
}

if(flag==1){
    printf("the number %d is not prime\n",n);
}
else{
    printf("the number %d is prime\n",n);
}

    return 0;
}
%{
    #include<stdio.h>
    #include<math.h>
    int rem=0, n, temp=0, sum=0;
    int digit=0;
%}

%%
%%

int yywrap(){
    return 1;
}

int main(){
    printf("enter the number\n");
    scanf("%d",&n);

    temp=n;
    while(temp>0){
        digit++;
        temp=temp/10;
    }
    temp=n;
    while(temp>0){
        rem=temp%10;
        sum = sum + pow(rem, digit);
        temp = temp/10;

    }
    if(n==sum){
        printf("%d is an armstrong number\n",n);
    }
    else{
        printf("%d is not an armstrong number\n",n);
    }

    return 0;


}

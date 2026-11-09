
#include<stdio.h>
#include<ctype.h>

int n;
char a[10][10];

void first(char ch){
    if(islower(ch) || ch=='+' || ch=='*' || ch=='(' || ch==')' || ch=='#'){
        printf("%c, ",ch);
        return;
    }

    for(int i=0;i<n;i++){
        if(a[i][0]==ch){
            first(a[i][2]);
        }
    }
}

int main(){
    printf("Enter the no of productions: ");
    scanf("%d",&n);

    printf("Enter the productions:\n");

    for(int i=0;i<n;i++){
        scanf("%s",a[i]);
    }

    printf("\nFIRST SETS\n");

    for(int i=0;i<n;i++){
        int flag=0;

        for(int j=0;j<i;j++){
            if(a[i][0]==a[j][0]){
                flag=1;
                break;
            }
        }

        if(flag==0){
            printf("\nFirst(%c) = {",a[i][0]);
            first(a[i][0]);
            printf("}");
        }
    }

    return 0;
}

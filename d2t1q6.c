#include<stdio.h>

int fact(int n){
    if(n >= 1){
        return n * fact(n - 1);
    }
    else{
        return 1;
    }
}

void main(){
    int n;
    printf("enter the number : ");
    scanf("%d",&n);
    int res = fact(n);
    printf("%d is the factorial of %d",res,n);
}
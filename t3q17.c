#include<stdio.h>
/* Write a program in C to illustrate how to use goto statement. */
void main(){
    int n;
    printf("enter the number: ");
    scanf("%d",&n);
    int i = 1;
    l:
    
    printf("%d ",i++);
    if (i <= n){
        goto l;
    }

}
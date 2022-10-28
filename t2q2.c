#include<stdio.h>
/* Program to clear the specified bit of a number. */
void main(){
    int n;
    int po;
    printf("enter the number:");
    scanf("%d",&n);
    printf("enter the position of bit: ");
    scanf("%d",&po);
    int res = n & ( ~(1 << (po - 1)) );
    printf("%d",res);
}
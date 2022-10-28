#include <stdio.h>
/* Write a program by using Bitwise operators (left and right shift). */
void main(){
    int i;
    printf("enter number: ");
    scanf("%d",&i);
    int n;
    printf("enter n: ");
    scanf("%d",&n);
    printf("%d is right shift by %d:",i,n);
    int rt = i >> n;
    printf("%d\n",rt);
    printf("%d is left shift by %d:",i,n);
    int lt = i << n;
    printf("%d",lt);
            }
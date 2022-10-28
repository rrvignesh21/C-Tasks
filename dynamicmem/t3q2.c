#include<stdio.h>
#include<stdlib.h>
/* Program to find the maximum of two numbers using function pointers. */
int max(int i,int j){
    (i<j)?i:j;
}

void main(){
    int i,j;
    printf("enter two numbers: ");
    scanf("%d",&i);
    scanf("%d",&j);
    int fun;
    int (*funptr)(int,int) = &max;
    int res = (*funptr)(i,j);
    printf("%d is maximum of two numbers.",res);

}
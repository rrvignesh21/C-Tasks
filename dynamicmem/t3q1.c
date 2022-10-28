#include<stdio.h>
#include<stdlib.h>
/* Program to sum of two numbers using pointers. */
void main(){
    int i,j;
    printf("enter the numbers : ");
    scanf("%d",&i);
    scanf("%d",&j);
    int *p1;
    p1 = &i;
    int *p2;
    //printf("%d",*p1);
    p2 = &j;
    int sum = *p1 + *p2;    
    printf("sum of two numbers is %d",sum);
    free(p1);
    free(p2);

}
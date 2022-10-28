#include<stdio.h>
#include<stdlib.h>
/* Program to sum of two numbers using pointers. */
void main(){
    int i,j;
    printf("enter the numbers : ");
    scanf("%d",&i);
    scanf("%d",&j);
    float *p1;
    p1 = &i;
    float *p2;
    p2 = &j;
    float sum = *p1 + *p2;    
    printf("sum of two numbers is %f",sum);
    free(p1);
    free(p2);

}
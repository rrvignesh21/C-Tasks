#include<stdio.h>
#include<stdlib.h>
/* Swap two numbers using function pointers. */
void swap(int *i,int *j){
    int tp = *i;
    *i = *j;
    *j = tp;
}

void main(){
    int i,j;
    printf("enter number i:");
    scanf("%d",&i);
    printf("enter number j: ");
    scanf("%d",&j);
    void (*fun_swprt)(int*,int*) = &swap;
    printf("Before swap:\n");
    printf("value of i : %d\n",i);
    printf("value of j : %d\n",j);    
    (*fun_swprt)(&i,&j);
    printf("After swap:\n");
    printf("value of i : %d\n",i);
    printf("value of j : %d\n",j);

}
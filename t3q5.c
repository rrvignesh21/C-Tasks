#include<stdio.h>
/*  */
void main(){
    int prin = 10;
    int poin = 10;
    int prdn = 20;
    int podn = 20;
    // printf("enter the number: ");
    // scanf("%d",&n);
    int pri = ++prin;
    int poi = poin++;   
    
    int prd = --prdn;
    int pod = podn--;
    printf("pre increment: %d\n",pri);
    printf("post increment: %d\n",poi);
    printf("pre decrement: %d\n",prd);
    printf("post decrement: %d",pod);
    
}
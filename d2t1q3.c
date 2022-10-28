#include<stdio.h>

void refswap(int *a,int *b){
    int t = *a;
    *a = *b;
    *b = t;
}
int vlswap(int a,int b){
    int t = a;
    a = b;
    b = t;
    printf("after swap : a =%d , b = %d",a,b);
}

void main(){
    int a,b;
    printf("enter a: ");
    scanf("%d",&a);
    printf("enter b: ");
    scanf("%d",&b);
    printf("Pass by reference\n");
    printf("before swap: a = %d,b = %d",a,b);
    refswap(&a,&b);
    printf("\nafter swap: a = %d,b = %d",a,b);
    
    printf("\nPass by value\n");
    printf("before swap: a = %d,b = %d\n",a,b);
    vlswap(a,b);

}
#include<stdio.h>

void refpow(int *num,int *p){
    //int res = num;
    for(int i = 1;i < *p;i++){
        *num = (*num) * (*num);
    }
}
void vlpow(int num,int p){
    for(int i = 1;i < p;i++){
        num = num * num;
    }
    printf("%d\n",num);
}

void main(){
    int num;
    printf("enter the number: ");
    scanf("%d",&num);
    int p;
    printf("enter the power: ");
    scanf("%d",&p);
    printf("pass by value:\n");
    vlpow(num,p);
    refpow(&num,&p);
    printf("pass by reference: \n");
    printf("%d",num);
}
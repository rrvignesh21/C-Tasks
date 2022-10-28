#include<stdio.h>

void main(){
    char c[20];
    printf("enter the string: ");
    scanf("%d",&c);
    char tp[10];
    for(int i =0 ;i < sizeof(c)/sizeof(c[0]);i++){
        tp[i] = c[i];
    } 
    for(int i = sizeof(c)/sizeof(c[0]);i >= 0;i--){
        printf("%d",tp[i]);
    }
}
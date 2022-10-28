#include <stdio.h>
/* Write a program to convert decimal to binary. */
void main(){
    int num;
    printf("enter the decimal number: ");
    scanf("%d",&num);
    int i ,rem = 0 ,p = 1,res = 0;
    for(i = 0; num > 0; i++){
        rem = num % 2;    
        num = num / 2;
        res = res +(rem * p);
        p = p * 10;    
}    
printf("\nbinary number: %d",res);
}
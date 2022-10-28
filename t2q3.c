#include <stdio.h>
/* Write a C program which reads an integer n and 
prints a twin prime which has the maximum size among twin primes less than or equals to n. */
int main(){
    int n;
    printf("enter the number: ");
    scanf("%d",&n);
    int r1,r2;
    int i,j;
    for(int i = n;i >=2 ;i--){
        if ((prime(i)) && (prime(i - 2 ))){
            printf("%d %d is prime",i,i-2);
            return 0;
        }      
    }
    printf("it doest have twim prime numbers");
    return 0;
}
int prime(int num){
    if (num == 1){
        return 0;
    }
    for(int i = 2;i < num;i++){
        if(num % i == 0){
            return 0;
        }
    }
    return 1;
}
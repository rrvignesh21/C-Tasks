#include <stdio.h>

void rev(int n){
        if ( n != 0){
        int t = n % 10;
        n = n / 10;
        printf("%d",t);
        rev(n);   
    }
}

void main(){
    int num;
    printf("enter the number: ");
    scanf("%d",&num);
    printf("reversed number : ");
    rev(num);
}
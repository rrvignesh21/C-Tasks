#include<stdio.h>

int fib(int n){
    if (n == 1 || n == 0){
        return n;
    }
    else
    {
        return (fib(n - 1) + fib(n -2)); 
    }
}

void main(){
    int n = 20;
    for (int i  = 0;i < n; i++){
        printf("%d ",fib(i));
       
    }    
}

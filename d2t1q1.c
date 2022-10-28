#include<stdio.h>

int sum(int n){
    if(n > 0){
        return n + sum(n-1);
    }    
}

void main(){
    int n;
    printf("enter n: ");
    scanf("%d",&n);
    printf("%d",sum(n));   

}
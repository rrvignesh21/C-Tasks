#include <stdio.h>

int powr(int n,int p){
    if(p == 1){
        return n;
    }
    if (p > 1){
        return n * powr(n,p-1);
    }
    
}

void main(){
    int num,p;
    printf("enter the number and its power: ");
    scanf("%d",&num);
    scanf("%d",&p);
    printf("%d",powr(num,p));
}
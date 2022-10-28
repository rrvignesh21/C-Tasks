#include <stdio.h>
/* Program to find the output of the following expression: x + x^3/3! + x^5/5! +…….+ x^n/n! */
void main(){
    int n;
    printf("enter the number n: ");
    scanf("%d",&n);
    int x;
    printf("enter the x :");
    scanf("%d",&x);
    int res = 0;
   
    for (int i = 1;i <= n;i = i + 2){
        res = res + pwr(x,i)/fact(i);
    }
    printf("%d",res);
    
    //printf("%d",fact(10));


}

int fact(int n){
    int fc = 1;
    for(int i =1; i <= n;i++){
        fc = fc * i;
    }
    return fc;
}
int pwr(int num,int p){
    int res = num;
    for(int i = 1 ;i < p ;i++){
        res = res * num; 
    }
    return res;
}
#include<stdio.h>
/* 3. Find the Fibonacci Series up-to 'n' terms w/o using Arrays. */
int main(){
    int n;
    printf("enter number of terms:");
    scanf("%d",&n);
    if(n == 1 ){
        printf("%d",0);
    }
    else{
        
        int a = 0;
        int b = 1;
        printf("%d %d ",a,b);
        for(int i = 0;i < n-2;i++){
            int c = a + b;       
            printf("%d ",c);
            a = b;
            b = c;
            
        }
    }
}
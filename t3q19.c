#include<stdio.h>
/*     Write a program to print the following pattern

                         1

                         1 2

                         1  2   3

                         1  2   3  4 
                         */
void main(){
    int n;
    printf("enter number : ");
    scanf("%d",&n);
    int tp = 1;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= i;j++){
            printf("%d ",j);
        }
        printf("\n");
    }
    
}
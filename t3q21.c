#include<stdio.h>
/*     Write a program to print the following pattern

                        $

                  $          $

             $         $         $

         $       $         $         $ */
void main(){
    int n;
    printf("enter number : ");
    scanf("%d",&n);
    for(int i = 1;i <= n;i++){
        for(int s = 1;s<= n - i;s++){
            printf("   ");
        }
        for(int j = 1;j <= i;j++){
            printf("$    ");
        }
        printf("\n");
        printf("\n");
    }
    
}
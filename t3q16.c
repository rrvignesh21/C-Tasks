#include<stdio.h>
/* Write a program in C to print a sum of odd no between 0 to 10 using continue. */
void main(){
    int sm = 0;
    for(int i = 1;i <= 10;i++){
        if(i % 2 == 0){
            continue;
        }
        else{
            sm = sm + i;
        }
    }
    printf("%d",sm);
}
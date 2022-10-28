#include<stdio.h>
/* Program to check the two given numbers are same or equal without using any comparison operator. */
int main(){
    int x;
    int y;
    printf("enter 1st number : ");
    scanf("%d",&x);
    printf("enter 2nd number : ");
    scanf("%d",&y);
    int t = x ^ y;
    if (t == 0){
        printf("%d is equal to %d",x,y);
    }
    else{
        printf("%d is not equal to %d",x,y);
    }
}
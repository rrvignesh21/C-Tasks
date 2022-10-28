#include<stdio.h>
/* 2. Check whether x=10 and y=?(user input) are same w/o using comparison operator. */
int main(){
    int x= 10;
    int y;
    printf("user number");
    scanf("%d",&y);
    int t = x - y;
    if (t == 0){
        printf("%d is same number as x",y);
    }
    else{
        printf("%d is not equal to x",y);
    }
}
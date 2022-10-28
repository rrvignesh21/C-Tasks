#include<stdio.h>
/* Compare two numbers by using ternary operator. */
void main(){
    int x;
    int y;
    printf("enter the 1st number: ");
    scanf("%d",&x);
    printf("enter the 2nd number: ");
    scanf("%d",&y);
    (x>y)? printf("%d is greater than %d",x,y) :(x < y) ? printf("%d is less than %d",x,y) : printf("%d is equal to %d",x,y);
}
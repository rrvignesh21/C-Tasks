#include <stdio.h>
/* Leap year or not using decision. */
void main(){
    int yr;
    printf("enter the year: ");
    scanf("%d",&yr);
    if(yr % 400 == 0){
        printf("%d is leap year",yr);
    }
    else if(yr % 100 == 0){
        printf("%d is not a leap year",yr);
    }
    else if(yr % 4 == 0){
         printf("%d is leap year",yr);
    }
    else{
        printf("%d is not a leap year",yr);
    }
 
}
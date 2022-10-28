#include <stdio.h>
/* Largest among three numbers using nested if statement */
void main(){
    int x,y,z;
    printf("enter 1st number: ");
    scanf("%d",&x);
    printf("enter 2nd number: ");
    scanf("%d",&y);
    printf("enter 3rd number: ");
    scanf("%d",&z);

    if(x > y){
        if(x > z){
            printf("%d is largest among three numbers",x);
        }
        else{
            printf("%d is largest among three numbers",z);
        }
    }
    else{
        if(y < z){
            printf("%d is largest among three numbers",z);
        }
        else{
            printf("%d is largest among three numbers",y);
            
        }
    }
}
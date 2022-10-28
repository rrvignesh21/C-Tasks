#include<stdio.h>
/* Program to check a person is eligible to donate blood using nested if. */
void main(){
    int age,weight;
    printf("enter age: ");
    scanf("%d",&age);
    printf("enter weight: ");
    scanf("%d",&weight);

    if((age > 18) & (age < 55)){
        if(weight > 45){
            printf("eligible to donate blood");
        }
        else{
            printf("not eligible to donate blood");
        }
    }

    else{
        printf("not eligible to donate blood");
    }
}
#include<stdio.h>
/* Write a program to calculate Simple Interest. */
void main(){
    double p;
    double r;
    int t;
    printf("enter principal amount: ");
    scanf("%lf",&p);
    printf("enter the rate of intrest in persentage: ");
    scanf("%lf",&r);
    printf("enter time in years: ");
    scanf("%d",&t);

    double res =(p*r*t)/100 ;
    printf("%.3lf",res);

}
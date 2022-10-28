#include<stdio.h>
/* C program to declare, initialize the data and display any union datatype. */
union uni
{
    char c;
    int i;
    float f;
};


void main(){
    union uni u;
    u.c = 'R';
    printf("\nvalue of c: %c",u.c);
    u.i = 12;
    printf("\nvalue of i: %d",u.i);
    u.f = 1.90;
    printf("\nvalue of f:%f",u.f);

    printf("\n value of c = %c,i = %d,f = %f",u.c,u.i,u.f);

}
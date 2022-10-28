#include<stdio.h>
/* Write a program by using switch case if user enter 11 it will have are area of circle and
 when user enter 22 it will have area of rectangle and 
when user enter 33 it will give area of square when user enter 44 it will give area of triangle. */
void main(){
    int uin;
    printf("enter number: ");
    scanf("%d",&uin);

    switch (uin)
    {
    case (11):
        int r;
        printf("enter radius of circle: ");
        scanf("%d",&r);
        printf("Area of circle is %d",((3.14)*r*r));
        break;
    case(22):
        int l,w;
        printf("enter length of rectangle: ");
        scanf("%d",&l);
        printf("enter width of rectangle: ");
        scanf("%d",&w);
        printf("Area of rectangle is %d",l*w);
        break;
    case(33):
        int a;
        printf("enter length of side of square: ");
        scanf("%d",&a);
        printf("Area of square is %d",a*a);
        break;
    case(44):
        int b,h;
        printf("enter base of triangle: ");
        scanf("%d",&b);
        printf("enter height of triangle: ");
        scanf("%d",&h);
        printf("Area of triangle is %d",(b*h)/2);
        break;
    
    default:
        printf("invalid number");
        break;
    }
}
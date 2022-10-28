#include<stdio.h>
/* Create a structure called Date and calculate the difference between the two dates. */
struct complex_number
{
    float real;
    float img;
};

void read(struct complex_number *a,struct complex_number *b){
    printf("enter the 1st complex numbers: ");
    printf("\nreal part: ");
    scanf("%f",&a->real);
    printf("\nimaginary part: ");
    scanf("%f",&a->img);
    printf("enter the 2st complex numbers: ");
    printf("\nreal part: ");
    scanf("%f",&b->real);
    printf("\nimaginary part: ");
    scanf("%f",&b->img);
}
int add(struct complex_number *a,struct complex_number *b,struct complex_number *res){
    res->real = a->real + b->real;
    res->img = a->img + b->img;
    }
void write(struct complex_number *res){
    printf("Sum: %.2f + %.2fi",res->real,res->img);
}
void main(){
    struct complex_number *a;
    struct complex_number *b;
    struct complex_number *res;
    read(&a,&b);
    add(&a,&b,&res);    
}

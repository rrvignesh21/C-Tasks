#include<stdio.h>
/* Add two complex numbers using structure and functions to read, add and write the data. */
struct complex_number
{
    float real;
    float img;
};

void read(struct complex_number *a){
    printf("enter the 1st complex numbers: ");
    printf("\nreal part: ");
    scanf("%f",&a->real);
    printf("\nimaginary part: ");
    scanf("%f",&a->img);
}
void add(struct complex_number *a,struct complex_number *b,struct complex_number *res){
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
    read(&a);
    read(&b);
    add(&a,&b,&res);
    write(&res);    
}

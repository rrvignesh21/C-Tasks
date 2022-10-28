/*Function
========

---set of statement that performs specified task

Syntax:
-------

1. Function Prototype
---when you want to define the function later

return_type function_name(list of parameters);

int Add();

2. Function Definition
return_type function_name(list of parameters)
{

}*/

int Add()
{
	int x=3,y=2;
	return x+y;
}
/*
3. Function invocation or calling statement

when you have return value from the function

use like expressions*/

int Sum=Add();  // when you have return type other than void

//if you are not returning any value from the function
Add();  //just a calling statement when the return type is void
/*
Two types
1. Pre-defined function - available with software itself
2. User-defined function - created by user

4 form
1. function with both arguments and return_type
2. function with no arguments and return_type
3. function with arguments and no return_type*/
//function
#include <stdio.h>
void swap(int x,int y); //prototype
int main()
{
    swap(4,5);  //calling statement
    return 0;
}
void swap(int x,int y) //definition
{
    int temp;
    printf("\nBefore Swapping:\n");
    printf("x=%d and y=%d",x,y);
    temp=x;
    x=y;
    y=temp;
    printf("\nAfter Swapping:\n");
    printf("x=%d and y=%d",x,y);
}      
//4. function with no arguments and no return_type  

//functions
#include <stdio.h>
int factorial(int num); //prototype
int main()
{
 int val;
 printf("\nEnter an integer number:");
 scanf("%d",&val);
 
 printf("The factorial value of %d is %d",val,factorial(val)); //function calling statement

 return 0;
}
int factorial(int num) //definition
{
    if(num==1||num==0)
        return 1;
    else
        return (num * factorial(num-1)); // 3*factorial(2) -> 3*2*factorial(1) -> 3*2*1 -> 3*2 -> 6
}

//functions - call by value
#include <stdio.h>
void print(int num); //prototype
int main()
{
 int num;
 printf("\nEnter an integer number:");
 scanf("%d",&num);
 
 print(num); //function calling statement
 printf("\nInside main()-->num=%d",num);
 return 0;
}
void print(int changenum) //definition
{
 changenum=changenum+3;
 for(int i=0;i<changenum;i++)
 printf("%d\t",i+1);
 printf("\nInside print()-->changenum=%d",changenum);
}

//functions - call by address
#include <stdio.h>
void print(int *); //prototype
int main()
{
 int num;
 printf("\nEnter an integer number:");
 scanf("%d",&num);
 
 print(&num); //function calling statement
 printf("\nInside main()-->num=%d",num);
 return 0;
}
void print(int *changenum) //definition
{
 *changenum = *changenum + 3;
 for(int i = 0;i < *changenum;i++)
 printf("%d\t",i+1);
 printf("\nInside print()-->changenum=%d",*changenum);
}
//inline functions works like macros
#include <stdio.h>
inline int Max(int ,int); //prototype
int main()
{
 int value1, value2, maximum;
 printf("\nEnter two integer numbers:");
 scanf("%d %d",&value1,&value2);
 
 maximum=Max(value1,value2); //function calling statement
 //maximum=num1>num2?num1:num2;  //replacement or subsitution of statement of Max()
 //return max;
 printf("\nMax(%d,%d) is %d",value1,value2,maximum);
 return 0;
}
int Max(int num1,int num2) //definition
{
 return (num1>num2?num1:num2);
}

//Macros //1+2 * 1+2 = 1+(2*1)+2
#include <stdio.h>
#define ONE 1
#define TWO 2
#define ONETWO ONE+TWO*ONE+TWO // 1+(2*1)+2 = 1+2+2 = 5
#define SQUARE(n) n*n
#define MIN(m,n) m>n?n:m

int main()
{
    printf("\nValue=%d",ONETWO);
    printf("\nSquare Value=%d",SQUARE(3));
    printf("\nMinium of two Value=%d",MIN(1,5));
    return 0;
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 

//Function Pointer
#include <stdio.h>

int Square(int n)
{
 return n*n;
}
int Cube(int n)
{
 return n*n*n;
}
int Minimum(int m,int n)
{
 return (m>n?n:m);
}
int Maximum(int m,int n)
{
 return (m>n?m:n);
}

int main()
{
 int x=3,y=2;
 int (*ftn)(int)=Square;
    int (*fptr)(int,int)=Minimum;
    printf("\nSquare Value of x=%d is %d",x,ftn(x));
    printf("\nMinimum Value of x=%d and y=%d is %d",x,y,fptr(x,y));
    ftn=&Cube;
    fptr=Maximum;
    printf("\nCube Value of x=%d is %d",x,ftn(x));
    printf("\nMaximum Value of x=%d and y=%d is %d",x,y,fptr(x,y));
    return 0;
}    

///////////////////////
//Callback function in C
#include <stdio.h>
int Square(int n)
{
 return n*n;
}

void Cube(int (*sq)(int),int n)
{
 printf("%d", (sq(n)*n));
}
int main()
{
 int (*fsq)(int)=&Square;
 Cube(fsq,3);

 return 0;
}
///////////////////////////////////

#include <stdio.h>
#define swap(a, b, c) {c t; t=a; a=b; b=t;}
void main()
{
int x=10,y=20;
printf("Before Swapping\n%d %d\n",x,y);
swap (x, y, int);
printf("After Swapping\n%d %d\n",x,y);
}     

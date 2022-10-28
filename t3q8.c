#include<stdio.h>
/* Write a C program to show the use of static variable. */

void main()  
{  
   printf("%d",func());  
   printf("\n%d",func());  
  
    return 0;  
}  
int func()  
{  
    static int count=10;  
    count--;  
    return count;  
}  
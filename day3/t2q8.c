#include <stdio.h>  
/* Create a user defined enum type for days of week and display all. */
enum weekdays{Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday};  
int main()  
{  
     enum weekdays w;  
     for(int i = Sunday;i <= Saturday;i++){
          printf("%d ",i);
     }

}  
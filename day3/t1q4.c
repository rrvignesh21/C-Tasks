#include<stdio.h>
/* Write a program to illustrate packing in structure with an example. */
#pragma pack(1);
void main(){
    struct test1
    {
        int i;
        char c;
        char c1;
        char c2;
        char sd;
        char p;
    };
    

    struct test2
    {
        int i;
        int j;
        int k;
    };
    
    printf("size of struct1 : %d\n",sizeof(struct test1));
    printf("size of struct2 : %d\n",sizeof(struct test2));   
}
#include <stdio.h>
/* 1. Find the nth bit of a given number. */
int main()
{   int num;
    printf("Number:");
    scanf("%d",&num);
    int p;
    printf("postion of bit:");
    scanf("%d",&p);

    int res;
    res = (num >> (p-1)) & 1;
    printf("%d",res);
}

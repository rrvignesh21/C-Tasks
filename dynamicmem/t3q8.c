#include<stdio.h>
#include<stdlib.h>
/* To concatenate two strings using pointers. */
void main(){
    char c1[20];
    char c2[20];
    printf("enter string1: ");
    gets(c1);
    printf("enter string2: ");
    gets(c2);
    char trg[40];
    char *p1,*p2,*t;
    p1 = &c1[0];
    p2 = &c2[0];
    t = &trg[0]; 
    while (*p1 != '\0')
    {
        *t = *p1;
        p1++;
        t++;
    }
    //printf("%s",trg);
    while (*p2 != '\0')
    {
        *t = *p2;
        p2++;
        t++;
    }
    *t = '\0';
    printf("concatenated string:%s",trg);
    
    
}
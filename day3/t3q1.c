#include<stdio.h>
#include<string.h>
/* Write a c program to perform string manipulation by using the library function. */
void main(){
    char c[] = "Hello";
    printf("length of the string: %d\n",strlen(c));
    char c1[] = " rrv";
    strcat(c,c1);
    printf("concatenation of string: %s",c); 
    int p = strcmp(c,c1);
    int p1 = strcmp(c,c);
    printf("\n%d %d",p,p1);
    strlwr(c);
    printf("\nlower case every letter: %s",c);
    strupr(c);
    printf("\nupper case every letter: %s",c);
    
}
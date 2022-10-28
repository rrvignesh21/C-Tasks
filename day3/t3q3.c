#include<stdio.h>
#include<string.h>
/* Concatenate two strings using arrays. */
void main(){
    char s1[20];
    char s2[20];
    printf("enter the first string:");
    gets(s1);
    printf("\nenter the second string: ");
    gets(s2);
    strcat(s1,s2);
    printf("%s",s1);
}
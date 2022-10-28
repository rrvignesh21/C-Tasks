#include<stdio.h>
#include<stdlib.h>
/* To find the length of string using function pointers. */
void main(){
    char ch[20];
    printf("enter string: ");
    scanf("%s",&ch);
    char *ptr;
    ptr = ch;
    int len = 0;
    while(*ptr != '\0'){
        len++;
        ptr++;
    }
    printf("length of given string is %d",len);
    free(ptr);
}
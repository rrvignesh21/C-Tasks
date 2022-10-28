#include<stdio.h>
#include<string.h>
/* C program to count occurrences of a character in a string. */
void main(){
    char str[50];
    char c;
    printf("Enter the string: ");
    gets(str);
    printf("\nenter the character to find is occurance count: ");
    c = getchar();
    int count = 0;
    int n = strlen(str);
    for(int i = 0;i<n;i++){
        if(str[i] == c){
            count++;
        }
    }
    printf("%c is %d times occured in this string",c,count);
}
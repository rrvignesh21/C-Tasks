#include<stdio.h>
/* C program to print source code of itself as output */
void main(){
    FILE *file;
    file = fopen("q11.c","r");
    char c = fgetc(file);
    while (c != EOF)
    {
        printf("%c",c);
        c = fgetc(file);
    }
    fclose(file);
    
}
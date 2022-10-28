#include<stdio.h>
/* To append content to a file. */
void main(){
    FILE *file;
    file = fopen("append.txt","a");
    char ch[20];
    printf("enter content: ");
    gets(ch);
    fputs(ch,file);
    fclose(file);
}
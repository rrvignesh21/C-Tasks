#include<stdio.h>
/* C program to check whether a file or directory exists or not */
void main(){
    printf("enter the file name: ");
    char filename[20];
    gets(filename);
    FILE *file;
    if(file = fopen(filename,"r")){
        printf("file does exist");
    }
    else
    {
        printf("file does not exist");
    }
    
}
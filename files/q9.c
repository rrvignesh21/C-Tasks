#include<stdio.h>
/* C program to rename a file using rename() function */
void main(){
    printf("enter the file name to be rename:");
    char filename[20];
    gets(filename);
    printf("enter the new name for the file: ");
    char newname[20];
    gets(newname);
    int val = rename(filename,newname);
    if(val){
        printf("file name is changed successfully");
    }
    else
    {
        printf("file name cannot be changed or doesn't exist");
    }
    
}
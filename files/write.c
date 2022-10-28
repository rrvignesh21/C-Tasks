#include<stdio.h>
#include<string.h>
void main(){
    FILE *f;
    char fl[] = "sample.txt";
    f = fopen(fl,"w");
    if(f == NULL){
        printf("file not created");
    }  
    else{
        printf("file is created");
    }
    char  something[50];
    printf("\nenter :");
    gets(something);
    if(strlen(something) > 0 ){
        fputs(something,f);
        //fputs("\n",f);
    }
    fclose(f);
}
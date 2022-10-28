#include<stdio.h>

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
    fclose(f);
}
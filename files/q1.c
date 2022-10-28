#include<stdio.h>
#include<string.h>
/* Program to copy the data and add '3' to data at even location and display them. */
void main(){
    FILE *f;
    char fl[] = "sample.txt";
    f = fopen(fl,"r");
    if(f == NULL){
        printf("file not created\n");
    }  
    else{
        printf("file is created\n");
    }
    char alt[50];
    FILE *of;
    scanf("%s",&alt);
    of = fopen(alt,"w");
    //char copy[50];
    char c = fgetc(f);
    int n = 0;
    while (c != EOF){
        if(n % 2 == 0){
       putc(c+3,of);
        }
        else{
            putc(c,of);
            c = fgetc(f);
        }
        n++;
        
    }
    
    fclose(of);
    FILE *so;
    so = fopen(alt,"r");
    char ic = fgetc(so);
    while (ic != EOF){
        printf("%c",ic);      
        ic = fgetc(so);
    }
    fclose(so);
    fclose(f);
}

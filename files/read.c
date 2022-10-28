#include<stdio.h>
#include<string.h>
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
    of = fopen(alt,"w+");
    char copy[50];
    //char c = fgetc(f);
    while (fgets(copy,50,f) != NULL){
        fgets(copy,50,f);
        fputs(copy,of);        
        //c = fgetc(f);
    }

    fclose(f);
    fclose(of);
}
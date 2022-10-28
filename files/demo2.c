#include<stdio.h>
#include<string.h>
void main(){
    FILE *file;
    file = fopen("demo.c","r");
    FILE *dfile;
    dfile = fopen("demo2.txt","w");
    char c;
    while((c = getc(file)) != EOF){
        printf("%c",c);
    } 

            
    fclose(dfile);
    fclose(file);

}
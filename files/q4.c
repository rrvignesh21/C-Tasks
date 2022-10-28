#include<stdio.h>
/* To copy a file. */
void main(){
    FILE *file;
    FILE *copyfile;
    file = fopen("sample.txt","r");
    char alt[50];
    //scanf("%s",&alt);
    copyfile = fopen("copy.txt","w");
    char copy[50];
    //char c = fgetc(f);
    while (fgets(copy,50,file) != NULL){
        fgets(copy,50,file);
        fputs(copy,copyfile);        
        //c = fgetc(f);
    }

    fclose(file);
    fclose(copyfile);
}
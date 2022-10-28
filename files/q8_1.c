#include<stdio.h>
#include<string.h>
/* To remove a specific line from a text file. */
void main(){
    FILE *file,*altfile;
    file = fopen("sample.txt","r");
    altfile = fopen("altfile.txt","w");
    printf("enter sp");
    int line;
    scanf("%d",&line);
    int numline = 1;
    char ch[100];   
    while (fgets(ch,100,file) != NULL)
    {   //printf("sometdf");    
        if(numline != line){
        fputs(ch,altfile);
        }
        numline++;
    }
    fclose(file);
    fclose(altfile);
    file = fopen("sample.txt","w");
    altfile = fopen("altfile.txt","r");
    char achr[100];
    while (fgets(achr,100,altfile) != NULL)
    {
        fputs(achr,file);
    }
    fclose(file);
    fclose(altfile);
    //printf("%d",numline);
    
}
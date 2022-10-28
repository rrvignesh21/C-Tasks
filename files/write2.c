#include<stdio.h>
#include<string.h>
void main(){
    char filename[20];
    printf("enter the name of the file: ");
    scanf("%s",&filename);
    printf("enter string : ");
    char c = getchar();
    char str[50];
    gets(str);
    FILE *filep;
    filep = fopen(filename,"w+");

    fwrite(str,strlen(str)+1,1,filep);
    fseek(filep,0,SEEK_SET);
    char res[50];
    fread(res,strlen(str)+1,1,filep);
    printf("%s",res);
    fclose(filep);
}
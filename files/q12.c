#include<stdio.h>
/* To replace a specific line in a file with a line of another file. */
void main(){
    FILE *fromfile,*tofile,*dumyfile;
    fromfile = fopen("fromfile.txt","r");
    tofile = fopen("tofile.txt","r");
    dumyfile = fopen("dumyfile.txt","w");
    printf("enter line number: ");
    int line;
    scanf("%d",&line);
    int numline = 1;
    char chf[100],cht[100];   
    while (fgets(chf,100,fromfile) != NULL && fgets(cht,100,tofile))
    {   //printf("sometdf");    
        if(numline == line){
            fputs(chf,dumyfile);
        }
        else{
            fputs(cht,dumyfile);
        }
        
        numline++;
    }
    fclose(fromfile);
    fclose(tofile);
    fclose(dumyfile);
    dumyfile = fopen("dumyfile.txt","r");
    tofile = fopen("tofile.txt","w");
    char achr[100];
    while (fgets(achr,100,dumyfile) != NULL)
    {
        fputs(achr,tofile);
    }
    fclose(tofile);
    fclose(dumyfile);
}

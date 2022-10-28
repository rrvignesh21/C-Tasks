#include<stdio.h>
#include<string.h>
/* Program to find and replace a word in a text file. */

void main()
{
	FILE *file,*tempfile;
	file=fopen("sample123.txt","r");
	tempfile=fopen("tempfile.txt","w");
	char reword[20],replace[20];
	printf("Enter a word to be Search\n");
	scanf("%s",&reword);
	fflush(stdin);
	printf("Enter a word to be Replace\n");
	scanf("%s",&replace);
	char temp[20];
    while(fscanf(file,"%s",temp)!=EOF)
	{  
		if(!strcmp(temp,reword))
		{
			fprintf(tempfile,"%s ",replace);
		}
		else
		{
			fprintf(tempfile,"%s ",temp);	
		}	
        
	}
	
	fclose(file);
	fclose(tempfile);
    file=fopen("sample123.txt","w");
	tempfile=fopen("tempfile.txt","r");
    char c = getc(tempfile);
    while (c != EOF)
    {
        putc(c,file);
        c = getc(tempfile); 
    }
    fclose(file);
    fclose(tempfile);   


}
#include<stdio.h>
#include<string.h>
/* Program to remove duplicate letters in a file. */
void main(){
    FILE *f;
    char fl[] = "copy2.txt";
    f = fopen(fl,"r");

    char copy[50];
    //char c = fgetc(f);
    while (fgets(copy,50,f) != NULL){
        //fputs(copy,of);        
        //c = fgetc(f);
    }     
    
    for(int i = 0; i < strlen(copy); i++)
    {   
	for(int j = i + 1; copy[j] != '\0'; j++)
	{
		if(copy[j] == copy[i])  
		{
			for(int k = j; copy[k] != '\0'; k++)
			{
				copy[k] = copy[k + 1];
			}
		}
	}

}
    fclose(f);
    f = fopen(fl,"w");
    if(strlen(copy) > 0 ){
        fputs(copy,f);
    }
    fclose(f);
}

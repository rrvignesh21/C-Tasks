#include<stdio.h>
#include<string.h>
void main(){
    FILE *f;
    char fl[] = "copy2.txt";
    f = fopen(fl,"r");
                                        
    char copy[50];
    
    while (fgets(copy,50,f) != NULL){       
        fgets(copy,50,f);
        
        
    }     
    printf("%s",copy);  
    
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

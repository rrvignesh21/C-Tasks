#include<stdio.h>
#include<string.h>
/* Program to count and remove all the comment lines in a "C" Program. */
void main(){
    FILE *file;
    file = fopen("demo.c","r");
    FILE *dfile;
    dfile = fopen("copycmd.c","w");
    char c = fgetc(file);
    int count = 0;
    while(c != EOF){
        if(c == '/'){
            c = fgetc(file);
            if(c == '/'){
                while((c = fgetc(file)) != '\n'){
                    continue;
                }
            count++;
            }
            
            else if(c == '*'){
                c = fgetc(file);
                while(c != '*'){
                    c = fgetc(file);
                    continue;
                }
               if((c = fgetc(file)) == '/'){
                    count++;
                    continue;
                }
                
            }
        }

        
        
        fputc(c,dfile);
        printf("%c",c);
        
        c = getc(file);
    } 
    printf("no of comments : %d",count);
    
    //printf("something");
        //fputs(c,dfile);
    //printf("%s",c);
            
    fclose(dfile);
    fclose(file);

}
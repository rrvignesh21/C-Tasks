#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/* Program to allocate memory at runtime for an array containing "welcome" and
 add '4' to the characters at even numbered location. */
void main(){
    char *ch;
    ch = (char *)malloc(10 * sizeof(char));
    strcpy(ch,"welcome");
    int idx = 0; 
    //char *tmp = ch;
    while(*(ch+idx) != '\0'){
        if(idx % 2 == 0){
            *(ch+idx) = *(ch+idx) + 4;
        }
        //printf("%c ",*ch);
        idx++;
    }
    printf("%s",ch);
    free(ch);

}
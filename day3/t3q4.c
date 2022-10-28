#include<stdio.h>
#include <string.h>
/* Count the total number of words in a string. */
void main(){
    char in[50];
    printf("enter the stirng: ");
    gets(in);
    int wcount = 0;
    int n = strlen(in);
    for(int i = 0;i < n;i++){
        if(in[i] == ' '){
            wcount++; 
        }
    }
    printf("No of words in given string: %d",wcount+1);
}
#include<stdio.h>
#include <string.h>
/* Create an array that contains "yourname" where add 1 to the content of odd-numbered locations and 
subtract 1 from the even-numbered locations. */
void main(){

    char name[20];
    gets(name);
    int n = strlen(name);
    for(int i = 0;i < n;i++){
        if(i%2 == 0){
            name[i] = name[i] - 1;
            //printf("%c",name[i]-1);
        }
        else{
            name[i] = name[i] + 1;
            //printf("%c",name[i]+1);
        }
    }
    printf("%s",name);
}
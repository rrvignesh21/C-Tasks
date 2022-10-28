#include<stdio.h>
#include <string.h>
void main(){
    char c[] = "something";
    for(int i = sizeof(c)/sizeof(c[0]);i >= 0;i--){
        printf("%c",c[i]);
    }
}
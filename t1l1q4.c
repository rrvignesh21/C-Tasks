#include<stdio.h>
/* 4. Display the ASCII Table. */
void main(){
    printf("%s   %s\n","char","ASCII Value");
    for(int i = 0;i < 256; i ++){
        printf("%c    %d\n",i,i);
    }
}
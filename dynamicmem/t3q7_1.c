#include<stdio.h>
#include<stdlib.h>
/* To copy one string to another using pointers. */
void main(){
    char inp[20];
    printf("enter string: ");
    scanf("%s",&inp);
    char *ptr;
    ptr = &inp[0];
    char trg[20];
    int idx = 0;
    while (*ptr != '\0')
    {
        trg[idx] = *ptr;
        idx++;
        ptr++;
    }
    trg[idx] = '\0'; 
    printf("copied string %s",trg);
    
}
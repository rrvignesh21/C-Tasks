#include<stdio.h>
/* Write a program to differentiate local and global variables. */
int glob = 10;
void main(){
    int glob = 2;
    something();
    printf("\nlocal variable:");
    printf("%d ",glob);


}
int something(){

    printf("global variable: ");
    printf("%d ",glob);
    
}
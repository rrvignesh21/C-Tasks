#include<stdio.h>
#include<string.h>
/* Write a program to check whether the entered string is palindrome or not. */
int main(){
    char in[20];
    printf("enter the string: ");
    scanf("%s",&in);
    //printf("%d",strlen(in));
    int n = strlen(in);
    int l = n - 1;
    for(int i = 0;i < l;i++){
        if (in[i] == in[l])
        {   
            --l;
            continue;
        }
        if(in[i] != in[l])
        {  
            printf("Given string is not a palindrome");
            return 0;
            break;
        }
    }
    printf("%s is palindrome",in);
    return 0;
}
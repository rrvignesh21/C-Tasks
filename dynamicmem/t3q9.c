#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/* To compare two strings using pointers. */
int main(){
    char str1[20],str2[20];
    char *ptr1,*ptr2;
    printf("enter 1st string: ");
    scanf("%s",&str1);
    printf("enter 2nd string: ");
    scanf("%s",&str2);
    ptr1 = &str1[0];
    ptr2 = &str2[0];
    while ((*ptr1 != '\0') && (*ptr2 != '\0'))
        {
            if(*ptr1 == *ptr2){
                ptr1++;
                ptr2++;
                continue;
            }
            else{
                printf("%s is not equal to %s",str1,str2);
                return 0;
            }
            
        }
        printf("%s is equal to %s",str1,str2);
        free(ptr1);
        free(ptr2);
        return 0;
}
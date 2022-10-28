#include <stdio.h>
/* Create an array that contains any string,
 where remove all occurrences of any special characters and spaces and
 find the length of the string w/o using strlen(). */
void main(){
    char str[20];
    gets(str);
    int c = 0;
    for(int i = 0;i<sizeof(str)/sizeof(str[0]);i++){
        if((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122 || (str[i] >= 48 && str[i]<= 57))){
            c++;
        }
    }
    printf("\n%d",c);
}
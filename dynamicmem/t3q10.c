#include <stdio.h>
#include <string.h>
/* Write a program in C to print all permutations of a given string using pointers. */
void swap(char *ch1, char *ch2)
{
    char tmp;
    tmp = *ch1;
    *ch1 = *ch2;
    *ch2 = tmp;
}
void permu(char *ch, int start, int end)
{
   int i;
   if (start == end){
     printf("%s  ", ch);
   }
   else
   {
       for (i = start; i <= end; i++)
       {
          swap((ch+start), (ch+i));
          permu(ch, start+1, end);
          swap((ch+start), (ch+i)); 
       }
   }
}
 
int main()
{
    char str[20];
    printf("enter the string");
    scanf("%s",&str);
    int n = strlen(str);
    printf(" The permutations of the string are : \n");
    permu(str, 0, n-1);
    printf("\n");
    return 0;
}
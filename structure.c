#include<stdio.h>
struct str
{
    int i;
    char cr;
}some;
union str1
{
    int i;
    char cr;
}uni;

void main(){
    some;
    some.cr = 'c';
    some.i = 123;
    printf("%C %d\n",some.cr,some.i);
    uni.cr = 'd';
    uni.i = 23;
    printf("%C %d",uni.cr,uni.i);

}
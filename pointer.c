#include<stdio.h>

void main(){
    int *a,a1;
    void *b;
    int *s;
    int b1;
    a1 = 12;
    b1 = 2;
    a = &a1;
    b = &b1;
    s = &b1;
    int c1 = *a + *(int *)b;
    int c2 = *a + *s;
    printf("%d\n",c2);
    printf("%d\n",c1);
    printf("void pointer : %d",*(int *)b);
    int *si;
    int **db;
    int vl = 23;
    si = &vl;
    db = &si;
    printf("single pointer:%d\n",*si);
    printf("double pointer:%d",**db);
}
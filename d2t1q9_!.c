#include<stdio.h>

#define MAX(x,y) ((x > y) ? x:y)
#define CUBE(sqr) (sqr * sqr)
#define POWR(x,p) {}
#define PROD(x,y) { int res = 0; for(int i = 0;i < y;i++) { res = res + x;} printf(res);}                       
                                                                                      


void main(){
    printf("%d",CUBE(2));
}
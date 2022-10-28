#include <stdio.h>
 
static inline int vol(int s){
    return (s*s*s);
}

void main(){
    int s;
    printf("enter the size:");
    scanf("%d",&s);
    int res = vol(s);
    printf("volume : %d",res);
}
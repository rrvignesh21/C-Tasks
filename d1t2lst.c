#include<stdio.h>

int sum(int x,int y,int z){
    while(y != 0){
    unsigned c = x & y;

    x = x ^ y;
    y = c << 1;

    }
    //return x;
    while (z !=0)
    {
        unsigned c = x & z;
        x = x ^ z;
        z = c << 1;
    }
    return x;
    
}

void main(){
    int x,y,z;
    printf("enter three numbers : ");
    scanf("%d",&x);
    scanf("%d",&y);
    scanf("%d",&z);
    printf("sum : %d",sum(x,y,z));
    
}
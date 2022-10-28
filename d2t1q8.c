#include <stdio.h>

#define MAX(x,y,z) ((x > y) ? (( x > z) ? x:z):((y > z) ? y:z))
#define MIN(x,y,z) ((x < y) ? ((x < z)?x:z):((y<z)?y:z))

void main(){
    int x,y,z;
    printf("enter three numbers: ");
    scanf("%d",&x);
    scanf("%d",&y);
    scanf("%d",&z);
    printf("maximum : %d\nminimum : %d",MAX(x,y,z),MIN(x,y,z));
}

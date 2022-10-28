#include <stdio.h>

void main(){
        int n;
        printf("enter the number: ");
        scanf("%d",&n);
        int c = 0;
        int rm = 0;
        while (n > 0){
            rm = n % 10;
            n = n / 10;
            if (rm == 1){
                c++;
            }
            else{
                continue;
            }
        }
        printf("%d ",c);
}
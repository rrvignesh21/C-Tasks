#include <stdio.h>
/* Write a C program to which reads n digits chosen from 0 to 9 and counts the number of combinations
 where the sum of the digits equals to given number.
 Do not use the same digits in a combination.*/
int comb(int n,int s,int l){
    int i;
    int result = 0;
    
    if(n == 1){
        if ((s >= l) && (s <= 9)){
            return 1;
        }
        else{
            return 0;
        }
    }
    for(i = l;i <= 9;i++){
        result += comb(n -1, s - i, i+1);
        }
    return result;
}

void main(){
    int n;
    int sum;
    printf("enter the combination: ");
    scanf("%d",&n);
    printf("enter the sum: ");
    scanf("%d",&sum);
    int res = comb(n,sum,0);
    printf("%d",res);
}
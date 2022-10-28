#include <stdio.h>
/* 5. Find the maximum of 'n' numbers. */
void main(){
    int n;
    printf("enter the number of elements: ");
    scanf("%d",&n);
    int arr[n];
    printf("enter the numbers: ");
    for(int i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }
   // printf("%d",arr[5]);
   int hig = arr[0];
   for(int i = 1;i<n;i++){
    if(hig < arr[i]){
        hig = arr[i];
    }
    else{
        continue;
    }
   }
   printf("highest number in given numbers is %d",hig);


}
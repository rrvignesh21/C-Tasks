#include<stdio.h>

void main(){
    int n;
    printf("enter the number of elements: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter numbers: ");
    for(int i = 0;i < n;i++){
        scanf("%d",&arr[i]);
        }
     for (int i = n / 2; i > 0; i /= 2) {
    for (int j = i; j < n; j += 1) {
      int temp = arr[j];
      int k;
      for (k = j; j >= i && arr[k - i] > temp; k -= i) {
        arr[k] = arr[k - i];
      }
      arr[k] = temp;
    }
  }
  
    for(int i = 0;i < n;i++){
        printf("%d ",arr[i]);
    }

}
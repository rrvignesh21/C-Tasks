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
        int k, j;
    for(int i = 1; i < n; i++){
        k = arr[i];
        j = i - 1;
        while ( j >= 0 && arr[j] > k ){
            arr[j + 1] = arr[j];
            j = j - 1;
            }
        arr[j + 1] = k;
        }
    for(int i = 0;i < n;i++){
        printf("%d ",arr[i]);
    }        
}


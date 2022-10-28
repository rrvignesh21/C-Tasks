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

    for(int i = 0;i < n - 1;i++){
        int min = arr[i];
        int id = i;
        for(int j = i + 1;j< n;j++){
            if (arr[j] < min){
                min = arr[j];
                id = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[id];
        arr[id] = temp;

    }
        for(int i = 0;i < n;i++){
        printf("%d ",arr[i]);
    }

}
#include<stdio.h>
#include<stdlib.h>

void main(){
    int n;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements: ");
    for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int j = 0;
    for(int i = 0;i<n;i++){
    if(arr[i] != 0){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        j++;
    }
    }
    for(int i = 0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
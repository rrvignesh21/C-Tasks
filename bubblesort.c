#include<stdio.h>

void main(){
    int n;
    printf("enter the size of the array: ");
    scanf("%d",&n);
    int arr[n];
    printf("enter numbers: ");
    for(int i = 0;i < n;i++){
        scanf("%d",&arr[i]);
    }
    for(int j = 0; j < n;j++){
    for(int i = 0 ; i < (n - 1); i++){
        if(arr[i] > arr[i+1]){
            int tp = arr[i+1];
            arr[i+1] = arr[i];
            arr[i] = tp; 
        }
    }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    
}
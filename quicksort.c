#include<stdio.h>


int povit(int arr[],int low,int high){
    int povit = arr[high];
    int i = low - 1;
    for(int j = low;j<high;j++){
        if(arr[j] <= povit){
            i++;
            int tp = arr[i];
            arr[i] = arr[j];
            arr[j] = tp;
        }
    } 
   int t = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = t;
    return i+1;
}
void quicksort(int arr[], int low,int high){
    if(low < high){
    int p = povit(arr,low,high);

    quicksort(arr,low,p - 1);
    quicksort(arr,p + 1,high);
    }        

}
void main(){
    int n;
    printf("enter the number of elements: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter numbers: ");
    for(int i = 0;i < n;i++){
        scanf("%d",&arr[i]);
        }
        quicksort(arr,0,n-1);
        for(int i = 0;i < n;i++){
        printf("%d ",arr[i]);
        }

}


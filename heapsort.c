#include<stdio.h>

void heapify(int arr[],int n,int i){
    int lr = i;
    int lf = 2 * i + 1;
    int rt = 2 * i + 2;
    
    if(lf < n && arr[lf] > arr[lr]){
        lr = lf;
    }
    if (rt < n && arr[rt] > arr[lr]){
        lr = rt;
    }
    if(lr != i){
        int tmp = arr[i];
        arr[i] = arr[lr];
        arr[lr] = tmp;
        heapify(arr,n,lr);
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
    for(int i = (n / 2)-1; i >= 0;i--){
        heapify(arr,n,i);
    }

    for(int i = n - 1; i >= 0;i--){
        int tmp = arr[0];
        arr[0] = arr[i];
        arr[i] = tmp;
        heapify(arr,i,0); 
    }

        for(int i = 0;i < n;i++){
        printf("%d ",arr[i]);
        }

}
#include<stdio.h>
/* Program to create a binary search tree using arrays. */

int *heapify(int arr[],int n,int i){
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
    return arr;
}
int *insert(int i, int key,int arr[]) {
    int root = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  if (key < arr[i])
    insert(left, key, arr);
  else
    insert(right, key, arr);

  return arr;
}

void main(){
    int n;
    printf("enter the number of elements: ");
    scanf("%d",&n);
    int arr[n];
    for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int lr = arr[0];
    for(int i = 0; i < n;i++){
        insert(0,arr[i],arr);
    }
    int *res = insert(0,arr[0],arr);
    for(int i = 0; i < n; i++){
        printf("%d ",res[i]);
    }

}
#include<stdio.h>

int binarysearch(int arr[],int l,int r,int n){
    if(r >= l){
        int mid = (l +(r-l))/2;
        if (arr[mid] == n){
            return(mid+1);
        }
        if(arr[mid] > n){
            binarysearch(arr,l,mid - 1,n);
        }
        
        binarysearch(arr,mid+1,r,n);
        
    }    
    return -1;
}

void main(){
    int n;
    printf("enter the number of elements: ");
    scanf("%d",&n);
    int arr[] = {1,2,3,4,5,6,7,8,9,10,12,13,14,15,17,18,20};
    int pos = binarysearch(arr,0,(sizeof(arr)/sizeof(arr[0]))-1,n);
    if (pos >= 0){
        printf("%d is in %d position in the array",n,pos);
    }
    else{
        printf("%d is not found in this array",n);
        printf("%d",pos);
    }
}
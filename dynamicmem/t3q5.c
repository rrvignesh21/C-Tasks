#include<stdio.h>
#include<stdlib.h>
/* To search an element in array using function pointers. */
int search(int *arr,int n,int val){
    for(int i = 0;i < n;i++){
        if(*(arr+i) == val){
            return i;
        }
    }
    return -1;
}

void main(){
    printf("enter the number of elements: ");
    int n;
    scanf("%d",&n);
    int *arr;
    arr = (int *)malloc(n*sizeof(int));
    printf("enter elements: ");
    for(int i = 0;i<n;i++){
        scanf("%d",(arr+i));
    }
    int val;
    printf("enter the value to search: ");
    scanf("%d",&val);
    int (*search_ptr)(int *,int ,int) = &search;
    int res = (*search_ptr)(arr,n,val);
    if(res >= 0){
        printf("%d is found at %d postion",val,res);
    }
    else{
        printf("%d is not found in this array",val);
    }
    
}
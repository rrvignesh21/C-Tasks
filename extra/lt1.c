#include<stdio.h>

void main(){
    int n;
    printf("enter no of elements: ");
    scanf("%d",&n);
    int arr[n];
    printf("\nenter elements: ");
    for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int h = arr[n -1];
    int rmax = 0;
    int wd = 1,len = 0;
    for(int i = n-2;i >= 0;i--){
        if(arr[i] < h){
            len = arr[i];
        }
        else{
            len = h;
        }
        int area = wd * len;
        if(rmax < area){
            rmax = area;
        }
        wd++;
    }
    printf("%d",rmax);

}
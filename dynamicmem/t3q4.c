#include<stdio.h>
#include<stdlib.h>
/* C program to input and print array elements using pointers.s */
void main(){
    printf("enter the number of elements: ");
    int n;
    scanf("%d",&n);
    int *arr;
    printf("Enter Elements: ");
    arr = (int *)malloc(n*sizeof(int));
    for(int i = 0;i<n;i++){
        scanf("%d",(arr+i));
    }
    printf("Elements stored : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",*(arr+i));
    }
    
}
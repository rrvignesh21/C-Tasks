#include<stdio.h>
#include<stdlib.h>
/* C program to search element in array using pointers. */
int main(){
        int n;
        printf("enter number of elements: ");
        scanf("%d",&n);
        int arr[n];
        int *ptr;
        ptr = &arr[0];
        printf("enter the elements: ");
        for(int i = 0; i<n; i++){
            scanf("%d",&arr[i]);
        }
        int val;
        printf("enter the element to search: ");
        scanf("%d",&val);

        for(int i = 0;i < n;i++){
            if(*ptr == val){
                printf("%d is found in %d position",val,i);
                return 0;                
            }
            ptr++;
        }
        printf("%d is not found in this array",val);
        free(ptr);
        return 0;
}
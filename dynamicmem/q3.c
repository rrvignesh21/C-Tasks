#include<stdio.h>
#include<stdlib.h>
/* Manipulate an array using pointers,
 where find out count of the prime numbers and its position stored in that array. */
int chechprime(int num){
    if(num ==1 || num == 0){
        return 0;
    }
    for(int i = 2;i < num;i++){
        if(num % i == 0){
            return 0;
        }
    }
    return 1;
}
void main(){
        int n;
        printf("enter number of elements: ");
        scanf("%d",&n);
        int arr[n];
        int *ptr;
        ptr = &arr;
        //arr = (int *)malloc(10 * sizeof(int));
        printf("enter the elements: ");
        for(int i = 0; i<n; i++){
            scanf("%d",&arr[i]);
        }

        int count = 0;
        printf("position of prime number: ");
        for(int i = 0;i < n;i++){
            if(chechprime(*ptr)){
                count++;
                printf("%d ",i);                
            }
            //printf("%d ",*ptr);
            ptr++;
        }
        printf("\nnumber of prime numbers : %d",count);
        free(ptr);
}
#include<stdio.h>
#include<stdlib.h>
/* Program to allocate memory for 10 integers and
 reallocate the same memory for 15 integers and store some integer data(may be positive or negative) and
 find the odd numbers and its position or index.v  */
void main(){
        int *arr;
        arr = (int *)malloc(10 * sizeof(int));
        printf("enter first 10 elements: ");
        for(int i = 0; i<10; i++){
            scanf("%d",arr+i);
        }
        //arr = (int *)malloc(5 * sizeof(int));
        arr = (int *)realloc(arr,sizeof(int)*15);
        printf("enter remaining 5 elements: ");

        for(int i = 10;i < 15;i++){
            scanf("%d",arr+i);
        }
        for(int i = 0;i<15;i++){
            if(*(arr+i)%2 != 0){
                printf("%d - postion:%d\n",*(arr+i),i);
            }
            //printf("%d ",*(arr+i));
        }
        free(arr);
}
# include<stdio.h>

int main(){
    int n;
    printf("enter the number : ");
    scanf("%d",&n);
    int arr[] = {4,6,3,1,7,8,9,5,4,11};
    for(int i = 0;i < sizeof(arr)/sizeof(arr[0]);i++){
        if (arr[i] == n){
            printf("%d is found in %d position of the array",n,i+1);
            return 0;
        }
        }
    printf("%d is not found in the array",n);
}
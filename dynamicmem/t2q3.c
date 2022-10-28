#include<stdio.h>
/* Access two dimensional arrays using pointers in C. */
void main(){
    printf("Enter the number of columns");
    int n; 
    scanf("%d", &n);
    printf("Enter the number of rows");
    int m; 
    scanf("%d", &m);

    int arr[n][m];
    printf("enter the elements: \n");
    for (int a=0; a<n; a++){
            for (int b=0; b<m; b++){
    scanf("%d",&arr[a][b]);
        }
    }
    printf("ARRAY:\n");
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            printf("%d ",*(*(arr+i)+j));
        }
        printf("\n");
    }
}
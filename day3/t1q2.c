#include<stdio.h>
/* Create a Sparse matrix and find out the locations where 1's are there. */
void main(){
    int n,m;
    printf("enter number of row: ");
    scanf("%d",&n);
    printf("enter number of column: ");
    scanf("%d",&m);
    int sparse_matrix[n][m];
    for(int i = 0;i < n;i++){
        for(int j = 0;j<m;j++){
            scanf("%d",&sparse_matrix[i][j]);
        }
    }
    printf("there are ones in following positions:\n");
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(sparse_matrix[i][j] != 0){
                printf("%d %d\n",i,j);
            }
        }
    }
}
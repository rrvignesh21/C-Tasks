#include<stdio.h>
#include<stdlib.h>

int* reaarr(int n,int m,int r,int c,int arr[n][m]){
        int newarr[r][c];
        int tpi = 0,tpj = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                newarr[tpi][tpj] = arr[i][j];
                tpj += 1 ;
                if(tpj == c){
                    tpi = tpi+1;
                    tpj = 0;
                }
            }
        }
       printarr(r,c,newarr);
}
void printarr(int n,int m,int arr[n][m]){
    for(int i=0;i<n;i++)
    {   
        for(int j=0; j < m ; j++)
        {   
            printf("%d ",arr[i][j]);
        }        
        printf("\n");
}
}
void main(){
    printf("enter row: ");
    int n;
    scanf("%d", &n);

    printf("enter column: ");
    int m;
    scanf("%d", &m);
    printf("%d %d\n ",n,m);
    int arr[n][m];
    printf("Enter the elements : \n");
    for(int i=0;i<n;i++)
    {   
        for(int j=0; j < m ; j++)
        {   
            scanf("%d",&arr[i][j]);
        }        
    }
    printf("enter resize column: ");
    int c;
    scanf("%d",&c);
    printf("enter resize row: ");
    int r;
    scanf("%d",&r);
    if((r*c) != (n*m)){
        printarr(n,m,arr);
    }
    else{
    reaarr(n,m,r,c,arr);
    }
}
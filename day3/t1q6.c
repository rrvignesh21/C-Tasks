#include<stdio.h>
/* Create an adjacency matrix,
 where '1' represents the edges of a graph from i -> j, also use i != j  as a constraint and
 find the number of incoming and out going edges of each vertex. */

void main(){
    int n;
    printf("enter number of edges: ");
    scanf("%d",&n);
    
    int v;
    printf("enter number of vertices: ");
    scanf("%d",&v);
    int grp[n][2]; 
    int res[v][v];
    printf("enter vertices: ");
    for(int i = 0;i < n;i++){
        for(int j = 0;j < 2;j++){
            scanf("%d",&grp[i][j]);
        }
    }
    //printf("%d\n",n);
    for(int i = 0;i < v;i++){               /* for creating a matrix full of zeros */
        for(int j = 0;j < v;j++){
            res[i][j] = 0;
        }
    }
    for(int i = 0;i<n;i++){             /* using grp to turn 1s in place of edges */
        int x = grp[i][0];
        int y = grp[i][1];
        res[x-1][y-1] = 1;
    }
    for(int i = 0;i < v;i++){
        for(int j = 0;j < v;j++){
            printf("%d",res[i][j]);
        }
        printf("\n");
    }
    for(int i = 0;i < v;i++){
        int in = 0;
        int out = 0;
        printf("for vertices %d: \n",i+1);
        for(int j = 0;j < v;j++){
            if(res[i][j] == 1){
                out++;
            }
            if(res[j][i] == 1){
                in++;
            }
        }printf("in : %d,out: %d\n",in,out);

    }  
}
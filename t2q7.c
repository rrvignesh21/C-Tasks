#include<stdio.h>
//Print a checkerboard (8-by-8 grid). Each square should be 5-by-3 characters wide. A 2-by-2 example follows:
void main(){
    int hig = 32;
    int wid = 48;
    for(int i = 0;i <= hig;i++){
        for(int j = 0;j <= wid;j++){
            if(i % 4 == 0 && j % 6 == 0){
                printf("+");
            }
            if(i % 4 == 0 && j % 6 > 0 ){
                printf("-");
            }
            if(i % 4 > 0 && j % 6 == 0){
                printf("|");
            }
            if (i % 4 > 0 && j % 6 > 0){
                printf(" ");
            }


        }
        printf("\n");
    }
}
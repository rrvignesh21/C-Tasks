#include <stdio.h>

void upperalb(int n){
    
    
    if ( (n <= 90) && (n >= 65)){
        printf("%c ",n);
        return upperalb(n + 1);
    }
    else{
        return;
    }

}

void main(){

    upperalb(65);
}
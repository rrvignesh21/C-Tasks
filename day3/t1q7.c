#include<stdio.h>
#include <stdlib.h>
#include <string.h>
/* Program to evaluate the balanced parenthesis using stack. */

int checkbrak(char c1,char c2);

void main(){
    char c[20];
    printf("enter the parenthesis: ");
    scanf("%s",c);
    char re[20];
    int tp = -1;
    for(int i = 0;i < strlen(c);i++){
        if (tp == -1){
        if(c[i] == '{' || c[i] == '[' || c[i] == '('){
            tp++;
            re[tp] = c[i];
        }
        }
        else{
        if(c[i] == '{' || c[i] == '[' || c[i] == '('){
            tp++;
            re[tp] = c[i];
        }
        else if(c[i] == '}' || c[i] == ']' || c[i] == ')'){
            if(checkbrak(re[tp],c[i])){
                tp--;
            }
            else{
                printf("Unbalanced");
                break;
            }
        }
        }
    }
    if((strlen(c) == tp + 1)||(tp == -1)){
    printf("balanced ");
    }    
}

int checkbrak(char c1,char c2){
    if(( c1=='(' && c2==')' )||( c1=='[' && c2==']' )||( c1=='{' && c2=='}' )){
        return 1;
    }
    else{
        return 0;
    }
}
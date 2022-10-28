#include<stdio.h>
struct stack
    {   
        int size;
        int top;
        int arr[];
    };

void createstack(struct stack s,int max){
    s.top = -1; 
    s.size = 0; 
    s.arr[max];  
} 
int isempty(struct stack s){
    if (s.top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct stack s,int num){
        s.top++;
        s.arr[s.top] = num;
        s.size++;
    
}
int top(struct stack s){
    if (isempty(s)){
        return 0;
    }
    else{
        return s.arr[s.top];
    }
}
int pop(struct stack s){
    if (isempty(s)){
        return -1;
        }
    else{
        return s.arr[s.top];
        s.arr[s.top] = 
        s.top--;
        s.size--;
    }
}
void main(){
    //int n;
   // printf("enter the size of stack: ");
   // scanf("%d",&n);    
    struct stack s;
    createstack(s,10);
    push(s,1);
    push(s,10);
    for(int i = 0;i<s.size;i++){
        printf("%d ",s.arr[i]);
    }


}
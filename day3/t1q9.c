#include<stdio.h>
/* Program to implement Queue. */
#define SIZE 20 
int que[SIZE];
int front = -1;
int rear = -1;
void enqueue(int val);
void dequeue();
void display();
void main(){
    int i = 1;
    int c;
    while (i)
    {
        printf("enter choice 1-enqueue/2-dequeue/3-display/4-exit :");
        scanf("%d",&c);
        switch (c)
        {
        case 1:
            int tmp;
            printf("enter number to enqueue: ");
            scanf("%d",&tmp);
            enqueue(tmp);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            i = 0;
            break;            
        default:
            break;
        }        
    }  
}
void enqueue(int val){
    if(rear == SIZE-1){
        printf("\n queue is full");
    }
    else{
        if(front == -1){
            front = 0;
        }
        rear++;
        que[rear] = val;
    }
}
void dequeue(){
    if(front == -1){
        printf("\n queue is empty");
    }
    else{
        printf("deleted :%d\n",que[front]);
        front++;
        if(front > rear){
            front = rear = -1; 
        }
    }
}
void display(){
    if(rear == -1){
        printf("\n queue is empty");
    }
    else{
        for(int i =front;i<= rear;i++){
            printf("%d ",que[i]);
        }
        printf("\n");
    }
}
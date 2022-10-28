#include<stdio.h>
#include <stdlib.h>
/* Write a C program to create a Stack along with writing a code to
 create, insert, delete, search, traverse and display all the nodes. */
struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL; 
void traverse_link(struct node *s);
void push(struct node *n,int dt);
int search(struct node *n,int val);
void pop();

void main(){
    int choice;
    int fg = 1;
    while (fg)
    {  
    printf("enter choice[1->push:2->pop:3->display:4->search:5->exit]");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        int tmp;
        printf("enter the number to push: ");
        scanf("%d",&tmp);
        push(top,tmp);
        break;
    case 2:
        pop();
        break;
    case 3:
        traverse_link(top);
        break;
    case 4:
        int val;
        printf("enter the value to search: ");
        scanf("%d",&val);
        int i = search(top,val);
        if(i >= 0){
            printf("%d is found at %dth position\n",val,i);
        }
        else{
            printf("%d is not fount in the stack\n",val);
        }
        break;
    case 5:
        fg = 0;
        break;
    default:
        break;
    }
    }
}

void traverse_link(struct node *s){
    struct node* cur = s;
    while(cur != NULL){
        printf("%d->",cur->data);
        cur = cur->next; 
    }
    printf("\n");
    //printf("%d",head.data);
}


void push(struct node *n,int dt){
    if(top == NULL){
        struct node *s = (struct node*)malloc(sizeof(struct node));    
        s->data = dt;
        s->next = NULL;
        top = s;
    }
    else{    
    struct node *s = (struct node*)malloc(sizeof(struct node));
    s->data = dt;
    s->next = n;
    top = s;
    }
}
void pop(){
    if(top == NULL){
        printf("stack is empty");
    }
    else{
        int tmpr = top->data;
        printf("pop->%d",tmpr);
        top = top->next;
    }
}
int search(struct node *n,int val){
    int i = 1;
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp = top;
    while (temp->data != val){
        if(temp->next == NULL){
            return -1;
        }
        i++;
        temp = temp->next;
    }
    return i;
    //temp->next = temp->next->next;
}




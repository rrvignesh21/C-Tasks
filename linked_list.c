#include<stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL; 


void traverse_link(struct node *s){
    struct node* cur = s;
    while(cur != NULL){
        printf("%d->",cur->data);
        cur = cur->next; 
    }
    //printf("%d",head.data);
}


void add_element_lst(struct node *h,int val){
    struct node *cur = (struct node*) malloc(sizeof(struct node));
    cur = h;
    while(cur->next != NULL){
        cur = cur->next;
        //printf("%d",cur->data);
    }
    struct node *new = (struct node*) malloc(sizeof(struct node));
    new->data = val;
    //printf("%d",new->data);
    cur->next = new;
    new->next = NULL;
}
void add_element(struct node *h,int val,int pos){
    struct node *cur = (struct node*) malloc(sizeof(struct node));
    cur = h;
    struct node *new = (struct node*) malloc(sizeof(struct node));
    new->data = val;
    int c = 0;
    if(pos == 1){
        push(cur,val);
    }
    else{
    for(int i=2; i< pos; i++) {
        if(cur->next!=NULL) {
            cur = cur->next;
            }
}
}
    new->next = cur->next;
    cur->next = new;

}

void delete_lst(){
    struct node *cur = (struct node*) malloc(sizeof(struct node)); 
    cur = head;
    while(cur->next->next != NULL){
        cur = cur->next;
        //printf("%d",cur->data);
    }
    cur->next = NULL;
}
void push(struct node *n,int dt){
    struct node *s = (struct node*)malloc(sizeof(struct node));
    s->data = dt;
    s->next = n;
    n = s;
    head = s;
}
void delete_front(){
    head = head->next;
}
void delete(struct node *n,int pos){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp = head;
    for(int i=2; i< pos; i++) {
        if(temp->next!=NULL) {
            temp = temp->next;
            }
}

temp->next = temp->next->next;
}

void main(){
    struct node *n1 = (struct node*) malloc(sizeof(struct node));
    n1->data = 12;
    n1->next = NULL;
    head = n1;

    //add_element(3,head);
    push(n1,56);
    add_element_lst(head,3);
    add_element_lst(head,234);
    add_element_lst(head,4);
    add_element_lst(head,11);
    add_element_lst(head,56);
    delete_lst();
    delete_lst();
    delete_lst();
    delete_front();
    push(head,345);
    push(head,980);
    add_element(head,43,3);
    traverse_link(head);
    add_element(head,87,1);
    //delete(head,2);
    printf("\n");
    traverse_link(head);
    
    //printf("%d",n1.next->data);
}

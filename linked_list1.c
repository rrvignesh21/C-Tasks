#include<stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL; 
void traverse_link(struct node *s);
void append(struct node *h,int val);
void add_element(struct node *h,int val,int pos);
void delete_lst();
void push(struct node *n,int dt);
void delete_front();
void delete(struct node *n,int pos);
void flist(int arr[],struct node *nd,int n);
void deletebyval(struct node *n,int val);

void main(){
    struct node *n1 = (struct node*) malloc(sizeof(struct node));
    n1->data = 12;
    n1->next = NULL;
    head = n1;

    //add_element(3,head);
    push(n1,56);
    append(head,3);
    append(head,234);
    append(head,4);
    append(head,11);
    append(head,56);
    delete_lst();
    delete_lst();
    delete_lst();
    delete_front();
    push(head,345);
    push(head,980);
    add_element(head,43,3);
    traverse_link(head);
    add_element(head,87,1);
    int arr[] = {1,2,3,4,5,6};
    int n = ((sizeof(arr)) / (sizeof(arr[0])));
    flist(arr,head,n);
    //delete(head,2);
    printf("\n");
    //printf("%d\n",(sizeof(arr)) / (sizeof(arr[0])));
    traverse_link(head);
    printf("\n");
    deletebyval(head,2);
    traverse_link(head);
    
    //printf("%d",n1.next->data);
}
void flist(int arr[],struct node *nd,int n){
    //int n = sizeof(arr) / sizeof(arr[0]);
    for(int i = 0;i < n;i++){
        append(nd,arr[i]);
    }
}

void deletebyval(struct node *n,int val){

struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp = head;
    while (temp->next->data != val){
        temp = temp->next;
    }
temp->next = temp->next->next;
}
void traverse_link(struct node *s){
    struct node* cur = s;
    while(cur != NULL){
        printf("%d->",cur->data);
        cur = cur->next; 
    }
    //printf("%d",head.data);
}


void append(struct node *h,int val){
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




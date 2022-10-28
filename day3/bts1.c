#include<stdio.h>

#define size 50
void insert(int tree[],int element,int index)
{

    if(index >= size){
        printf("Size Exceeded\n");
    }
    else if(tree[index]==NULL){
        tree[index]=element;   
    }
    else if(element<tree[index]){
        insert(tree,element,(index*2)+1);
    }
    else if(element > tree[index]){
        insert(tree,element,(index*2)+2);
    }
    
}
void display(int tree[],int index)
{
    if(tree[index]!=NULL)
    {
        display(tree,(index*2)+1);
        printf("%d ",tree[index]);
        display(tree,(index*2)+2);
    }
}
int insert1(int* tree, unsigned current_idx, int element){
    if (current_idx >= size) return -1;

    if(tree[current_idx]==NULL){
        tree[current_idx]=element;
        return 0;
    }

    if(element<tree[current_idx]){
        return insert1(tree, 2*current_idx + 1, element);  
    }

    return insert1(tree, 2*current_idx + 2, element);  
}
void main()
{
    int tree[size],element,choice,i;
    for(i=0;i<size;i++)
        tree[i]=NULL;
    char ch;
    int fg = 1;
    while(fg)
    {
        printf("Enter choice 1:add/2:display/3:exit : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 :
                printf("Enter the element\n");
                scanf("%d",&element);
                insert1(&tree,element,0);
                break;
            case 2 :     
                display(tree,0);
                printf("\n");
                break;
            case 3:
                fg = 0;
                break;
            default :
                printf("Enter Valid Input\n");
        }
    }
    
}
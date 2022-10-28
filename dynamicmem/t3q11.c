#include<stdio.h>
#include<stdlib.h>
//Write a program in C to use a pointer to the union data type.
struct student
{
    int rno;
    char name[20];
    int marks[5];
};
typedef struct student student;
void main(){
    student *s2;
    s2 = (student *)malloc(1*sizeof(student));
    printf("Accessing structure using pointer:\n");
    printf("enter student roll number: ");
    scanf("%d",&s2->rno);
    printf("enter student name: ");
    scanf("%s",&s2->name);
    printf("enter marks of five subjects: \n");
    for(int i = 0;i<5;i++){
        printf("enter subject %d mark : ",i+1);
        scanf("%d",&s2->marks[i]);
    }
    printf("Student Name : %s\nStudent Roll number: %d\n",s2->name,s2->rno);
    for (int i = 0; i < 5; i++)
    {
        printf("Student mark in subject %d : %d\n",i+1,s2->marks[i]);
    }
    
    
    
}

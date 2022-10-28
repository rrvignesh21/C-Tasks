#include<stdio.h>
#include<stdlib.h>
//Write a program in C to show the usage of pointer to the structure.
union student
{
    int rno;
    char name[20];
    int tmark;
};

typedef union student student;
void main(){
    student *s1;
    s1 = (student *)malloc(1*sizeof(student));
    printf("Enter student roll number: ");
    scanf("%d",&s1->rno);
    printf("Student Roll Number: %d\n",s1->rno);
    printf("Enter student name: ");
    scanf("%s",&s1->name);
    printf("Student Name: %s\n",s1->name);
    printf("enter total mark: ");
    scanf("%d",&s1->tmark);    
    printf("Total Mark: %d\n",s1->tmark);
}
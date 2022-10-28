#include<stdio.h>
/* Create a structure student having data members to store roll number, name of student, name of three subjects, max marks and minimum marks.
 Declare a structure variable of student provide facilities to input data in data member and display result of student. */
struct student
{
    int rollnumber;
    char name[20];
    char subject[3][20];
    int max_mark;
    int min_mark;
};


void main(){
    int n;
    printf("enter number of students: ");
    scanf("%d",&n);
    struct student s[n];
    for(int i = 0;i < n;i++){
        printf("\nenter student %d roll number: ",i+1);
        scanf("%d",&s[i].rollnumber);
        printf("\nenter student %d name: ",i+1);
        scanf("%s",&s[i].name);
        for(int j = 0;j < 3;j++){
        printf("\nenter student %d mark in subject %d:",i+1,j+1);
        scanf("%s",&s[i].subject[j]);
        printf("\n");
        }
        printf("enter student %d max mark: ",i+1);
        scanf("%d",&s[i].max_mark);
        printf("enter student %d min mark: ",i+1);
        scanf("%d",&s[i].min_mark);
    }
    for(int i = 0;i < n;i++){
        printf("\nstudent %d roll number:%d ",i+1,s[i].rollnumber);
        printf("\nstudent %d name: %s",i+1,s[i].name);
        for(int j = 0;j < 3;j++){
        printf("\nstudent %d mark in subject %d: %s \n",i+1,j+1,s[i].subject[j]);
        }
        printf("student %d max mark: %d ",i+1,s[i].max_mark);
        printf("\nstudent %d min mark: %d ",i+1,s[i].min_mark);
        }
}
#include<stdio.h>
/* Write a c program to read and
 print an employee’s details like name, employee id, salary using structure. */
struct employee
{
    int id;
    char name[20];
    int salary;
};


void main(){
    int n;
    printf("enter number of employees: ");
    scanf("%d",&n);
    struct employee e[n];
    for(int i = 0;i < n;i++){
        printf("\nenter employee %d id: ",i+1);
        scanf("%d",&e[i].id);
        printf("\nenter employee %d name: ",i+1);
        scanf("%s",&e[i].name);
        printf("\nenter student %d salary: ",i+1);
        scanf("%d",&e[i].salary);
    }

    for(int i = 0;i < n;i++){
        printf("\nemployee %d id:%d ",i+1,e[i].id);
        printf("\nenter employee %d name: %s",i+1,e[i].name);
        printf("\nenter student %d salary: %d",i+1,e[i].salary);
        printf("\n");
    }



}
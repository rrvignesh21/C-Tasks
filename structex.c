#include<stdio.h>

struct student
{
    int id;
    char name[20];
    char emailid[35];
    char dept[10];
    char clg[35];
    char role[20];
};


void main(){
    struct student s[5];
    int c = 1;
    for(int i = 0;i < 5;i++){
        printf("enter student %d id: ",c);
        scanf("%d",&s[i].id);
        printf("enter student %d name: ",c);
        scanf("%s",&s[i].name);
        printf("enter student %d emailid: ",c);
        scanf("%s",&s[i].emailid);
        printf("enter student %d dept: ",c);
        scanf("%s",&s[i].dept);
        printf("enter student %d clg: ",c);
        scanf("%s",&s[i].clg);
        printf("enter student %d role: : ",c);
        scanf("%s",&s[i].role);
        c++;
    }
    c = 1;
    for(int i = 0;i < 5;i++){
        printf("\nstudent %d id: %d",c,s[i].id);
        printf("\nstudent %d name: %s",c,s[i].name);
        printf("\nstudent %d emailid: %s",c,s[i].emailid);
        printf("\nstudent %d dept: %s",c,s[i].dept);
        printf("\nstudent %d clg: %s",c,s[i].clg);
        printf("\nstudent %d role: %s",c,s[i].role);
        printf("\n");
        c++;
    }   

}
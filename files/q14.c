#include<stdio.h>
#include<string.h>
/* To create an Employee detail 
using structure and update the same in a file using fscanf() and fprintf() functions. */
struct employee
{
    int id;
    char name[20];
    char position[20];
    int salary;
};

void add(FILE *file){
    file = fopen("employee_detail.txt","a");
    struct employee emp;
    printf("\nenter employee id: ");
    scanf("%d",&emp.id);
    fprintf(file,"%d ",emp.id);
    printf("\nenter employee name: ");
    scanf("%s",&emp.name);
    fprintf(file,"%s ",emp.name);
    printf("\nenter employee position: ");
    scanf("%s",&emp.position);
    fprintf(file,"%s ",emp.position);
    printf("\nenter employee salary: ");
    scanf("%d",&emp.salary);
    fprintf(file,"%d ",emp.salary);
    fprintf(file,"%s","\n");
    fclose(file);
}
void display(FILE *file){
    file = fopen("employee_detail.txt","r");
    struct employee emp;
    
    int i = 1;
    while (!feof(file))
    {   
        char tmp[3];
        fscanf(file,"%d ",&emp.id);
        printf("employee %d id: %d\n",i,emp.id);
        fscanf(file,"%s ",&emp.name);
        printf("employee %d name: %s\n",i,emp.name);
        fscanf(file,"%s ",&emp.position);
        printf("employee %d postion: %s\n",i,emp.position);
        fscanf(file,"%d ",&emp.salary);
        printf("employee %d salary: %d\n",i,emp.salary);
        printf("============================================\n");
       // fscanf(file,"%s",&tmp);
        //printf(tmp);
        i++;
    }
    fclose(file);
    
    
}

void main(){
    printf("enter the number of employees: ");
    int num;
    scanf("%d",&num);
    struct employee emp;
    FILE *file;
    file = fopen("employee_detail.txt","w");
    for (int i = 0; i < num; i++)
    {
        printf("\nenter employee %d id: ",i+1);
        scanf("%d",&emp.id);
        fprintf(file,"%d ",emp.id);
        printf("\nenter employee %d name: ",i+1);
        scanf("%s",&emp.name);
        fprintf(file,"%s ",emp.name);
        printf("\nenter employee %d position: ",i+1);
        scanf("%s",&emp.position);
        fprintf(file,"%s ",emp.position);
        printf("\nenter employee %d salary: ",i+1);
        scanf("%d",&emp.salary);
        fprintf(file,"%d ",emp.salary);
        fprintf(file,"%s","\n");        
    }
    fclose(file);
    int fg = 1;
    while(fg){
        int i;
        printf("enter choice : 1-add new employee,2-diplay,3-exit: ");
        scanf("%d",&i);
        switch (i)
        {
        case 1:
            add(file);
            break;
        case 2:
            display(file);
            break;
        case 3:
            fg = 0;
            break;
        default:
            break;
        }
    }

    
    

}
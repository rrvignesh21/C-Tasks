#include<stdio.h>
#include<string.h>
/* Program to read 10 student details from a file and write them into another file for those
 who have total marks>400 or Average>80.
Note: RNo, Name, Course, Mark-1,Mark-2,Mark-3,Mark-4,Mark-5,Total and Average as 		
fields of a Student structure.
Use binary form. */
struct student
{
    int rno;
    char name[20];
    char course[20];
    int mark[5];
    int total;
    int average;
};
void main(){
    struct student s;
    FILE *file;
    FILE *bfile;
    file = fopen("student.txt","r");
    bfile = fopen("student.bin","wb");
    int cn = 0;
    while (!feof(file))
    {   
        fscanf(file,"%d",&s.rno);
        fscanf(file,"%s",&s.name);
        fscanf(file,"%s",&s.course);
        for(int i = 0;i<5;i++){
            fscanf(file,"%d",&s.mark[i]);
        }
        s.total = s.mark[0]+s.mark[1]+s.mark[2]+s.mark[3]+s.mark[4];
        s.average = s.total / 5;
        if(s.average > 80 || s.total > 400){
            fwrite(&s,sizeof(struct student),1,bfile);
            cn++;
        }
    }  
    fclose(bfile);
    fclose(file);
    bfile = fopen("student.bin","rb");
    struct student tmp;
    while(fread(&tmp,sizeof(struct student),1,bfile)){
        printf("Roll number: %d\n",tmp.rno);
        printf("Name : %s\n",tmp.name);
        printf("course : %s\n",tmp.course);
        for(int i =0 ;i<5;i++){
            printf("marks: %d\n",tmp.mark[i]);
        }
        printf("total : %d\n",tmp.total);
        printf("average: %d\n",tmp.average);
        printf("=======================================\n");
    }
    fclose(bfile);
    
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*  For Coordinator

    ➤  He or she can login to their respective interface and mention the department.

    ➤ Enter the total number of students the enter their register number. Then mention the marks in the respective subjects for a respective semester.

    ➤ Behind the scene the grade, result and GPA must be calculated and stored along with the student information in a separate file.

    For Student

    ➤ They have to enter their password and register number to login to their interface.

    ➤ After selecting the semester the result should be display along with the register number and  GPA. 
*/

struct User
{
    char Name[20];
    char Department[20];
    char Id[20];
    char password[20];
};
typedef struct User user;

struct semester{
    int number_of_subjects;
    char subject[20][20];
    int marks[20];
    int credit[20];
    char grade[20];
    float gpa;
};
typedef struct semester semester;

struct  Date
{
    int day;
    int month;
    int year;
};
typedef struct Date date;

struct Student
{
    int Register_number;
    int no_of_semester;
    semester semester[8];
    date DOB;
}; 
typedef struct Student student;

void registation();
int login();
void mark_entry();
void result_display(int Register_Number,date dob);

void main(){
   
    int choice;
    int fg = 1;
    while(fg){
    printf("1.Coordinator\n2.Student\n3.Exit\n");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        int login_reg;
        printf("1.Login\n2.Register\n");
        scanf("%d",&login_reg);
        switch (login_reg)
        {
        case 1:
            int responce = login();
            if(responce == 1){
                mark_entry();
            }
            else{
                break;
            }
            break;
        case 2:
            registation();
            break;        
        default:
            break;
        }

        break;
    case 2:
        int Register_number;
        printf("Enter Register Number: ");
        scanf("%d",&Register_number);
        date dob;
        printf("Enter your date of birth: ");
        scanf("%d/%d/%d",&dob.day,&dob.month,&dob.year);
        result_display(Register_number,dob);
        break;
    case 3:
        fg = 0;
        break;
    default:
        break;
    }
    }
}

void registation(){                         //Registation process.
    FILE *coordiatorfile;
    coordiatorfile = fopen("User.bin","ab");
    user registation;
    printf("NAME : ");
    scanf("%s",registation.Name);
    printf("DEPARTMENT : ");
    scanf("%s",registation.Department);
    printf("USERID : ");
    scanf("%s",registation.Id);
lb:  printf("PASSWORD : ");
    scanf("%s",registation.password);
    int len = strlen(registation.password);
    if(len <= 4){
        printf("Password is weak\nHas to have more than 8 characters\n");
        goto lb;
    }
    fwrite(&registation,sizeof(user),1,coordiatorfile);
    printf("Registed successfully!!\nLogin to enter Marks\n");
    fclose(coordiatorfile);
}

int login(){
    char userid[20];
    char userpassword[20];
    printf("User Id : ");
    scanf("%s",&userid);
    printf("Password : ");
    scanf("%s",&userpassword);
    user user;
    FILE *coordiatorfile;
    coordiatorfile = fopen("User.bin","rb");
    while (fread(&user,sizeof(user),1,coordiatorfile))
    {   //checking userid and password
        if((!strcmp(user.Id,userid)) && (!strcmp(user.password,userpassword))){
            printf("Login Successfully!!\n");
            return 1;       
        }              
    }
    printf("Wrong password or user Id\n");
    printf("if new, Register \n");
    fclose(coordiatorfile);
    return 0;
}

void mark_entry(){
    int number_of_students;
    printf("Enter Total Number of Students : ");
    scanf("%d",&number_of_students);
    student student;
    printf("Enter number of semester : ");
    scanf("%d",&student.no_of_semester);
    for(int i = 0;i<student.no_of_semester;i++){
        printf("Enter no of subjects in semester %d :",i+1);
        scanf("%d",&student.semester[i].number_of_subjects);
            for(int j = 0; j < student.semester[i].number_of_subjects;j++){
            printf("Enter subject Names : ");
            fflush(stdin);
            scanf("%[^\n]s",&student.semester[i].subject[j]);
            fflush(stdin);
            printf("Enter the credit of the subject : ");
            fflush(stdin);
            scanf("%d",&student.semester[i].credit[j]);
            fflush(stdin);
        }
    }
    FILE *studentresults;
    //write 
    studentresults = fopen("Student_results.bin","wb");
    for(int i = 0;i<number_of_students;i++){
        printf("Enter Register_number: ");
        scanf("%d",&student.Register_number);
        printf("Enter Date of birth of student: ");
        scanf("%d/%d/%d",&student.DOB.day,&student.DOB.month,&student.DOB.year);
        for(int j = 0;j < student.no_of_semester;j++){
            printf("SEMESTER %d\n",j+1);
            int Total = 0;
            int total_credit = 0;
            printf("%d Subjects\n",student.semester[j].number_of_subjects);
            for (int k = 0; k < student.semester[j].number_of_subjects; k++)
            {  
   label1:   printf("Enter mark in %s ",student.semester[j].subject[k]);
             scanf("%d",&student.semester[j].marks[k]);
                if(!(student.semester[j].marks[k] >= 0 && student.semester[j].marks[k] <= 100)){
                    printf("Enter valid marks\n");
                    goto label1;
                }
                if(student.semester[j].marks[k] < 35){
                    student.semester[j].grade[k] = 'F';
                }
                if(student.semester[j].marks[k] >= 35 && student.semester[j].marks[k] < 60){
                    student.semester[j].grade[k] = 'C';
                }
                if(student.semester[j].marks[k] >= 60 && student.semester[j].marks[k] < 75){
                    student.semester[j].grade[k] = 'B';
                }
                if(student.semester[j].marks[k] >= 75 && student.semester[j].marks[k] < 85){
                    student.semester[j].grade[k] = 'A';
                }
                if(student.semester[j].marks[k] >= 85 && student.semester[j].marks[k] <= 100){
                    student.semester[j].grade[k] = 'O';
                }
                Total = Total + ((student.semester[j].marks[k]/10) * (student.semester[j].credit[k]));
                total_credit = total_credit + student.semester[j].credit[k];
            }
            student.semester[j].gpa = Total / (float)total_credit;         
        }
        fwrite(&student,sizeof(student),1,studentresults);
    } 
    fclose(studentresults);  
}

void result_display(int Register_Number,date dob){
    FILE *student_results;
    student student;
    student_results = fopen("Student_results.bin","rb");
    while (fread(&student,sizeof(student),1,student_results))
    {   
        if(student.Register_number == Register_Number && ((student.DOB.day == dob.day) &&(student.DOB.month == dob.month) && (student.DOB.year == dob.year))){
            printf("Register Number: %d\n",student.Register_number);
            for(int i = 0;i<student.no_of_semester;i++){
                printf("====================================\n");
                printf("Semester %d subject marks\n",i+1);
                for(int j = 0;j < student.semester[i].number_of_subjects;j++){
                    printf(" %s  :  %c  \n",student.semester[i].subject[j],student.semester[i].grade[j]);
                    printf("--------------------------------\n");
                }
                printf("Semester %d gpa : %.2f\n",i+1,student.semester[i].gpa);
            }
        }
    }
    fclose(student_results);
}
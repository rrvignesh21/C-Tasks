#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Build the basic management application by your own choice using functions. */
int option = 0;
int i = 0;
int n = 0;
int j = 0;
float present = 75.00;
char money = 'P';
float tdays = 1;
 

struct student {
    int id;
    char name[20];
    int rno;
    char fees;
    float days;
    float attend;
} s[50];
 

void add(struct student s[]);
void addnewStudent(struct student s[]);
void eligibleStudents(struct student s[]);
void execute();
void printStudents(struct student s[]);
void deleteRecord(struct student s[]);
 

void execute()
{
    printf(
        " Enter the serial number"
        "to select the option \n");
    printf(" 1. To add New Student \n");
    printf(" 2. To show Eligible"
           "candidates \n");
    printf(" 3. To delete the "
           "student record \n");
    printf(" 4. To change the "
           "eligibility criteria \n");
    printf(" 5. Reset the "
           "eligibility criteria \n");
    printf(" 6. Print the list "
           "of all the student \n");
    printf(" Enter 0 to exit \n");
 
    scanf("%d", &option);
 

    switch (option) {
    case 1:
        addnewStudent(s);
        execute();
        break;
    case 2:
        eligibleStudents(s);
        execute();
        break;
 
    case 3:
        deleteRecord(s);
        execute();
        break;
 
    case 4:
        printf("Old Attendance "
               "required = %f",
               present);
        printf(
            "\n Enter the updated "
            "attendence required \n");
        scanf("%f", &present);
        printf("fees status required"
               " was %c \n",
               money);
        printf("Enter the new fees "
               "status 'P' for paid 'N' "
               "for not paid and "
               "'B' for both \n");
        scanf("%c", &money);
        printf("Eligibility Criteria updated \n");
        execute();
        break;
 
    case 5:
        present = 75.00;
        money = 'P';
        printf("Eligibility creitria reset \n");
        execute();
        break;
 
    case 6:
        printStudents(s);
        execute();
        break;
 
    case 7:
        execute();
        break;
    case 0:
        exit(0);
 
    default:
        printf("Enter number only from 0-4 \n");
        execute();
    }
}
void addnewStudent(struct student s[]){
    if(n > 50){
        printf("Can't add ");
    }
    else{
    printf("Student number %d \n",
               (n - 1));
 
        printf("Enter the name of"
               " the student \n");
        scanf("%s", s[n].name);
 
        printf("Enter the roll number \n");
        scanf(" %d", &s[n].rno);
 
        printf("Enter the fees of the"
               "student 'P' for paid "
               ", 'N' for not paid \n");
        scanf(" %c", &s[n].fees);
 
        printf("Enter the number of"
               "days the student was "
               "present \n");
        scanf("%f", &s[n].days);
 
        s[n].attend = (s[n].days
                       / tdays)
                      * 100;
        printf("student attendence = %f \n",
               s[n].attend);
    }
    n = n + 1;
    
}

void printStudents(struct student s[])
{
    for (i = 0; i < n; i++) {
 
        printf("Name of student %s \n",
               s[i].name);
        printf("Student roll number = %d \n",
               s[i].rno);
        printf("Student fees status = %c \n",
               s[i].fees);
        printf("Student number of days "
               "present = %f \n",
               s[i].days);
        printf("Student attendence = %f \n",
               s[i].attend);
        printf("_________________________\n");
    }
}
 

void deleteRecord(struct student s[])
{
    int a = 0;
    printf("Enter the roll number of "
           "the student to delete it ");
    scanf("%d", &a);
 

    for (i = 0; i <= n; i++) {

        if (s[i].rno == (a)) {
 

             for (int j = i - 1; i < n - 1; i++)  
        {  
            s[i] = s[i+1]; 
        } n--;
            printf("Student Record deleted");
        }
    }
}
 

void eligibleStudents(struct student s[])
{
    printf("\n");
    printf("Qualified student are = \n");
 

    for (i = 0; i < n; i++) {

        if (s[i].fees == money || 'B' == money) {
            if (s[i].attend >= present) {
                printf("Student name = %s \n",
                       s[i].name);
                printf("Student roll no. = %d \n",
                       s[i].rno);
                printf(" Student fees = %c \n",
                       s[i].fees);
                printf(" Student attendence = %f \n",
                       s[i].attend);
            }
        }
    }
}
 
void add(struct student s[50])
{
    printf("Enter the total ");
    printf("number of working days \n");
    scanf("%f", &tdays);
 
    printf("Enter the number");
    printf("of students \n");
    scanf("%d", &n);
    if(n <= 50){
    for (i = 0; i < n; i++) {
 
        printf("Student number %d \n",
               (i + 1));
 
        printf("Enter the name of"
               " the student \n");
        scanf("%s", s[i].name);
 
        printf("Enter the roll number \n");
        scanf(" %d", &s[i].rno);
 
        printf("Enter the fees of the"
               "student 'P' for paid "
               ", 'N' for not paid \n");
        scanf(" %c", &s[i].fees);
 
        printf("Enter the number of"
               "days the student was "
               "present \n");
        scanf("%f", &s[i].days);
 
        s[i].attend = (s[i].days
                       / tdays)
                      * 100;
        printf("student attendence = %f \n",
               s[i].attend);
    }
    }
    else{
        printf("Cant do this:");
    }
    execute();
}
 

int main()
{
    printf("Welcome to Student "
           "database registration \n");
 
    printf("Enter 0 to exit \n");
    printf("Enter 1 to add student"
           " record \n");
 
    scanf("%d", &option);

    switch (option) {
    case 0:
        exit(0);
 
    case 1:
        add(s);
        break;
 
    default:
        printf("Only enter 0 or 1");
        execute();
    }
    return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
/*   Create a Library management system using C file system.It should follows the below scenarios,

    Display the front screen having two options 1. Books Issue 2.Books Return 

    After clicking the respective numbers it should move to the corresponding menu

    In Books issue:

    ➤ Get the inputs like Stud_name,Stud_Regno,Stud_Dept,No of books, Books ID, Issued date, returning date.

    ➤ Store those information on a file system

    In Books Return page:

    ➤ Type the Register number (Stud_Regno)

    ➤ It should display the information about the student like name, department,books issued, no of books, due date and due amount.

    ➤ After clicking returned option by admin or library manager the corresponding information about the student must be deleted.

    ➤ Then store the returned candidates information in the another file */
struct Date{
    int day;
    int month;
    int year;
};
typedef struct Date date;

struct Book{
    int Book_Id;
    char Book_Name[20];
};
typedef struct Book book;

struct Library
{
    int number_of_books;
    book books[20];
    int issued_books;
};

struct Student_detail
{
    char Stud_name[20];
    int Stud_Regno;
    char Stud_Dept[20];
    int No_of_books;
    book book[5];
    date Issued_date;
    date returning_date;
};
typedef struct Student_detail student;

void bookissue();
int validate_date(int dd,int mm,int yy,int curyy);
date difference_btw_date(date date1,date date2);
void readfile(FILE *file);
date search(int Register_number);
void Returned_Book(int Register_number,date return_date);

void main(){
    int choice;
    int fg = 1;
    while(fg){
    printf("\t\t\t1. Book Issue\n\n\t\t\t2. Book Return\n\n\t\t\t3.Exit\n");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        printf("Book Issue:\n");
        bookissue();
        break;
    case 2:
        int Register_number;
        printf("Enter Register Number: ");
        scanf("%d",&Register_number);
        date return_date = search(Register_number);
        int choice2;
        printf("Book Return \n");
        printf("1.Return Book\n2.Display all Student date\n3.Display date of student who returned books\n");
        scanf("%d",&choice2);

        switch (choice2)
        {
        case 1:
            if(return_date.day == -1){
                printf("There is no student with %d register number\n",Register_number);
            }
            else{
            Returned_Book(Register_number,return_date);
            printf("Book returned.\n");
            }
            break; 
        case 2:
            printf("===============================================\n");
            FILE *issuedfile;
            issuedfile = fopen("students_detail.bin","rb");
            readfile(issuedfile);
            break;
        case 3:
            FILE *returnedfile;
            returnedfile = fopen("returned_Canditates.bin","rb");
            readfile(returnedfile);
            break;
        
        default:
            break;
        }
        break;
    case 3:
        fg = 0;
        break;

    default:
        break;
    }    
}
}

void readfile(FILE *file){       //Reading File

    student student;
    while (fread(&student,sizeof(student),1,file))
    {
        printf("Student Name: %s\n",student.Stud_name);
        printf("Roll Number: %d\n",student.Stud_Regno);
        printf("Department: %s\n",student.Stud_Dept);
        printf("No of Books: %d\n",student.No_of_books);
        printf("Books: ");
        for(int i = 0;i<student.No_of_books;i++){
            printf("Id : %d\n",student.book[i].Book_Id);
            printf("Name : %s\n\n",student.book[i].Book_Name);
        }
        printf("\n");
        printf("Issue Date: %d/%d/%d\n",student.Issued_date.day,student.Issued_date.month,student.Issued_date.year);
        printf("Return Date: %d/%d/%d\n",student.returning_date.day,student.returning_date.month,student.returning_date.year);
        printf("================================================================================\n");
    }
    fclose(file);
}

void bookissue(){           //Issue Books
    FILE *issuefile;
    issuefile = fopen("students_detail.bin","ab");
    student student;
    printf("Enter Student Name: ");
    scanf("%s",&student.Stud_name);

    printf("Enter Student Register number: ");
    scanf("%d",&student.Stud_Regno);

    printf("Enter Student Department: ");
    scanf("%s",&student.Stud_Dept);

book: printf("Enter No of Books: ");
    scanf("%d",&student.No_of_books);
    if(student.No_of_books > 5){
        printf("Can't issue more than 5 books\n");
        printf("Maximum 5 books\n");
        goto book;  
    }

    printf("Enter Book details : \n");
    for(int i = 0;i < student.No_of_books;i++){
        printf("Enter Book Id: ");
        scanf("%d",&student.book[i].Book_Id);
        getchar();
        printf("Enter Book Name : ");
        //scanf("%s",&student.book[i].Book_Name);
        gets(student.book[i].Book_Name);
        printf("\n");
    }
    time_t stime;
    time(&stime);
    struct tm *timeinfo; 
    timeinfo = localtime(&stime);
    student.Issued_date.year = timeinfo->tm_year + 1900;
    student.Issued_date.month = timeinfo->tm_mon + 1;
    student.Issued_date.day = timeinfo->tm_mday;  
rdate:  printf("Enter returning date [Maximum 1 month]: ");
        scanf("%d/%d/%d",&student.returning_date.day,&student.returning_date.month,&student.returning_date.year);
        if(!validate_date(student.returning_date.day,student.returning_date.month,student.returning_date.year,student.Issued_date.year)){
            printf("Invalid Date!!!\n");
            printf("Enter valid Date :\n");
            goto rdate;
        }
        date difference = difference_btw_date(student.Issued_date,student.returning_date);
        if(difference.month > 1){
            printf("Invalid Date!!!\n");
            printf("Enter valid Date :\n");
            goto rdate;
        }
        if(difference.year < 0 || difference.year > 1){
            printf("Invalid Date!!!\n");
            printf("Enter valid Date :\n");
            goto rdate;
        }
    fwrite(&student,sizeof(student),1,issuefile); 
    fclose(issuefile);
}

void Returned_Book(int Register_number,date return_date){    // Removing returned students info from Issue file
    FILE *issuefile;                        //appending Student date who returned the Books    
    FILE *tempfile;
    FILE *returnedfile;
    student student;
    issuefile = fopen("students_detail.bin","rb");
    tempfile = fopen("temp.bin","wb");
    returnedfile = fopen("returned_Canditates.bin","ab");
    while (fread(&student,sizeof(student),1,issuefile))
    {
        if(student.Stud_Regno == Register_number){
        student.returning_date = return_date;
        fwrite(&student,sizeof(student),1,returnedfile);            
        }
        else{
        fwrite(&student,sizeof(student),1,tempfile);
        }
    }
    fclose(issuefile);
    fclose(tempfile);
    fclose(returnedfile);
    issuefile = fopen("students_detail.bin","wb");
    tempfile = fopen("temp.bin","rb");
    while (fread(&student,sizeof(student),1,tempfile))
    {
        fwrite(&student,sizeof(student),1,issuefile);
    }
    fclose(issuefile);
    fclose(tempfile);
    remove("temp.bin");
}

int validate_date(int dd,int mm,int yy,int curyy){
    if(yy>=curyy && yy<=2025)
    {
        //check month
        if(mm>=1 && mm<=12)
        {
            //check days
            if((dd>=1 && dd<=31) && (mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12))
            {
                return 1;
            }
            else if((dd>=1 && dd<=30) && (mm==4 || mm==6 || mm==9 || mm==11))
            {    
                return 1;
            }
            else if((dd>=1 && dd<=28) && (mm==2))
            {
                return 1;
            }
            else if(dd==29 && mm==2 && (yy%400==0 ||(yy%4==0 && yy%100!=0)))
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}

date difference_btw_date(date date1,date date2){    //Getting difference between two dates
        if(date2.day < date1.day)
    {      

        if (date2.month == 3)
        {

            if ((date2.year % 4 == 0 && date2.year % 100 != 0) || (date2.year % 400 == 0)) 
            {
                date2.day += 29;
            }

            else
            {
                date2.day += 28;
            }                        
        }
        // borrow days from Apr or June or Sep or Nov
        else if (date2.month == 5 || date2.month == 7 || date2.month == 10 || date2.month == 12) 
        {
           date2.day += 30; 
        }

        // borrow days from Jan or Mar or May or July or Aug or Oct or Dec
        else
        {
           date2.day += 31;
        }

        date2.month  = date2.month  - 1;
    }

    if (date2.month  < date1.month )
    {
        date2.month  += 12;
        date2.year -= 1;
    }       
    date difference_btw_dates;
    difference_btw_dates.day = date2.day - date1.day;
    difference_btw_dates.month = date2.month - date1.month;
    difference_btw_dates.year = date2.year - date1.year;
    return  difference_btw_dates;
}

date search(int Register_number){        //searching and displaying student info using Registration number
    FILE *issuefile;
    student student;
    issuefile = fopen("students_detail.bin","rb");
    while (fread(&student,sizeof(student),1,issuefile))
    {
        if(student.Stud_Regno == Register_number){
        printf("Student Name: %s\n",student.Stud_name);
        printf("Roll Number: %d\n",student.Stud_Regno);
        printf("Department: %s\n",student.Stud_Dept);
        printf("No of Books: %d\n",student.No_of_books);
        printf("Books: \n");
        for(int i = 0;i < student.No_of_books;i++){
            printf("Id : %d \n",student.book[i].Book_Id);
            printf("Book Name : %s\n\n",student.book[i].Book_Name);
        }
        printf("\n");
        
        printf("Issue Date: %d/%d/%d\n",student.Issued_date.day,student.Issued_date.month,student.Issued_date.year);

        struct tm duedatestruct = { .tm_year = student.Issued_date.year - 1900,.tm_mon = student.Issued_date.month - 1,.tm_mday = student.Issued_date.day }; 
        duedatestruct.tm_mday += 30;
        mktime(&duedatestruct);
        date due_date;
        due_date.year = duedatestruct.tm_year + 1900;
        due_date.month = duedatestruct.tm_mon + 1;
        due_date.day = duedatestruct.tm_mday;
        printf("Due Date: %d/%d/%d\n",due_date.day,due_date.month,due_date.year);
        date returned_date;
la:     printf("Book returned date :");
        scanf("%d/%d/%d",&returned_date.day,&returned_date.month,&returned_date.year);
        if(!validate_date(returned_date.day,returned_date.month,returned_date.year,student.Issued_date.year)){
            printf("Enter valid Date:\n");
            goto la;
        }
        if(returned_date.year < student.returning_date.year){
            printf("Enter valid Date:\n");
            goto la;
        }
        date difference_btw_dates = difference_btw_date(due_date,returned_date);        
        int due_amount = dueCalculation(difference_btw_dates);
        printf("Due Amount = %d Rupees\n",due_amount);
        printf("=====================================================================================\n");
        return returned_date;
        }
    }
    printf("There no student with %d roll number is here",Register_number);
    date false_date;
    false_date.day = -1;
    false_date.month = -1;
    false_date.year = -1;
    return false_date;
}

int dueCalculation(date difference){            //Calculating Due fee.
    int due = 1;
    int due_amount;
    due_amount = ((difference.year * 365)*due) + ((difference.month * 30)*due) + ((difference.day)*due);
    return due_amount;
}

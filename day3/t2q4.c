#include<stdio.h>
/* Create a structure called Date and calculate the difference between the two dates.
 */
struct date
{
    int day;
    int month;
    int year;
};


int valid_date(int day, int mon, int year)    
{
    int is_valid = 0;
    if(mon >= 1 && mon <= 12)
        {
       if (mon == 2)
       {
                if (day <= 29 && day > 0) 
                {
                    is_valid = 1;
                }
                else{
                    is_valid = 0;
                }
            }
            else if (mon == 4 || mon == 6 || mon == 9 || mon == 11) 
            {
                if (day > 30)
                {
                    is_valid = 0;
                }
            }
            else if(day > 31)
            {            
                is_valid = 0;
            }        
        }

        else
        {
            is_valid = 1;
        }

    return is_valid;

}
void main(){
    struct date d1;
    struct date d2;
    struct date res;
    printf("enter 1st date (day month year):");
    scanf("%d %d %d",&d1.day,&d1.month,&d1.year);
    printf("%d %d %d",d1.day,d1.month,d1.year);
    printf("enter 2st date (day month year):");
    scanf("%d %d %d",&d2.day,&d2.month,&d2.year);
    if((valid_date(d1.day,d1.month,d1.year))&&(valid_date(d2.day,d2.month,d2.year))){
    if(d2.day < d1.day){
        if(d2.month == 3){
            d2.day += 28;
        }
        else if (d2.month == 5 || d2.month == 7 || d2.month == 10 || d2.month == 12) 
        {
           d2.day += 30; 
        }
        else
        {
           d2.day += 31;
        }
        d2.month -= 1;
    }
    if(d2.month > d1.month){
        d2.month += 12;
        d2.year -= 1;
    }

    res.day = d2.day - d1.day;
    res.month = d2.month - d1.month;
    res.year = d2.year - d1.year;
    printf("Difference: %d years,%d months,%d days",res.year,res.month,res.day);
    }
    else{
        printf("invalid dates");
    }
}

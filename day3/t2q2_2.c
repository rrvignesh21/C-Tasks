#include <stdio.h>

struct date{
      int day;
      int month;
      int year;
   };
struct details
{
    char name[20];
    int price;
    int code;
    int qty;
    struct date date;
};

struct customers
{
    int id;
    char name[20];
    int phonenumber;
    struct details items[];
};
struct data{
    struct customers c;
    struct customers *next;    
};
void add(struct data *d){
    
}
void main(){


}
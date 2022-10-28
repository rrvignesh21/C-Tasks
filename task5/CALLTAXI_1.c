#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct Record
{
    int customer_Id;
    //taxi current_taxi;
    char From_location[3];
    char To_loaction[3];
    int pickup_Time;
    int DropTime;
    int cost;
};
typedef struct Record record;

struct Taxi
{
    int taxi_Id;
    char current_location[3];
    int current_time;
    int earning;
    int number_of_booking;
    record taxirecord[50];
};
typedef struct Taxi taxi;

taxi *inizialize_Taxi(int n);
int allocating_Taxi(int customer_id,char pickup_point[],char drop_point[],int pickup_time,int n,taxi *taxi[]);
int check_location(char location);
int taxi_charge(int distance);
int distance(char start,char stop);
void Booking(int customer_id,char pickup_point[],char drop_point[],int pickup_time,int n,taxi *taxi[]);
void display();

void main(){
    int n = 5;
    
    taxi taxi[] = *inizialize_Taxi(n);
    
    int choice;
    int fg = 1;
    while (fg)
    {   
        printf("1.Booking\n2.Details about Taxi\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            int customer_id;
            char pickup_point[3],drop_point[3];
            int pickup_time;
            printf("\nCustomer Id :");
            scanf("%d",&customer_id);
//l1:
         printf("\npickup point :");
            //pickup_point = getchar();
            scanf("%s",&pickup_point);
         /*   if(check_location(pickup_point)){
                printf("Invalid Location.\n");
                printf("Enter valid location:\n");
                goto l1;
            }*/
//l2:         
            printf("\ndrop point :");
            scanf("%s",&drop_point);
            /*if(check_location(drop_point)){
                printf("Invalid Location.\n");
                printf("Enter valid location:\n");
                goto l2;
            }*/
l3:         printf("\npickup time :");
            scanf("%d",&pickup_time);
            if(!(pickup_time >=0 && pickup_time <= 23)){
                printf("Enter valid time:\n");
                goto l3;
            }
            int allocated_taxi_id = allocating_Taxi(customer_id,pickup_point,drop_point,pickup_time,n,&taxi);
            if(allocated_taxi_id == -1){
                printf("Taxi cant be allocated\n");
            }
            else{
                printf("Taxi - %d is allocated\n",allocated_taxi_id);
                int i = distance(pickup_point[0],drop_point[0]);
                printf("distance : %d\n",i);
                Booking(customer_id,pickup_point,drop_point,pickup_time,n,&taxi);
            }
            break;
        case 2:
            display(taxi,n);
            break;
        case 3:
            fg = 0;
            break;
        default:
            break;
        }
    }
}

taxi *inizialize_Taxi(int n){
    taxi taxies[n];
    for(int i = 0;i<n;i++){
        taxies[i].taxi_Id = i+1;
        taxies[i].current_location[0] = 'A';
        taxies[i].earning = 0;
        taxies[i].number_of_booking = 0;
        taxies[i].current_time = 0;
    }
    return taxies;
}

int distance(char start,char stop){
    int distance = start - stop;
    return abs(distance);
}

int allocating_Taxi(int customer_id,char pickup_point[],char drop_point[],int pickup_time,int n,taxi *taxi[]){
    int index = 0;
    int minimum_earning;
    int minimum_distance = 6;
    int allocated_taxi_id = -1;
    int distance_between_taxi_pickup_point;
    for(int i = 0;i<n;i++){
        if(taxi[i]->taxi_Id == 1){
        minimum_earning = taxi[i]->earning;
        allocated_taxi_id = taxi[i]->taxi_Id;
        }
        distance_between_taxi_pickup_point = distance(taxi[i]->current_location[0],pickup_point[0]);
        if(pickup_time >= taxi[i]->current_time){
        if(distance_between_taxi_pickup_point == 0){
                if(minimum_earning >= taxi[i]->earning){
                        minimum_earning = taxi[i]->earning;
                        allocated_taxi_id = taxi[i]->taxi_Id;
                        minimum_distance = 0;
                    }
                if(minimum_earning > taxi[i]->earning){
                    minimum_earning = taxi[i]->earning;
                }
        }
        else if(distance_between_taxi_pickup_point <= minimum_distance){
            if((minimum_earning > taxi[i]->earning) && (distance_between_taxi_pickup_point <= minimum_distance)){
                        minimum_earning = taxi[i]->earning;
                        allocated_taxi_id = taxi[i]->taxi_Id;
                    }
            if(minimum_distance > distance_between_taxi_pickup_point){
                minimum_distance = distance_between_taxi_pickup_point;
                }
            }
        }
    }
    return allocated_taxi_id;
}

void Booking(int customer_id,char pickup_point[],char drop_point[],int pickup_time,int n,taxi *taxi[]){
    int allocated_taxi_id = allocating_Taxi(customer_id,pickup_point,drop_point,pickup_time,n,taxi);
    if(allocated_taxi_id > 0 ){
    for(int i= 0;i<n;i++){

        if(allocated_taxi_id == taxi[i]->taxi_Id){
            taxi[i]->taxirecord[taxi[i]->number_of_booking].customer_Id = customer_id;
            taxi[i]->taxirecord[taxi[i]->number_of_booking].From_location[0] = pickup_point[0];
            taxi[i]->taxirecord[taxi[i]->number_of_booking].To_loaction[0] = drop_point[0];
            taxi[i]->taxirecord[taxi[i]->number_of_booking].pickup_Time = pickup_time;
            taxi[i]->taxirecord[taxi[i]->number_of_booking].DropTime = pickup_time + distance(pickup_point[0],drop_point[0]);
            taxi[i]->taxirecord[taxi[i]->number_of_booking].cost = earning(distance(pickup_point[0],drop_point[0]));
            taxi[i]->earning = taxi[i]->earning + taxi[i]->taxirecord[taxi[i]->number_of_booking].cost;
            taxi[i]->number_of_booking = taxi[i]->number_of_booking + 1;
            taxi[i]->current_location[0] = drop_point[0];
            taxi[i]->current_time = pickup_time + distance(pickup_point[0],drop_point[0]);
        }
        } 
    }
}

void display(taxi taxi[],int n){

    for(int i= 0;i<n;i++){
        printf("taxi Id = %d\n",taxi[i].taxi_Id);
        printf("taxi_cuurent location:%c",taxi[i].current_location[0]);
        printf("taxi current time : %d",taxi[i].current_time);
        printf("taxi earning : %d\n",taxi[i].earning);
        printf("customer id   from   to   pickuptime   Droptime   Amount \n");
        for(int j = 0;j<taxi[i].number_of_booking;j++){
                printf("%d   ",taxi[i].taxirecord[j].customer_Id);
                printf("%c   ",taxi[i].taxirecord[j].From_location[0]);
                printf("%c   ",taxi[i].taxirecord[j].To_loaction[0]);
                printf("%d   ",taxi[i].taxirecord[j].pickup_Time);
                printf("%d   ",taxi[i].taxirecord[j].DropTime);
                printf("%d   ",taxi[i].taxirecord[j].cost);
                printf("\n");
            }
            printf("\n");
        }
}
/*
int  check_location(char location){
    if((!strcmp(location,'A'))||(!strcmp(location,'B'))||(!strcmp(location,'C'))||(!strcmp(location,'D'))||(!strcmp(location,'E'))|| (!strcmp(location,'F'))){
        return 1;
    }
    else{
        return 0;
    }
}*/

int earning(int distane){
    int earning = ((((distane)*15)-5)*10) + 100;
    return earning;
}
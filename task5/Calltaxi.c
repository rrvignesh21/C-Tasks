#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct Record
{
    int customer_Id;
    char From_location[3];
    char To_location[3];
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

void inizialize_Taxi(int n);
int allocating_Taxi(int customer_id,char pickup_point[],char drop_point[],int pickup_time);
int check_location(char location);
int taxi_charge(int distance);
int distance(char start,char stop);
void Booking(int customer_id,char pickup_point[],char drop_point[],int pickup_time);
void display();
int earning(int distance);

void main(){
    int n = 4;
    inizialize_Taxi(n);
    int choice;
    int fg = 1;
    while (fg)
    {   
        printf("\t\t\t1.Booking\n\t\t\t2.Details about Taxi\n\t\t\t3.Exit\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            int customer_id;
            char pickup_point[3],drop_point[3];
            int pickup_time;
            printf("\nCustomer Id :");
            scanf("%d",&customer_id);
l1:         printf("\npickup point :");
            //pickup_point = getchar();
            scanf("%s",&pickup_point);
            if(!check_location(pickup_point[0])){
                printf("Invalid Location.\n");
                printf("Enter valid location:\n");
                goto l1;
            }
l2:         printf("\ndrop point :");
            scanf("%s",&drop_point);
            if(!check_location(drop_point[0])){
                printf("Invalid Location.\n");
                printf("Enter valid location:\n");
                goto l2;
            }
l3:         printf("\npickup time :");
            scanf("%d",&pickup_time);
            if(!(pickup_time >=0 && pickup_time <= 23)){
                printf("Enter valid time:\n");
                goto l3;
            }
            int allocated_taxi_id = allocating_Taxi(customer_id,pickup_point,drop_point,pickup_time);
            if(allocated_taxi_id == -1){
                printf("Taxi cant be allocated\n");
            }
            else{
                printf("Taxi - %d is allocated\n",allocated_taxi_id);
                Booking(customer_id,pickup_point,drop_point,pickup_time); 
            }
            break;
        case 2:
            display();
            break;
        case 3:
            fg = 0;
            break;
        default:
            break;
        }
    }
}

void inizialize_Taxi(int n){            //inizializing n number of taxies to defailt values
    FILE *taxi_details;
    taxi_details = fopen("Taxi.bin","wb");
    taxi taxi;
    for(int i = 0;i<n;i++){
        taxi.taxi_Id = i+1;
        taxi.current_location[0] = 'A';
        taxi.earning = 0;
        taxi.number_of_booking = 0;
        taxi.current_time = 0;
        fwrite(&taxi,sizeof(taxi),1,taxi_details);
    }
    fclose(taxi_details);
}

int distance(char start,char stop){ //calculating distance between two points 
    int distance = start - stop;
    return abs(distance);
}

//ckecking if taxi is free and allocation the taxi
int allocating_Taxi(int customer_id,char pickup_point[],char drop_point[],int pickup_time){
    FILE *taxi_details;                 
    taxi taxi;
    int index = 0;
    int minimum_earning;                    //for keep track of minimum earnimg if there is more than one taxies in a point
    int minimum_distance = 6;
    int allocated_taxi_id = -1;             
    int traveling_time;                     
    int distance_between_taxi_pickup_point;
    int i = 0,j = 0;                        //for taxis located in same point or at equal distance 
    taxi_details = fopen("Taxi.bin","rb");
    while (fread(&taxi,sizeof(taxi),1,taxi_details)){
        distance_between_taxi_pickup_point = distance(taxi.current_location[0],pickup_point[0]);
        traveling_time = taxi.current_time + distance_between_taxi_pickup_point;
        if((pickup_time >= taxi.current_time) && (traveling_time <= pickup_time)){
        if(distance_between_taxi_pickup_point == 0){    //checking if is there taxi available in pickup point
            if(i == 0){
                minimum_earning = taxi.earning;
                allocated_taxi_id = taxi.taxi_Id;
                i++;
            }
            if(minimum_earning >= taxi.earning){ 
                        allocated_taxi_id = taxi.taxi_Id;
                        minimum_earning = taxi.earning;
                        minimum_distance = 0;
                    }
        } 
        //checking if there is taxi avaliable near pickup point
        else if(distance_between_taxi_pickup_point <= minimum_distance){
            if(j == 0){
                minimum_earning = taxi.earning;
                allocated_taxi_id = taxi.taxi_Id;
                minimum_distance = distance_between_taxi_pickup_point;
            }
            if((minimum_earning >= taxi.earning) && (distance_between_taxi_pickup_point <= minimum_distance)){
                        minimum_earning = taxi.earning;
                        allocated_taxi_id = taxi.taxi_Id;
                    }
            if(minimum_distance > distance_between_taxi_pickup_point){
                minimum_distance = distance_between_taxi_pickup_point;
                }
            }
        }
    }
    return allocated_taxi_id;
}

//making changes to taxi details file about new booking taxi.
void Booking(int customer_id,char pickup_point[],char drop_point[],int pickup_time){
    FILE *taxi_details,*temp_file;
    taxi taxi;
    int allocated_taxi_id = allocating_Taxi(customer_id,pickup_point,drop_point,pickup_time);
    taxi_details = fopen("Taxi.bin","rb");
    temp_file = fopen("temp.bin","wb");
    if(allocated_taxi_id > 0 ){
    while(fread(&taxi,sizeof(taxi),1,taxi_details)){
        if(allocated_taxi_id == taxi.taxi_Id){
            taxi.taxirecord[taxi.number_of_booking].customer_Id = customer_id;
            taxi.taxirecord[taxi.number_of_booking].From_location[0] = pickup_point[0];
            taxi.taxirecord[taxi.number_of_booking].To_location[0] = drop_point[0];
            taxi.taxirecord[taxi.number_of_booking].pickup_Time = pickup_time;
            taxi.taxirecord[taxi.number_of_booking].DropTime = (pickup_time + distance(pickup_point[0],drop_point[0])) % 24;
            taxi.taxirecord[taxi.number_of_booking].cost = earning(distance(pickup_point[0],drop_point[0]));
            taxi.earning = taxi.earning + taxi.taxirecord[taxi.number_of_booking].cost;
            taxi.number_of_booking = taxi.number_of_booking + 1;
            taxi.current_location[0] = drop_point[0];
            taxi.current_time = (pickup_time + distance(pickup_point[0],drop_point[0])) % 24;
        }
        fwrite(&taxi,sizeof(taxi),1,temp_file);
        }
    fclose(taxi_details);
    fclose(temp_file);
    taxi_details = fopen("Taxi.bin","wb");
    temp_file = fopen("temp.bin","rb");
    while (fread(&taxi,sizeof(taxi),1,temp_file))
    {
        fwrite(&taxi,sizeof(taxi),1,taxi_details);
    }
    fclose(taxi_details);
    fclose(temp_file);
    remove("temp.bin");   
    }
}

void display(){
    FILE *taxi_details;
    taxi taxi;
    taxi_details = fopen("Taxi.bin","rb");
    while(fread(&taxi,sizeof(taxi),1,taxi_details)){
        printf("taxi Id : %d\t\t\t",taxi.taxi_Id);
        printf("Total earning : %d\n",taxi.earning);
        printf("              \n\n");
        printf("customer id\tfrom\tto\tpickuptime\tDroptime\tAmount\t\n");
        for(int i = 0;i<taxi.number_of_booking;i++){
                printf("  %d ",taxi.taxirecord[i].customer_Id);
                printf("\t\t%c\t",taxi.taxirecord[i].From_location[0]);
                printf("%c\t",taxi.taxirecord[i].To_location[0]);
                printf("\t%d\t",taxi.taxirecord[i].pickup_Time);
                printf("%d\t",taxi.taxirecord[i].DropTime);
                printf("\t%d\t",taxi.taxirecord[i].cost);
                printf("\n");
            }
            printf("---------------------------------------------------------------------------------\n");
            printf("\n");
        }
}

int check_location(char location){             // checking the points is valid or not
    if((location == 'A')||(location =='B')||(location == 'C')||(location == 'D')||(location =='E')|| (location == 'F')){
        return 1;
    }
    else{
        return 0;
    }
}

int earning(int distance){                       //calculating earning 
    int earning = ((((distance)*15)-5)*10) + 100;
    return earning;
}




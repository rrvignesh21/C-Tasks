#include<stdio.h>
/* Add two distances and also convert inches into feet and vice-versa using structure (in inch-feet) */
struct distance
{
    int feet;
    int inch;
};

void main(){
    struct distance d1;
    struct distance d2;
    struct distance res;
    printf("enter 1st distance:\n");
    printf("enter feet: ");
    scanf("%d",&d1.feet);
    printf("\nenter inch: ");
    scanf("%d",&d1.inch);
    printf("enter 2nd distance:\n");
    printf("enter feet: ");
    scanf("%d",&d2.feet);
    printf("\nenter inch: ");
    scanf("%d",&d2.inch);
    res.feet = d1.feet + d2.feet;
    res.inch = d1.inch + d2.inch;
    while(res.inch >= 12){
        res.inch = res.inch - 12;
        ++res.feet;
    }
    printf("\n Sum of two distance = %dfeet %dinch",res.feet,res.inch);

    
}
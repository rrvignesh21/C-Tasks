#include<stdio.h>

#define MAX(x,y) ((x > y) ? x:y)
#define SQUARE(x) (x * x)
#define CUBE(sqr) (SQUARE(sqr) * sqr)
#define POWR(x,p) { int res = x; if (p == 1){printf("%d",x);} for(int i = 1;i<p;i++){res = res * res;}printf("%d",res);}
#define PROD(x,y) { int res = 0; for(int i = 0;i<y;i++){ res = res + x; }printf("%d",res);}                       
                                                                                      


void main(){
    char fn;
    while (fn != 'e')
    {       
    printf("\nenter operation(a/b/c/d): ");
    fn = getchar();
    switch (fn)
    {
    case ('a'):
        printf("Maximum of two numbers:\n");
        int x,y;
        printf("enter two number: ");
        scanf("%d",&x);
        scanf("%d",&y);
        printf("maximum of two number is %d",MAX(x,y));
        break;
    case ('b'):
        printf("Cube of Number\n");
        int a;
        printf("enter the number: ");
        scanf("%d",&a);
        printf("%d",CUBE(a));
        break;
    case('c'):
        printf("power of numbers");
        int X,n;
        printf("Enter number and power: ");
        scanf("%d",&X);
        scanf("%d",&n);
        POWR(X,n);
        break;
    case('d'):
        printf("Product of two numbers: \n");
        int p,d;
        printf("enter two numbers : ");
        scanf("%d",&p);
        scanf("%d",&d);
        PROD(p,d);
        break;
    default:
        break;
    }
    } 
    //POWR(2,3);
    //printf("%d",CUBE(3));
    //PROD(4,3);
}
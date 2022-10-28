#include <stdio.h>
#include <math.h>
/* Write a program in C to perform maths and
 character library function using switch case (use 5 operations on each) */
void main(){
    
    printf("enter math/char function[m/c]: ");
    char mod;
    scanf("%c",&mod);
    char dum;
    scanf("%c",&dum);
    
    switch (mod)
    {
    case ('m'):
        char fun;
        printf("function: ");
        scanf("%c",&fun);
        switch (fun)
        {
        case ('2'):
            int n;
            printf("enter the number to be squared: ");
            scanf("%d",&n);
            printf("%d",n*n);
            break;
        case('e'):
            int en;
            printf("enter the number to e power of x :");
            scanf("%d",&en);
            float res = 2.718;
            for(int i = 2;i<= en;i++){
                res = res * res;
            }
            printf("%f",res);
            break;
        case('c'):
            float nf;
            printf("ceil\n:");
            printf("enter number: ");
            scanf("%f",&nf);
            printf("%f",ceil(nf));
            break;
        case('f'):
            float nf2;
            printf("floor\n:");
            printf("enter the number");
            scanf("%f",&nf2);
            printf("%f",floor(nf2));
            break;
        case('s'):
            int s;
            printf("square root:\n ");
            printf("enter the number: ");
            scanf("%d",&s);
            printf("%d",sqrt(s));
            break;
        
        default:
            printf("invalid operation");
            break;
        }
        break;
    case('c'):
        char cfun;
        printf("enter function :");
        scanf("%c",&cfun);
       char dumi1;
       scanf("%c",&dumi1);

        switch (cfun)
        {
        case ('u'):
            char c;
            printf("enter the char: ");
            scanf("%c",&c);
            int i;
            for (i = 65;i <= 90;i++){
                if (c == i){
                    printf("%c is uppercase",c);
                    break;
                }
            }
            if(i >= 90){

            printf("%c is not uppercase",c);
            }
            break;
        case('l'):
            char lc;
            printf("enter char:");
            scanf("%c",&lc);
            int j;
            for(j = 97;j <= 122;j++){
                if(lc == j){
                    printf("%c is lowercase",lc);
                    break;        
                }
            }
            if (j >= 122){
                printf("%c is not lowercase",lc);
            }
            break;
        case('c'):
            char lowc;
            printf("enter the char: ");
            scanf("%c",&lowc);
            int ic;
            for (ic = 65;ic <= 90;ic++){
                if (lowc == ic){
                    printf("%c is uppercase",lowc);
                    break;
                }
            }
            printf("%c",lowc - 32);
            break;
        case('o'):
            char higc;
            printf("enter the char: ");
            scanf("%c",&higc);
            int jc;
            for (jc = 97;jc <= 122;jc++){
                if (lowc == jc){
                    printf("%c is lowercase",higc);
                    break;
                }
            }
            printf("%c",higc + 32);
            break;
        case('n'):
            char num;
            printf("enter the char: ");
            scanf("%c",&num);
            int kc;
            for (kc = 48;kc <= 57;kc++){
                if (num == kc){
                    printf("%c is a number",num);
                    break;
                }
            }
            if(kc == 58){
            printf("%c is not a number",num);
            }
            break;
        default:
            break;
        }
        break;
    
    default:
        break;
    }
}
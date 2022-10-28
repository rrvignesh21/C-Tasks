#include<stdio.h>
/* Write a program to take input of 5 subject.
 Find total and percent based on percent provide grade like: */
void main(){
    int s1,s2,s3,s4,s5;
    printf("enter subject 1 mark: ");
    scanf("%d",&s1);
    printf("enter subject 2 mark: ");
    scanf("%d",&s2);
    printf("enter subject 3 mark: ");
    scanf("%d",&s3);
    printf("enter subject 4 mark: ");
    scanf("%d",&s4);
    printf("enter subject 5 mark: ");
    scanf("%d",&s5);

    int total = s1+s2+s3+s4+s5;
    int per = (total * 100)/500;
    printf("%d\n",per);
    printf("%d\n",total);

    if(per > 80){
        printf("A+");
    }
    else if((per >= 65)&(per <= 80)){
        printf("A");
    }
    else if ((per >= 50) & (per <= 65))
    {
        printf("B");
    }
    else if((per >= 42) & (per<= 50)){
        printf("C");
    }
    else if(per < 42){
        printf("Fail");
    }

}
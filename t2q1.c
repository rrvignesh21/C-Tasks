#include <stdio.h>
/* The program adds, subtracts, multiplies, and divides simple integers.
 When the program is running, it zeros the result register and displays its contents.
  The user can then type in an operator and number. The result are updated and displayed.
 The following operators are valid: */
void main(){
    int res = 0;
    int b = 1;
    printf("calc");

      int n;
        char c;
    printf("\nResult: %d\n",res);
        printf("Enter operator and number: ");

    while(b){
        printf("Enter operator and number: ");

        scanf("%c",&c);
        scanf("%d",&n);    
   
      
        switch (c)
        {
        case '+':
            res = res + n;
            break;
        case '-':
            res = res - n;
            break;
        case '*':
        res = res * n;
        
        break;
        case '/':
            res = res / n;
            break;
        default:
            b = 0;
            break;
        }
        char s;
        scanf("%c",&s);
        printf("\nResult: %d\n",res);
    }
}
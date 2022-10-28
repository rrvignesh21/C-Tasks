#include<stdio.h>
#include<string.h>
/* Program to evaluate an arithmetic expression using stack. */
int optop = -1;
char opstack [100];
int vltop = -1;
int vlstack[100];


int isempty(int i){
   if(i == -1){
      return 1;
   }
   else{
      return 0;
   }

}
void pushc(char v){
      optop++;
      opstack[optop] = v;
}

void pushin(int i){
      vltop++;
      vlstack[vltop] = i;
}

char popc(){
      char tp = opstack[optop];
      optop--;
      return tp;      
}
int popi(){
      int tp = vlstack[vltop];
      vltop--;
      return tp;
}
int precedence(char op){
    if(op == '+'||op == '-')
    return 1;
    if(op == '*'||op == '/')
    return 2;
    return 0;
}

int opert(int a, int b, char op){
    switch(op){
        case '+':
             return a + b;
        case '-':
             return a - b;
        case '*':
             return a * b;
        case '/':
             return a / b;
    }
}
int isnumber(char c){
   if(c <= '9' && c >='0'){
      return 1;
   }
   else{
      return 0;
   }
}
int res(char s[],int n){
   int i;
   printf("len =  %d\n",n);
   for(int i = 0;i < n; i++){
      printf("char from string = %c\n",s[i]);
      if(s[i] == ' '){
         continue;
      }
      else if(s[i] =='('){
         pushc(s[i]);
      }
      else if(isnumber(s[i])){
         int tp = 0;
         while(i < n && isnumber(s[i])){
            tp = (tp * 10) +(s[i] - '0');
            i++;
         }
         pushin(tp);
         printf("res1 - %d\n",vlstack[vltop]);
         i--;
      }
      else if(s[i] == ')'){
         while(!isempty(optop) && opstack[optop] != '('){
            int v2 = popi();
            int v1 = popi();
            char op = popc();
            printf("%d %c %d\n",v1,op,v2);
            int res = opert(v1,v2,op);
            pushin(res);
         }
         if(!isempty(optop)){
            char tmp = popc();
         }
         }
      else{
            while(!isempty(optop) && precedence(opstack[optop]) >= precedence(s[i])){
               int v2 = popi();
               int v1 = popi();
               char op = popc();
               printf("%d %c %d\n",v1,op,v2);
               int res = opert(v1,v2,op);
               pushin(res);
            }
            pushc(s[i]);
         }
   }

   while(!isempty(optop)){
         int v2 = popi();
         int v1 = popi();
         char op = popc();
         int res = opert(v1,v2,op);
         printf("%d %c %d\n",v1,op,v2);
         
         pushin(res);
      }
      return vlstack[vltop];
   }

void main(){
   char oper[20];
   printf("Enter the expersion: ");
   gets(oper);
   int len = strlen(oper);
   int result = res(oper,len);

   printf("result = %d",result);

}
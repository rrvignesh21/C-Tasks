#include<stdio.h>
/* To read numbers from a file and write even, odd numbers to separate files. */
void main(){
    FILE *nfile,*odd,*even;
    nfile = fopen("numbers.txt","r");
    odd = fopen("odd.txt","w");
    even = fopen("even.txt","w");
    char c = getc(nfile);
    while(c != EOF){
        if(c >= '0' && c <= '9'){
            int i = c - '0';
            if(i % 2 == 0){
                putc(c,even);
            }
            else{
                putc(c,odd);
            }
        }
        c = getc(nfile); 
    }
    fclose(nfile);
    fclose(odd);
    fclose(even);
}
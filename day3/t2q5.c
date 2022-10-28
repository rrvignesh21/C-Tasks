#include<stdio.h>
#include<string.h>
/* Create a structure called Time and convert the time into hours or minutes or seconds. */
struct time{
	int hour;
	int min;
	int sec;
    char p[2];
};
void main()
{
	struct time t;
	printf("Enter time[Hour:Min:Sec]:\n");
	scanf("%d:%d:%d",&t.hour,&t.min,&t.sec);
	printf("Enter AM or PM:\n");
	scanf("%s",t.p);	    
	if(!strcmp(t.p,"PM"))
		t.hour += 12;
	else{
		if(t.hour==12)
			t.hour=0;
	}
    float reshour = 0;
    reshour = t.hour + (t.min / (float)60) + (t.sec / (float)3600);
    printf("\n%f Hours\n",reshour);
    float resmin = 0;
    resmin = (t.hour*60) + t.min +(t.sec/(float)60);
    printf("%f Minutes\n",resmin); 
    float ressec=0;
	ressec =(t.hour*3600) + (t.min*60) + t.sec;
	printf("%f Seconds\n",ressec);

}
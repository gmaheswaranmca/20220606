//Read date with format dd-MM-yyyy and put into the attributes of date_t struct {day:int,month:int,year:int}
#include<stdio.h>
#include<stdlib.h>

struct _date_t{
	int day;
	int month;
	int year;
};
typedef struct _date_t date_t;

int main(){
	date_t dt;
    char str_dt[256];
    printf("Enter date(format:dd-MM-yyyy):"); scanf("%s",str_dt);
    printf("The string date we read is %s\n",str_dt);

    sscanf(str_dt,"%02d-%02d-%04d",&dt.day,&dt.month,&dt.year);
    printf("The date object is [day=%d, month=%d, year=%d]\n",dt.day,dt.month,dt.year);

	return EXIT_SUCCESS;
}
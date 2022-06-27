//Read date_t struct attributes {day:int,month:int,year:int}
//Convert date object to string with format dd-MM-yyyy and print it
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
    printf("Enter day number:"); scanf("%d",&dt.day);
    printf("Enter month number:"); scanf("%d",&dt.month);
    printf("Enter year:"); scanf("%d",&dt.year);

    sprintf(str_dt,"%02d-%02d-%04d",dt.day,dt.month,dt.year);
    printf("The formed date string is %s\n",str_dt);

	return EXIT_SUCCESS;
}
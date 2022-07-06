#include"flight_ui.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void ui_flight_create(flight_t* addr){
	//scanf for addr->[attr]
	printf("\nEnter flight id:"); scanf("%d",&addr->flight_id);
	printf("\nEnter flight number:"); scanf("%s",addr->flight_number);
	printf("\nEnter source:"); scanf("%s",addr->source);
	printf("\nEnter destination:"); scanf("%s",addr->destination);
	printf("\nEnter number of seats:"); scanf("%d",&addr->number_of_seats);
	printf("\nEnter Fare:"); scanf("%lf",&addr->ticket_fare);
}
void ui_flight_update(flight_t* addr){
	//scanf for addr->[attr to be updated]
	printf("\nEnter Fare:"); scanf("%lf",&addr->ticket_fare);
}	
void ui_flight_delete(flight_t* addr, int *is_confirmed_addr){ // confirmation 
	//print addr->{attr} / confirmation
	printf("\nflight id:%d",addr->flight_id);
	printf("\nflight number:%s",addr->flight_number);
	printf("\nsource:%s",addr->source);
	printf("\ndestination:%s",addr->destination);
	printf("\nnumber of seats:%d",addr->number_of_seats);
	printf("\nFare:%.2lf",addr->ticket_fare);
	
	char ch;
	printf("\nAre you sure to delete(y/n)?"); getchar(); scanf("%c",&ch);
	(*is_confirmed_addr) = (('y' == ch) || ('Y' == ch));
}	
void ui_flight_show_all(flight_t* flights, int size, int* action_type_addr, int* index_addr){
	//print all the products in tabular column 
	//update | delete by index of display order 
	printf("\n%-5s%-13s%-15s%-15s%7s%10s",
		"ID",
		"Flight Number",
		"Source",
		"Destination",
		"Seats",
		"Fare");
	for(int I=0; I<size; I++){
		printf("\n%-5d%-13s%-15s%-15s%7d%10.2f",
			flights[I].flight_id,
			flights[I].flight_number,
			flights[I].source,
			flights[I].destination,
			flights[I].number_of_seats,
			flights[I].ticket_fare);
	}
}

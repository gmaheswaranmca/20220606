#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/* flight_t.h */
typedef struct { 
	int flight_id; 
	char flight_number[ 256 ];
	char source[ 256 ]; 
	char destination[ 256 ];
	int number_of_seats; 
	double ticket_fare;
}flight_t;


/* flight_db.c */
struct{ 
	char db_name[ 256 ]; 
	char db_temp_name [ 256 ];
} dbn = { "flight.dat","flight_temp.dat"};
/* flight_db.c */
typedef int (*compare_addr_t)(void* val, void* search);
   
/* flight_db.c */
void flight_db_create(flight_t *addr) { 
	FILE *output = fopen(dbn.db_name,"a"); 
	fwrite(addr,1,sizeof(flight_t),output);
	fclose(output); 
}

/* flight_db.c */
/*
int flight_db_find(int flight_id){ 
	FILE *input = fopen(dbn.db_name,"r"); 
	flight_t flight;
	int index = -1;
	int I=0;
	while(fread(&flight,1,sizeof(flight_t),input)) { 
		if(flight.flight_id == flight_id){ 
			index=I;
			break;
		}
		I++;
	}
	fclose(input); 
	return index;
}
*/

int flight_db_find(compare_addr_t doCompare, void *search){ 
	flight_t flight;
	int index = -1;
	int I=0;
	
	
	FILE *input = fopen(dbn.db_name,"r"); 
	
	while(fread(&flight,1,sizeof(flight_t),input)) { 
		if(doCompare(&flight, search)==0){ //fn ptr -> compare fn(flight_t*,int/char*)
			index=I;
			break;
		}
		I++;
	}
	fclose(input); 
	
	return index;
}

int doCompareById(void* val, void* search){
	flight_t* addr=val;
	int flight_id = *(int*)search;
	if(flight_id == addr->flight_id)
	   return 0;
	else if(flight_id < addr->flight_id)
	   return -1;
	else
	   return 1;
}

int doCompareByFlightNumber(void* val, void* search){
	flight_t* addr=val;
	char* flight_number = search;
	return strcmp(flight_number, addr->flight_number);
}

int flight_db_find_by_id(int flight_id){
	return flight_db_find(doCompareById,&flight_id);
}

int flight_db_find_by_number(char *flight_number){
	return flight_db_find(doCompareByFlightNumber, flight_number);
}

void flight_db_update(flight_t *addr, int index) { 
	int flightObjectChars = (int)sizeof(flight_t);
	int offset = index * flightObjectChars;

	FILE *inout = fopen(dbn.db_name,"r+"); 
	fseek(inout,offset,SEEK_SET);
	fwrite(addr,1,sizeof(flight_t),inout);
	fclose(inout); 
}

void flight_db_delete(flight_t *addr, int index) {
	flight_t val;
	int I = 0;

	FILE *input = fopen(dbn.db_name,"r"); 
	FILE *output = fopen(dbn.db_name,"w");
	while(0!=fread(&val,1,sizeof(flight_t),input)) { 
		if(I != index){ //or if arg is flight_id, then compare
			fwrite(addr,1,sizeof(flight_t),output);
		}
		I++;
	}
	fclose(output);
	fclose(input); 
	
	remove(dbn.db_name);
	rename(dbn.db_temp_name,dbn.db_name);
}

int flight_db_count(){ 
	int countChars = 0;
	int countObjects = 0;
	
	FILE *input = fopen(dbn.db_name,"r"); 
	fseek(input,0,SEEK_END);
	countChars = ftell(input);	
	fclose(input); 
	
	countObjects = countChars / (int)sizeof(flight_t);
	return countObjects;
}

void flight_db_read_all(flight_t* array,int size){ //size is not used. 
	flight_t flight;
	int I=0;
	
	FILE *input = fopen(dbn.db_name,"r"); 
	
	while(0!=fread(&flight,1,sizeof(flight_t),input)) { //while --or-- for range 1..size
		array[I] = flight;
		I++;
	}
	fclose(input);
}

	
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
//ui_controller
void action_product_show_all();
void action_product_create(){
	flight_t val={};
	ui_flight_create(&val);
	flight_db_create(&val);
	//Successful message you print 
	//Ask to go further?
	printf("\nSuccessfuly flight is added.");
	
	getchar(); printf("\nPress any key to continue..."); getchar();
	action_product_show_all();
}
void action_product_show_all(){
	int size =  flight_db_count();
	flight_t *array = (flight_t*)malloc(size * sizeof(flight_t));
	flight_db_read_all(array, size);
	int action_type;
	int index;
	ui_flight_show_all(array, size,&action_type,&index);
	free(array);
}
//......

int main(){
	int menu = 0;
	do{
		printf("\nChoice(1-create flight, 2-list flights):"); scanf("%d",&menu);
		
		switch(menu){
			case 1: action_product_create(); break;
			case 2: action_product_show_all(); break;	
		}
	}while((1<=menu) && (menu<=2));
	return EXIT_SUCCESS;
}

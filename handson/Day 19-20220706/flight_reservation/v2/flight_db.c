#include"flight_db.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

static struct{ 
	char db_name[ 256 ]; 
	char db_temp_name [ 256 ];
} dbn = { "flight.dat","flight_temp.dat"};

typedef int (*compare_addr_t)(void* val, void* search);
   
void flight_db_create(flight_t *addr) { 
	FILE *output = fopen(dbn.db_name,"a"); 
	fwrite(addr,1,sizeof(flight_t),output);
	fclose(output); 
}

/*
int flight_db_find_by_id(int flight_id){ 
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

static int flight_db_find(compare_addr_t doCompare, void *search){ 
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

static int doCompareById(void* val, void* search){
	flight_t* addr=val;
	int flight_id = *(int*)search;
	if(flight_id == addr->flight_id)
	   return 0;
	else if(flight_id < addr->flight_id)
	   return -1;
	else
	   return 1;
}

static int doCompareByFlightNumber(void* val, void* search){
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


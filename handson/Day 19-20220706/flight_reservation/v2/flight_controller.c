#include"flight_controller.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
	array = NULL;
}
//......

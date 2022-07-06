#pragma once
typedef struct { 
	int flight_id; 
	char flight_number[ 256 ];
	char source[ 256 ]; 
	char destination[ 256 ];
	int number_of_seats; 
	double ticket_fare;
}flight_t;

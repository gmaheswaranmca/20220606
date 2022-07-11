#include<stdio.h>	
#include<stdlib.h>	
#define NO_THREAD 1

#ifndef NO_THREAD
//Start no-threaded routines
void app(){
	printf("no-threaded routines.\n");
}
//End Start no-threaded routines	
#else
#include<threads.h>
//Start threaded-routines 
#define SYNC_WRITE_OP 0
	
#ifndef SYNC_WRITE_OP
//Start no mutex or no atomic 
void app(){
	printf("no mutex or no atomic.\n");
}
//End no mutex or no atomic
#else
//Start mutex or atomic
#define IS_ATOMIC_OP 0

#ifndef IS_ATOMIC_OP
//start mutex op 
void app(){
	printf("mutex op.\n");
}
//end mutex op 
#else
#include<stdatomic.h>	
//start atomic op  
void app(){
	printf("atomic op .\n");
}
//end atomic op 

#endif 
//End mutex or atomic
#endif 	
//End threaded-routines 	 
#endif 

int main(){
	printf("In main.\n");
	app();
	printf("End of main.\n");
	return EXIT_SUCCESS;
}
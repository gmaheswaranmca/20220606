#include<stdio.h>	
#include<stdlib.h>	
#include<time.h>
#define NO_THREAD 1


//library

#ifndef NO_THREAD
//Start no-threaded routines
//End Start no-threaded routines	
#else
#include<threads.h>
//Start threaded-routines 
#define SYNC_WRITE_OP 1
	
#ifndef SYNC_WRITE_OP
//Start no mutex or no atomic 
//End no mutex or no atomic
#else
//Start mutex or atomic
#define IS_ATOMIC_OP 1

#ifndef IS_ATOMIC_OP
//start mutex op 
//end mutex op 
#else
#include<stdatomic.h>	
//start atomic op  
//end atomic op 

#endif 
//End mutex or atomic
#endif 	
//End threaded-routines 	 
#endif 



//code
#define MAX_WORKERS 10000000
#define BATCH_SIZE 10000

void insert()
{
	char fname[]="num.dat";
	    FILE* out=fopen(fname,"wb");
	    if(out==NULL)
        {
        	printf("This is null");
        	return;    
        }    
        for(long i=0;i<MAX_WORKERS;i++)    
        {        
        	fwrite(&i,1,sizeof(long),out);    
        } 
        fclose(out);   
}
void read(long *array)
{
	char fname[]="num.dat";
	    FILE* in=fopen(fname,"r");
	    if(in==NULL)
        {
        	printf("This is null");
        	return;    
        }    
        for(int i=0;i<MAX_WORKERS;i++)    
        {        
        	fread((array + i),1,sizeof(long),in); 
        	//printf(" %ld,",array[i]);   
        } 
        fclose(in);   
}
clock_t t1,t2;

#ifndef NO_THREAD
//Start no-threaded routines
long sum = 0;
void app(){
	printf("no-threaded routines.\n");
}
//End Start no-threaded routines	
#else
//Start threaded-routines 

	
#ifndef SYNC_WRITE_OP
//Start no mutex or no atomic 
long sum = 0;
void app(){
	printf("no mutex or no atomic.\n");
}
//End no mutex or no atomic
#else
//Start mutex or atomic

#ifndef IS_ATOMIC_OP
//start mutex op 
long sum = 0;
mtx_t MUTX;
void app(){
	printf("mutex op.\n");
}
//end mutex op 
#else
//start atomic op  
atomic_long sum = 0;
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
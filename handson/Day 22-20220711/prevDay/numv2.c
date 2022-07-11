#include<stdio.h>
#include<threads.h>
#include<stdlib.h>
#include<time.h>
#include<stdatomic.h>
#define MAX_WORKERS 10000000
#define BATCH_SIZE 10000
long sum = 0;
atomic_long sum2 = 0;
 //_Thread_local long sum2 = 0;
mtx_t MUTX;
clock_t t1,t2;
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
void doSum(long *array)
{
	for(int i=0;i<BATCH_SIZE;i++)    
        {  
        	//mtx_lock(&MUTX);      
        	sum += array[i]; /**** RACE****/   
        	//mtx_unlock(&MUTX);
        } 
}
int dosum_routine(void* arg)
{
	long* array=(long*)arg;
	doSum(array);
	return 0;
}
void doSum_v2(long *array)
{
	for(int i=0;i<BATCH_SIZE;i++)    
        {  
      //  	mtx_lock(&MUTX);      
        	sum2 += array[i]; /**** RACE****/   
        //	mtx_unlock(&MUTX);
        } 
}
int dosum_routine_v2(void* arg)
{
	long* array=(long*)arg;
	doSum_v2(array);
	return 0;
}
void bulk_process(long* array)
{
	thrd_t workers[MAX_WORKERS/BATCH_SIZE];
 		for(int i=0;i<MAX_WORKERS/BATCH_SIZE;i++)    
        {      
        	//printf(" batch = %d\n",i);  
        	thrd_create(&workers[i],dosum_routine,&array[i*BATCH_SIZE]); //&array[0*BATCH_SIZE], &array[1*BATCH_SIZE]
        	//thrd_create(workers+ i ,dosum_routine,array + i*BATCH_SIZE); 
        } 
     //   printf("line 63\n");
        for(int i=0;i<MAX_WORKERS/BATCH_SIZE;i++)    
        {        
        	thrd_join(workers[i],NULL);   
        }
         printf("Sum = %ld\n",sum);
      //  printf("line 69\n");
        
}
void bulk_process_v2(long* array)
{
	thrd_t workers[MAX_WORKERS/BATCH_SIZE];
 		for(int i=0;i<MAX_WORKERS/BATCH_SIZE;i++)    
        {      
        	//printf(" batch = %d\n",i);  
        	thrd_create(&workers[i],dosum_routine_v2,&array[i*BATCH_SIZE]); //&array[0*BATCH_SIZE], &array[1*BATCH_SIZE]
        	//thrd_create(workers+ i ,dosum_routine,array + i*BATCH_SIZE); 
        } 
     //   printf("line 63\n");
        for(int i=0;i<MAX_WORKERS/BATCH_SIZE;i++)    
        {        
        	thrd_join(workers[i],NULL);   
        }
         printf("Sum = %ld\n",sum2);
      //  printf("line 69\n");
        
}
void disp_time()
{
		time_t rawtime;
		  struct tm * timeinfo;
		  time ( &rawtime );
		  timeinfo = localtime ( &rawtime );
		  printf ( "Current local time and date: %s", asctime (timeinfo) );
        
}

void __attribute__((constructor))startup()
{
	printf("startup\n"); 
	mtx_init(&MUTX,mtx_plain);
}
void __attribute__((destructor))cleanup()
{
	mtx_destroy(&MUTX);
	printf("cleanup\n"); 
}
int main()
{    
		//printf("line 52\n");
		long* array = (long *)malloc(sizeof(long)*MAX_WORKERS);
		insert();
 		read(array);
 		//printf("line 56: %ld\n",array[MAX_WORKERS-1]);
 		int n=5;
 		printf("without lock\n");
 		while(n)
 		{
 			sum=0;
 			t1=clock();
	 		bulk_process(array);
	 		t2=clock();
	 		double dur = 1000.0*(t2-t1)/CLOCKS_PER_SEC;
	 		printf("CPU time used (per clock()): %.2lf ms\n", dur);
	 		//disp_time();
	 		n--;
 		}
 		n=5;
  		printf("with lock\n");
  		while(n)
 		{
 			sum2=0;
 			t1=clock();
	 		bulk_process_v2(array);
	 		t2=clock();
	 		double dur = 1000.0*(t2-t1)/CLOCKS_PER_SEC;
	 		printf("CPU time used (per clock()): %.2lf ms\n", dur);
	 		//disp_time();
	 		n--;
 		}
        free(array);
        array=NULL;
        return 0;
}        
        

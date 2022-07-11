#include<stdio.h>
#include<stdlib.h>

#define IS_THREADED 1

#if defined(IS_THREADED) && IS_THREADED==1
#include<threads.h>
#endif

#define STADIUM_CAPACITY 75000000UL
unsigned long AttendanceCount=0UL;

unsigned long EntranceOneCount=0UL;
unsigned long EntranceTwoCount=0UL;
unsigned long EntranceThreeCount=0UL;
unsigned long EntranceFourCount=0UL;
unsigned long attendeesOne[STADIUM_CAPACITY]={};
unsigned long attendeesTwo[STADIUM_CAPACITY]={};
unsigned long attendeesThree[STADIUM_CAPACITY]={};
unsigned long attendeesFour[STADIUM_CAPACITY]={};

long findSumOfCounters()
{
	return EntranceOneCount + EntranceTwoCount + EntranceThreeCount + EntranceFourCount;
}
int isStadiumFull(){
	return findSumOfCounters() >= STADIUM_CAPACITY; 
}

void doCountAtEntranceOne(){
	while(!isStadiumFull()){		
		//AttendanceCount++;
		//attendeesOne[EntranceOneCount] = AttendanceCount;
		EntranceOneCount++;
		//printf(" %lu ", EntranceOneCount);
	}
}
void doCountAtEntranceTwo(){
	while(!isStadiumFull()){		
		//AttendanceCount++;
		//attendeesTwo[EntranceTwoCount] = AttendanceCount;
		EntranceTwoCount++;
		//printf(" %lu ", EntranceOneCount);
		
	}
}
void doCountAtEntranceThree(){
	while(!isStadiumFull()){
		//AttendanceCount++;
		//attendeesThree[EntranceThreeCount] = AttendanceCount;
		EntranceThreeCount++;
		//printf(" %lu ", EntranceOneCount);
	}
}
void doCountAtEntranceFour(){
	while(!isStadiumFull()){
		//AttendanceCount++;
		//attendeesFour[EntranceFourCount] = AttendanceCount;
		EntranceFourCount++;
		//printf(" %lu ", EntranceOneCount);
	}
}
void doDisplayCounter()
{
	while(!isStadiumFull()){
		printf("\r%-60s",
			"");
		printf("\r%-10lu%-10lu%-10lu%-10lu%-10lu",
			AttendanceCount,
			EntranceOneCount,
			EntranceTwoCount,
			EntranceThreeCount,
			EntranceFourCount);
	}
}
#if defined(IS_THREADED) && IS_THREADED==1
int doCountAtEntranceOne_routine(void* arg){
	doCountAtEntranceOne();
	return EXIT_SUCCESS;
}
int doCountAtEntranceTwo_routine(void* arg){
	doCountAtEntranceTwo();
	return EXIT_SUCCESS;
}
int doCountAtEntranceThree_routine(void* arg){
	doCountAtEntranceThree();
	return EXIT_SUCCESS;
}
int doCountAtEntranceFour_routine(void* arg){
	doCountAtEntranceFour();
	return EXIT_SUCCESS;
}
int doDisplayCounter_routine(void* arg){
	doDisplayCounter();
	return EXIT_SUCCESS;
}
void app(){
	printf("%-10s%-10s%-10s%-10s%-10s\n","attendance","counter1","counter2","counter3","counter4");
	thrd_t thr_one;
	thrd_t thr_two;
	thrd_t thr_three;
	thrd_t thr_four;
	thrd_t thr_disp;
	thrd_create(&thr_one, doCountAtEntranceOne_routine,NULL);
	thrd_create(&thr_two, doCountAtEntranceTwo_routine,NULL);
	thrd_create(&thr_three, doCountAtEntranceThree_routine,NULL);
	thrd_create(&thr_four, doCountAtEntranceFour_routine,NULL);	
	thrd_create(&thr_disp, doDisplayCounter_routine,NULL);	
	
	thrd_join(thr_one,NULL);
	thrd_join(thr_two,NULL);
	thrd_join(thr_three,NULL);
	thrd_join(thr_four,NULL);
	thrd_join(thr_disp,NULL);
	printf("\nCricket is started.\n");
}
#else
void app(){
	printf("%-10s%-10s%-10s%-10s%-10s\n","attendance","counter1","counter2","counter3","counter4");
	doCountAtEntranceOne();
	doCountAtEntranceTwo();
	doCountAtEntranceThree();
	doCountAtEntranceFour();
	doDisplayCounter();
	printf("\nCricket is started.\n");
}
#endif

int main(){
	printf("Cricket is going to get started.\n");
	app();
	return EXIT_SUCCESS;
}
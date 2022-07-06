//non-threaded vs threaded two routines(many test cases)
#include<stdio.h>
#include<stdlib.h>
#include<threads.h>
#include <time.h>
void parentSayHi(){
	for(int I=1; I<=10; I++){
		printf("Parent says Hi#%d\n",I);
		thrd_sleep(&(struct timespec){.tv_nsec=100000}, NULL);
	}
}
void childSayHello(){
	for(int I=1; I<=10; I++){	
		printf("Child says Hello#%d\n",I);
		thrd_sleep(&(struct timespec){.tv_nsec=100000}, NULL);
	}
}

int childRoutine(void* arg){
	childSayHello();
	
	return EXIT_SUCCESS;
}

void mainNonThreaded(){
	
	childSayHello();
	parentSayHi();
}


void mainThreaded(){
	thrd_t childThr;
	int tc_code = thrd_create(&childThr,&childRoutine,NULL); //thread is defined and ready to run	
	parentSayHi();
	tc_code = thrd_join(childThr,NULL);
}
int main(){
	printf("Non-threaded:\n");
	mainNonThreaded();

	for(int J=1; J<=10; J++){
		printf("threaded:(test case#%d)\n",J);
		mainThreaded();
	}

	
	return EXIT_SUCCESS;
}

/* 
output
$ gcc program-threaded.c -o main -lpthread
$ ./main
Non-threaded:
Child says Hello#1
Child says Hello#2
Child says Hello#3
Child says Hello#4
Child says Hello#5
Child says Hello#6
Child says Hello#7
Child says Hello#8
Child says Hello#9
Child says Hello#10
Parent says Hi#1
Parent says Hi#2
Parent says Hi#3
Parent says Hi#4
Parent says Hi#5
Parent says Hi#6
Parent says Hi#7
Parent says Hi#8
Parent says Hi#9
Parent says Hi#10
threaded:(test case#1)
Parent says Hi#1
Child says Hello#1
Parent says Hi#2
Child says Hello#2
Parent says Hi#3
Child says Hello#3
Parent says Hi#4
Child says Hello#4
Parent says Hi#5
Child says Hello#5
Parent says Hi#6
Child says Hello#6
Parent says Hi#7
Child says Hello#7
Parent says Hi#8
Child says Hello#8
Parent says Hi#9
Child says Hello#9
Parent says Hi#10
Child says Hello#10
threaded:(test case#2)
Parent says Hi#1
Child says Hello#1
Parent says Hi#2
Child says Hello#2
Parent says Hi#3
Child says Hello#3
Parent says Hi#4
Child says Hello#4
Parent says Hi#5
Child says Hello#5
Parent says Hi#6
Child says Hello#6
Parent says Hi#7
Child says Hello#7
Parent says Hi#8
Child says Hello#8
Parent says Hi#9
Child says Hello#9
Parent says Hi#10
Child says Hello#10
threaded:(test case#3)
Parent says Hi#1
Child says Hello#1
Parent says Hi#2
Child says Hello#2
Parent says Hi#3
Child says Hello#3
Parent says Hi#4
Child says Hello#4
Parent says Hi#5
Child says Hello#5
Parent says Hi#6
Child says Hello#6
Parent says Hi#7
Child says Hello#7
Parent says Hi#8
Child says Hello#8
Parent says Hi#9
Child says Hello#9
Parent says Hi#10
Child says Hello#10
threaded:(test case#4)
Parent says Hi#1
Child says Hello#1
Parent says Hi#2
Child says Hello#2
Parent says Hi#3
Child says Hello#3
Parent says Hi#4
Child says Hello#4
Parent says Hi#5
Child says Hello#5
Parent says Hi#6
Child says Hello#6
Parent says Hi#7
Child says Hello#7
Parent says Hi#8
Child says Hello#8
Parent says Hi#9
Child says Hello#9
Parent says Hi#10
Child says Hello#10
threaded:(test case#5)
Parent says Hi#1
Child says Hello#1
Parent says Hi#2
Child says Hello#2
Parent says Hi#3
Child says Hello#3
Parent says Hi#4
Child says Hello#4
Parent says Hi#5
Child says Hello#5
Parent says Hi#6
Child says Hello#6
Parent says Hi#7
Child says Hello#7
Parent says Hi#8
Child says Hello#8
Parent says Hi#9
Child says Hello#9
Parent says Hi#10
Child says Hello#10
threaded:(test case#6)
Parent says Hi#1
Child says Hello#1
Parent says Hi#2
Child says Hello#2
Parent says Hi#3
Child says Hello#3
Parent says Hi#4
Child says Hello#4
Parent says Hi#5
Child says Hello#5
Parent says Hi#6
Child says Hello#6
Parent says Hi#7
Child says Hello#7
Parent says Hi#8
Child says Hello#8
Parent says Hi#9
Child says Hello#9
Parent says Hi#10
Child says Hello#10
threaded:(test case#7)
Parent says Hi#1
Child says Hello#1
Parent says Hi#2
Child says Hello#2
Parent says Hi#3
Child says Hello#3
Parent says Hi#4
Child says Hello#4
Parent says Hi#5
Child says Hello#5
Parent says Hi#6
Child says Hello#6
Parent says Hi#7
Child says Hello#7
Parent says Hi#8
Child says Hello#8
Parent says Hi#9
Child says Hello#9
Parent says Hi#10
Child says Hello#10
threaded:(test case#8)
Parent says Hi#1
Child says Hello#1
Parent says Hi#2
Child says Hello#2
Parent says Hi#3
Child says Hello#3
Parent says Hi#4
Child says Hello#4
Parent says Hi#5
Child says Hello#5
Parent says Hi#6
Child says Hello#6
Parent says Hi#7
Child says Hello#7
Parent says Hi#8
Child says Hello#8
Parent says Hi#9
Child says Hello#9
Parent says Hi#10
Child says Hello#10
threaded:(test case#9)
Parent says Hi#1
Child says Hello#1
Parent says Hi#2
Child says Hello#2
Parent says Hi#3
Parent says Hi#4
Child says Hello#3
Parent says Hi#5
Parent says Hi#6
Child says Hello#4
Parent says Hi#7
Child says Hello#5
Parent says Hi#8
Child says Hello#6
Parent says Hi#9
Child says Hello#7
Parent says Hi#10
Child says Hello#8
Child says Hello#9
Child says Hello#10
threaded:(test case#10)
Parent says Hi#1
Child says Hello#1
Parent says Hi#2
Child says Hello#2
Parent says Hi#3
Child says Hello#3
Parent says Hi#4
Child says Hello#4
Parent says Hi#5
Child says Hello#5
Parent says Hi#6
Child says Hello#6
Parent says Hi#7
Child says Hello#7
Parent says Hi#8
Child says Hello#8
Parent says Hi#9
Child says Hello#9
Parent says Hi#10
Child says Hello#10
$

*/
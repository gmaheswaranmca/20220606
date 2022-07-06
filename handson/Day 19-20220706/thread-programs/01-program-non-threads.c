//non-threaded two routines
#include<stdio.h>
#include<stdlib.h>
void parentSayHi(){
	for(int I=1; I<=10; I++){
		printf("Parent says Hi#%d\n",I);
	}
}
void childSayHello(){
	for(int I=1; I<=10; I++){	
		printf("Child says Hello#%d\n",I);
	}
}

int main(){
	childSayHello();
	parentSayHi();
	return EXIT_SUCCESS;
}
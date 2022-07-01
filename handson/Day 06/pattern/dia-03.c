#include<stdio.h>
#include<stdlib.h>

int main(){ 
	int N = 0;
	char stars[256] ="*********************************************";
	char spaces[256] ="                                              ";
	printf("Enter number of lines:"); scanf("%d",&N);
	for(int I=1; I <= N; I++){
		printf("%.*s%.*s%.*s\n",(N-I),spaces,I,stars,I-1,stars);
	}
	for(int I=N-1; I >=1 ; I--){
		printf("%.*s%.*s%.*s\n",(N-I),spaces,I,stars,I-1,stars);
	}
	return EXIT_SUCCESS;
}
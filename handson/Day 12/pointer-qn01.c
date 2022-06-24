#include<stdio.h>
#include<stdlib.h>
long anotherData = 200L; //anotherData{8400} [200Lxxx] [300L]

void f(long *dataAddr){     //dataAddr{8036} [4062xxx] [8400]
	dataAddr = &anotherData;
	(*dataAddr) = (*dataAddr) + 100L;
}
int main(){
	long data = 100L;           // data{4062} [100L] 
	long* ptrToData = &data;     // ptrToData{6012} [4062]
	f(ptrToData);               //f(4062addr)
	printf("%ld",(*ptrToData)); //100L printed
	return EXIT_SUCCESS;
}
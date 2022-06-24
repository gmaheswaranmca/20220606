#include<stdio.h>
#include<stdlib.h>
long anotherData = 200L; 

void g(long **dataAddrAddr){    
    long *dataAddr = (*dataAddrAddr);   //20000
	dataAddr = &anotherData;            //10000
	(*dataAddr) = (*dataAddr) + 100L; 
    
    (*dataAddrAddr) = dataAddr;     
}
int main(){
	long data = 100L;          
	long* ptrToData = &data;     
	g(&ptrToData);               
	printf("%ld",(*ptrToData)); 
	return EXIT_SUCCESS;
}
/*
scope        variable                addr           value 
global       anotherData             10000          300L        xxxxxx200L
main         data                    20000          100L      
main         ptrToData               25000          10000       xxxx20000
g            dataAddrAddr            30000          25000
g            dataAddr                34000          10000       xxxxx20000
            
*/

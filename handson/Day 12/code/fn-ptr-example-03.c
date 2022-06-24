//Example for function pointer
//		function pointer to function 
//		pass function pointer as argument to function 

#include <stdio.h>
#include <stdlib.h>

double findSum(double first, double second){
	return first + second;
}

double findDifference(double first, double second){
	return first - second;
}

double doOperation(double first, double second, double (*operationAddr)(double, double)){
    return operationAddr(first,second);
}

int main()
{
    double firstNumber = 1.0;
    double secondNumber = 0.5;
    
    double sum = 0.0;
    double difference = 0.0;
    
    sum = doOperation(firstNumber,secondNumber,findSum);
    difference = doOperation(firstNumber,secondNumber,findDifference);
    
    printf("The sum and difference of %.2lf and %.2lf are %.2lf and %.2lf",
        firstNumber,secondNumber,
        sum, difference);
    
    return EXIT_SUCCESS;
}
//Example for function pointer

#include <stdio.h>
#include <stdlib.h>

double findSum(double first, double second){
	return first + second;
}

double findDifference(double first, double second){
	return first - second;
}

int main()
{
    double (*operationAddr)(double, double);
    
    double firstNumber = 1.0;
    double secondNumber = 0.5;
    
    double sum = 0.0;
    double difference = 0.0;
    
    operationAddr = &findSum;
    sum = (*operationAddr)(firstNumber,secondNumber);
    
    operationAddr = &findDifference;
    difference = (*operationAddr)(firstNumber,secondNumber);
    
    printf("The sum and difference of %.2lf and %.2lf are %.2lf and %.2lf",
        firstNumber,secondNumber,
        sum, difference);
    
    return EXIT_SUCCESS;
}
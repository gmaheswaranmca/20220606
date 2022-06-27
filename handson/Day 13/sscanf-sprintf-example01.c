//sscanf: read data from string, sprintf: write data into string 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){ 
	//sscanf
	char numbers_in_str[1000] = "10 20 30";//"10\n20\n30";
	short first, second, third; 	
    sscanf(numbers_in_str,"%hd %hd %hd", &first,&second,&third);
    printf("The numbers read are %hd %hd %hd\n",first,second,third);


	char data_in_str[1000] = "43\nMaheswaran\n2500.00";//"43 Maheswaran 2500.00"
	short age; 
    char name[256];	
    double sal;
    sscanf(data_in_str,"%hd %s %lf", &age,name,&sal);
    printf("The data read are [%hd] [%s] [%.2lf]\n",age,name,sal);

	//sprintf
    char numbers_in_str2[1000];
    sprintf(numbers_in_str2,"first=%hd second=%hd third=%hd", first,second,third);
    printf("The string we wrote is %s\n",numbers_in_str2);

    char data_in_str2[1000];
    sprintf(data_in_str2,"age=%hd name=%s sal=%.2lf", age,name,sal);
    printf("The string we wrote is %s\n",data_in_str2);

	return EXIT_SUCCESS;
}
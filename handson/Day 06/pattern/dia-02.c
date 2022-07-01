#include<stdio.h>
#include<stdlib.h>

int main(){
	int numberOfLines = 0;
	char stars[256] ="*********************************************";
	char spaces[256] ="                                              ";
	printf("Enter number of lines:"); scanf("%d",&numberOfLines);
	for(int lineI=1; lineI <= numberOfLines; lineI++){
		printf("%.*s%.*s%.*s\n",(numberOfLines-lineI),spaces,lineI,stars,lineI-1,stars);
	}
	for(int lineI=numberOfLines-1; lineI >=1 ; lineI--){
		printf("%.*s%.*s%.*s\n",(numberOfLines-lineI),spaces,lineI,stars,lineI-1,stars);
	}
	return EXIT_SUCCESS;
}
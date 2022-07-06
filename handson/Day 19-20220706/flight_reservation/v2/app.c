#include"flight_controller.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	int menu = 0;
	do{
		printf("\nChoices");
		printf("\t1-list flights,2-create flight");
		printf("\t0-Exit):"); 
		printf("Your Choice:"); scanf("%d",&menu);
		
		if(1==menu){
			action_product_show_all();
		}else if(2==menu){
			action_product_create();	
		}
	}while((1<=menu) && (menu<=2));
	return EXIT_SUCCESS;
}

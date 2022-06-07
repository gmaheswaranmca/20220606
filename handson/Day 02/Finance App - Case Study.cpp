case study:
	"Finance App" -> Loan Processing App
		- Scheme "Education Loan", "Personal Loan", "Home Loan"
		- Customer 
			Portal 
				Register 
				Login 
					Apply for Loan (Loan Application)
					View Application 
		- Employee 
			Scheme - Add, Update 
			Process Loan from Application 
				Verification
				Background Verification 
				Loan Approval 
			Loan 
			
Objects / Table of Records / Database 
	Customer
	Employee
	Scheme
	Loan Application
	Loan Processing 
	Loan 
	
File Database 	
	Text File (Comma Separated Values)
	Binary File 
	
Project Structure:	
	(Directory Structure)
financeapp	
	header
		scheme_t.h scheme_db.h scheme_add_ux.h
	source 
		scheme_db.c scheme_add_ux.c employee_app.c
	object
	build 
...............................................................
#/home/mahesh/financeapp
$cd ../source
$ gcc -I../header *.c -c
$ ls
$ mv *.o ../object
$ ls
$ ls ../object
$ cd ../object
$ gcc *.o -o ../build/finempapp
$ cd ../build
$ ./finempapp 
Choice (1-Manage Scheme, 2-Process Loan, 3-Release Loan, 0-Exit):
1
Choice (1-Add Scheme, 2-Update Loan, 3-Display Schemes, 0-Exit):
1
Read scheme details from the user console(keyboard) here... into scheme objectCall scheme_create pass the scheme object as the argumentChoice (1-Add Scheme, 2-Update Loan, 3-Display Schemes, 0-Exit):
0
Choice (1-Manage Scheme, 2-Process Loan, 3-Release Loan, 0-Exit):
0
...............................................................
    
    
...............................................................
#/home/mahesh/financeapp
$ cd ../source
$ gcc -I../header *.c -c                !!! COMPILE
$ mv *.o ../object
$ cd ../object
$ gcc *.o -o ../build/finempapp         !!! BUILD 
$ cd ../build
$ ./finempapp                           !!! RUN / EXECUTE
...............................................................
    
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^	
scheme_t.h	
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
#pragma once						
struct _scheme_t{
int scheme_id;
char scheme_name[256];
double max_loan_amount;
//...
};
typedef struct _scheme_t scheme_t;
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^


^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
scheme_db.h
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
#pragma once
#include"scheme_t.h"
void scheme_create(scheme_t scheme);
void scheme_update(scheme_t scheme);
void scheme_read_all(scheme_t schemes[], int* scheme_size_addr);
void scheme_read_byid(scheme_t *scheme_addr, int scheme_id);
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^



^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
scheme_db.c
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
#include"scheme_db.h"
void scheme_create(scheme_t scheme)
{
    //code here 
    //add into file (either as the binary or text)
}   
void scheme_update(scheme_t scheme)
{
    //code here 
    //update into file
}   
void scheme_read_all(scheme_t schemes[], int* scheme_size_addr)
{
    //code here 
    //read from file - all scheme records
}   
void scheme_read_byid(scheme_t *scheme_addr, int scheme_id)
{
    //code here 
    //read from file - one scheme record 
}   
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^


^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
scheme_add_ux.h
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
#include"scheme_db.h"
void scheme_create_page();
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^


^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
scheme_add_ux.c
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
#include"scheme_add_ux.h"
#include<stdio.h>
void scheme_create_page(){
    //Declare & Define scheme object here 
    printf("Read scheme details from the user console(keyboard) here...");
    printf(" into scheme object");
    //CODE HERE
    printf("Call scheme_create pass the scheme object as the argument");
    //CODE HERE
    //scheme_create(/*pass sheme object*/);
}
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^


^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
employee_app.c
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
#include "scheme_add_ux.h"
#include<stdio.h>
void manage_scheme()
{
    int menu;
    do {
        printf("Choice (1-Add Scheme, 2-Update Loan, 3-Display Schemes, 0-Exit):\n");
        scanf("%d",&menu);
        
        if(1 == menu){
            scheme_create_page();
        }
    }while(1 == menu || 2 == menu || 3 == menu);
}   

int main()
{
    int menu;
    
    do {
        printf("Choice (1-Manage Scheme, 2-Process Loan, 3-Release Loan, 0-Exit):\n");
        scanf("%d",&menu);
        
        if(1 == menu){
            manage_scheme(); 
        }
    }while(1 == menu || 2 == menu || 3 == menu);
    return 0;
}
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

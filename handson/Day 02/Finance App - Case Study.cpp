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
		scheme_t.h scheme_db.h 
	source 
		scheme_db.c 
	object
	build 
	
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
}   
void scheme_update(scheme_t scheme)
{
    //code here 
}   
void scheme_read_all(scheme_t schemes[], int* scheme_size_addr)
{
    //code here 
}   
void scheme_read_byid(scheme_t *scheme_addr, int scheme_id)
{
    //code here 
}   
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
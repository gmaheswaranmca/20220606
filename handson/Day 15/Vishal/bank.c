#include <stdio.h>


typedef struct _DOB_t
{
	int Day;
	int Month;
	int Year;
}DOB_t;

typedef struct _BankCustomer_t
{
	char AccHolderName[128];
	char PhoneNumber[16];
	char Gender;
	char Email[128];
	char AadhaarID[16];
	char PanCard[16];
	char CustomerID[32];
	char Password[32];
	int  PreferredAccountType;
	char Address[256];
    DOB_t DOB;
}__attribute__((packed, aligned(1))) BankCustomer_t;  //in the place of 1; power of 2

//bank.c:24:1: error: requested alignment ‘3’ is not a positive power of 2
void main()
{
   printf("size = %lu", sizeof(BankCustomer_t));
   
}


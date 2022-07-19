#pragma once
typedef struct _DOB_t
{
	int Day;
	int Month;
	int Year;
}DOB_t;

typedef struct _BankCustomer_t
{
	char AccHolderName[128];
	char AccountNumber[32];
	char PhoneNumber[16];
	char Gender;
	char Email[128];
	char AadhaarID[16];
	char PanCard[16];
	char CustomerID[32];
	char Password[32];
	char Address[256];
	double Amount;
    	DOB_t DOB;
}BankCustomer_t;

typedef struct _AccountTransaction_t
{
	char TransactionType[20];
	char AccountNumber[32];
	double Amount;
	DOB_t Trans_Date;
}AccountTransaction_t;
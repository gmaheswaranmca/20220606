#pragma once
#include"cust_acc_struct.h"
void customer_bdb_insert(BankCustomer_t* Customer);
void customer_bdb_readAll(BankCustomer_t* customerAddr, int* countAddr);
void customer_bdb_random_access(BankCustomer_t* Customer, int* countAddr);
void customer_bdb_readById(BankCustomer_t* Customer, char* AadhaarId);
void customer_bdb_update(BankCustomer_t Customer);
void customer_bdb_delete(BankCustomer_t Customer);

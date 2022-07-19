#pragma once
#include"cust_acc_struct.h"

void customer_bdb_transaction_details(AccountTransaction_t * Customer);
void customer_bdb_read_customer_transactions(AccountTransaction_t *list, char* AccNum);
int customer_bdb_count_customer_transactions(char* AccNum);

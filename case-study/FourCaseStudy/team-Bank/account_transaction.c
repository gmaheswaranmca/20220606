#include "account_transaction.h"
#include<stdio.h>
#include<string.h>

void customer_bdb_transaction_details(AccountTransaction_t * Customer){
    char fileName[] = "Account_Transaction.dat";
    FILE* out = fopen(fileName,"ab");
    if(out == NULL){
        printf("FILE ERROR.\n");
        return;
    }
    
    fwrite(Customer,1,sizeof(AccountTransaction_t),out);
    
    fclose(out);
}

int customer_bdb_count_customer_transactions(char* AccNum)
{
    int I=0;
    AccountTransaction_t Tran = {};
    
    char fileName[] = "Account_Transaction.dat";
    FILE* in = fopen(fileName,"rb");
    if(in == NULL)
    {
        printf("FILE ERROR.\n");
        return 0;
    }
    while(fread(&Tran,1,sizeof(AccountTransaction_t),in))
    {
        if(!strcmp(Tran.AccountNumber,AccNum))
        {
        	I++;
        } 	
    }
    fclose(in);
    return I;
}

void customer_bdb_read_customer_transactions(AccountTransaction_t *list,char* AccNum)
{
    int I=0;
    AccountTransaction_t Tran = {};
    char fileName[] = "Account_Transaction.dat";
    
    FILE* in = fopen(fileName,"rb");
    if(in == NULL)
    {
        printf("FILE ERROR.\n");
        return;
    }
    while(fread(&Tran,1,sizeof(AccountTransaction_t),in))
    {
        if(!strcmp(Tran.AccountNumber,AccNum))
        {
        	list[I] = Tran;
        	I++;
        } 	
    }
    fclose(in);
}


#include"account_func.h"
#include<stdio.h>
#include<string.h>

void customer_bdb_insert(BankCustomer_t* Customer)
{
    char fileName[] = "Account.dat";
    FILE* out = fopen(fileName,"ab");
    if(out == NULL)
    {
        printf("FILE ERROR.\n");
        return;
    }
    fwrite(Customer,1,sizeof(BankCustomer_t),out);
    fclose(out);
}

void customer_bdb_readAll(BankCustomer_t* customers, int* countAddr)
{
    int I=0;
    BankCustomer_t Cust;
    
    char fileName[] = "Account.dat";
    FILE* in = fopen(fileName,"rb");
    if(in == NULL)
    {
        printf("FILE ERROR.\n");
        return;
    }
    while(fread(&Cust,1,sizeof(BankCustomer_t),in))
    {
        customers[I] = Cust;
        I++;
    }
    fclose(in);
    (*countAddr) = I;
}

void customer_bdb_random_access(BankCustomer_t* Customers, int* countAddr)
{
    int I=0;
    BankCustomer_t Cust;
    
    char fileName[] = "Account.dat";
    FILE* in = fopen(fileName,"rb");
    fseek(in,0,SEEK_END);
    long pos = ftell(in);
    printf("position is %ld object size is %lu\n",pos,sizeof(BankCustomer_t));	
    int numberOfAccounts = pos / sizeof(BankCustomer_t);
    printf("Number of Accounts is %d\n",numberOfAccounts);
    
    printf("Enter the Accounts index(start index is 1):");
    int index;
    scanf("%d",&index);//1 2 3
    
    int offsetToMove = (index-1) * sizeof(BankCustomer_t);
    fseek(in,offsetToMove,SEEK_SET);
    fread(&Cust,1,sizeof(BankCustomer_t),in);
    
    printf("Customer id is %s\n",Cust.AadhaarID);
    
    
    fclose(in);
    (*countAddr) = I;
}


void customer_bdb_readById(BankCustomer_t* Customer, char* AccNum){
  
    int I=0;
    BankCustomer_t Cust;
    
    char fileName[] = "Account.dat";
    FILE* in = fopen(fileName,"rb");
    if(in == NULL){
        printf("FILE ERROR.\n");
        return;
    }
    while(fread(&Cust,1,sizeof(BankCustomer_t),in)){
        if(!strcmp(Cust.AccountNumber,AccNum)){
        	(*Customer) = Cust;
        	break;
        }
        I++;
    }
    fclose(in);
}


void customer_bdb_update(BankCustomer_t Customer){
	int I=0;
    BankCustomer_t Cust;
    
    char fileName[] = "Account.dat";
    FILE* in = fopen(fileName,"rb+");
    if(in == NULL){
        printf("FILE ERROR.\n");
        return;
    }
    while(fread(&Cust,1,sizeof(BankCustomer_t),in)){
    	I++;
    	if(!(strcmp(Cust.AadhaarID, Customer.AadhaarID))){        	
        	break;
        }        
    }
    if(I > 0){
    	fseek(in,(I-1)*sizeof(BankCustomer_t),SEEK_SET);
    	fwrite(&Customer,1,sizeof(BankCustomer_t),in);
    }
    fclose(in);
}

void customer_bdb_delete(BankCustomer_t Customer){
	int I=0;
    BankCustomer_t Cust;
    
    char fileName[] = "Account.dat";
    char tempFileName[] = "Accounttemp.dat";
    FILE* in = fopen(fileName,"r");
    FILE* out = fopen(tempFileName,"w");
    if(in == NULL){
        printf("(in)FILE ERROR.\n");
        return;
    }
    if(out == NULL){
        printf("(out)FILE ERROR.\n");
        return;
    }
    while(fread(&Cust,1,sizeof(BankCustomer_t),in)){
    	I++;
    	if(strcmp(Cust.AadhaarID, Customer.AadhaarID)){        	
        	fwrite(&Cust,1,sizeof(BankCustomer_t),out);
        }        
    }    
    fclose(out);
    fclose(in); 
    remove(fileName);
    rename(tempFileName,fileName);
}

#include"cust_acc_struct.h"
#include"myutil.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"account_func.h"
#include"account_transaction.h"

int check_username_password(char *username, char *password);
void allocating_account_number(BankCustomer_t*);
void login();
void customer_ui_create_account(){
    BankCustomer_t customer={};
    clear_input_buffer();
    printf("Enter Account Holder Name :"); 
    scanf("%[^\n]s",customer.AccHolderName);
    printf("Enter Customer PhoneNumber:"); 
    clear_input_buffer(); 
    scanf("%[^\n]s",customer.PhoneNumber);
    clear_input_buffer();
    printf("Enter the Gender(M/F/T) : ");
    scanf("%c",&customer.Gender);
    printf("Enter Email :");
    clear_input_buffer(); 
    scanf("%[^\n]s",customer.Email);
    clear_input_buffer();
    printf("Enter AadhaarID : "); 
    scanf("%[^\n]s",customer.AadhaarID);
    printf("Enter Pancard : "); 
    clear_input_buffer();
    scanf("%[^\n]s",customer.PanCard);
    printf("Enter Address : ");
    clear_input_buffer(); 
    scanf("%[^\n]s",customer.Address);
    printf("Enter Date of Birth(D M Y) : ");
    clear_input_buffer(); 
    scanf("%d %d %d",&customer.DOB.Day,&customer.DOB.Month,&customer.DOB.Year);
    
    customer.Amount = 0;
    allocating_account_number(&customer);
    customer_bdb_insert(&customer);
}

void allocating_account_number(BankCustomer_t* customer)
{
   sprintf(customer->AccountNumber,"1%s",customer->AadhaarID);
}


void customer_ui_list_account(){
    BankCustomer_t customers[1000];
    int count = 0;
    customer_bdb_readAll(customers,&count);
    
    
    printf("\n\n\nCustomers(Binary File)\n\n\n");
    for(int I = 0; I < count; I++){
        printf("%d)\n",I+1);
        printf("Account Holder Name : %s\n",customers[I].AccHolderName);
        printf("Account Number : %s\n",customers[I].AccountNumber);
        printf("Phone Number:%s\n",customers[I].PhoneNumber);
        printf("Gender : %c\n",customers[I].Gender);
        printf("Email : %s\n",customers[I].Email);
        printf("Aadhaar : %s\n",customers[I].AadhaarID);
        printf("Pancard : %s\n",customers[I].PanCard);
        printf("Address : %s\n",customers[I].Address);
        printf("Date of Birth : %d/%d/%d\n",customers[I].DOB.Day, customers[I].DOB.Month, customers[I].DOB.Year);
        printf("Amount : %.2lf\n",customers[I].Amount);
    }
}
void customer_ui_find_account(){
    BankCustomer_t customer;
    char AccNum[16];
    printf("Enter Account Number to find:");
    clear_input_buffer();
    scanf("%[^\n]s",AccNum);
    customer_bdb_readById(&customer,AccNum);
    
    printf("\n\n\nThe searched customer(Binary File):\n");    
	
	printf("Account Holder Name : %s\n",customer.AccHolderName);
	printf("Account Number : %s\n",customer.AccountNumber);
        printf("Phone Number:%s\n",customer.PhoneNumber);
        printf("Gender : %c\n",customer.Gender);
        printf("Email : %s\n",customer.Email);
        printf("Aadhaar : %s\n",customer.AadhaarID);
        printf("Pancard : %s\n",customer.PanCard);
        printf("Address : %s\n",customer.Address);
        printf("Date of Birth : %d/%d/%d\n",customer.DOB.Day, customer.DOB.Month, customer.DOB.Year);
        printf("Amount : %.2lf\n",customer.Amount);
}

void customer_ui_edit_account(){
    BankCustomer_t customer;
    char AccNum[16];;
    printf("Enter customer Account Number to find: ");
    clear_input_buffer();
    scanf("%[^\n]s",AccNum);
    customer_bdb_readById(&customer,AccNum);
    
    printf("\n\n\nThe searched customer(Binary File):\n");    
	
	printf("Account Holder Name : %s\n",customer.AccHolderName);
	printf("Account Number : %s\n",customer.AccountNumber);
        printf("Phone Number:%s\n",customer.PhoneNumber);
        printf("Gender : %c\n",customer.Gender);
        printf("Email : %s\n",customer.Email);
        printf("Aadhaar : %s\n",customer.AadhaarID);
        printf("Pancard : %s\n",customer.PanCard);
        printf("Date of Birth : %d/%d/%d\n",customer.DOB.Day, customer.DOB.Month, customer.DOB.Year);
        printf("Amount : %.2lf\n",customer.Amount);
       
    printf("Enter Address(new) : "); 
    clear_input_buffer();
    scanf("%[^\n]s",customer.Address);
    customer_bdb_update(customer);	
    
    printf("Customer is updated successfully.\n");
}
void customer_ui_delete_account(){
    BankCustomer_t customer;
    char AccNum[16];
    printf("Enter Account Number to find:");
    clear_input_buffer(); 
    scanf("%[^\n]s",AccNum);
    customer_bdb_readById(&customer,AccNum);
    
    printf("\n\n\nThe searched customer(Binary File):\n");    
	
	printf("Account Holder Name : %s\n",customer.AccHolderName);
	printf("Account Number : %s\n",customer.AccountNumber);
        printf("Phone Number:%s\n",customer.PhoneNumber);
        printf("Gender : %c\n",customer.Gender);
        printf("Email : %s\n",customer.Email);
        printf("Aadhaar : %s\n",customer.AadhaarID);
        printf("Pancard : %s\n",customer.PanCard);
        printf("Address : %s\n",customer.Address);
        printf("Date of Birth : %d/%d/%d\n",customer.DOB.Day, customer.DOB.Month, customer.DOB.Year);
        printf("Amount : %.2lf\n",customer.Amount);
   
    char ch; 
    printf("Are you sure to delete(y/n)?"); clear_input_buffer(); scanf(" %c",&ch);
    if('y' == ch || 'Y' == ch){ 
    	customer_bdb_delete(customer);
    	printf("Customer is deleted successfully.\n");
    }
}

void customer_ui_deposit_account()
{
    BankCustomer_t customer;
    AccountTransaction_t transaction;
    
    printf("Enter the date(D M Y) : ");
    scanf("%d %d %d",&transaction.Trans_Date.Day,&transaction.Trans_Date.Month,&transaction.Trans_Date.Year);
    strcpy(transaction.TransactionType,"Deposit");
    
    double amount;	
	char accNum[32];
	clear_input_buffer();
	printf("Enter the Customer Account Number : ");
	scanf("%s",accNum);
	customer_bdb_readById(&customer,accNum);
	printf("Account Holder Name : %s\n",customer.AccHolderName);
	
	printf("Enter the amount to deposit : ");
	scanf("%lf",&amount);
	
    customer.Amount = customer.Amount + amount;
    customer_bdb_update(customer);
    printf("successfully depoisted\n");
    
    sprintf(transaction.AccountNumber,"%s",customer.AccountNumber);
    transaction.Amount = amount;
    customer_bdb_transaction_details(&transaction);
}

void customer_ui_withdraw_account(){
	BankCustomer_t customer;
	AccountTransaction_t transaction;
    
    printf("Enter the date(D M Y) : ");
    scanf("%d %d %d",&transaction.Trans_Date.Day,&transaction.Trans_Date.Month,&transaction.Trans_Date.Year);
    strcpy(transaction.TransactionType,"Withdraw");
    
	double amount;
	char accNum[32];
	clear_input_buffer();
	printf("Enter the Customer Account Number : ");
	scanf("%s",accNum);
	customer_bdb_readById(&customer,accNum);
	//clear_input_buffer();
	printf("Account Holder Name : %s\n",customer.AccHolderName);
	
	//scanf("%s",accNum);
	printf("Enter the amount to withdraw : ");
	scanf("%lf",&amount);
	
	if(customer.Amount < amount)
	{
	    printf("Account balance %.2f is lower than %.2f\n",customer.Amount, amount);
	    return;
	}
	else
	{
	    customer.Amount = customer.Amount - amount;
	    customer_bdb_update(customer);
	    printf("successfully withdrawn...\n");
	} 
	
	sprintf(transaction.AccountNumber,"%s",customer.AccountNumber);
    transaction.Amount = amount;
    customer_bdb_transaction_details(&transaction);  
}

void customer_ui_transfer_account()
{
    BankCustomer_t customer1, customer2;
    AccountTransaction_t transaction;
    
    printf("Enter the date(D M Y) : ");
    scanf("%d %d %d",&transaction.Trans_Date.Day,&transaction.Trans_Date.Month,&transaction.Trans_Date.Year);
    
    double amount;
    char accNum1[32], accNum2[32];
    clear_input_buffer();
    printf("Enter your Account Number : ");
    scanf("%s",accNum1);
    customer_bdb_readById(&customer1,accNum1);
    printf("Account Holder Name : %s\n",customer1.AccHolderName);
    
    printf("Enter Transferee Account Number : ");
    scanf("%s",accNum2);
    customer_bdb_readById(&customer2,accNum2);
    printf("Account Holder Name : %s\n",customer2.AccHolderName);
    
    printf("Enter the Amount you want to transfer : ");
    scanf("%lf",&amount);
    
    printf("Transfering from %s Account to %s Account\n\n",customer1.AccHolderName, customer2.AccHolderName);
    
    if(customer1.Amount < amount)
	{
	    printf("Account balance %.2f is lower than %.2f\n",customer1.Amount, amount);
	    printf("Unable to Transfer....\n");
	    return;
	}
	else
	{
	    customer1.Amount = customer1.Amount - amount;
	    customer_bdb_update(customer1);
	} 
	
	customer2.Amount = customer2.Amount + amount;
	customer_bdb_update(customer2);
	
	sprintf(transaction.AccountNumber,"%s",customer1.AccountNumber);
	strcpy(transaction.TransactionType,"withdraw");
    transaction.Amount = amount;
    customer_bdb_transaction_details(&transaction);
    
    sprintf(transaction.AccountNumber,"%s",customer2.AccountNumber);
	strcpy(transaction.TransactionType,"deposit");
    transaction.Amount = amount;
    customer_bdb_transaction_details(&transaction);
}

void customer_ui_transaction_history()
{
    char accNum[16] = {};
    BankCustomer_t Customer = {};
	printf("Enter the Account Number : ");
	scanf("%s",accNum);
	customer_bdb_readById(&Customer,accNum);
	printf("Account Holder Name : %s\n",Customer.AccHolderName);
	
	int transaction_count = customer_bdb_count_customer_transactions(accNum);
	
	AccountTransaction_t *TranList = (AccountTransaction_t*) malloc( transaction_count * sizeof(AccountTransaction_t));
	if(TranList == NULL)
	{
	     printf("Memory is not allocated\n");
	     return;
	}
	
	customer_bdb_read_customer_transactions(TranList ,accNum);
	
	int count = 5, I = 1;
    if( transaction_count < 5)
    {
         count = transaction_count;
    }
    printf("AccNum\tAccount-Name\n");
    printf("%s\t%s\n",accNum,Customer.AccHolderName);
    
    printf("S.No\t  Date  \tT-Type \t Amount\n");	
	while(count)
	{
	    printf("%d\t%d/%d/%d\t%s\t%.2lf\n",I,TranList[transaction_count-1].Trans_Date.Day,
	    								   TranList[transaction_count-1].Trans_Date.Month,
	    								   TranList[transaction_count-1].Trans_Date.Year, 
	    								   TranList[transaction_count-1].TransactionType,
	    								   TranList[transaction_count-1].Amount);
		count--;
		I++;
		transaction_count--;	
	}
	
	free(TranList);
	TranList = NULL;
}

void transaction_app(){
	int menu;
    	do{
        printf("\n\nPick Choice\n");
        printf("\t1-Deposit, 2-Withdraw, 3-Transfer, 4-Transaction History\n");
        printf("\t0-Exit\n"); 
        printf("Your Choice:"); scanf("%d",&menu);
        printf("\n");
        if(1==menu){
             customer_ui_deposit_account();
        }else if(2==menu){
            customer_ui_withdraw_account() ;
        }else if(3==menu){
             customer_ui_transfer_account();
        }else if(4==menu){
             customer_ui_transaction_history();
        }else{
            printf("Shutting down the transaction app....\n");
        }
    }
    while((1<=menu) && (menu<=3));
}

void admin_app(){
	int menu;
	
    	do{
        printf("\n\nPick Choice\n");
        printf("\t1-Create Account, 2-Read All, 3-Read by AccNum\n");
        printf("\t4-Edit Customer 5-Delete Customer 6- Transaction 999-shutting down\n");
        printf("\t0-Login\n"); 
        printf("Your Choice:"); scanf("%d",&menu);
        printf("\n");
        if(1==menu){
             customer_ui_create_account();
        }else if(2==menu){
             customer_ui_list_account();
        }else if(3==menu){
             customer_ui_find_account();
        }else if(4==menu){
             customer_ui_edit_account();
        }else if(5==menu){
             customer_ui_delete_account();
		}else if(6==menu){
             transaction_app();
        }else if(999 == menu){
      	     printf("Shutting down the app....\n");
      	     break;
        }else{
        	login();
       	}
    }
    while((1<=menu) && (menu<=999));
}
void login(){
	char Username[50];
	char Password[50];
	login_loop:
	printf ("Enter the Username : ");
	scanf("%s",Username);
	printf ("Enter the Password : ");
	scanf("%s",Password);
	if(check_username_password(Username, Password)){
		admin_app();
	}else{
	printf ("Invalid Username/Password.\n");
		goto login_loop;		
	}
}
int check_username_password(char *username, char *password)
{
    char userArray[3][50] = {"Aniprada", "Arya", "Mounika"};
    char passwordArray[3][50] ={"1234", "1234", "1234"};
    
    for(int i = 0; i<3; i++)
    {
        if((strcmp(userArray[i],username) == 0) && (strcmp(passwordArray[i],password) == 0))
           return 1;
    }
    
    return 0;
}
int main(){
    login();
    return EXIT_SUCCESS;
}

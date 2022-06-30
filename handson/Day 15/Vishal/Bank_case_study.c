//1. reading data objects from keyboard and forming doubly-linked list 
//#pragma startup app_init
//#pragma exit app_close
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
}BankCustomer_t;
//__attribute__((__packed__)) BankCustomer_t;

typedef struct _Node_t
{
	struct _Node_t *prev;
	BankCustomer_t data;
	struct _Node_t *next;
}Node_t;

Node_t *head = NULL;
Node_t *tail = NULL;

void insertNodeBack(BankCustomer_t);
Node_t * createNode(BankCustomer_t);
void readDetails(BankCustomer_t*);
void doTraversal();
void printDetails(BankCustomer_t);
void clear_input_buffer();
void destroy();
void deleteNodeFront();

void __attribute__((constructor))app_init()
{
	printf("Inside app_init\n");
}

void __attribute__((destructor))app_close()
{
    destroy();
	printf("Inside app_close\n");
} 

int main()
{
    //app_init();
	BankCustomer_t customer = {};
	int n;
	printf("\n Enter no. of customers :");
	scanf("%d",&n);
	//clear_input_buffer();
	
	
	for ( int I = 0; I<n; I++)
	{
		readDetails(&customer);
		insertNodeBack(customer);
		
	}
	
	doTraversal();
	
	
    
    //app_close();
    return 0;
}

Node_t * createNode(BankCustomer_t val)
{
   Node_t *node = (Node_t *)malloc(1*sizeof(Node_t)); // (Node_t *)calloc(1,sizeof(Node_t))
   memset(node,0,sizeof(Node_t));
   node->data = val;   //memcpy(&node->data, &val, sizeof(BankCustomer_t)) //shallow copy
   node->prev = NULL;
   node->next = NULL;
   
   return node;
}
void insertNodeBack(BankCustomer_t val)
{
	Node_t* node = createNode(val);
	
	if( head == NULL )
	{
		head = tail = node;
		
	}
    else
	{
	   tail->next = node;
	   node->prev = tail;
	   tail = node;
	}
}

void readDetails(BankCustomer_t* customerAddr)
{
	printf("\n\t\tWelcome\n\n");
	printf("\tName : ");
	clear_input_buffer();
	//fgets(customerAddr->AccHolderName,128,stdin);
	scanf("%[^\n]s",customerAddr->AccHolderName);
	clear_input_buffer();
	printf("\tPhone Number : ");
	//fgets(customerAddr->PhoneNumber,16,stdin);
	scanf("%[^\n]s",customerAddr->PhoneNumber);
	clear_input_buffer();
	printf("\tGender(M/F/T) : ");
	scanf("%c",&customerAddr->Gender);
	printf("\tEmail : ");
	scanf("%s",customerAddr->Email);
	printf("\tAadhaarID : ");
	scanf("%s",customerAddr->AadhaarID);
	printf("\tPanCard : ");
	scanf("%s",customerAddr->PanCard);
	printf("\tCustomerID : ");
	scanf("%s",customerAddr->CustomerID);
	printf("\tPassword : ");
	scanf("%s",customerAddr->Password);
	printf("\tAccount type(1-Saving 2-Current 3-Recurring Deposit 4-Fixed Deposit): ");
	scanf("%d",&customerAddr->PreferredAccountType);
	printf("\tAddress : ");
	clear_input_buffer();
	//fgets(customerAddr->Address,256,stdin);
	scanf("%[^\n]s",customerAddr->Address);
	printf("\tDate of Brith(dd mm yyyy) : ");
	scanf("%d %d %d",&customerAddr->DOB.Day, &customerAddr->DOB.Month, &customerAddr->DOB.Year);		
}

void db_bank_add(BankCustomer_t* customerAddr)
{
  char filename [] = "bank.dat";
  FILE* out = fopen(filename, "ab");
  if(out == NULL)
  {
     printf("FILE ERROR");
  }
  else
  {
    fwrite(customerAddr, sizeof(BankCustomer_t), 1, out);
  }
  fclose(out); 
}

void doTraversal()
{
	Node_t *node = head;
	
	if( node == NULL )
	{
	    printf("\n\n Customer List is Empty ....\n");
	}
    else
	{
	    do
		{
			//printDetails(node->data);
			db_bank_add(&node->data);
			node = node->next;
        }while(node != NULL);
	}	
}

void printDetails(BankCustomer_t val)
{
   printf("\n\n\n\n");
   printf("\tName : %s\n",val.AccHolderName);
   printf("\tPhone Number : %s\n",val.PhoneNumber);
   printf("\tGender : %c\n",val.Gender);
   printf("\tEmail : %s\n",val.Email);
   printf("\tAadhaarID : %s\n",val.AadhaarID);
   printf("\tPanCard : %s\n",val.PanCard);
   printf("\tCustomerID : %s\n",val.CustomerID);
   printf("\tPassword : %s\n",val.Password);
   printf("\tPreferred Account Type : %d\n",val.PreferredAccountType);
   printf("\tAddress : %s\n",val.Address);
   printf("\tDate of Birth : %d/%d/%d\n",val.DOB.Day, val.DOB.Month, val.DOB.Year);   
}

void clear_input_buffer()
{
	while(getchar() != '\n');
}

void destroy()
{
	
	if( head == NULL )
	{
	    //printf("\n\n Customer List is Empty ....\n");
	}
    else
	{
	    do
		{
			deleteNodeFront();
        }while(head != NULL);
	}	
}

void deleteNodeFront()
{
   Node_t* node = head;
   if(head->next != NULL)
   {
      head->next->prev = NULL;
      head = head->next;
   }
   else
   {
   	  head = tail = NULL; 	  
   } 
   printDetails(node->data);
   node->next = NULL;
   free(node);  
}
   		








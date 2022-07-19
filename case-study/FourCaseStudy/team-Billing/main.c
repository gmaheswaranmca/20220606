
#include"db.h"
#include"myutil.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void ui_product_create(){
    int N;
    printf("Enter Number of products:");
    scanf("%d",&N);
   
    for (int i =0 ;i< N;i++)
    {
    	ProductCatalog_t prd={};
    	printf("Enter Product id:"); 
    	scanf("%d",&prd.product_id);
    	printf("Enter product name:"); 
    	clear_input_buffer(); 
    	scanf("%[^\n]s",prd.product_name);
    	ProductCatalog_t prdTemp;
        prd_db_find_ByName(&prdTemp,prd.product_name);
        if(strcmp(prdTemp.product_name,prd.product_name)==0)
        {
        	printf("Product already exist!!!");
        	break;
        }
    	printf("Enter Quantity:"); 
    	scanf("%d",&prd.qty);
    	printf("Enter price:"); 
    	scanf("%f",&prd.price);
   
    	prd_db_insert(&prd);
    }
}
void ui_product_show_all(){
    ProductCatalog_t prdts[1000];
    int count = 0;
    prd_db_readAll(prdts,&count);
    
    
    printf("\n\n\t\t\t\tProducts\n\n\n");
    printf("\tProduct id\tProduct name\tProduct quantity\tPrice\n");
    printf("------------------------------------------------------------------------------------------------------------------\n\n");
    for(int I = 0; I < count; I++){
        printf("\t%d",prdts[I].product_id);
        printf("\t\t%s",prdts[I].product_name);
        printf("\t\t%d",prdts[I].qty);
        printf("\t\t%f\n",prdts[I].price);
    }
    
}

void ui_order_view(){
    Order_t ordrs[1000];
    int count = 0;
    prd_db_readAll_order(ordrs,&count);
    
    if(count == 0)
    {
    	printf("No order available!!!");
    }
    else
    {
    	printf("\n\n\t\t\t\tOrders\n\n\n");
    	printf("\tOrder id\tCustomer Name\tProduct name\tProduct quantity\tPrice\n");
    	printf("------------------------------------------------------------------------------------------------------------------\n\n");
    	for(int I = 0; I < count; I++){
        	printf("\t%d",ordrs[I].order_id);
         	printf("\t\t%s",ordrs[I].custName);
        	printf("\t\t%s",ordrs[I].product_name);
        	printf("\t\t%d",ordrs[I].qty);
        	printf("\t\t%f\n",ordrs[I].price);
    	}
    }
    
}


void ui_product_update(){
    ProductCatalog_t prd;
    int id,choice;
    printf("Enter product Id to update:"); 
    scanf("%d",&id);
    prd_db_find(&prd,id);
    if(prd.product_id == id)
    {
    	printf("\n\n\nThe searched Product:\n");    
	printf("Product id:%d\n",prd.product_id);
	printf("Product name:%s\n",prd.product_name);
	printf("Quantity:%d\n",prd.qty);
	printf("Price:%.2lf\n\n\n",prd.price);
	printf("Enter the field to edit: 1.Product Name\t2.Quantity\t3.Price\n");
	printf("Enter your choice : ");
	scanf("%d",&choice);
	switch(choice){
	    case 1:
	        printf("Enter new product name:");
	        scanf("%s",prd.product_name);
	        prd_db_update(prd);
	        printf("Product is updated successfully.\n");
	        break;
	    case 2:
	        printf("Enter new product quantity:");
	        scanf("%d",&prd.qty);
	        prd_db_update(prd);
	        printf("Product is updated successfully.\n");
	        break;
	     case 3:
	        printf("Enter price value to be updated:");
	        scanf("%f",&prd.price);
	        prd_db_update(prd);
	        printf("Product is updated successfully.\n");
	        break;
	     default:
	        printf("Wrong choice");
	}
    }
    else{
    	printf("Item does not exist!!!");
    }
   
}
 void ui_product_delete(){
    ProductCatalog_t prd;
    int id;
    printf("Enter product Id to delete:"); 
    scanf("%d",&id);
    prd_db_find(&prd,id);
    
    if(prd.product_id == id)
    {
	    printf("\n\n\nThe searched Product :\n");    
		
	    printf("Product id:%d\n",prd.product_id);
	    printf("Product name:%s\n",prd.product_name);
	    printf("Quantity:%d\n",prd.qty);
	    printf("Price:%.2lf\n\n\n",prd.price);
	   
	    char ch; 
	    printf("Are you sure you want to delete!!! If yes press Y else N :"); 
	    clear_input_buffer(); 
	    scanf("%c",&ch);
	    if('y' == ch || 'Y' == ch){ 
	    	prd_db_delete(prd.product_id);
	    	printf("Product is deleted successfully.\n");
	    }
    }
    else
    {
    	printf("Item doesnot exist!!!");
    }
}

void ui_billing(){

    int id,choice;
    float total = 0.0;
    printf("Enter Order Id for billing:"); 
    scanf("%d",&id);
    Order_t odrs[1000];
    int count = 0;
    prd_db_findOrderId(odrs,&count,id);
    if(count > 0)
    {
    	printf("Order Id :%d\n", odrs[0].order_id);
    	printf("Name :%s\n", odrs[0].custName);
    	printf("Phone Number :%s\n", odrs[0].phone);
    	printf("Product name\tQuantity\tPrice\n");
    	printf("____________________________________\n");
    	for(int i =0;i<count;i++)
    	{
    		printf("%s\t%d\t%f\n",odrs[i].product_name,odrs[i].qty,odrs[i].price);
    		total+= odrs[i].price;
    	}
    	printf("\n\t\tTotal Amount: %f\n",total); 
    	printf("Bill is generated ....");
    	prd_db_delete_order(id);  
    		
    }
    else{
    	printf("no order available!!!");
    }
    
    
    
}

int ui_AdminLogin_create()

{
	int menu; 
	do{
		printf("\n\nPick Choice\n");
		printf("\t1-Create Product\t2-Read All");
		printf("\t3-Update\t4-Delete Product\t5-View Order\n");
		printf("\t6.Billing\t0-Exit\n"); 
		printf("Your Choice:"); scanf("%d",&menu);
		printf("\n");
		if(menu<=6)
		{
		
		switch(menu)
		{
		case 1:
			ui_product_create();
			break;
		case 2:
			ui_product_show_all();
			break;
		case 3:
			ui_product_update();
			break;
		case 4:
			ui_product_delete();
			break;
		case 5:
			ui_order_view();
			break;
		case 6:
			ui_billing();
			break;
		default:
			printf("Shutting down the app....\n");
		}
		}
		else {
          printf("Enter the Correct choice");
          }
          
	}while((1<=menu) && (menu<=5));
	return EXIT_SUCCESS;
}

int Login_password()
{
	printf("\n\nEnter username and password to access the admin login\n");
	char username[15]; 
	char password[12]; 
	printf("Enter your username:\n"); 
	scanf("%s",username); 
	printf("Enter your password:\n"); 
	scanf("%s",password); 
	if(strcmp(username,"billing")==0){ 
		if(strcmp(password,"123")==0){ 
			ui_AdminLogin_create();
		}else{ 
			printf("\nwrong password"); 
		} 
	}else{ 
		printf("\nUser doesn't exist"); 
	} 
}
 
 
void ui_product_show_all_in_cart(){
    ProductCatalog_t prdts[1000];
    int count = 0;
    prd_db_readAll_from_cart(prdts,&count);
    if(count == 0)
    {
    	printf("Cart is Empty!!!");
    }
    else
    {
    	printf("\n\t\tProduct Cart\n\n");
    	printf("\tProduct name\tProduct quantity\n");
    	printf("--------------------------------------------------------------\n");
    	for(int I = 0; I < count; I++){
       	printf("\t%s",prdts[I].product_name);
        	printf("\t\t%d\n",prdts[I].qty);
        }
     }
    
}

void ui_place_order(){
    ProductCatalog_t prdts[1000];
    Order_t order[1000];
    int oId;
    char cName[50],phone[20];
    int count = 0;
    prd_db_readAll_from_cart(prdts,&count);
    if(count == 0)
    {
    	printf("Cart is Empty!!!");
    }
    else
    {
    
    	printf("Enter Order Id:");
    	scanf("%d",&oId);
    	printf("Enter Name:");
    	scanf("%s",cName);
    	printf("Enter Phone number:");
    	scanf("%s",phone);
    	
    	for(int i=0;i<count;i++)
    	{
    		
    		strcpy(order[i].product_name,prdts[i].product_name);
    		order[i].order_id = oId;
    		strcpy(order[i].custName,cName);
    		strcpy(order[i].phone,phone);
    		order[i].qty = prdts[i].qty;
    		order[i].price = prdts[i].price;
    		prd_db_insert_order(&order[i]);
    		ProductCatalog_t prdTemp;
        	prd_db_find_ByName(&prdTemp,prdts[i].product_name);
        	prdTemp.qty = prdTemp.qty - prdts[i].qty;
        	prd_db_update(prdTemp);
    	}
    	
    	printf("Order placed successfully");
    }
    
}

void ui_cancel_order(){
    int id,choice;
    float total = 0.0;
    printf("Enter Order Id for cancel:"); 
    scanf("%d",&id);
    Order_t odrs[1000];
    int count = 0;
    prd_db_findOrderId(odrs,&count,id);
    if(count > 0)
    {
    	printf("Order Id :%d\n", odrs[0].order_id);
    	printf("Name :%s\n", odrs[0].custName);
    	printf("Phone Number :%s\n", odrs[0].phone);
    	printf("Product name\tQuantity\tPrice\n");
    	printf("____________________________________\n");
    	for(int i =0;i<count;i++)
    	{
    		printf("%s\t%d\t%f\n",odrs[i].product_name,odrs[i].qty,odrs[i].price);
    		total+= odrs[i].price;
    	}
    	char ch; 
    	printf("Are you sure you want to delete!!! If yes press Y else N :"); 
    	clear_input_buffer(); 
    	scanf("%c",&ch);
    	if('y' == ch || 'Y' == ch){ 
    		prd_db_delete_order(id); 
    		printf("Order cancelled!!!\n");
    	}
    	 
    		
    }
    else{
    	printf("no order available!!!");
    }
    
}


void ui_Add_to_cart(){
    int N;
    printf("Enter Number of products:");
    scanf("%d",&N);
   
    for (int i =0 ;i< N;i++)
    {
    	ProductCatalog_t prdTemp;
    	
    	ProductCatalog_t prd={};
   	printf("Enter product name:"); 
    	clear_input_buffer(); 
    	scanf("%[^\n]s",prd.product_name);
    	printf("Enter Quantity:"); 
    	scanf("%d",&prd.qty);
    	prd_db_find_ByName(&prdTemp,prd.product_name);
    	if(strcmp(prdTemp.product_name,"")==0)
    	{
    		printf("Item doesnot exist!!!");
    		break;
    	}
    	if(prd.qty > prdTemp.qty)
    	{
    		printf("Quantity exceeded!!!");
    		break;
    	}
    	prd.price = prd.qty * prdTemp.price;
    	prd_db_insert_cart(&prd);
    }
}
void ui_product_update_to_cart(){
    ProductCatalog_t prd;
    
    char product_name[50];
    printf("Enter product name to update:"); 
    scanf("%s",product_name);
    prd_db_find_at_cart(&prd,product_name);
    if(strcmp(prd.product_name,product_name)==0)
    {
    	printf("\n\n\nThe searched Product Details:\n");    
    	printf("Product name:%s\n",prd.product_name);
    	printf("Quantity:%d\n",prd.qty);
    	printf("Enter new product quantity:");
    	scanf("%d",&prd.qty);
    	ProductCatalog_t prdTemp;
    	prd_db_find_ByName(&prdTemp,prd.product_name);
    	if(prd.qty > prdTemp.qty)
    	{
    		printf("Quantity exceeded!!!");
    	}
    	else
    	{
    		prd.price = prd.qty * prdTemp.price;
    		prd_db_update_cart(prd);
    		printf("Product is updated successfully.\n");
    	}
    }
    else
    {
    	printf("Item doesnot exist!!!");
    }
}
void ui_product_delete_to_cart(){
    ProductCatalog_t prd ={};
    char product_name[50];
    printf("Enter product name to delete:"); 
    prd_db_find_at_cart(&prd,product_name);
    if(strcmp(prd.product_name,product_name)==0)
    {
   	    printf("\n\n\nThe searched Product_name :%s \n", prd.product_name);    
	    printf("Quantity:%d\n",prd.qty);
	    char ch; 
	    printf("Are you sure you want to delete!!! If yes press Y else N :"); 
	    clear_input_buffer(); 
	    scanf("%c",&ch);
	    if('y' == ch || 'Y' == ch){ 
	    	 prd_db_delete_cart(product_name);
	    	 printf("Product is deleted successfully.\n");
	    	
	    }
    }
    else
    {
    	printf("Item doesnot exist!!!");
    }
}	
int ui_UserLogin_create()
{
	int menu2;
	printf("WELCOME TO USER LOGIN");

 	do{
          printf("\n\nEnter your choice\n");
          printf("\t1-Display Stock Items to be selected\t2-Add to cart\t3-Update cart\t4- Delete cart\t5- Display cart\n");
          printf("\t6-Place Order\t7-Cancel Order");
          printf("\t0-Exit\n"); 
          printf("Your Choice:"); 
          scanf("%d",&menu2);
          printf("\n");
          if(1==menu2){
          	ui_product_show_all();
          }else if(2==menu2){
   		ui_Add_to_cart();
          }
          else if(3==menu2){
          	ui_product_update_to_cart();
          }
          else if(4==menu2){
           	ui_product_delete_to_cart();
          }
          else if(5==menu2){
          	ui_product_show_all_in_cart();
          }
          else if(6==menu2){
          	ui_place_order();
          }
          else if(7==menu2){
          	ui_cancel_order();
          }
          else
          {
          printf("Enter the Correct choice");
          }
     }while((1<=menu2) && (menu2<=6));
     return EXIT_SUCCESS;
}


int main(){
    int menu,menu1;
     printf("\n\t\t**********************Billing Application*********************************\n");
     
     do{
          printf("\n\nEnter choice for Login\n");
          printf("\t1-Admin Login\t2-User Login\n");
          printf("\t0-Exit\n"); 
          printf("Your Choice:"); 
          scanf("%d",&menu1);
          printf("\n");
          if(1==menu1){
          	Login_password();
	   }
	  else if(2==menu1){
          	ui_UserLogin_create();
          }
           else
          {
          printf("Enter the Correct choice");
          }
          
   }while((1<=menu1) && (menu1>2));
   return EXIT_SUCCESS;
}


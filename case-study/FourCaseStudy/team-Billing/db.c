#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "db.h"

 void prd_db_insert(ProductCatalog_t* val){
   
    char fileName[] = "billing.dat";
    FILE* out = fopen(fileName,"ab");
    if(out == NULL){
        printf("FILE ERROR.\n");
        return;
    }
    
    fwrite(val,1,sizeof(ProductCatalog_t),out);
    fclose(out);
 }
 void prd_db_insert_cart(ProductCatalog_t* val1){
   
    char fileName[] = "cart.dat";
    FILE* out1 = fopen(fileName,"ab");
    if(out1 == NULL){
        printf("FILE ERROR.\n");
        return;
    }
    
    fwrite(val1,1,sizeof(ProductCatalog_t),out1);
    fclose(out1);
 }
 
 void prd_db_insert_order(Order_t* val1){
   
    char fileName[] = "order.dat";
    FILE* out1 = fopen(fileName,"ab");
    if(out1 == NULL){
        printf("FILE ERROR.\n");
        return;
    }
    
    fwrite(val1,1,sizeof(Order_t),out1);
    fclose(out1);
    remove("cart.dat");
 }
 
 void prd_db_readAll(ProductCatalog_t* val, int* count){
    
    int I=0;
    ProductCatalog_t prd;
    
    char fileName[] = "billing.dat";
    FILE* in = fopen(fileName,"rb");
    if(in == NULL){
        printf("FILE ERROR.\n");
        return;
    }
    while(fread(&prd,1,sizeof(ProductCatalog_t),in)){
        val[I] = prd;
        I++;
    }
    fclose(in);
   (*count) = I;
}
void prd_db_readAll_from_cart(ProductCatalog_t* val1, int* count){
    
    int I=0;
    ProductCatalog_t prd;
    
    char fileName[] = "cart.dat";
    FILE* in = fopen(fileName,"rb");
    if(in == NULL){
        printf("FILE ERROR.\n");
        return;
    }
    while(fread(&prd,1,sizeof(ProductCatalog_t),in)){
        val1[I] = prd;
        I++;
    }
    fclose(in);
   (*count) = I;
}
void prd_db_readAll_order(Order_t* val, int* count){
    
    int I=0;
    Order_t prd;
    
    char fileName[] = "order.dat";
    FILE* in = fopen(fileName,"rb");
    if(in == NULL){
        printf("FILE ERROR.\n");
        return;
    }
    while(fread(&prd,1,sizeof(Order_t),in)){
        val[I] = prd;
        I++;
    }
    fclose(in);
   (*count) = I;
} 
 void prd_db_read(int index, ProductCatalog_t* addr){
     
    char fileName[] = "billing.dat";
    int I=0;
    ProductCatalog_t p;
    FILE* in = fopen(fileName,"r");
    if(in == NULL)
    {
        printf("FILE ERROR.\n");
        return;
    }
    
    while(fread(&p,1,sizeof(ProductCatalog_t),in))
    {
        int counter = 1;
        if(counter == index)
        {
            (*addr) = p;
            break;
        }
        I++;
    }
    
    fclose(in);
     
 }
 
void prd_db_read_from_cart(int index1, ProductCatalog_t* addr){
     
    char fileName[] = "cart.dat";
    int I=0;
    ProductCatalog_t p;
    FILE* in = fopen(fileName,"r");
    if(in == NULL)
    {
        printf("FILE ERROR.\n");
        return;
    }
    
    while(fread(&p,1,sizeof(ProductCatalog_t),in))
    {
        int counter = 1;
        if(counter == index1)
        {
            (*addr) = p;
            break;
        }
        I++;
    }
    
    fclose(in);
     
 }
 

void prd_db_find( ProductCatalog_t* addr, int productId){
     
     int I=0;
    ProductCatalog_t p;
    
    char fileName[] = "billing.dat";
    FILE* in = fopen(fileName,"rb");
    if(in == NULL){
        printf("FILE ERROR.\n");
        return;
    }
    while(fread(&p,1,sizeof(ProductCatalog_t),in)){
       
        if(p.product_id == productId){
        	(*addr) = p;
        	break;
        }
        I++;
    }
    fclose(in);
     
 }
 
 
 void prd_db_findOrderId( Order_t* val, int* count, int orderId){
     
    int I=0;
    Order_t o;
    
    char fileName[] = "order.dat";
    FILE* in = fopen(fileName,"rb");
    if(in == NULL){
        printf("FILE ERROR.\n");
        return;
    }
    while(fread(&o,1,sizeof(Order_t),in)){
        if(o.order_id == orderId){
        	val[I] = o;
        	I++;
        }
        
    }
    fclose(in);
    (*count) = I; 
 }
 
 void prd_db_find_ByName( ProductCatalog_t* addr, char productName[]){
     
    int I=0;
    ProductCatalog_t p;
    
    char fileName[] = "billing.dat";
    FILE* in = fopen(fileName,"rb");
    if(in == NULL){
        printf("FILE ERROR.\n");
        return;
    }
    while(fread(&p,1,sizeof(ProductCatalog_t),in)){
       
        if(strcmp(p.product_name,productName)==0){
        	(*addr) = p;
        	break;
        }
        I++;
    }
    fclose(in);
     
 }
void prd_db_find_at_cart( ProductCatalog_t* addr, char product_name[]){
     
     int I1=0;
    ProductCatalog_t p = {};
    
    char fileName[] = "cart.dat";
    FILE* in = fopen(fileName,"rb");
    if(in == NULL){
        printf("FILE ERROR.\n");
        return;
    }
    while(fread(&p,1,sizeof(ProductCatalog_t),in)){
      
       if(strcmp(p.product_name,product_name)==0){
        	printf("!%s ", p.product_name);
        	(*addr) = p;
        	break;
        	
        }
        I1++;
       
    }
    fclose(in);
     
 }

 
 void prd_db_update(ProductCatalog_t val){
 	    
    int I=0;
    ProductCatalog_t p;
    
    char fileName[] = "billing.dat";
    FILE* in = fopen(fileName,"rb+");
    if(in == NULL){
        printf("FILE ERROR.\n");
        return;
    }
    while(fread(&p,1,sizeof(ProductCatalog_t),in)){
    	I++;
        if(p.product_id == val.product_id){        	
        	break;
        }        
    }
    if(I > 0){
    	fseek(in,(I-1)*sizeof(ProductCatalog_t),SEEK_SET);
    	fwrite(&val,1,sizeof(ProductCatalog_t),in);
    }
    fclose(in);
 }
 void prd_db_update_cart(ProductCatalog_t val){
    int I=0;
    ProductCatalog_t p;
    
    char fileName[] = "cart.dat";
    FILE* in = fopen(fileName,"rb+");
    if(in == NULL){
        printf("FILE ERROR.\n");
        return;
    }
    while(fread(&p,1,sizeof(ProductCatalog_t),in)){
    	I++;
        if(strcmp(p.product_name,val.product_name)==0){        	
        	break;
        }        
    }
    if(I > 0){
    	fseek(in,(I-1)*sizeof(ProductCatalog_t),SEEK_SET);
    	fwrite(&val,1,sizeof(ProductCatalog_t),in);
    }
    fclose(in);
 }
 
 void prd_db_delete(int index){

    char fileName[] = "billing.dat";
    char tempFileName[] = "billingtemp.dat";
    ProductCatalog_t p;
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
     while(fread(&p,1,sizeof(ProductCatalog_t),in)){
       if(index != p.product_id)
       {        	
            fwrite(&p,1,sizeof(ProductCatalog_t),out);
       } 
    }    
    fclose(out);
    fclose(in); 
    remove(fileName);
    rename(tempFileName,fileName);
     
 }
 void prd_db_delete_cart(char product_name[]){

    char fileName[] = "cart.dat";
    char tempFileName[] = "carttemp.dat";
    ProductCatalog_t p;
    FILE* in1 = fopen(fileName,"r");
    FILE* out1 = fopen(tempFileName,"w");
    if(in1 == NULL){
        printf("(in)FILE ERROR.\n");
        return;
    }
    if(out1 == NULL){
        printf("(out)FILE ERROR.\n");
        return;
    }
     while(fread(&p,1,sizeof(ProductCatalog_t),in1)){
        if(strcmp(p.product_name,product_name) != 0)
       {        	
            fwrite(&p,1,sizeof(ProductCatalog_t),out1);
       } 
    }     
    fclose(out1);
    fclose(in1); 
    remove(fileName);
    rename(tempFileName,fileName);
     
 }
 
 void prd_db_delete_order(int orderId){

    char fileName[] = "order.dat";
    char tempFileName[] = "ordertemp.dat";
    Order_t o;
    FILE* in1 = fopen(fileName,"r");
    FILE* out1 = fopen(tempFileName,"w");
    if(in1 == NULL){
        printf("(in)FILE ERROR.\n");
        return;
    }
    if(out1 == NULL){
        printf("(out)FILE ERROR.\n");
        return;
    }
     while(fread(&o,1,sizeof(Order_t),in1)){
        if(o.order_id != orderId)
       {        	
            fwrite(&o,1,sizeof(Order_t),out1);
       } 
    }     
    fclose(out1);
    fclose(in1); 
    remove(fileName);
    rename(tempFileName,fileName);
     
 }
 

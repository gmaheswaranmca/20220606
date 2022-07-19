#pragma once

typedef struct _PRODUCT
{
    int product_id;
    char product_name[50];
    int qty;
    float price;
}ProductCatalog_t;

typedef struct _ORDER
{
    int order_id;
    char product_name[50];
    int qty;
    float price;
    char phone[20];
    char custName[50];
}Order_t;

    void prd_db_insert(ProductCatalog_t* val);//completed
    void prd_db_find( ProductCatalog_t* addr, int product_id);
    void prd_db_update(ProductCatalog_t val);
    void prd_db_read(int index, ProductCatalog_t* addr);
    int prd_db_count();
    void prd_db_readAll(ProductCatalog_t* products,int* count);
    void prd_db_delete(int index);
    void prd_db_insert_cart(ProductCatalog_t* val1);
    void prd_db_readAll_from_cart(ProductCatalog_t* val1, int* count);
    void prd_db_find_at_cart( ProductCatalog_t* addr, char product_name[]);
    void prd_db_read_from_cart(int index1, ProductCatalog_t* addr);
    void prd_db_update_cart(ProductCatalog_t val1);
    void prd_db_delete_cart(char product_name[]);
    void prd_db_insert_order(Order_t* val1);
    void prd_db_readAll_order(Order_t* val, int* count);
    void prd_db_find_ByName( ProductCatalog_t* addr, char productName[]);
    void prd_db_findOrderId( Order_t* val, int* count, int orderId);
    void prd_db_delete_order(int orderId);

//1. reading data objects from keyboard and forming doubly-linked list 
//#pragma startup app_init
//#pragma exit app_close

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"dlist.h"
Node_t *head = NULL;
Node_t *tail = NULL;
Node_t * createNode(book_t val)
{
   Node_t *node = (Node_t *)malloc(1*sizeof(Node_t)); // (Node_t *)calloc(1,sizeof(Node_t))
   memset(node,0,sizeof(Node_t));
   node->data = val;   //memcpy(&node->data, &val, sizeof(book_t)) //shallow copy
   node->prev = NULL;
   node->next = NULL;
   
   return node;
}
void insertNodeBack(book_t val)
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
   node->next = NULL;
   free(node);  
}
void doTraversal(fn_t printBook)
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
			printBook(&node->data);
			node = node->next;
        }while(node != NULL);
	}	
}		








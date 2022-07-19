#pragma once
#include"object_t.h"
typedef struct _Node_t
{
	struct _Node_t *prev;
	book_t data;
	struct _Node_t *next;
}Node_t;
typedef void (*fn_t)(book_t* addr);
extern Node_t *head ;
extern Node_t *tail ;

void insertNodeBack(book_t);
Node_t * createNode(book_t);
void destroy();
void deleteNodeFront();
void doTraversal(fn_t printBook);

#pragma once
#include"object_t.h"
#include"book_bdb.h"
#include<stdio.h>
#include<string.h>
void book_insert(book_t* book);
void book_readAll(book_t* book, int* countAddr);
void book_delete(int id);
void book_readById(book_t* bookAddr, int bookId);
void book_update(book_t book);


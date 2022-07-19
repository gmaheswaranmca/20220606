#pragma once
#include"object_t.h"
#include"user_bdb.h"
#include<stdio.h>
#include<string.h>
void user_insert(user_t* user);
void user_readAll(user_t* user, int* countAddr);
void user_delete(int id);
void user_readById(user_t* userAddr, int userId);
void user_update(user_t* userAddr);


#pragma once
#include"flight_t.h"
void flight_db_create(flight_t *addr);
int flight_db_find_by_id(int flight_id);
int flight_db_find_by_number(char *flight_number);
void flight_db_update(flight_t *addr, int index);
void flight_db_delete(flight_t *addr, int index);
int flight_db_count();
void flight_db_read_all(flight_t* array,int size);

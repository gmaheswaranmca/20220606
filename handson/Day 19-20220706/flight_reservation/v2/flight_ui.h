#pragma once
#include"flight_t.h"
void ui_flight_create(flight_t* addr);
void ui_flight_update(flight_t* addr);
void ui_flight_delete(flight_t* addr, int *is_confirmed_addr);
void ui_flight_show_all(flight_t* flights, int size, int* action_type_addr, int* index_addr);

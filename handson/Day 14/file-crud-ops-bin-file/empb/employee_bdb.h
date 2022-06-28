#pragma once
#include"employee_t.h"
void emp_bdb_insert(employee_t* employeeAddr);
void emp_bdb_readAll(employee_t* employeeAddr, int* countAddr);
void emp_bdb_random_access(employee_t* employees, int* countAddr);
void emp_bdb_readById(employee_t* employeeAddr, int empId);
void emp_bdb_update(employee_t employee);
void emp_bdb_delete(employee_t employee);



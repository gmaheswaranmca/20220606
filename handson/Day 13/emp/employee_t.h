#pragma once
#include"date_t.h"
struct _employee_t{
 int empId;
 char empName[256];
 date_t dateOfJoining;
 char jobTitle[256];
 int deptId;
 double salary;
};
typedef struct _employee_t employee_t;
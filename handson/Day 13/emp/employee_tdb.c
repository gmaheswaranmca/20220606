#include"employee_tdb.h"
#include<stdio.h>
#include<string.h>
void emp_tdb_insert(employee_t* employeeAddr){
    //CODE for writing into the flat file db "emp.txt"
    char fileName[] = "emp.txt";
    FILE* out = fopen(fileName,"a");
    if(out == NULL){
        printf("FILE ERROR.\n");
        return;
    }
    
    fprintf(out, "\n%d %s %02d-%02d-%04d %s %d %lf",
        employeeAddr->empId,
        employeeAddr->empName,
        employeeAddr->dateOfJoining.day,employeeAddr->dateOfJoining.month,employeeAddr->dateOfJoining.year,
        employeeAddr->jobTitle,
        employeeAddr->deptId,
        employeeAddr->salary);
    
    fclose(out);
}
void emp_tdb_readAll(employee_t* employees, int* countAddr){
    //CODE for reading from the flat file db "emp.txt"
    int I=0;
    employee_t emp;
    
    char fileName[] = "emp.txt";
    FILE* in = fopen(fileName,"r");
    if(in == NULL){
        printf("FILE ERROR.\n");
        return;
    }
    char line[1000];
    
    //fgets(line,1000,in); printf("[DEBUG:%s(%d)]\n",line,strlen(line));
    while(fgets(line,1000,in)){
        if(strlen(line) > 1){
            sscanf(line, "%d %s %02d-%02d-%04d %s %d %lf",
                &emp.empId,
                emp.empName,
                &emp.dateOfJoining.day,&emp.dateOfJoining.month,&emp.dateOfJoining.year,
                emp.jobTitle,
                &emp.deptId,
                &emp.salary);
            employees[I] = emp;
            I++;
        }
        //fgets(line,1000,in);printf("[DEBUG:%s(%d)]\n",line,strlen(line));
    }
    fclose(in);
    (*countAddr) = I;
}


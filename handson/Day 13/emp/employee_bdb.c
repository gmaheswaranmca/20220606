#include"employee_bdb.h"
#include<stdio.h>
#include<string.h>
void emp_bdb_insert(employee_t* employeeAddr){
    //CODE for writing into the flat file db "emp.dat"
    char fileName[] = "emp.dat";
    FILE* out = fopen(fileName,"ab");
    if(out == NULL){
        printf("FILE ERROR.\n");
        return;
    }
    
    fwrite(employeeAddr,1,sizeof(employee_t),out);
    
    fclose(out);
}
void emp_bdb_readAll(employee_t* employees, int* countAddr){
    //CODE for reading from the flat file db "emp.dat"
    int I=0;
    employee_t emp;
    
    char fileName[] = "emp.dat";
    FILE* in = fopen(fileName,"rb");
    if(in == NULL){
        printf("FILE ERROR.\n");
        return;
    }
    while(fread(&emp,1,sizeof(employee_t),in)){
        employees[I] = emp;
        I++;
    }
    fclose(in);
    (*countAddr) = I;
}


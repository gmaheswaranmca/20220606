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
void emp_bdb_random_access(employee_t* employees, int* countAddr){
    //CODE for reading from the flat file db "emp.dat"
    int I=0;
    employee_t emp;
    
    char fileName[] = "emp.dat";
    FILE* in = fopen(fileName,"rb");
    fseek(in,0,SEEK_END);
    long pos = ftell(in);
    printf("position is %ld object size is %lu\n",pos,sizeof(employee_t));	
    int numberOfEmployees = pos / sizeof(employee_t);
    printf("Number of employees is %d\n",numberOfEmployees);
    
    printf("Enter the employee index(start index is 1):");
    int index;
    scanf("%d",&index);//1 2 3
    
    int offsetToMove = (index-1) * sizeof(employee_t);
    fseek(in,offsetToMove,SEEK_SET);
    fread(&emp,1,sizeof(employee_t),in);
    
    printf("emp id is %d\n",emp.empId);
    
    
    fclose(in);
    (*countAddr) = I;
}


void emp_bdb_readById(employee_t* employeeAddr, int empId){
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
        //employees[I] = emp;
        if(emp.empId == empId){
        	(*employeeAddr) = emp;
        	break;
        }
        I++;
    }
    fclose(in);
}

void emp_bdb_update(employee_t employee){
	int I=0;
    employee_t emp;
    
    char fileName[] = "emp.dat";
    FILE* in = fopen(fileName,"rb+");
    if(in == NULL){
        printf("FILE ERROR.\n");
        return;
    }
    while(fread(&emp,1,sizeof(employee_t),in)){
    	I++;
        if(emp.empId == employee.empId){        	
        	break;
        }        
    }
    if(I > 0){
    	fseek(in,(I-1)*sizeof(employee_t),SEEK_SET);
    	fwrite(&employee,1,sizeof(employee_t),in);
    }
    fclose(in);
}

void emp_bdb_delete(employee_t employee){
	int I=0;
    employee_t emp;
    
    char fileName[] = "emp.dat";
    char tempFileName[] = "emptemp.dat";
    FILE* in = fopen(fileName,"r");
    FILE* out = fopen(tempFileName,"w");
    if(in == NULL){
        printf("(in)FILE ERROR.\n");
        return;
    }
    if(out == NULL){
        printf("(out)FILE ERROR.\n");
        return;
    }
    while(fread(&emp,1,sizeof(employee_t),in)){
    	I++;
        if(emp.empId != employee.empId){        	
        	fwrite(&emp,1,sizeof(employee_t),out);
        }        
    }    
    fclose(out);
    fclose(in); 
    //rename the emptemp.dat as emp.dat
    remove(fileName);
    rename(tempFileName,fileName);
}

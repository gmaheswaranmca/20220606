#include"employee_bdb.h"
#include"myutil.h"
#include<stdio.h>
#include<stdlib.h>

void emp_ui_create_emp(){
    employee_t employee={};
    printf("Enter employee id:"); scanf("%d",&employee.empId);
    printf("Enter employee name:"); clear_input_buffer(); scanf("%[^\n]s",employee.empName);
    char dateOfJoining_str[20];
    printf("Enter date of joining(format dd-MM-yyyy):"); scanf("%s",dateOfJoining_str);
    sscanf(dateOfJoining_str,"%02d-%02d-%04d",
        &employee.dateOfJoining.day,
        &employee.dateOfJoining.month,
        &employee.dateOfJoining.year);
    printf("Enter job title:"); clear_input_buffer();scanf("%[^\n]s",employee.jobTitle);
    printf("Enter department id:"); scanf("%d",&employee.deptId);
    printf("Enter salary:"); scanf("%lf",&employee.salary);
    
    emp_bdb_insert(&employee);
    
}
void emp_ui_list_emp(){
    employee_t employees[1000];
    int count = 0;
    emp_bdb_readAll(employees,&count);
    
    
    printf("\n\n\nEmployee(Binary File)\n\n\n");
    for(int I = 0; I < count; I++){
        printf("%d)\n",I);
        printf("employee id:%d\n",employees[I].empId);
        printf("employee name:%s\n",employees[I].empName);
        printf("date of joining:%02d-%02d-%04d\n",employees[I].dateOfJoining.day,
            employees[I].dateOfJoining.month,
            employees[I].dateOfJoining.year);
        printf("job title:%s\n",employees[I].jobTitle);
        printf("department id:%d\n",employees[I].deptId);
        printf("salary:%.2lf\n\n\n",employees[I].salary);
    }
}
void emp_ui_find_emp(){
    employee_t employee;
    int id;
    printf("Enter emploee id to find:"); scanf("%d",&id);
    emp_bdb_readById(&employee,id);
    
    
    printf("\n\n\nThe searched employee(Binary File):\n");    
	
	printf("employee id:%d\n",employee.empId);
	printf("employee name:%s\n",employee.empName);
	printf("date of joining:%02d-%02d-%04d\n",employee.dateOfJoining.day,
		employee.dateOfJoining.month,
		employee.dateOfJoining.year);
	printf("job title:%s\n",employee.jobTitle);
	printf("department id:%d\n",employee.deptId);
	printf("salary:%.2lf\n\n\n",employee.salary);

   
}

void emp_ui_edit_emp(){
    employee_t employee;
    int id;
    printf("Enter emploee id to find:"); scanf("%d",&id);
    emp_bdb_readById(&employee,id);
    
    
    printf("\n\n\nThe searched employee(Binary File):\n");    
	
	printf("employee id:%d\n",employee.empId);
	printf("employee name:%s\n",employee.empName);
	printf("date of joining:%02d-%02d-%04d\n",employee.dateOfJoining.day,
		employee.dateOfJoining.month,
		employee.dateOfJoining.year);
	printf("job title:%s\n",employee.jobTitle);
	printf("department id:%d\n",employee.deptId);
	printf("salary:%.2lf\n\n\n",employee.salary);
    
    printf("Enter salary(new):"); scanf("%lf",&employee.salary);
    emp_bdb_update(employee);	
    
    printf("Employee is updated successfully.\n");
}
void emp_ui_delete_emp(){
    employee_t employee;
    int id;
    printf("Enter emploee id to find:"); scanf("%d",&id);
    emp_bdb_readById(&employee,id);
    
    
    printf("\n\n\nThe searched employee(Binary File):\n");    
	
	printf("employee id:%d\n",employee.empId);
	printf("employee name:%s\n",employee.empName);
	printf("date of joining:%02d-%02d-%04d\n",employee.dateOfJoining.day,
		employee.dateOfJoining.month,
		employee.dateOfJoining.year);
	printf("job title:%s\n",employee.jobTitle);
	printf("department id:%d\n",employee.deptId);
	printf("salary:%.2lf\n\n\n",employee.salary);
   
    char ch; 
    printf("Are you sure to delete(y/n)?"); clear_input_buffer(); scanf("%c",&ch);
    if('y' == ch || 'Y' == ch){ 
    	emp_bdb_delete(employee);
    	printf("Employee is deleted successfully.\n");
    }
}
void learn_random_access(){
	employee_t employees[1000];
    int count = 0;
    emp_bdb_random_access(employees,&count);
	
}
int main(){
    int menu;
    do{
        printf("\n\nPick Choice\n");
        printf("\t1-Create Employee, 2-Read All, 3-Read By Employee ID\n");
        printf("\t4-Edit Employee 5-Delete Employee\n");
        printf("\t33-Learning, 0-Exit\n"); 
        printf("Your Choice:"); scanf("%d",&menu);
        printf("\n");
        if(1==menu){
             emp_ui_create_emp();
        }else if(2==menu){
             emp_ui_list_emp();
        }else if(3==menu){
             emp_ui_find_emp();
        }else if(4==menu){
             emp_ui_edit_emp();
        }else if(5==menu){
             emp_ui_delete_emp();
        }else if(33==menu){
             learn_random_access();
        }else{
            printf("Shutting down the app....\n");
        }
    }
    while(((1<=menu) && (menu<=5)) || 33==menu);
	return EXIT_SUCCESS;
}

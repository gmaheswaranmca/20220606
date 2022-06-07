
---------------------------------------------------------------
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
v01/main.c 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
#define SIZE 100
#include<stdio.h>
int main(){
  int size;
  double salaries[SIZE];
  //Read number of salaries 
  printf("Enter number of salaries:"); 
  scanf("%d",&size);//5
  //Read Salaries
  for(int I=0; I < size; I++)
  {
    printf("Enter salary at index %d:",I); 
	scanf("%lf",&salaries[I]);//{2000.0,1500.0,3000.0,1800.0,2500.0}
  }	
  //Display salaries
  printf("\nSalaires(Before Sort):\n");
  for(int I=0; I < size; I++)
  {
    printf("%.2lf ", salaries[I]); 
  }	
  //Do Sorting
  for(int I=0; I < (size-1); I++)
  {
    int sortIndex = I;
    for(int J=I+1; J < size; J++)
	{
      if(salaries[J] < salaries[sortIndex])
	  {
        sortIndex = J;
      }
    }
    if(I != sortIndex){
        float tempSal = salaries[I];
        salaries[I] = salaries[sortIndex];
        salaries[sortIndex] = tempSal;  
    }
  }
  //Display salaries
  printf("\nSalaires(After Sort):\n");
  for(int I=0; I < size; I++)
  {
    printf("%.2lf ", salaries[I]); 
  }	
  return 0;
}
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
---------------------------------------------------------------

---------------------------------------------------------------
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
v02/main.c 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
#define SIZE 100
#include<stdio.h>
void readNumOfSalaries(int* sizeAddr);
void readSalaries(double salaries[], int size);
void displaySalaries(double salaries[], int size, char* caption);
void doSorting(double salaries[], int size);
void doSwap(double *firstAddr, double *secondAddr);
int main(){
  int size;
  double salaries[SIZE];
  readNumOfSalaries(&size);
  readSalaries(salaries,size);
  displaySalaries(salaries,size,"Salaires(Before Sort)");
  doSorting(salaries,size);
  displaySalaries(salaries,size,"Salaires(After Sort)");
  return 0;
}
void readNumOfSalaries(int* sizeAddr){
  //Read number of salaries 
  printf("Enter number of salaries:"); 
  scanf("%d",sizeAddr);//5
} 
void readSalaries(double salaries[], int size){
  //Read Salaries
  for(int I=0; I < size; I++)
  {
    printf("Enter salary at index %d:",I); 
	scanf("%lf",&salaries[I]);//{2000.0,1500.0,3000.0,1800.0,2500.0}
  }	
}  
void displaySalaries(double salaries[], int size, char* caption){
  //Display salaries
  //printf("\nSalaires(Before Sort):\n");
  printf("\n%s:\n",caption);
  for(int I=0; I < size; I++)
  {
    printf("%.2lf ", salaries[I]); 
  }	
}  
void doSorting(double salaries[], int size){
  //Do Sorting
  for(int I=0; I < (size-1); I++)
  {
    int sortIndex = I;
    for(int J=I+1; J < size; J++)
	{
      if(salaries[J] < salaries[sortIndex])
	  {
        sortIndex = J;
      }
    }
    if(I != sortIndex){
        doSwap(&salaries[I], &salaries[sortIndex]);
    }
  }
}  

void doSwap(double *firstAddr, double *secondAddr){
        //swap two data in value memory 
        double tempSal = (*firstAddr);
        (*firstAddr) = (*secondAddr);
        (*secondAddr) = tempSal;  
}
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
---------------------------------------------------------------


---------------------------------------------------------------
"program in execution" is called "process"
---------------------------------------------------------------
$gcc salary_sort.c -c                   
$gcc main.c -c
$gcc salary_sort.o main.o -o salmain
$./salmain
Enter number of salaries:5
Enter salary at index 0:1200
Enter salary at index 1:1500
Enter salary at index 2:2000
Enter salary at index 3:1800
Enter salary at index 4:1400

Salaires(Before Sort):
1200.00 1500.00 2000.00 1800.00 1400.00 
Salaires(After Sort):
1200.00 1400.00 1500.00 1800.00 2000.00 

$rm salary_sort.o main.o salmain

............................................................
$gcc salary_sort.c -c                   
$gcc main.c -c

we can do in one line as:
$gcc *.c -c 
............................................................

............................................................
$rm salary_sort.o main.o salmain

can be done in easier as:

$rm *.o salmain
............................................................
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
v03/main.c 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
#include"myconst.h"
#include"salary_sort.h"
int main(){
  int size;
  double salaries[SIZE];
  readNumOfSalaries(&size);
  readSalaries(salaries,size);
  displaySalaries(salaries,size,"Salaires(Before Sort)");
  doSorting(salaries,size);
  displaySalaries(salaries,size,"Salaires(After Sort)");
  return 0;
}
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
v03/salary_sort.c 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
#include<stdio.h>
#include"salary_sort.h"
void readNumOfSalaries(int* sizeAddr){
  //Read number of salaries 
  printf("Enter number of salaries:"); 
  scanf("%d",sizeAddr);//5
} 
void readSalaries(double salaries[], int size){
  //Read Salaries
  for(int I=0; I < size; I++)
  {
    printf("Enter salary at index %d:",I); 
	scanf("%lf",&salaries[I]);//{2000.0,1500.0,3000.0,1800.0,2500.0}
  }	
}  
void displaySalaries(double salaries[], int size, char* caption){
  //Display salaries
  //printf("\nSalaires(Before Sort):\n");
  printf("\n%s:\n",caption);
  for(int I=0; I < size; I++)
  {
    printf("%.2lf ", salaries[I]); 
  }	
}  
void doSorting(double salaries[], int size){
  //Do Sorting
  for(int I=0; I < (size-1); I++)
  {
    int sortIndex = I;
    for(int J=I+1; J < size; J++)
	{
      if(salaries[J] < salaries[sortIndex])
	  {
        sortIndex = J;
      }
    }
    if(I != sortIndex){
        doSwap(&salaries[I], &salaries[sortIndex]);
    }
  }
}  

void doSwap(double *firstAddr, double *secondAddr){
        //swap two data in value memory 
        double tempSal = (*firstAddr);
        (*firstAddr) = (*secondAddr);
        (*secondAddr) = tempSal;  
}
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^


^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
v03/salary_sort.h 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
void readNumOfSalaries(int* sizeAddr);
void readSalaries(double salaries[], int size);
void displaySalaries(double salaries[], int size, char* caption);
void doSorting(double salaries[], int size);
void doSwap(double *firstAddr, double *secondAddr);
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
v03/myconst.h 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
#define SIZE 100
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
---------------------------------------------------------------



---------------------------------------------------------------
salaries is the list
move each salary into emp object 
sort emp objects based on salary 


!!!
whereever we use the term "Salaries/salaries" we have to change it as "Employees/employees"
at the time reading (input) we have to read "emp_name" as well
at the time displaying (print) we have to display "emp_name" as well
---------------------------------------------------------------
$gcc *.c -c 
$gcc *.o -o salmain
$./salmain
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
v04/main.c 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
#include"myconst.h"
#include"salary_sort.h"
int main(){
  int size;
  emp_t salaries[SIZE];
  readNumOfSalaries(&size);
  readSalaries(salaries,size);
  displaySalaries(salaries,size,"Salaires(Before Sort)");
  doSorting(salaries,size);
  displaySalaries(salaries,size,"Salaires(After Sort)");
  return 0;
}
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
v04/salary_sort.c 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
#include<stdio.h>
#include"salary_sort.h"
void readNumOfSalaries(int* sizeAddr){
  //Read number of salaries 
  printf("Enter number of salaries:"); 
  scanf("%d",sizeAddr);//5
} 
void readSalaries(emp_t salaries[], int size){
  //Read Salaries
  for(int I=0; I < size; I++)
  {
    printf("Enter salary at index %d:",I); 
	scanf("%lf",&salaries[I].salary);//{2000.0,1500.0,3000.0,1800.0,2500.0}
  }	
}  
void displaySalaries(emp_t salaries[], int size, char* caption){
  //Display salaries
  //printf("\nSalaires(Before Sort):\n");
  printf("\n%s:\n",caption);
  for(int I=0; I < size; I++)
  {
    printf("%.2lf ", salaries[I].salary); 
  }	
}  
void doSorting(emp_t salaries[], int size){
  //Do Sorting
  for(int I=0; I < (size-1); I++)
  {
    int sortIndex = I;
    for(int J=I+1; J < size; J++)
	{
      if(salaries[J].salary < salaries[sortIndex].salary)
	  {
        sortIndex = J;
      }
    }
    if(I != sortIndex){
        doSwap(&salaries[I], &salaries[sortIndex]);
    }
  }
}  

void doSwap(emp_t *firstAddr, emp_t *secondAddr){
        //swap two data in value memory 
        emp_t tempSal = (*firstAddr);
        (*firstAddr) = (*secondAddr);
        (*secondAddr) = tempSal;  
}
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^


^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
v04/salary_sort.h 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
#include "emp_t.h"
void readNumOfSalaries(int* sizeAddr);
void readSalaries(emp_t salaries[], int size);
void displaySalaries(emp_t salaries[], int size, char* caption);
void doSorting(emp_t salaries[], int size);
void doSwap(emp_t *firstAddr, emp_t *secondAddr);
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
v04/myconst.h 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
#define SIZE 100
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
v04/emp_t.h 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
struct _emp_t{
    char emp_name[256];
    double salary;
};

typedef struct _emp_t emp_t;
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
---------------------------------------------------------------



---------------------------------------------------------------
Assignment Task: Migration Task
Comipilation and Execution 
---------------------------------------------------------------
ver05
salaries is the list
move each salary into emp object 
sort emp objects based on salary 


introduce the proper namings into v04 
and read/print "emp_name" as well 
---------------------------------------------------------------
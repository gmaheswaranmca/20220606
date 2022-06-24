#include <stdio.h>
#include <stdlib.h>

struct _emp_t{
    char name[256];
    double salary;
};
typedef struct _emp_t emp_t;
 
int compare_emp(const void* a, const void* b)
{
    emp_t first = *(const emp_t*)a;
    emp_t second = *(const emp_t*)b;
    
    //asc
    if (first.salary < second.salary) return -1;
    if (first.salary > second.salary) return 1;
    return 0;
}
 
int main(void)
{
    emp_t employees[] = {{"Rahul",4000.0},{"Dhoni",3000.0},{"Pant",2500.0},{"Varun",1800.0}};
    int size = 4;
 
    qsort(employees, size, sizeof(emp_t), compare_emp);
 
    for (int i = 0; i < size; i++) {
        printf("[%s %.2lf] ", employees[i].name,employees[i].salary);
    }
 
    printf("\n");
    
    return EXIT_SUCCESS;
}
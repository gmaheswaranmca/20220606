#include<stdio.h>
#include<stdlib.h>
#define GIVE_CODE_DB_INSERT(NAME,TYPE,OBJNAME,FILENAME) void NAME(TYPE* OBJNAME){char fileName[] = FILENAME;FILE* out = fopen(fileName,"ab");if(out == NULL){printf("FILE ERROR.\n");return;}fwrite(OBJNAME,1,sizeof(TYPE),out);fclose(out);}

GIVE_CODE_DB_INSERT(emp_bdb_insert,employee_t,employeeAddr,"emp.dat")


GIVE_CODE_DB_INSERT(book_db_insert,book_t,bookAddr,"book.dat")


GIVE_CODE_DB_INSERT(product_db_insert,product_t,productAddr,"product.data")


int main(){
	return EXIT_SUCCESS;
}


/*
gcc generate-code-v1.c -E 
*/
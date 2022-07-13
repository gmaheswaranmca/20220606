//#define JOIN(a,b) a##b
#define GIVE_CODE_DB_INSERT(NAME1,NAME2,NAME3) void NAME1##_db_insert(NAME2##_t* NAME2##Addr) \
{ \
    char fileName[] = #NAME3; \
    FILE* out = fopen(fileName,"ab"); \
    if(out == NULL){printf("FILE ERROR.\n"); \
        return; \
    } \
    fwrite(NAME2##Addr,1,sizeof(NAME2##_t),out); \
    fclose(out); \
}
GIVE_CODE_DB_INSERT(emp,employee,emp.dat)
//JOIN(emp,dat)



/*
gcc generate-code-v3.c -E | sed "s/;/;\n/g"

gcc generate-code-v3.c -E | sed "s/;/;\n/g" | sed "s/{/\n{\n/g" | tail -11

*/
#define GIVE_CODE_DB_INSERT(NAME) void NAME##_db_insert(NAME##_t* NAME##Addr) \
{ \
	char fileName[] = #NAME##.dat; \
	FILE* out = fopen(fileName,"ab"); \
	if(out == NULL){printf("FILE ERROR.\n"); \
		return; \
	} \
	fwrite(NAME##Addr,1,sizeof(NAME##_t),out); \
	fclose(out); \
}


GIVE_CODE_DB_INSERT(cart)
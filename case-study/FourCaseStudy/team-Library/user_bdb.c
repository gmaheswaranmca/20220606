#include"user_bdb.h"
#include<stdio.h>
#include<string.h>
void user_insert(user_t* user){
    char fileName[] = "user.dat";
    FILE* out = fopen(fileName,"ab");
    if(out == NULL){
        printf("FILE ERROR.\n");
        return;
    }
    fwrite(user,1,sizeof(user_t),out);
    fclose(out);
}
void user_readAll(user_t* user, int* countAddr){
    int I=0;
    user_t temp;
    
    char fileName[] = "user.dat";
    FILE* in = fopen(fileName,"rb");
    if(in == NULL){
        printf("FILE ERROR.\n");
        return;
    }
    while(fread(&temp,1,sizeof(user_t),in)){
        user[I] = temp;
        I++;
    }
    fclose(in);
    (*countAddr) = I;
}
void user_delete(int id){
	int I=0;
    user_t temp;
    
    char fileName[] = "user.dat";
    char tempFileName[] = "usertemp.dat";
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
    while(fread(&temp,1,sizeof(user_t),in)){
    	I++;
        if(temp.userId != id){        	
        	fwrite(&temp,1,sizeof(user_t),out);
        }        
    }    
    fclose(out);
    fclose(in); 
    remove(fileName);
    rename(tempFileName,fileName);
}
void user_readById(user_t* userAddr, int userId){
    int I=0;
    user_t temp;
    
    char fileName[] = "user.dat";
    FILE* in = fopen(fileName,"rb");
    if(in == NULL){
        printf("FILE ERROR.\n");
        return;
    }
    while(fread(&temp,1,sizeof(user_t),in)){
        if(temp.userId == userId){
        	(*userAddr) = temp;
        	break;
        }
        I++;
    }
    fclose(in);
}
void user_update(user_t* userAddr){
	int I=0;
    user_t temp;
    
    char fileName[] = "user.dat";
    FILE* in = fopen(fileName,"rb+");
    if(in == NULL){
        printf("FILE ERROR.\n");
        return;
    }
    while(fread(&temp,1,sizeof(user_t),in)){
    	I++;
        if(temp.userId == userAddr->userId){        	
        	break;
        }        
    }
    if(I > 0){
    	fseek(in,(I-1)*sizeof(user_t),SEEK_SET);
    	fwrite(userAddr,1,sizeof(user_t),in);
    }
    fclose(in);
}



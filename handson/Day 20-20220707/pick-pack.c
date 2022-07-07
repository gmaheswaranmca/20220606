#include<stdio.h>
#include<stdlib.h>
#include<threads.h>
typedef struct{
	int orderedQty;
	int pickedQty;
	int packedQty;
} production_t;

static struct{
    mtx_t MUTX; //mutually exclusion | lock - unlock | RACE 
    mtx_t MUTX_COND;
    cnd_t COND_VAR; // wait.(result).continue // monitor .(result). worker | NON-WAKEUP..(result)..WAKEUP
} pref;

void production_constructor(production_t* factory, int orderedQty){//10
	factory->orderedQty = orderedQty;
	factory->pickedQty = 0;
	factory->packedQty = 0;
}

void production_pick_one(production_t* factory){
	factory->pickedQty++;
	printf("The picked items is %d\n",factory->pickedQty);
}

void production_pack_one(production_t* factory){
	factory->packedQty++;
	printf("The packed items is %d\n",factory->packedQty);
}	
	
void production_pick(production_t* factory){
	while(factory->pickedQty < factory->orderedQty){
	    mtx_lock(&pref.MUTX);
		production_pick_one(factory);
		mtx_unlock(&pref.MUTX);
		//if once the pick, continue to pack 
		cnd_signal(&pref.COND_VAR); // WAKE-UP
	}
}

void production_pack(production_t* factory){
	do{
	    /*if(){
	        continue;
	    }*/
	    while(factory->pickedQty == 0 || 
			factory->packedQty == factory->pickedQty){
			//wait for pick 
			printf("waiting for pick...\n");
			cnd_wait(&pref.COND_VAR,&pref.MUTX_COND); //NON-WAKE-UP
			printf("woke up\n");
		}
	    printf("after woke up\n");
		//printf("(pack)packedQty=%d pickedQty=%d\n",factory->packedQty,factory->pickedQty);
		while(factory->packedQty < factory->pickedQty){
			production_pack_one(factory);
		}
	}while(factory->pickedQty < factory->orderedQty);
}		

int production_pick_routine(void* arg){
	production_t* factory = arg;
	production_pick(factory);
	return EXIT_SUCCESS;
}

int production_pack_routine(void* arg){
	production_t* factory = arg;
	production_pack(factory);
	return EXIT_SUCCESS;
}

int main(){
	production_t factory_val;//shared memory by threads
	int orderedQty;
	printf("Enter the number of qty ordered:"); scanf("%d",&orderedQty);
	production_constructor(&factory_val,orderedQty);
	
	mtx_init(&pref.MUTX, mtx_plain);
	mtx_init(&pref.MUTX_COND, mtx_plain);
	cnd_init(&pref.COND_VAR);
	
	int RET_CODE_PICK;
	int RET_CODE_PACK;
	
	thrd_t thr_pick;
	thrd_t thr_pack;
	
	thrd_create(&thr_pack,production_pack_routine,&factory_val);
	thrd_create(&thr_pick,production_pick_routine,&factory_val);

	thrd_join(thr_pick,&RET_CODE_PICK);
	thrd_join(thr_pack,&RET_CODE_PACK);
	

	
	cnd_destroy(&pref.COND_VAR);
	mtx_destroy(&pref.MUTX_COND);
	mtx_destroy(&pref.MUTX);
	
	
	printf("End of app.\n");
	
	//production_pick(&factory_val);
	//production_pack(&factory_val);
	return EXIT_SUCCESS;
}


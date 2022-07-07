#include<stdio.h>
#include<stdlib.h>
#include<threads.h>
#include<time.h>
typedef struct _node_t{
	struct _node_t* prev;
	struct _node_t* next;
	void *data_addr;
}node_t;

typedef struct {
	node_t *head;
	node_t *tail;
	int count;
} dlist_t;



node_t* node_create(void* val_addr){
	node_t* node = (node_t*)malloc(1*sizeof(node_t));
	(*node) = (node_t){};
	node->next = NULL;
	node->prev = NULL;
	node->data_addr = val_addr;
}
void dlist_init(dlist_t* list_addr){
	list_addr->head = NULL;
	list_addr->tail = NULL;
	list_addr->count = 0;
}
void dlist_push_back(dlist_t* list_addr, void* val_addr){
	node_t* node = node_create(val_addr);
	if(list_addr->head == NULL){
		list_addr->head = node;
		list_addr->tail = node;
		return;
	}
	
	list_addr->tail->next = node;
	node->prev = list_addr->tail;
	list_addr->tail = node;
	
	list_addr->count++;
}

void dlist_pop_front(dlist_t* list_addr){
	if(list_addr->head == NULL){
		return;
	}
	node_t* node = list_addr->head;
	if(node->next == NULL){
		list_addr->head = NULL;
		list_addr->tail = NULL;
	}else{
		list_addr->head = node->next;
	}
	list_addr->count--;
	//free'd node 
	free(node->data_addr);
	node->prev = NULL;
	node->next = NULL;
	free(node);
}

void* dlist_front(dlist_t* list_addr){
	if(list_addr->head == NULL){
		return NULL;
	}
	return list_addr->head->data_addr;
}

void dlist_destroy(dlist_t* list_addr){
	while(list_addr->count > 0){
		dlist_pop_front(list_addr);
	}
}

typedef struct{
	dlist_t list;
}queue_t;

void queue_init(queue_t* queue_addr){
	dlist_init(&queue_addr->list);
}
void queue_push(queue_t* queue_addr,void* val_addr){
	dlist_push_back(&queue_addr->list, val_addr); 
}

void queue_pop(queue_t* queue_addr){
	dlist_pop_front(&queue_addr->list); 
}

void* queue_front(queue_t* queue_addr){
	return dlist_front(&queue_addr->list); 
}

int queue_size(queue_t* queue_addr){
	return queue_addr->list.count;
}
void queue_destroy(queue_t* queue_addr){
	dlist_destroy(&queue_addr->list);
}

static struct{
	mtx_t MUTX;
	cnd_t COND_VAR;
} pref;


typedef struct{
	queue_t queue;
	int orderedQty;
	int producedQty;
	int consumedQty;
}production_t;


void production_init(production_t* factory, int orderedQty){
	queue_init(&factory->queue);
	factory->orderedQty = orderedQty;
	factory->producedQty = 0;
	factory->consumedQty = 0;
}

void production_produce(production_t* factory){
	factory->producedQty ++;
	int* product_id_addr = (int*)malloc(1*sizeof(int));
	(*product_id_addr) = factory->producedQty;
	queue_push(&factory->queue, product_id_addr);
}

int production_consume(production_t* factory){
	factory->consumedQty ++;
	int product_id = *(int*)queue_front(&factory->queue);
	queue_pop(&factory->queue);
	return product_id;
}

void production_destroy(production_t* factory){
	queue_destroy(&factory->queue);
}


void producer(production_t* factory){
	while(factory->producedQty < factory->orderedQty){
		//do 'produce' 
		mtx_lock(&pref.MUTX);
		production_produce(factory); //produce safely
		mtx_unlock(&pref.MUTX);
		//wake up | inform consumer about produced 
		cnd_signal(&pref.COND_VAR);
		//??
		
		printf("Produced is %d qty.\n",factory->producedQty);
	}
	printf("Production is fully done.\n");
}

void consumer(production_t* factory){
	if(
		(
			(factory->producedQty == factory->orderedQty) &&
			(factory->consumedQty == factory->producedQty)
		)
	){
		return;
	}
	do{
		while(factory->consumedQty >= factory->producedQty){
			//wait | waiting for production 
			printf("Consumer is waiting for production\n");
			cnd_wait(&pref.COND_VAR,&pref.MUTX);
			//??
		}
		//
		while(factory->consumedQty < factory->producedQty){
			//do 'consume' 
			int product_id = production_consume(factory);
			printf("Consumed product's id is %d\n",product_id);
		}
	}while(factory->producedQty < factory->orderedQty);
	
	printf("Consumption is fully done.\n");
}

int producer_routine(void* arg){
	production_t* factory = arg;
	producer(factory);
	return EXIT_SUCCESS;
}

int consumer_routine(void* arg){
	production_t* factory = arg;
	consumer(factory);
	return EXIT_SUCCESS;
}

int main(){
	int orderedQty;
	printf("Enter ordered qty:"); scanf("%d",&orderedQty);
	printf(".........................Famous Producer - Consumer Problem.....................\n");
	
	mtx_init(&pref.MUTX, mtx_plain);
	cnd_init(&pref.COND_VAR);
	
	production_t factory_val;
	production_init(&factory_val,orderedQty);
	//producer - consumer workers ie peer-peer 
	thrd_t thr_producer;
	thrd_t thr_consumer;
	thrd_create(&thr_consumer,consumer_routine,&factory_val);
	thrd_create(&thr_producer,producer_routine,&factory_val);
	thrd_join(thr_consumer,NULL);
	thrd_join(thr_producer,NULL);
	
	//manager is off the work 
	
	production_destroy(&factory_val);
	
	cnd_destroy(&pref.COND_VAR);
	mtx_destroy(&pref.MUTX);
	printf(".........................	Thank you!       .....................\n");
	return EXIT_SUCCESS;
}
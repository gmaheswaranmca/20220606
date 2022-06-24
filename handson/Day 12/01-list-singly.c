#include<stdio.h>
#include<stdlib.h>

struct _SLL_node_t;
typedef struct _SLL_node_t SLL_node_t;
struct _SLL_node_t{
    double data;
    SLL_node_t* nextNodeAddr;
};

void node_init(SLL_node_t* nodeAddr, double val){
    nodeAddr->data = val;
    nodeAddr->nextNodeAddr = NULL;
}

struct _singly_list_t;
typedef struct _singly_list_t singly_list_t;

struct _singly_list_t{
    SLL_node_t* frontNodeAddr;
};

void list_pop_front(singly_list_t* listAddr);
double list_front(singly_list_t* listAddr);

void list_init(singly_list_t* listAddr){
    listAddr->frontNodeAddr = NULL;
}

void list_destroy(singly_list_t* listAddr){
     while(listAddr->frontNodeAddr != NULL){
         //printf("%.2lf is being deleted....\n",list_front(listAddr));
         list_pop_front(listAddr);
     }
     listAddr->frontNodeAddr = NULL;
}

void list_push_front(singly_list_t* listAddr, double val){
    SLL_node_t* nodeAddr = (SLL_node_t*)malloc(1 * sizeof(SLL_node_t));
    node_init(nodeAddr,val); //{val,NULL}
    
    if(listAddr->frontNodeAddr == NULL){
        listAddr->frontNodeAddr = nodeAddr;
    }else{
        nodeAddr->nextNodeAddr = listAddr->frontNodeAddr; // bring the new node before the old list
        listAddr->frontNodeAddr = nodeAddr; // change the list front pointer 
    }
}
void list_pop_front(singly_list_t* listAddr){
    if(listAddr->frontNodeAddr == NULL){
        printf("List is empty.\n");
        return;
    }
    SLL_node_t* nodeAddr = listAddr->frontNodeAddr;
    
    //ADJUSTMENT 
    listAddr->frontNodeAddr = listAddr->frontNodeAddr->nextNodeAddr;
    
    //Deallocator
    nodeAddr->nextNodeAddr = NULL;
    free(nodeAddr);
    nodeAddr = NULL;
}
double list_front(singly_list_t* listAddr){
    if(listAddr->frontNodeAddr == NULL){
        printf("List is empty.\n");
        return -1.0;
    }
    return listAddr->frontNodeAddr->data;
}

//
void list_traversal(singly_list_t* listAddr){
    SLL_node_t* nodeAddr = listAddr->frontNodeAddr;
    printf("The salaries are:\n");
    while(nodeAddr != NULL){
        printf("%.2lf ->",nodeAddr->data);
        nodeAddr = nodeAddr->nextNodeAddr;
    }
    printf("\n");
}

//
void list_traversal_recursion_forward(SLL_node_t* nodeAddr){
    if(nodeAddr == NULL){
        return;
    }
    printf("%.2lf ->",nodeAddr->data);
    list_traversal_recursion_forward(nodeAddr->nextNodeAddr);
}

void list_traversal_recursion_backward(SLL_node_t* nodeAddr){
    if(nodeAddr == NULL){
        return;
    }
    
    list_traversal_recursion_backward(nodeAddr->nextNodeAddr);
    printf("%.2lf ->",nodeAddr->data);
}


int main(){
    singly_list_t list;
    list_init(&list);
    
    int menu;
    do{
        printf("Pick Choice\n");
        printf("\t1-Add Front, 2-Delete Front\n");
        printf("\t3-Traversal\n");
        printf("\tRecursion next 4-Traversal Forward, 5-Traversal Backward\n");
        printf("\t0-Exit\n");
        printf("Your Choice:"); scanf("%d",&menu);
        
        if(1 == menu){
            double salary = 0.0;
            printf("Enter data:"); scanf("%lf",&salary);
            list_push_front(&list, salary);
        }else if(2 == menu){
            if(list.frontNodeAddr == NULL){
                printf("List is empty.\n");
            }else{
                double salary = list_front(&list);
                list_pop_front(&list);
                printf("%.2lf is Deleted.\n",salary);
            }
        }else if(3 == menu){
            list_traversal(&list);
        }else if(4 == menu){
            printf("The salaries are:\n");
            list_traversal_recursion_forward(list.frontNodeAddr);
            printf("\n");
        }else if(5 == menu){
            printf("The reverse of the salaries are:\n");
            list_traversal_recursion_backward(list.frontNodeAddr);
            printf("\n");
        }else{
            printf("Application is shutting down....\n");    
        }
    }while((1 <= menu) && (menu <= 5));
    
    list_destroy(&list);
    return EXIT_SUCCESS;
}
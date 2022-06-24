
#include<stdio.h>
#include<stdlib.h>

struct _DLL_node_t;
typedef struct _DLL_node_t DLL_node_t;
struct _DLL_node_t{
    DLL_node_t* prevNodeAddr;
    double data;
    DLL_node_t* nextNodeAddr;
};

void node_init(DLL_node_t* nodeAddr, double val){
    nodeAddr->prevNodeAddr = NULL;
    nodeAddr->data = val;
    nodeAddr->nextNodeAddr = NULL;
}

struct _doubly_list_t;
typedef struct _doubly_list_t doubly_list_t;

struct _doubly_list_t{
    DLL_node_t* frontNodeAddr;
    DLL_node_t* backNodeAddr;
};

void list_pop_front(doubly_list_t* listAddr);
double list_front(doubly_list_t* listAddr);

void list_init(doubly_list_t* listAddr){
    listAddr->frontNodeAddr = NULL;
    listAddr->backNodeAddr = NULL;
}

void list_destroy(doubly_list_t* listAddr){
     while(listAddr->frontNodeAddr != NULL){
         //printf("%.2lf is being deleted....\n",list_front(listAddr));
         list_pop_front(listAddr);
     }
     listAddr->frontNodeAddr = NULL;
     listAddr->backNodeAddr = NULL;
}

void list_push_front(doubly_list_t* listAddr, double val){
    DLL_node_t* nodeAddr = (DLL_node_t*)malloc(1 * sizeof(DLL_node_t)); 
    node_init(nodeAddr,val); //{val,NULL}
    
    //ADJUST
    //CODE HERE
}
void list_pop_front(doubly_list_t* listAddr){
    if(listAddr->frontNodeAddr == NULL){
        printf("List is empty.\n");
        return;
    }
    DLL_node_t* nodeAddr = listAddr->frontNodeAddr;
    
    //ADJUSTMENT 
    //CODE HERE
    
    //Deallocator
    nodeAddr->nextNodeAddr = NULL;         
    free(nodeAddr);                        
    nodeAddr = NULL;
}
double list_front(doubly_list_t* listAddr){
    if(listAddr->frontNodeAddr == NULL){
        printf("List is empty.\n");
        return -1.0;
    }
    return listAddr->frontNodeAddr->data;
}

void list_push_back(doubly_list_t* listAddr, double val){
    DLL_node_t* nodeAddr = (DLL_node_t*)malloc(1 * sizeof(DLL_node_t)); 
    node_init(nodeAddr,val); //{val,NULL}
    
    //ADJUST
    //CODE HERE
}
void list_pop_back(doubly_list_t* listAddr){
    if(listAddr->backNodeAddr == NULL){
        printf("List is empty.\n");
        return;
    }
    DLL_node_t* nodeAddr = listAddr->backNodeAddr;
    
    //ADJUSTMENT 
    //CODE HERE
    
    //Deallocator
    nodeAddr->prevNodeAddr = NULL;         
    free(nodeAddr);                        
    nodeAddr = NULL;
}
double list_back(doubly_list_t* listAddr){
    if(listAddr->backNodeAddr == NULL){
        printf("List is empty.\n");
        return -1.0;
    }
    return listAddr->backNodeAddr->data;
}

//
void list_traversal_forward(doubly_list_t* listAddr){
    DLL_node_t* nodeAddr = listAddr->frontNodeAddr;
    printf("The salaries are:\n");
    while(nodeAddr != NULL){
        printf("%.2lf ->",nodeAddr->data);
        nodeAddr = nodeAddr->nextNodeAddr;
    }
    printf("\n");
}
void list_traversal_backward(doubly_list_t* listAddr){
    DLL_node_t* nodeAddr = listAddr->backNodeAddr;
    printf("The reverse of salaries are:\n");
    while(nodeAddr != NULL){
        printf("%.2lf ->",nodeAddr->data);
        nodeAddr = nodeAddr->prevNodeAddr;
    }
    printf("\n");
}
void list_traversal_next_recursion_forward(DLL_node_t* nodeAddr){
    if(nodeAddr == NULL){
        return;
    }
    printf("%.2lf ->",nodeAddr->data);
    list_traversal_next_recursion_forward(nodeAddr->nextNodeAddr);
}

void list_traversal_next_recursion_backward(DLL_node_t* nodeAddr){
    if(nodeAddr == NULL){
        return;
    }
    
    list_traversal_next_recursion_backward(nodeAddr->nextNodeAddr);
    printf("%.2lf ->",nodeAddr->data);
}
void list_traversal_prev_recursion_backward(DLL_node_t* nodeAddr){
    if(nodeAddr == NULL){
        return;
    }
    printf("%.2lf ->",nodeAddr->data);
    list_traversal_prev_recursion_backward(nodeAddr->prevNodeAddr);
}

void list_traversal_prev_recursion_forward(DLL_node_t* nodeAddr){
    if(nodeAddr == NULL){
        return;
    }
    
    list_traversal_prev_recursion_forward(nodeAddr->prevNodeAddr);
    printf("%.2lf ->",nodeAddr->data);
}

int main(){
    doubly_list_t list;
    list_init(&list);
    
    int menu;
    do{
        printf("Pick Choice\n");
        printf("\t1-Add Front, 2-Delete Front\n");
        printf("\t3-Add Back, 4-Delete Back\n");
        printf("\t5-Traversal Forward,6-Traversal Backward\n");
        printf("\tRecursion next 7-Traversal Forward, 8-Traversal Backward\n");
        printf("\tRecursion prev 9-Traversal Forward, 10-Traversal Backward\n");
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
            double salary = 0.0;
            printf("Enter data:"); scanf("%lf",&salary);
            list_push_back(&list, salary);
        }else if(4 == menu){
            if(list.frontNodeAddr == NULL){
                printf("List is empty.\n");
            }else{
                double salary = list_back(&list);
                list_pop_back(&list);
                printf("%.2lf is Deleted.\n",salary);
            }
        }else if(5 == menu){
            list_traversal_forward(&list);
        }else if(6 == menu){
            list_traversal_backward(&list);
        }else if(7 == menu){
            printf("The salaries are:\n");
            list_traversal_next_recursion_forward(list.frontNodeAddr);
            printf("\n");
        }else if(8 == menu){
            printf("The reverse of the salaries are:\n");
            list_traversal_next_recursion_backward(list.frontNodeAddr);
            printf("\n");
        }else if(9 == menu){
            printf("The salaries are:\n");
            list_traversal_prev_recursion_forward(list.backNodeAddr);
            printf("\n");
        }else if(10 == menu){
            printf("The reverse of the salaries are:\n");
            list_traversal_prev_recursion_backward(list.backNodeAddr);
            printf("\n");
        }else{
            printf("Application is shutting down....\n");    
        }
    }while((1 <= menu) && (menu <= 10));
    
    list_destroy(&list);
    return EXIT_SUCCESS;
}		
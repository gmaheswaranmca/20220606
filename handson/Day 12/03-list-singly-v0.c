#include<stdio.h>
#include<stdlib.h>

struct _node_t{
    double data;
    struct _node_t* next;
};
typedef struct _node_t node_t;

void traversal(node_t *head);
void pop_front(node_t **headAddr);

void node_init(node_t* node, double val){
    node->data = val;
    node->next = NULL;
}

void push_front(node_t **headAddr, double val){
    node_t *head = (*headAddr);
    
    node_t* node = (node_t*)malloc(1*sizeof(node_t));
    node_init(node,val);//{50,x}
    //adjust
    if(head == NULL){
        //empty list 
        head = node;
    }else{
        //list of atleast one node 
        node->next = head;
        head = node;
    }
    
    (*headAddr) = head;
}
void pop_front(node_t **headAddr){
    node_t *head = (*headAddr);
    
    if(head == NULL){
        printf("List is empty.\n");
        return;
    }
    
    node_t* node = head;
    //adjust
    if(node->next == NULL){
        head = NULL;
    }else{
        head = node->next;
    }
    
    //deallocator
    node->next = NULL;
    free(node);
    node = NULL;
    
    (*headAddr) = head;
}
double front(node_t *head){
    if(head == NULL){
        printf("List is empty.\n");
        return -1.0;
    }
    return head->data;
}
void traversal(node_t *head){
    node_t* node = head;
    printf("The salaries are:\n");
    while(node != NULL){
        printf("%.2lf ",node->data);
        node = node->next;
    }
    printf("\n");
}

void destroy(node_t **headAddr){
    node_t *head = (*headAddr);
    
    while(head != NULL){
        printf("%.2lf is deleted.\n",front(head));
        pop_front(&head);
    }
    
    (*headAddr) = head;
}

int main(){              // 50 40 30 
    node_t *head = NULL; // head[.]->[40,.]->[50,x]
                                        
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
            push_front(&head, salary);
        }else if(2 == menu){
            if(head == NULL){
                printf("List is empty.\n");
            }else{
                double salary = front(head);
                pop_front(&head);
                printf("%.2lf is Deleted.\n",salary);
            }
        }else if(3 == menu){
            traversal(head);
        }else{
            printf("Application is shutting down....\n");    
        }
    }while((1 <= menu) && (menu <= 3));
    
    destroy(&head);
    return EXIT_SUCCESS;
}
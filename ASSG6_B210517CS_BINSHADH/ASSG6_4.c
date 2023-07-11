#include <stdio.h>
#include<cstring.h>
#incude<cmath.h>
#include <stdlib.h>
struct Nodebase{
    int data;
    struct Nodebase *next;
};
typedef struct Nodebase* Node;
struct Queuebase{
    Node head;
    Node tail;
};
typedef struct Queuebase* Queue;
Node create_node(int k){
    Node new_node=(Node)malloc(sizeof(struct Nodebase));
    new_node->data=k;
    new_node->next=NULL;
    return new_node;
}
int queue_empty(Queue Q){
    return Q->head==NULL;
}
void enqueue(Queue Q,int k){
    Node new_node=create_node(k);
    if(queue_empty(Q)){
        Q->head=new_node;
    }
    else{
        Q->tail->next=new_node;
    }
    Q->tail=new_node;
}
void dequeue(Queue Q){
    if(queue_empty(Q)){
        printf("Empty ");
    }
    else{
        printf("%d ",Q->head->data);
        Node head=Q->head;
        Q->head=Q->head->next;
        free(head);
    }
}
int main()
{
    char c;
    int k;
    Queue Q=(Queue)malloc(sizeof(struct Queuebase));
    Q->head=NULL;
    Q->tail=NULL;
    while(1){
        scanf("%c%*c",&c);
        switch(c){
            case 'i':
                scanf("%d%*c",&k);
                enqueue(Q,k);
                break;
            case 'd':
                scanf("%d%*c",&k);
                while(k--){
                    dequeue(Q);
                }
                printf("\n");
                break;
            case 'e':
                if(queue_empty(Q)){
                    printf("YES\n");
                }
                else{
                    printf("NO\n");
                }
                break;
            case 't':
                return 0;
        }
    }
    return 0;
}

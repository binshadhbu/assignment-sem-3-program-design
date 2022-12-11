#include <stdio.h>
#include <stdlib.h>


struct Queuebase{
    int head;
    int tail;
    int size;
    int *arr;
};
typedef struct Queuebase* Queue;

int queue_full(Queue Q){
    return Q->size==0 || Q->head==(Q->tail+1)%Q->size;
}

int queue_empty(Queue Q){
    return Q->head==Q->tail;
}

void enqueue(Queue Q,int k){
    if(queue_full(Q)){
        printf("Full\n");
    }
    else{
        Q->arr[Q->tail]=k;
        Q->tail=(Q->tail+1)%Q->size;
    }
}

void dequeue(Queue Q){
    if(queue_empty(Q)){
        printf("Empty ");
    }
    else{
        printf("%d ",Q->arr[Q->head]);
        Q->head=(Q->head+1)%Q->size;
    }
}

int main()
{
    char c;
    int n,k;
    scanf("%d%*c",&n);
    Queue Q=(Queue)malloc(sizeof(struct Queuebase));
    Q->head=0;
    Q->tail=0;
    Q->size=n;                                        // Changes to be made here
    Q->arr=(int *)malloc((n)*sizeof(int));            // Changes to be made here
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
            case 'f':
                if(queue_full(Q)){
                    printf("YES\n");
                }
                else{
                    printf("NO\n");
                }
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

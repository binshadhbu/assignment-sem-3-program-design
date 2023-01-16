#include <stdio.h>
#include <stdlib.h>
struct Nodebase{
    int data;
    struct Nodebase *next;
};
typedef struct Nodebase* Node;
struct Stackbase{
    Node top;
};
typedef struct Stackbase* Stack;
Node create_node(int k){
    Node new_node=(Node)malloc(sizeof(int));
    new_node->data=k;
    new_node->next=NULL;
    return new_node;
}
int stack_empty(Stack S){
    return S->top==NULL;
}
void push(Stack S,int k){
    Node new_node=create_node(k);
    new_node->next=S->top;
    S->top=new_node;
}
int pop(Stack S){
    if(stack_empty(S)){
        printf("Empty ");
        return -1e7;
    }
    else{
        int value=S->top->data;
        Node top_pointer=S->top;
        S->top=S->top->next;
        free(top_pointer);
        return value;
    }
}
int main()
{
    int k,num;
    char c;
    Stack S=(Stack)malloc(sizeof(struct Stackbase));
    S->top=NULL;
    while(1){
        scanf("%c%*c",&c);
        switch(c){
            case 'i':
                scanf("%d%*c",&k);
                push(S,k);
                break;
            case 'd':
                scanf("%d%*c",&k);
                while(k--){
                    int num=pop(S);
                    if(num!=-1e7){
                        printf("%d ",num);
                    }
                }
                printf("\n");
                break;
            case 'e':
                if(stack_empty(S)){
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

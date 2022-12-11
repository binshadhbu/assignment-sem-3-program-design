#include <stdio.h>
#include <stdlib.h>
struct Stackbase{
    int top;
    int size;
    int *arr;
};
typedef struct Stackbase* Stack;
int stack_empty(Stack S){
    return S->top==-1;
}
int stack_full(Stack S){
    return S->top==S->size-1;
}
void push(Stack S,int k){
    if(stack_full(S)){
        printf("Full\n");
    }
    else{
        (S->arr)[++(S->top)]=k;
    }
}
int pop(Stack S){
    if(stack_empty(S)){
        printf("Empty ");
        return -1e7;
    }
    else{
        return S->arr[(S->top)--];
    }
}
int main()
{
    int n,k;
    char c;
    scanf("%d%*c",&n);
    Stack S=(Stack)malloc(sizeof(struct Stackbase));
    S->top=-1;
    S->size=n;
    S->arr=(int *)malloc(n*sizeof(int));
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
            case 'f':
                if(stack_full(S)){
                    printf("YES\n");
                }
                else{
                    printf("NO\n");
                }
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

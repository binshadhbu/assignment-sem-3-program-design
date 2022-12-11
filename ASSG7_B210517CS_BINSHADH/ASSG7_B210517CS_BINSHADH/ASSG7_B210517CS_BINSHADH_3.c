#include <stdio.h>
//#include <string.h>
#include <ctype.h>
#include <stdlib.h>
struct Stack
{
    int top;
    unsigned capacity;
    int* array;
};
int strlen(char exp[]){
    int j=0;
    while(exp[j]!='\0'){
        j++;

    }
    return j;
}
struct Stack* createStack( unsigned capacity )
{
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    if (!stack) return NULL;
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*) malloc(stack->capacity * sizeof(int));
    if (!stack->array) return NULL;
    return stack;
}
int isEmpty(struct Stack* stack)
{
    if(stack->top==-1){
        return 1;
    }else{
        return 0;
    }
}
int peek(struct Stack* stack)
{
    int value=stack->array[stack->top];
    return value;
}
int pop(struct Stack* stack)
{
    int ch=isEmpty(stack);
    if (!ch){
        return stack->array[stack->top--] ;

    }else{
        return '$';
    }
}
void push(struct Stack* stack,int op)
{
    stack->array[++stack->top] = op;
}
int evaluatePostfix(char* exp)
{

    struct Stack* stack = createStack(strlen(exp));
    int i;
    if (stack==NULL) return -1;
    for (i = 0; exp[i]; ++i)
    {
        if(exp[i]==' ')continue;
        else if (isdigit(exp[i]))
        {
            int num=0;
            while(isdigit(exp[i]))
            {
                num=num*10 + (int)(exp[i++]-'0');
            }
            --i;
            push(stack,num);
        }
        else
        {
            int val1 = pop(stack);
            int val2 = pop(stack);
            if(exp[i]=='+'){
                push(stack, val2 + val1);
            }else if(exp[i]=='-'){
                push(stack, val2 - val1);
            }else if(exp[i]=='*'){
                push(stack, val2 * val1);
            }else if(exp[i]=='/'){
                push(stack, val2/val1);
            }

        }
    }
    return pop(stack);
}
int main()
{
    int n;
    char exp[1000] ;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("\n");

        scanf("%[^\n]%*c",&exp);
        int j=0;
        while(exp[j] != '\0')
        {j++;}
        //printf("%d",j);
        printf ("%d\n", evaluatePostfix(exp));
    }

    return 0;
}


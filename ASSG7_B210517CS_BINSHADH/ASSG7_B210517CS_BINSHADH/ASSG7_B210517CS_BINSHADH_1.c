#include <stdio.h>
#include <stdlib.h>
struct Stack
{
    int top;
    int size;
    int *array;
};
int strlen(char exp[]){
    int j=0;
    while(exp[j]!='\0'){
        j++;

    }
    return j;
}
struct Stack * createStack (int size)
{
    struct Stack *stack = (struct Stack *) malloc (sizeof (struct Stack));

    if (!stack)
        return NULL;

    stack->top = -1;
    stack->size = size;
    stack->array = (int *) malloc (stack->size * sizeof (int));
    return stack;
}

int
isEmpty (struct Stack *stack)
{
    struct Stack *p,*q;
    int check;
    if(stack->top==-1){
        check=1;
    }else {
        check=0;
    }
    check=(stack->top==-1)?1:0;
    return check;
}

char
peek (struct Stack *stack)
{
    char value;
    value=stack->array[stack->top];
    return value;
}

char
pop_stack (struct Stack *stack)
{
    char ch;
    int check=isEmpty (stack);
    if (check==0) {
        ch = stack->array[stack->top--];
        return ch;
    }
    return '$';
}

void
push_to_stack(struct Stack *stack, char op)
{
    stack->array[++stack->top] = op;
}

int
check_operand (char ch)
{
    int check;
    if(ch >= 'a' && ch <= 'z'){
        check=1;
    }else {
        check=0;
    }
    return check;
}

int
select_operator (char ch)
{
    if(ch=='+'||ch=='-'){
        return 1;
    }else if(ch=='*'||ch=='/'){
        return 2;
    }else if(ch=='^'){
        return 3;
    }else{
        return -1;
    }
}

int
infixToPostfix (char *exp)
{
    int i, k;
    struct Stack *stack = createStack (strlen (exp));
    for (i = 0, k = -1; exp[i]; ++i)
    {
        if (check_operand(exp[i]))
            exp[++k] = exp[i];
        else if (exp[i] == '(')
            push_to_stack (stack, exp[i]);
        else if (exp[i] == ')')
        {
            while (!isEmpty (stack) && peek (stack) != '(')
                exp[++k] = pop_stack(stack);
            if (!isEmpty (stack) && peek (stack) != '(')
                return -1;
            else
                pop_stack(stack);
        }

        else
        {
            while (!isEmpty (stack) && select_operator(exp[i]) <= select_operator(peek(stack)))
                exp[++k] = pop_stack(stack);
            push_to_stack (stack, exp[i]);
        }
    }
    while (!isEmpty (stack))
        exp[++k] = pop_stack(stack);

    exp[++k] = '\0';
    printf ("%s\n", exp);
}

int
main ()
{
    int n;
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
    {
        char exp[1000];
        scanf ("\n");
        scanf ("%[^\n]%*c", exp);
        infixToPostfix (exp);
    }

    return 0;
}



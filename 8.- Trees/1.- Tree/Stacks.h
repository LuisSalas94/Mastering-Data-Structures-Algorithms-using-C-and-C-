#ifndef STACKS_H_INCLUDED
#define STACKS_H_INCLUDED
#include "Queve.h"

struct Stack
{

    int size;
    int top;
    struct Node **S;
};

void Stackcreate(struct Stack *st, int size)
{
    st->size = size;
    st->top = -1;
    st->S=(struct Node **)malloc(st->size*sizeof(struct Node*));
}

void push(struct Stack *st, struct Node *x)
{
    if(st->top == st->size-1)
    {
        printf("Stack Overflow");
    }
    else
    {
        st->top++;
        st->S[st->top] = x;
    }
}

struct Node *pop(struct Stack *st)
{
    struct Node *x = NULL;

    if(st->top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        x = st->S[st->top--];
    }
};

int isEmptyStack(struct Stack st)
{
    if(st.top == -1)
    {
        return 1;
    }
    return 0;
};

int isFullStack(struct Stack st)
{
    return st.top == st.size-1;
}


#endif // STACKS_H_INCLUDED

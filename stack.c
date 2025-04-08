#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

bool isEmpty(Stack_t *stack)
{
    return stack -> top == -1;
}

bool isFull(Stack_t *stack)
{
    return stack -> top == MAX_SIZE - 1;
}

void initStack(Stack_t *stack)
{
    stack -> top = -1;
}

void push(Stack_t *stack, Element_t e)
{
    if(isFull(stack))
    {
        perror("Stiva e plina\n");
        exit(-1);
    }
    stack -> date[++(stack -> top)] = e;
}

Element_t pop(Stack_t *stack)
{
    if(isEmpty(stack))
    {
        perror("Stiva e goala\n");
        exit(-1);
    }
    return stack -> date[(stack -> top)--];
}

Element_t peek(Stack_t *stack)
{
    if(isEmpty(stack))
    {
        perror("Stiva e goala\n");
        exit(-1);
    }
    return stack -> date[(stack -> top)];
}


#include <stdio.h>
#include <stdbool.h>
#include "stack.h"

int main(void)
{
    Stack_t stack;
    initStack(&stack, INITIAL_CAP);
    push(&stack, 3);
    printf("%d\n",peek(&stack));
    push(&stack, 5);
    push(&stack, 8);
    push(&stack, 2);
    printf("%d\n", peek(&stack));
    pop(&stack);
    printf("%d\n", peek(&stack));
    return 0;
}
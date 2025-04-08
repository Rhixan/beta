#ifndef __STACK_H__
#define __STACK_H__

#define INITIAL_CAP 4
#define MAX_SIZE 10

typedef int Element_t;
typedef struct {
    Element_t *date;
    int top;
    int capacity;
}Stack_t;

Stack_t* initStack(Stack_t* stack, int capacity);

bool isEmpty(Stack_t* stack);

bool isFull(Stack_t* stack);

void push(Stack_t* stack, Element_t e);

Element_t pop(Stack_t* stack);

Element_t peek(Stack_t* stack);

void freeStack(Stack_t* stack);

#endif
#ifndef __STACK__
#define __STACK__

#define MAX_SIZE 100

typedef int Element_t;
typedef struct {
    Element_t date[MAX_SIZE];
    int top;
}Stack_t;

bool isEmpty(Stack_t* stack);

bool isFull(Stack_t* stack);

void initStack(Stack_t* stack);

void push(Stack_t* stack, Element_t e);

Element_t pop(Stack_t* stack);

Element_t peek(Stack_t* stack);

#endif
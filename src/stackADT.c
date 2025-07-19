#include <stdio.h>
#include "stackADT.h"
#include <stdlib.h>

#define STACK_SIZE 100

struct stack_type
{
    int contents[STACK_SIZE];
    int top;
};

static void terminate(const char *message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

Stack create()
{
    Stack s = malloc(sizeof(struct stack_type));
    if (s == NULL)
    {
        terminate("Error creating stack: out of memory");
    }
    s->top = 0; // Initialize top to -1 indicating an empty stack
    return s;
}

void destroy(Stack s)
{
    if (s != NULL)
    {
        free(s);
        s = NULL; // Avoid dangling pointer
    }
}

void make_empty(Stack s)
{
    if (s != NULL)
    {
        s->top = 0; // Reset top to 0 indicating an empty stack
    }
}

bool is_empty(Stack s)
{
    if (s != NULL)
    {
        return s->top == 0; // Stack is empty if top is 0
    }
    return true; // Stack is not empty
}

bool is_full(Stack s)
{
    if (s != NULL)
    {
        return s->top == STACK_SIZE; // Stack is full if top equals STACK_SIZE
    }
    return false; // Stack is not full
}

void push(Stack s, int value)
{
    if (s == NULL || is_full(s))
    {
        terminate("Error pushing to stack: stack is full or not initialized");
    }
    s->contents[s->top++] = value; // Push value onto stack and increment top
}

int pop(Stack s)
{
    if (s == NULL || is_empty(s))
    {
        terminate("Error popping from stack: stack is empty or not initialized");
    }
    return s->contents[--s->top]; // Decrement top and return the value at that position
}
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
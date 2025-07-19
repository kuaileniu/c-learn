#ifndef STACKADT_H
#define STACKADT_H
#include <stdbool.h>

typedef struct stack_type *Stack;
// #define STACK_SIZE 100
// struct  stack_type
// {
//     int contents[STACK_SIZE];
//     int top;
// };

Stack create();
void destroy(Stack s);
bool is_empty(Stack s);
void make_empty(Stack s);
bool is_full(Stack s);
void push(Stack s, int value);
int pop(Stack s);

#endif
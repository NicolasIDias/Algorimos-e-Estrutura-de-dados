#pragma once

typedef struct Stack
{
    int *A;
    int size;
    int length;
    int tailIndex;
} stack_t;

stack_t new_stack(int size);
void resize(stack_t *stack);
void delete_stack(stack_t *stack);
void push(stack_t *stack, int x);
int pop(stack_t *stack);
void print_queue(stack_t *stack);
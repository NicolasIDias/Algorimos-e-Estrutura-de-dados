#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

stack_t new_stack(int size)
{
    stack_t stack;
    stack.A = malloc(size * sizeof(int));
    stack.size = size;
    stack.length = 0;
    stack.tailIndex = 0;

    return stack;
}

void push(stack_t *stack, int n)
{
    if (stack == NULL || stack->A == NULL)
        return;

    if (stack->length >= stack->size)
    {
        resize(stack);
    }

    stack->A[stack->length] = n;
    stack->length++;
}

int pop(stack_t *stack)
{
    if (stack == NULL || stack->length == 0)
    {
        printf("[Erro]: Pilha vazia ou inexistente\n");
    }
    stack->length--;
    return stack->A[stack->length];
}

void resize(stack_t *stack)
{
    if (stack == NULL)
    {
        printf("[Erro]: Pilha nao existe");
    }
    else
    {
        int size = stack->size * 2;
        int *tmp = realloc(stack->A, sizeof(int) * size);
        if (tmp != NULL)
        {
            stack->A = tmp;
            stack->size = size;
        }
        else
        {
            printf("[Erro]: Memoria insuficiente para dar resize");
        }
    }
}

void delete_stack(stack_t *stack)
{
    if (stack != NULL)
    {
        free(stack->A);
        stack->A = NULL;
        stack->length = 0;
        stack->tailIndex = 0;
        stack->size;
    }
    else
    {
        printf("[Erro]: Pilha nao existe");
    }
}
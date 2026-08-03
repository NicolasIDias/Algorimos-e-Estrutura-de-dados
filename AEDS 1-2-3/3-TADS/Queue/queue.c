#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

queue_t new_queue(int size)
{
    queue_t queue;
    queue.size = size;
    queue.length = 0;
    queue.tailIndex = 0;
    queue.A = malloc(sizeof(int) * size);

    return queue;
}

void delete_queue(queue_t *queue)
{
    if (queue != NULL)
    {
        free(queue->A);
        queue->A = NULL;
    }
    queue->size = 0;
    queue->length = 0;
    queue->tailIndex = 0;
}

void enqueue(queue_t *queue, int x)
{
    if (queue == NULL)
    {
        printf("[Erro]: Fila nao existe");
    }
    else
    {
        if (queue->length >= queue->size)
        {
            resize(queue);
        }
        queue->A[queue->length++] = x;
    }
}

int dequeue(queue_t *queue)
{
    if (queue == NULL)
    {
        printf("[Erro]: Fila nao existe");
    }else if(queue->length == queue->tailIndex){
        printf("[Erro]: Fila vazia");
    }
    else
    {   
        int n = queue->A[queue->tailIndex];
        for (int i = 0; i < queue->length - 1; i++)
        {
            queue->A[i] = queue->A[i + 1];
        }
        queue->length--;
        return n;
    }
}

void resize(queue_t *queue)
{
    if (queue == NULL)
    {
        printf("[Erro]: Fila nao existe");
    }
    else
    {
        int size = queue->size * 2;
        int *tmp = realloc(queue->A, sizeof(int) * size);
        if (tmp != NULL)
        {
            queue->A = tmp;
            queue->size = size;
        }
        else
        {
            printf("[Erro]: Memoria insuficiente para dar resize\n");
        }
    }
}

void print_queue(queue_t *queue)
{
    if (queue == NULL)
    {
        printf("[Erro]: Fila nao existe");
    }
    else
    {
        printf("[");
        for (int i = 0; i < queue->length; i++)
        {
            if (i == queue->length - 1)
            {
                printf("%d", queue->A[i]);
            }
            else
            {
                printf("%d, ", queue->A[i]);
            }
        }
        printf("]");
        printf("\n");
    }
}
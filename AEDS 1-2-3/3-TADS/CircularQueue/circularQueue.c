#include "circularQueue.h"
#include <stdlib.h>
#include <stdio.h>

circ_t create(int size)
{
    circ_t fila;
    fila.size = size + 1;
    fila.front = fila.rear = 0;

    fila.Q = malloc(sizeof(int) * fila.size);

    return fila;
}

void enqueue(circ_t *q, int x)
{
    int next = (q->rear + 1) % q->size;
    if (q->front == next)
        printf("Fila cheia\n");
    else
    {
        q->Q[next] = x;
        q->rear = next;
    }
}

int dequeue(circ_t *q)
{
    int x = -1;

    if (q->front == q->rear)
        printf("Fila vazia\n");
    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}

void destroy(circ_t *q)
{
    free(q->Q);
    q->Q = ((void *)0);
    q->front = q->rear = 0;
    q->size = 0;
    printf("Memoria da fila liberada.\n");
}
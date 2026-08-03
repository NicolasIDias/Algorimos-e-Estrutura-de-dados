#pragma once
#include "../0-shared/bool.h"

typedef struct Queue {
    int *A;
    int size;
    int length;
    int tailIndex;
}queue_t;


queue_t new_queue(int size);
void delete_queue(queue_t *queue);
void print_queue(queue_t *queue);
void enqueue(queue_t *queue, int x);
int dequeue(queue_t *queue);
void resize(queue_t *queue);
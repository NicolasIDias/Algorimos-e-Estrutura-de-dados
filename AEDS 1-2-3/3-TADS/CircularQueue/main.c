#include <stdio.h>
#include "circularQueue.h"

int main() {
    circ_t minhaFila = create(3);

    enqueue(&minhaFila, 10);
    enqueue(&minhaFila, 20);
    enqueue(&minhaFila, 30);

    enqueue(&minhaFila, 40);
    printf("Saiu: %d\n", dequeue(&minhaFila));
    printf("Saiu: %d\n", dequeue(&minhaFila));

    enqueue(&minhaFila, 40);
    enqueue(&minhaFila, 50);

    while (minhaFila.front != minhaFila.rear) {
        printf("Removido: %d\n", dequeue(&minhaFila));
    }

    destroy(&minhaFila);

    return 0;
}
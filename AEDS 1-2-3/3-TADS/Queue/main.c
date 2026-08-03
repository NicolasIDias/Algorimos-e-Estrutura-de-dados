#include <stdio.h>
#include "queue.h"

int main(){

    queue_t fila1 = new_queue(10);


    for(int i=0;i<6;i++){
        enqueue(&fila1, i);
    }

    int n = dequeue(&fila1);

    printf("%d\n", n);
    print_queue(&fila1);

    delete_queue(&fila1);
    return 0;
}
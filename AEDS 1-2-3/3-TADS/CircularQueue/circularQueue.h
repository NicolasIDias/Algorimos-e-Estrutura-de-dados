typedef struct CircularQueue
{

    int front, rear, size, *Q;

} circ_t;

circ_t create(int size);
void enqueue(circ_t *q, int x);
int dequeue(circ_t *q);
void destroy(circ_t *q);
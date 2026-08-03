#include <stdio.h>
#include <stdlib.h>

typedef struct node_t
{
	int val;
	struct node_t *next;
} Node;

typedef struct queue_t
{
	Node *dummy;
	Node *tail;
	int length;
} Queue;

Node *create_node(int val)
{
	Node *node = malloc(sizeof(Node));
	if(node == NULL) return NULL;

	node->val = val;
	node->next = NULL;

	return node;
}

Queue *create_queue(void)
{
	Queue *queue = malloc(sizeof(Queue));
	if(queue == NULL) return NULL;

	queue->dummy = malloc(sizeof(Node));
	queue->dummy->next = NULL;
	queue->tail = queue->dummy;
	
	queue->length = 0;

	return queue;
}

int queue_insert(Queue *queue, int val)
{
	Node *node = create_node(val);
	if(node == NULL || queue == NULL) return 0;		

	if(queue->length == 0)
	{
		queue->dummy->next = node;
		queue->tail = node;
	}
	else
	{
		queue->tail->next = node;
		queue->tail = node;
	}
	queue->length += 1; 
	return 1;
}

Node *queue_pop(Queue *queue)
{
	if(queue == NULL || queue->length == 0) return NULL;

	Node *first = queue->dummy->next;
	queue->dummy->next = first->next;

	if(queue->dummy->next == NULL)
	{
		queue->tail = queue->dummy;
	}

	queue->length -= 1;
	return first;
}

void print_queue(Queue *queue)
{
	if(queue == NULL || queue->length == 0) return;

	Node *current = queue->dummy->next;
	while(current != NULL)
	{
		printf("%d ", current->val);
		current = current->next;
	}
	printf("\n");
}

void free_queue(Queue *queue)
{
	if(queue == NULL) return;

	Node *curr = queue->dummy;
	while(curr != NULL)
	{
		Node *next_node = curr->next;
		free(curr);
		curr = next_node;
	}
	free(queue);
}

int main(void)
{
	Queue *q = create_queue();

	for(int i = 0; i < 10; i++)
	{
		queue_insert(q, i);
	}

	print_queue(q);

	free(queue_pop(q));
	free(queue_pop(q));
	free(queue_pop(q));

	print_queue(q);

	free_queue(q);

	return 0;
}

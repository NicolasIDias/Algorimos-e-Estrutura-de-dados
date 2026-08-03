#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
	int val;
	struct Node *next;
} node_t;

typedef struct List
{
	node_t *first;
	node_t *last;
	int counter;
} list_t;

list_t create_list()
{
	list_t list = {.first = NULL, .last = NULL, .counter = 0};
	return list;
}

node_t *create_node(int val)
{
	node_t *node = malloc(sizeof(node_t));

	node->val = val;
	node->next = NULL;

	return node;
}

void insert(list_t *list, int val)
{
	node_t *node = create_node(val);
	if (list->counter == 0 && list->first == NULL)
	{
		list->first = node;
		list->last = node;
	}
	else
	{
		list->last->next = node;
		list->last = node;
	}
	list->counter++;
}

void free_list(list_t *list)
{
	node_t *curr = list->first;
	node_t *next;

	while (curr != NULL)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	list->first = NULL;
	list->last = NULL;
	list->counter = 0;
}

void print_list(list_t *list)
{
	node_t *curr = list->first;
	while (curr != NULL)
	{
		printf("%d ", curr->val);
		curr = curr->next;
	}
	printf("\n");
}

int main(void)
{
	int a = 0, b = 1, c = 2, d = 3;
	list_t list = create_list();
	insert(&list, a);
	insert(&list, b);
	insert(&list, c);
	insert(&list, d);

	print_list(&list);
	free_list(&list);
	return 0;
}

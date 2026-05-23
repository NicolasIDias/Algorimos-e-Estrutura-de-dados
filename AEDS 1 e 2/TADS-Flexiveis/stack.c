#include <stdio.h>
#include <stdlib.h>

typedef struct stack_node_t
{
	int val;
	struct stack_node_t *bottom;
} StackNode;

typedef struct stack_t
{
	int length;
	StackNode *last;
} Stack;


StackNode *create_node(int val)
{
	StackNode *node = malloc(sizeof(StackNode));
	if(node == NULL) return NULL;

	node->val = val;
	node->bottom = NULL;

	return node;
}

Stack *create_stack()
{
	Stack *stack = malloc(sizeof(Stack));
	if(stack == NULL) return NULL;

	stack->length = 0;
	stack->last = NULL;

	return stack;
}

int stack_push(Stack *stack, int val)
{
	if(stack == NULL) return 0;

	StackNode *node = create_node(val);
	if(node == NULL) return 0;

	if(stack->last == NULL) stack->last = node;
	else
	{
		node->bottom = stack->last;
		stack->last = node;
	}
	stack->length += 1;

	return 1;
	
}

StackNode *stack_pop(Stack *stack)
{
	if(stack == NULL || stack->length == 0) return 0;	

	StackNode *curr = stack->last;
	
	stack->last = stack->last->bottom;

	stack->length -= 1;
	return curr;
}

void print_stack(Stack *stack)
{
	if(stack == NULL) return;
	
	StackNode *curr = stack->last;
	while(curr != NULL)
	{
		printf("%d ", curr->val);
		curr = curr->bottom;
	}
	printf("\n");
}

void free_stack(Stack *stack)
{
	if(stack == NULL) return;
	
	StackNode *node = stack->last;

	while(node->bottom != NULL)
	{
		StackNode *tmp = node;
		node = node->bottom;
		free(tmp);
	}

	free(stack);
}

int main(void)
{
	Stack *s = create_stack();
	
	for(int i = 0; i < 10; i++)
	{
		stack_push(s, i);
	}

	print_stack(s);

	free(stack_pop(s));
	free(stack_pop(s));
	free(stack_pop(s));

	print_stack(s);

	free_stack(s);

	return 0;
}


#include <stdio.h>
#include <stdlib.h>

typedef struct tree_node_t 
{
	int val;
	struct tree_node_t[] childs;
} TreeNode;

typedef struct tree_t
{
	TreeNode *root;
} Tree;

TreeNode *create_node(int val)
{
	TreeNode *node = malloc(sizeof(TreeNode));
	if(node == NULL) return NULL;

	node->val = val;
	node->childs = {NULL};
}

int main(void)
{
	Tree *tree = create_tree();

	return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct rb_node_t
{
	int val;
	int color; // 0: black 1:red
	struct rb_node_t *left;
	struct rb_node_t *right;
	struct rb_node_t *parent;
} RBNode;

typedef struct rb_tree_t
{
	RBNode *root;
} RBTree;

RBNode *create_node(int val, int color)
{
	RBNode *node = malloc(sizeof(RBNode));
	if(node == NULL) return NULL;

	node->left = NULL;
	node->right = NULL;
	node->val = val;
	node->color = color;

	return node;
}

RBTree *create_tree()
{
	RBTree *tree = malloc(sizeof(RBTree));
	if(tree == NULL) return NULL;

	tree->root = NULL;

	return tree;
}

void rotate_left(RBTree *tree, RBNode *node)
{
	RBNode *rNode = node->right;
	node->right = rNode->right;

	if(rNode->left != NULL)
	{
		rNode->left->parent = node;
	}
	rNode->parent = node->parent;

	if (node->parent == NULL) {
		tree->root = rNode;     
	}
	else if (node == node->parent->left) {
		node->parent->left = rNode;  
	}
	else {
		node->parent->right = rNode; 
	}

	rNode->left = node;
	node->parent = rNode;

}

void rotate_right(RBNode *node)
{
	RBNode *lNode = node->left;
	node->left = lNode->left;

	if(rNode->left != NULL)
	{
		rNode->left->parent = node;
	}
	rNode->parent = node->parent;

	if (node->parent == NULL) {
		tree->root = rNode;     
	}
	else if (node == node->parent->left) {
		node->parent->left = rNode;  
	}
	else {
		node->parent->right = rNode; 
	}

	rNode->left = node;
	node->parent = rNode;
}

RBNode *rb_insert(RBTree *tree, int val)
{
	if(tree == NULL) return;

	if(tree->root == NULL)
	{
		RBNode *node = create_node(val, 0);
		tree->root = node;
		return node;
	}

}

int main(void)
{


	return 0;
}

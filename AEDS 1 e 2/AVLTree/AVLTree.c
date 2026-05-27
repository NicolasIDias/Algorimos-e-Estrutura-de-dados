#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) (((a) > (b)) ? (a) : (b))

typedef struct avl_node_t
{
	int val;
	int height;
	struct avl_node_t *right;
	struct avl_node_t *left;
} AVLNode;

typedef struct avl_tree_t
{
	AVLNode *root;
} AVLTree;

AVLNode *create_node(int val)
{
	AVLNode *node = malloc(sizeof(AVLNode));
	if (node == NULL)
		return NULL;

	node->left = NULL;
	node->right = NULL;
	node->val = val;
	node->height = 1;

	return node;
}

int node_height(AVLNode *node)
{
	if (node == NULL)
		return 0;
	return node->height;
}

AVLTree *create_tree()
{
	AVLTree *tree = malloc(sizeof(AVLTree));
	if (tree == NULL)
		return NULL;

	tree->root = NULL;

	return tree;
}

AVLNode *rotate_left(AVLNode *node)
{
	if (node == NULL)
		return NULL;

	AVLNode *rNode = node->right;
	AVLNode *rlNode = rNode->left;

	rNode->left = node;
	node->right = rlNode;

	node->height = MAX(get_height(node->left), get_height(node->right));
	rNode->height = MAX(get_height(rNode->left), get_height(rNode->right));

	return rNode;
}

AVLNode *rotate_right(AVLNode *node)
{
	if (node == NULL)
		return NULL;

	AVLNode *lNode = node->left;
	AVLNode *lrNode = lNode->right;

	lNode->right = node;
	node->left = lrNode;

	node->height = MAX(get_height(node->left), get_height(node->right));
	lNode->height = MAX(get_height(lNode->left), get_height(lNode->right));

	return lNode;
}

void balance(AVLTree *tree)
{
	AVLNode *node = tree->root;

	if (node->left == NULL && node->right == NULL)
	{
		// Already balanced
		return;
	}
	else if (node->right != NULL)
	{
		if (node->right->right != NULL)
		{
			node = rotate_left(node);
		}
		else
		{
			node = rotate_right(node);
			node = rotate_left(node);
		}
	}
	else
	{
		if (node->left->rigt != NULL)
		{
			node = rotate_left(node);
		}
		else
		{
			node = rotate_right(node);
			node = rotate_left(node);
		}
	}

	return node;
}

AVLNode *insert_rec(AVLTree *tree, AVLNode *nodeToInsert)
{
	
}

int tree_insert(AVLTree *t, int val)
{
	AVLNode *node = create_node(val);
	if (node == NULL)
		return 1;

	node->val = val;
	node->right = NULL;
	node->left = NULL;

	if(t->root == NULL)
	{
		t->root = node;
	}
	else
	{
		insert_rec(node);
	}
}

int main(void)
{

	AVLTree *tree = create_tree();
	if (tree == NULL)
	{
		free(tree);
		return 1;
	}

	tree_insert(tree, 10);

	return 0;
}

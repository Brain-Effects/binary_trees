#include "binary_trees.h"
#include <stdlib.h>

/* Function to create a new node */
avl_t *binary_tree_node(avl_t *parent, int value);

/* Function to calculate the balance factor of a node */
int binary_tree_balance(const avl_t *tree);

/* Function to perform a left rotation at a given node */
avl_t *binary_tree_rotate_left(avl_t *tree);

/* Function to perform a right rotation at a given node */
avl_t *binary_tree_rotate_right(avl_t *tree);

/**
 * avl_insert - Inserts a value in an AVL Tree
 * @tree: Double pointer to the root node of the AVL tree for
 * inserting the value
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node = NULL;
	avl_t *current = NULL;
	avl_t *parent = NULL;

	if (tree == NULL)
		return (NULL);

	new_node = binary_tree_node(NULL, value);
	if (new_node == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = new_node;
		return (new_node);
	}

	current = *tree;
	while (current != NULL)
	{
		parent = current;
		if (value < current->n)
		current = current->left;
		else if (value > current->n)
		current = current->right;
		else
	{
		free(new_node);
		return (NULL);
	}
	}

	if (value < parent->n)
		parent->left = new_node;
	else
		parent->right = new_node;

	new_node->parent = parent;

	while (parent)
	{
	int balance;

	balance = binary_tree_balance(parent);
	if (balance > 1)
	{
		if (binary_tree_balance(parent->left) < 0)
		parent->left = binary_tree_rotate_left(parent->left);
		parent = binary_tree_rotate_right(parent);
	}
	else if (balance < -1)
	{
		if (binary_tree_balance(parent->right) > 0)
		parent->right = binary_tree_rotate_right(parent->right);
		parent = binary_tree_rotate_left(parent);
	}
		parent = parent->parent;
	}

	return (new_node);
}

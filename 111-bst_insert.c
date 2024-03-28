#include <stdlib.h>
#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree
 * @tree: Double pointer to the root node of the BST to insert the value
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *parent = NULL;
	bst_t *current = NULL;

	if (tree == NULL)
		return (NULL);

	current = *tree;
	while (current != NULL)
	{
	parent = current;
	if (value < current->n)
		current = current->left;
	else if (value > current->n)
		current = current->right;
	else
		return (NULL);
	}

	if (parent == NULL)
		*tree = binary_tree_node(parent, value);
	else if (value < parent->n)
		parent->left = binary_tree_node(parent, value);
	else
		parent->right = binary_tree_node(parent, value);

	if (parent == NULL)
		return (*tree);
	else if (value < parent->n)
		return (parent->left);
	else
		return (parent->right);
}

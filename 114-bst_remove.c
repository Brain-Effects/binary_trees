#include "binary_trees.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * bst_search - Searches for a value in a Binary Search Tree
 * @tree: Pointer to the root node of the BST to search
 * @value: Value to search in the tree
 *
 * Return: Pointer to the node containing a value equals to value,
 * or NULL if tree is NULL or if nothing is found
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);

	if (value < tree->n)
		return (bst_search(tree->left, value));
	else if (value > tree->n)
		return (bst_search(tree->right, value));
	else
		return ((bst_t *)tree);
}

/**
 * bst_inorder_successor - Finds the in-order successor of a
 * node in a Binary Search Tree
 * @node: Pointer to the node to find the in-order successor of
 *
 * Return: Pointer to the in-order successor node, or NULL if node
 * has no in-order successor
 */
bst_t *bst_inorder_successor(bst_t *node)
{
	bst_t *current = node;

	if (current->right != NULL)
	{
	current = current->right;
	while (current->left != NULL)
		current = current->left;
	}
	else
	{
		while (current->parent != NULL && current == current->parent->right)
		current = current->parent;
		current = current->parent;
	}
	return (current);
}

/**
 * bst_remove - Removes a node from a Binary Search Tree
 * @root: Pointer to the root node of the tree where you will remove a node
 * @value: Value to remove in the tree
 *
 * Return: Pointer to the new root node of the tree after removing
 * the desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node_to_remove = bst_search(root, value);
	bst_t *successor = NULL;
	bst_t *temp = NULL;

	if (node_to_remove == NULL)
		return (root);

	if (node_to_remove->left != NULL && node_to_remove->right != NULL)
	{
		successor = bst_inorder_successor(node_to_remove);
		node_to_remove->n = successor->n;
		node_to_remove = successor;
	}

	temp = node_to_remove->left ? node_to_remove->left : node_to_remove->right;

	if (temp == NULL)
	{
	if (node_to_remove == root)
		root = NULL;
	else if (node_to_remove->parent->left == node_to_remove)
		node_to_remove->parent->left = NULL;
	else
		node_to_remove->parent->right = NULL;
	}
	else
	{
	if (node_to_remove == root)
		root = temp;
	else if (node_to_remove->parent->left == node_to_remove)
		node_to_remove->parent->left = temp;
		else
		node_to_remove->parent->right = temp;

		temp->parent = node_to_remove->parent;
	}

	free(node_to_remove);
	return (root);
}

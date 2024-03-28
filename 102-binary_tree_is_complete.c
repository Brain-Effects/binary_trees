#include <stddef.h>
#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, otherwise 0. If tree is NULL, return 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int index = 0, nodes = 0;

	if (tree == NULL)
		return (0);

	nodes = binary_tree_size(tree);

	return (is_complete(tree, index, nodes));
}

/**
 * is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 * @index: index of the node
 * @nodes: total number of nodes
 *
 * Return: 1 if the tree is complete, otherwise 0
 */
int is_complete(const binary_tree_t *tree, int index, int nodes)
{
	if (tree == NULL)
		return (1);

	if (index >= nodes)
		return (0);

	return (is_complete(tree->left, 2 * index + 1, nodes) &&
			is_complete(tree->right, 2 * index + 2, nodes));
}

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 *
 * Return: size of a binary tree. If tree is NULL, return 0
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

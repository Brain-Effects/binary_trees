#include <stddef.h>
#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_levelorder - goes through a binary tree using
 * level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 *
 * Return: void
 */
void binary_tree_levelorder(const binary_tree_t *tree,
		void (*func)(int))
{
	size_t h, i;

	if (tree == NULL || func == NULL)
		return;

	h = binary_tree_height(tree) + 1;
	for (i = 0; i < h; i++)
		binary_tree_print_level(tree, func, i);
}

/**
 * binary_tree_print_level - prints a level of a binary tree
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 * @level: level to print
 *
 * Return: void
 */
void binary_tree_print_level(const binary_tree_t *tree, void (*func)(int),
		size_t level)
{
	if (tree == NULL)
		return;

	if (level == 0)
		func(tree->n);
	else if (level > 0)
	{
		binary_tree_print_level(tree->left, func, level - 1);
		binary_tree_print_level(tree->right, func, level - 1);
	}
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: height of a binary tree. If tree is NULL, return 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_left = 0;
	size_t height_right = 0;

	if (tree == NULL)
		return (0);

	height_left = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	height_right = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	return (height_left > height_right ? height_left : height_right);
}

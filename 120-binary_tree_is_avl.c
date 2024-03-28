#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

/**
 * height - Calculate the height of a node
 * @tree: Pointer to the node to calculate the height of
 *
 * Return: Height of the node
 */
int height(const binary_tree_t *tree)
{
	int height_l;
	int height_r;

	height_l = tree && tree->left ? 1 + height(tree->left) : 0;
	height_r = tree && tree->right ? 1 + height(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}

/**
 * is_bst - Check if a tree is a Binary Search Tree (BST)
 * @tree: Pointer to the root node of the tree to check
 * @min: Minimum value a node can take
 * @max: Maximum value a node can take
 *
 * Return: 1 if tree is a BST, and 0 otherwise
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);
	return (is_bst(tree->left, min, tree->n - 1) &&
		is_bst(tree->right, tree->n + 1, max));
}

/**
 * abs_diff - Calculate the absolute difference between the heights of the
 * left and right subtrees
 * @tree: Pointer to the root node of the tree to calculate the difference of
 *
 * Return: Absolute difference between the heights of the left and
 * right subtrees
 */
int abs_diff(const binary_tree_t *tree)
{
	int height_l;
	int height_r;

	height_l = tree && tree->left ? height(tree->left) : 0;
	height_r = tree && tree->right ? height(tree->right) : 0;
	return (height_l - height_r);
}

/**
 * binary_tree_is_avl - Check if a binary tree is a valid AVL Tree
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (is_bst(tree, INT_MIN, INT_MAX) &&
		abs(abs_diff(tree)) <= 1 &&
		binary_tree_is_avl(tree->left) &&
		binary_tree_is_avl(tree->right));
}

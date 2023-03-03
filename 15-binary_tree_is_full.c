#include "binary_trees.h"

/**
 * calc_full - Recursively checks if a binary tree is full.
 *
 * @tree: Pointer to the root node of the tree to check.
 * @is_full: Boolean value of tree's current full status.
 *
 * Return: Boolean value of tree's current full status.
 */

size_t calc_full(const binary_tree_t *tree, size_t is_full)
{
	if (!tree)
		return (is_full);

	if (tree->left)
		is_full = calc_full(tree->left, is_full);

	if (tree->right)
		is_full = calc_full(tree->right, is_full);

	if ((!tree->left && tree->right) || (tree->left && !tree->right))
		is_full = 0;

	return (is_full);
}

/**
 * binary_tree_is_full - Checks if a binary tree is full.
 *
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: Boolean value of tree's full status.
 */

size_t binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (calc_full(tree, 1));
}

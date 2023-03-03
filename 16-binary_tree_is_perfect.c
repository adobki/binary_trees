#include "binary_trees.h"

/**
 * calc_perfect - Recursively checks if a binary tree is perfect.
 *
 * @tree: Pointer to the root node of the tree to check.
 * @is_perfect: Boolean value of tree's current perfect status.
 *
 * Return: Boolean value of tree's current perfect status.
 */

int calc_perfect(const binary_tree_t *tree, size_t is_perfect)
{
	if (!tree)
		return (is_perfect);

	if (tree->left)
		is_perfect = calc_perfect(tree->left, is_perfect);

	if (tree->right)
		is_perfect = calc_perfect(tree->right, is_perfect);

	if ((!tree->left && tree->right) || (tree->left && !tree->right))
		is_perfect = 0;

	return (is_perfect);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 *
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: Boolean value of tree's perfect status.
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (calc_perfect(tree, 1));
}

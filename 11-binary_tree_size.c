#include "binary_trees.h"

/**
 * calc_size - Measures the size of a binary tree recursively.
 *
 * @tree: Pointer to a node in the tree to be traversed.
 * @size: Calculated height in current branch.
 *
 * Return: Calculated size from given node.
 */

size_t calc_size(const binary_tree_t *tree, size_t size)
{
	if (!tree)
		return (size);

	if (tree->left)
		size = calc_size(tree->left, ++size);

	if (tree->right)
		size = calc_size(tree->right, ++size);

	return (size);
}

/**
 * binary_tree_size - Measures the size of a binary tree.
 *
 * @tree: Pointer to the root node of the tree to be traversed.
 *
 * Return: Calculated size from given node.
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (calc_size(tree, 1));
}

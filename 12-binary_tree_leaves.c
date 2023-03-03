#include "binary_trees.h"

/**
 * count_leaves - Recursively counts the leaves in a binary tree.
 *
 * @tree: Pointer to a node in the tree to be traversed.
 * @leaves: Pointer to the root node of the tree to count number of leaves.
 *
 * Return: Number of leaves in given binary tree.
 */

size_t count_leaves(const binary_tree_t *tree, size_t leaves)
{
	if (!tree)
		return (leaves);

	if (tree->left)
		leaves = count_leaves(tree->left, leaves);

	if (tree->right)
		leaves = count_leaves(tree->right, leaves);

	if (!tree->left && !tree->right)
		leaves = count_leaves(tree->right, ++leaves);

	return (leaves);
}

/**
 * binary_tree_leaves - Counts the leaves in a binary tree.
 *
 * @tree: Pointer to the root node of the tree to count number of leaves.
 *
 * Return: Number of leaves in given binary tree.
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (count_leaves(tree, 0));
}

#include "binary_trees.h"

/**
 * count_nodes - Recursively counts nodes with >=1 child in a binary tree.
 *
 * @tree: Pointer to a node in the tree to be traversed.
 * @nodes: Pointer to the root node of the tree to count nodes.
 *
 * Return: Number of nodes with at least 1 child in given binary tree.
 */

size_t count_nodes(const binary_tree_t *tree, size_t nodes)
{
	if (!tree)
		return (nodes);

	if (tree->left)
		nodes = count_nodes(tree->left, nodes);

	if (tree->right)
		nodes = count_nodes(tree->right, nodes);

	if (tree->left || tree->right)
		nodes++;

	return (nodes);
}

/**
 * binary_tree_nodes - Counts nodes with at least 1 child in a binary tree.
 *
 * @tree: Pointer to the root node of the tree to count nodes.
 *
 * Return: Number of nodes with at least 1 child in given binary tree.
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (count_nodes(tree, 0));
}

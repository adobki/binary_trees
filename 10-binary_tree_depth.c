#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree.
 *
 * @tree: Pointer to a node to be measured in a tree.
 *
 * Return: Calculated depth to root from given node.
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t height = 0;

	if (!tree)
		return (0);

	while (tree->parent)
	{
		tree = tree->parent;
		height++;
	}

	return (height);
}

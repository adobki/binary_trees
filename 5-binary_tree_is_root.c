#include "binary_trees.h"

/**
 * binary_tree_is_root - Checks if a node is a leaf.
 *
 * @node: Pointer to the node to be checked.
 *
 * Return: 1 on success (if node is a leaf),
 *         0 otherwise.
 */

int binary_tree_is_root(const binary_tree_t *node)
{
	if (!node || node->parent)
		return (0);
	else
		return (1);
}

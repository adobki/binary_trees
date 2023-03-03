#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node in a binary tree.
 *
 * @node: Pointer to the node to find the uncle.
 *
 * Return: Uncle of given node on success,
 *         NULL otherwise.
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node || !node->parent || !node->parent->parent)
		return (NULL);

	node = node->parent;
	
	if (node == node->parent->left)
		return (node->parent->right);
	else
		return (node->parent->left);
}

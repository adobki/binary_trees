#include "binary_trees.h"

/**
 * binary_tree_node - Creates a binary tree node without any child.
 *
 * @parent: Pointer to the parent node of the node to create.
 * @value: Data to be put in the new node.
 *
 * Return: Pointer to created node on success,
 *         NULL otherwise.
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node = NULL;

	node = malloc(sizeof(binary_tree_t));
	if (!node)
		return (NULL);

	node->parent = parent;
	node->n = value;
	node->left = node->right = NULL;

	return (node);
}

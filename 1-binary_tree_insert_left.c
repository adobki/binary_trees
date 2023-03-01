#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a new node as the left child of another
 *                           node. If left child already exits, it becomes
 *                           left child of the new node.
 *
 * @parent: Pointer to the parent node of the node to create.
 * @value: Data to be put in the new node.
 *
 * Return: Pointer to created node on success,
 *         NULL on failure or if parent==NULL.
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	if (!parent)
		return (NULL);

	node = malloc(sizeof(binary_tree_t));
	if (!node)
		return (NULL);

	node->n = value;
	node->parent = parent;
	node->left = node->right = NULL;
	if (parent->left)
	{
		node->left = parent->left;
		parent->left->parent = node;
	}
	parent->left = node;

	return (node);
}

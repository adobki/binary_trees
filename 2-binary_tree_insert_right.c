#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a new node as the right child of another
 *                            node. If right child already exits, it becomes
 *                            right child of the new node.
 *
 * @parent: Pointer to the parent node of the node to create.
 * @value: Data to be put in the new node.
 *
 * Return: Pointer to created node on success,
 *         NULL on failure or if parent==NULL.
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
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
	if (parent->right)
	{
		node->right = parent->right;
		parent->right->parent = node;
	}
	parent->right = node;

	return (node);
}

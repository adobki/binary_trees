#include "binary_trees.h"

/**
 * binary_tree_postorder - Goes through binary tree using post-order traversal.
 *
 * @tree: Pointer to the root node of the tree to be traversed.
 * @func: Pointer to a function to be called for each node with node's value.
 */

void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	if (tree->left)
		binary_tree_postorder(tree->left, func);

	if (tree->right)
		binary_tree_postorder(tree->right, func);

	func(tree->n);
}

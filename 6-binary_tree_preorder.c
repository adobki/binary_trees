#include "binary_trees.h"

/**
 * binary_tree_preorder - Goes through a binary tree using pre-order traversal.
 *
 * @tree: Pointer to the root node of the tree to be traversed.
 * @func: Pointer to a function to be called for each node with node's value.
 */

void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	func(tree->n);

	if (tree->left)
		binary_tree_preorder(tree->left, func);

	if (tree->right)
		binary_tree_preorder(tree->right, func);
}

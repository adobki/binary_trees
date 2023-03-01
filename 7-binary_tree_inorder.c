#include "binary_trees.h"

/**
 * binary_tree_inorder - Goes through a binary tree using in-order traversal.
 *
 * @tree: Pointer to the root node of the tree to be traversed.
 * @func: Pointer to a function to be called for each node with node's value.
 */

void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	if (tree->left)
	{
		binary_tree_inorder(tree->left, func);
		func(tree->left->n);
		if (tree->right)
		{
			binary_tree_inorder(tree->right, func);
			func(tree->n);
		}
		return;
	}
	else if (tree->right)
	{
		binary_tree_inorder(tree->right, func);
		func(tree->right->n);
	}
	else
		func(tree->n);
}

/*
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	if (tree->left)
	{
		binary_tree_inorder(tree->left, func);
		func(tree->n);
		if (tree->right)
		{
			binary_tree_inorder(tree->right, func);
			func(tree->n);
		}
		return;
	}
	else if (tree->right)
	{
		binary_tree_inorder(tree->right, func);
		func(tree->n);
	}
	else
		func(tree->n);
}
*/

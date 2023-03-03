#include "binary_trees.h"

/**
 * calc_balance - Recursively measures the balance factor of a binary tree.
 *
 * @tree: Pointer to the root node of the tree to measure the balance factor.
 * @balance: Calculated balance factor at current point/iteration.
 *
 * Return: Calculated balance factor of given binary tree.
 */

int calc_balance(const binary_tree_t *tree, size_t balance)
{
	if (!tree)
		return (balance);

	if (tree->left)
		balance = calc_balance(tree->left, balance);

	if (tree->right)
		balance = calc_balance(tree->right, balance);

	if (tree->parent)
	{
		if (tree == tree->parent->left)
		{
			if (tree->parent->right)
				balance++;
			else
				balance--;
		}
		else
			if (!tree->parent->left)
				balance--;
	}

	return (balance);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree.
 *
 * @tree: Pointer to the root node of the tree to measure the balance factor.
 *
 * Return: Balance factor of given binary tree.
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (calc_balance(tree, 0));
}

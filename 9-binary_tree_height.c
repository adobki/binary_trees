#include "binary_trees.h"

/**
 * move_right - Support function for calc_height_left. Checks for a left child
 *              in current node of binary tree. If exits, calls parent function
 *              to continue measuring height.
 *
 * @tree: Pointer to a node in the tree to be traversed.
 * @height: Calculated height in current branch.
 * @max: Maximum calculated height across counted branches.
 *
 * Return: Calculated height from given root node.
 */

size_t move_right(const binary_tree_t *tree, size_t height, size_t max)
{
	if (!tree)
		return (height);

	if (tree->right)
		height = calc_height_left(tree->right, ++height, max);

	return (height);
}

/**
 * calc_height_left - Calculates the height of a binary tree recursively.
 *                    Function only checks for left children. Another function
 *                    is called to check for right siblings.
 *
 * @tree: Pointer to a node in the tree to be traversed.
 * @height: Calculated height in current branch.
 * @max: Maximum calculated height across counted branches.
 *
 * Return: Calculated height from given root node.
 */

size_t calc_height_left(const binary_tree_t *tree, size_t height, size_t max)
{
	size_t count = 0;

	if (!tree)
		return (0);

	if (!tree->left)
	{
		height = move_right(tree, height, max);
		return (height);
	}

	count = calc_height_left(tree->left, height + 1, max);
	if (count > max)
		max = count;

	count = move_right(tree, height, max);
	if (count > max)
		max = count;

	return (max);
}

/**
 * binary_tree_height - Measures the height of a binary tree.
 *
 * @tree: Pointer to the root node of the tree to be traversed.
 *
 * Return: Calculated height from given root node.
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (calc_height_left(tree, 0, 0));
}

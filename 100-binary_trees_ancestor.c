#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 *
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 *
 * Return: Lowest common ancestor of given nodes on success,
 *         NULL otherwise.
 */

b_tree *binary_trees_ancestor(const b_tree *first, const b_tree *second)
{
	b_tree *first_tmp = (b_tree *)first, *second_tmp = (b_tree *)second;

	if (!first || !first->parent || !second || !second->parent)
		return (NULL);

	while (first_tmp)
	{
		while (second_tmp)
		{
			if (first_tmp == second_tmp)
				return (first_tmp);

			second_tmp = second_tmp->parent;
		}

		first_tmp = first_tmp->parent;
		second_tmp = (b_tree *)second;
	}

	return (NULL);
}

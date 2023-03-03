#include "binary_tree_dlist.h"
#include "binary_trees.h"

/**
 * dlist - Creates a doubly linked list for storing a binary
 *         tree nodes' data. List is sorted by nodes' level.
 *
 * @head: Pointer to head node of a tree_dlist.
 * @data: Integer to be stored in the data field.
 * @level: Integer to be stored in the level field.
 *
 * Return: Calculated size from given node.
 */

tree_dlist *dlist(tree_dlist *head, int data, int level)
{
	tree_dlist *node = NULL, *tmp_head = head;

	node = malloc(sizeof(tree_dlist));
	if (!node)
		return (NULL);

	node->data = data;
	node->level = level;
	node->next = node->prev = NULL;

	if (!head)
		return (node);

	while (tmp_head)
	{
		if (level < tmp_head->level)
		{
			node->next = tmp_head, node->prev = tmp_head->prev;
			tmp_head->prev = node;
			if (node->prev)
				node->prev->next = node;

			return (head);
		}

		if (tmp_head->next)
			tmp_head = tmp_head->next;
		else
			break;
	}

	node->prev = tmp_head;
	tmp_head->next = node;

	return (head);
}

/**
 * calc_nodes - Measures the size of a binary tree recursively.
 *
 * @tree: Pointer to a node in the tree to be traversed.
 * @level: Current level in given tree.
 * @list: Doubly linked list for storing binary tree nodes' data.
 *
 * Return: Calculated size from given node.
 */

tree_dlist *calc_nodes(const b_tree *tree, size_t level, tree_dlist *list)
{
	if (!tree)
		return (list);

	list = dlist(list, tree->n, level);

	if (tree->left)
		calc_nodes(tree->left, level + 1, list);

	if (tree->right)
		calc_nodes(tree->right, level + 1, list);

	return (list);
}

/**
 * binary_tree_levelorder - Goes through a binary tree using level-order
 *                          traversal and calls func() with each node's value.
 *
 * @tree: Pointer to the root node of the tree to be traversed.
 * @func: Pointer to a function to be called for each node.
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	tree_dlist *nodes;

	if (!tree || !func)
		return;

	nodes = calc_nodes(tree, 0, NULL);

	while (nodes)
	{
		func(nodes->data);
		if (nodes->next)
			nodes = nodes->next;
		else
			break;
	}

	while (nodes)
	{
		if (nodes->prev)
		{
			nodes = nodes->prev;
			free(nodes->next);
		}
		else
		{
			free(nodes);
			return;
		}
	}
}

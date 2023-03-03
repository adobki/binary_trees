#ifndef _BINARY_TREE_DLIST_H_
#define _BINARY_TREE_DLIST_H_

/**
 * struct binary_tree_dlist - Doubly linked list for storing a binary tree
 *                            nodes' values. This is a helper function for
 *                            binary_tree_levelorder(), for its calls to
 *                            func() after traversing a binary tree.
 *
 * @data: Integer stored in the node.
 * @level: Node's level in the tree.
 * @prev: Pointer to the previous node.
 * @next: Pointer to the next node.
 */

typedef struct binary_tree_dlist
{
	int data;
	int level;
	struct binary_tree_dlist *prev;
	struct binary_tree_dlist *next;
} tree_dlist;

#endif /* _BINARY_TREE_DLIST_H_ */

#include "../binary_trees.h"

#include "0x1C/binary_tree_print.c"
#include "../0-binary_tree_node.c"
#include "../1-binary_tree_insert_left.c"
#include "../2-binary_tree_insert_right.c"
#include "../3-binary_tree_delete.c"

/**
 * main - Entry point. Tests the code.
 *
 * Return: Always 0 (Success).
 */

int main(void)
{
	binary_tree_t *root;

	root = binary_tree_node(NULL, 98);

	if (root)
	{
		root->left = binary_tree_node(root, 12);
		root->right = binary_tree_node(root, 402);
		binary_tree_insert_right(root->left, 54);
		binary_tree_insert_right(root, 128);

		binary_tree_insert_left(root->right, 256);
		binary_tree_insert_left(root->left, 4);

		binary_tree_print(root);

		binary_tree_delete(root);
	}

	return (0);
}

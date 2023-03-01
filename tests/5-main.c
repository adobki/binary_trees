#include "../binary_trees.h"

#include "0x1C/binary_tree_print.c"
#include "../0-binary_tree_node.c"
#include "../1-binary_tree_insert_left.c"
#include "../2-binary_tree_insert_right.c"
#include "../3-binary_tree_delete.c"
#include "../5-binary_tree_is_root.c"

/**
 * binYesNo - Converts binary/boolean value to Yes/No string.
 *
 * @bin: Binary integer that corresponds to 0==True, 1==False.
 *
 * Return: "No" if bin == 0,
 *         "Yes" otherwise.
 */

char *binYesNo(int bin)
{
	if (bin == 0)
		return ("No");
	else
		return ("Yes");
}

/**
 * main - Entry point. Tests the code.
 *
 * Return: Always 0 (Success).
 */

int main(void)
{
	binary_tree_t *root;
	int ret;

	root = binary_tree_node(NULL, 98);
	if (root)
	{
		root->left = binary_tree_node(root, 12);
		root->right = binary_tree_node(root, 402);
		binary_tree_insert_right(root->left, 54);
		binary_tree_insert_right(root, 128);

		binary_tree_print(root);

		ret = binary_tree_is_root(root);
		printf("Is %-4d a root: %s\n", root->n, binYesNo(ret));
		ret = binary_tree_is_root(root->right);
		printf("Is %-4d a root: %s\n", root->right->n, binYesNo(ret));
		ret = binary_tree_is_root(root->right->right);
		printf("Is %-4d a root: %s\n", root->right->right->n, binYesNo(ret));
		ret = binary_tree_is_root(root->left->right);
		printf("Is %-4d a root: %s\n", root->left->right->n, binYesNo(ret));
		ret = binary_tree_is_root(root->left);
		printf("Is %-4d a root: %s\n", root->left->n, binYesNo(ret));
		ret = binary_tree_is_root(NULL);
		printf("Is NULL a root: %s\n", binYesNo(ret));
	}

	binary_tree_delete(root);

	return (0);
}

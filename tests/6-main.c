#include "../binary_trees.h"

#include "0x1C/binary_tree_print.c"
#include "../0-binary_tree_node.c"
#include "../1-binary_tree_insert_left.c"
#include "../2-binary_tree_insert_right.c"
#include "../3-binary_tree_delete.c"
#include "../6-binary_tree_preorder.c"

/**
 * print_num - Prints a number
 *
 * @n: Number to be printed
 */
void print_num(int n)
{
	printf("%d\n", n);
}


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
		root->left->left = binary_tree_node(root->left, 6);
		root->left->right = binary_tree_node(root->left, 56);
		root->right->left = binary_tree_node(root->right, 256);
		root->right->right = binary_tree_node(root->right, 512);

		binary_tree_print(root);
		printf("\n");
		binary_tree_preorder(root, &print_num);
	}

	binary_tree_delete(root);

	return (0);
}

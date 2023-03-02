#include "../binary_trees.h"

#include "0x1C/binary_tree_print.c"
#include "../0-binary_tree_node.c"
#include "../1-binary_tree_insert_left.c"
#include "../2-binary_tree_insert_right.c"
#include "../3-binary_tree_delete.c"
#include "../11-binary_tree_size.c"

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
	int size;

	root = binary_tree_node(NULL, 98);
	if (root)
	{
		root->left = binary_tree_node(root, 90);
		root->right = binary_tree_node(root, 402);
		binary_tree_insert_left(root->right, 79);
		binary_tree_insert_right(root->right, 99);
		binary_tree_insert_right(root->left, 84);
		binary_tree_insert_left(root->left->right, 80);
		binary_tree_insert_right(root->left, 74);
		binary_tree_insert_right(root->left, 64);
		binary_tree_insert_left(root->left, 44);
		binary_tree_insert_left(root, 128);

		binary_tree_insert_right(root, 120);
		binary_tree_insert_right(root, 110);
		binary_tree_insert_right(root, 100);

		printf("\n");
		binary_tree_print(root);
		printf("\n");

		size = (int)binary_tree_size(root);
		printf("Size from %-4d= %-3d\n", root->n, size);
		size = binary_tree_size(root->right);
		printf("Size from %-4d= %-3d\n", root->right->n, size);
		size = binary_tree_size(root->left->left->right);
		printf("Size from %-4d= %-3d\n", root->left->left->right->n, size);
	}

	binary_tree_delete(root);

	return (0);
}

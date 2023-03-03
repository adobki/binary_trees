#include "../binary_trees.h"

#include "0x1C/binary_tree_print.c"
#include "../0-binary_tree_node.c"
#include "../1-binary_tree_insert_left.c"
#include "../2-binary_tree_insert_right.c"
#include "../3-binary_tree_delete.c"
#include "../14-binary_tree_balance.c"

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
	int balance;

	root = binary_tree_node(NULL, 98);
	if (root)
	{
		root->left = binary_tree_node(root, 12);
		root->right = binary_tree_node(root, 402);
		binary_tree_insert_right(root->left, 54);
		binary_tree_insert_right(root, 128);
		binary_tree_insert_left(root, 45);
		binary_tree_insert_right(root->left, 50);
		binary_tree_insert_left(root->left->left, 10);
		binary_tree_insert_left(root->left->left->left, 8);
		binary_tree_print(root);

		balance = binary_tree_balance(root);
		printf("Balance of %d: %+d\n", root->n, balance);
		balance = binary_tree_balance(root->right);
		printf("Balance of %d: %+d\n", root->right->n, balance);
		balance = binary_tree_balance(root->left->left->right);
		printf("Balance of %d: %+d\n", root->left->left->right->n, balance);
	}

	binary_tree_delete(root);

	return (0);
}

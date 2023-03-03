#include "../binary_trees.h"

#include "0x1C/binary_tree_print.c"
#include "../0-binary_tree_node.c"
#include "../1-binary_tree_insert_left.c"
#include "../2-binary_tree_insert_right.c"
#include "../3-binary_tree_delete.c"
#include "../100-binary_trees_ancestor.c"

/**
 * launch_test - Test ancestor function and print informations
 *
 * @n1: First node
 * @n2: Second node
 */
void launch_test(binary_tree_t *n1, binary_tree_t *n2)
{
	binary_tree_t *ancestor;
	int v1 = 0, v2 = 0;

	if (n1)
		v1 = n1->n;
	if (n2)
		v2 = n2->n;

	ancestor = binary_trees_ancestor(n1, n2);
	printf("Ancestor of [%d] & [%d]: ", v1, v2);
	if (!ancestor)
		printf("(nil)\n");
	else
		printf("%d\n", ancestor->n);
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

		launch_test(NULL, root->left->left->right->right);
		launch_test(NULL, NULL);
		launch_test(root->left, root->right);
		launch_test(root->left->left, root->right->right->right);
		launch_test(root->right->right, root->right->right->right);
		launch_test(root->left->left, root->right->right->right);
		launch_test(root->left->left->left, root->left->left->right->right->right);
	}

	binary_tree_delete(root);

	return (0);
}

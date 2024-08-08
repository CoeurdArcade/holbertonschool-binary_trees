#include "binary_trees.h"

/**
 * bst_search - finds location of where the value should be inserted
 * @tree: tree to sort in binary search order
 * @value: value to find where should be inserted
 *
 * Return: pointer to location to insert value at
 */

bst_t *bst_search(const bst_t *tree, int value)
{
	const bst_t *current = tree;

	while (current != NULL)
	{
		if (current->n == value)
			return ((bst_t *)current);

		if (value < current->n)
			current = current->left;
		else
			current = current->right;
	}

	return (NULL);
}

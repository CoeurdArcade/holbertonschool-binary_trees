#include "binary_trees.h"

/**
 * array_to_bst - builds a binary search tree from array of ints
 * @array: pointer to first element of array
 * @size: size of int array
 *
 * Return: pointer to the root node of bst or NULL if failed
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t i;

	if (array == NULL || size == 0)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		if (bst_insert(&tree, array[i]) == NULL)
		{
			fprintf(stderr, "Error: Failed to insert %d\n", array[i]);
			return (NULL);
		}
	}
	return (tree);
}

/**
 * bst_search - finds location of where the value should be inserted
 * @tree: tree to sort in binary search order
 * @value: value to find where should be inserted
 *
 * Return: pointer to location to insert value at
 */

bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);
	if (tree->n == value)
		return ((bst_t *)tree);
	if (value < tree->n)
		return (bst_search(tree->left, value));
	return (bst_search(tree->right, value));
}

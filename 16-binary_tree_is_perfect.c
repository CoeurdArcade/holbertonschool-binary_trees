#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a tree
 * @tree: pointer to the root node
 * Return: if tree null 0, else the height
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		int count_left = 0;

		int count_right = 0;

		if (tree->left)
			count_left = 1 + binary_tree_height(tree->left);

		if (tree->right)
			count_right = 1 + binary_tree_height(tree->right);

		if (count_left < count_right)
			return (count_right);
		else
			return (count_left);
	}

	return (0);
}

/**
 *binary_tree_size - measures the size of a tree
 *@tree: pointer to the root node of the tree
 *Return: 0 if null, else the measure of the tree
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	int counter = 0;

	if (tree != NULL)
	{
		counter++;

		counter += binary_tree_size(tree->left);

		counter += binary_tree_size(tree->right);
	}

	return (counter);
}

/**
 *binary_tree_is_perfect - checks if a binary tree is perfect
 *@tree: pointer to the root node
 *
 *Return: retunr 1 this a tree perfect else 0;
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int altura, tamanio;
	int n = 1;

	altura = binary_tree_height(tree);
	tamanio = binary_tree_size(tree);

	for (; altura >= 0; altura--)
	{
		n *= 2;
	}

	return (n - 1 == tamanio ? 1 : 0);

}

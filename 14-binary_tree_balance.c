#include "binary_trees.h"

/**
 * binary_tree_balance - measures the balance factor of binary tree
 * balance factor is difference in height of two children's subtrees
 * @tree: pointer to the root node of the tree
 *
 * Return: balance factor, or 0 if NULL
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (height_helper(tree->left) - height_helper(tree->right));
}

/**
 * max - returns the maximum of two numbers
 * @a: first number
 * @b: second number
 *
 * Return: the maximum of a and b
 */

size_t max(size_t a, size_t b)
{
	return (a > b ? a : b);
}

/**
 * height_helper - the heavy lifter
 * @tree: tree to measure
 *
 * Return: height, root inclusive
 */

size_t height_helper(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL)
		return (0);

	left = height_helper(tree->left);
	right = height_helper(tree->right);

	return (1 + max(left, right));
}

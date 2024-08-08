#include "binary_trees.h"

/**
 * binary_tree_is_bst - checks if tree is binary search tree
 * @tree: pointer to the root node of the tree
 *
 * Return: 1 if valid BST, 0 otherwise
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_bst_recursive((binary_tree_t *)tree, INT_MIN, INT_MAX));
}

/**
 * is_bst_recursive - recursively checks if valid binary search tree
 * @tree: tree to check
 * @min: minimum value root node must be greater than
 * @max: maximum value root node must be less than
 *
 * Return: 1 if successful, 0 if failed
 */

int is_bst_recursive(binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);
	if (tree->n <= min || tree->n >= max)
		return (0);
	return (check_left(tree->left, min, tree->n) &&
			check_right(tree->right, tree->n, max));
}

/**
 * check_left - checks the left subtree
 * @tree: left subtree to check
 * @min: minimum value root node must be greater than
 * @max: maximum value root node must be less than
 *
 * Return: 1 if successful, 0 if failed
 */

int check_left(binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);
	if (tree->n <= min || tree->n >= max)
		return (0);
	return (check_left(tree->left, min, tree->n) &&
			check_right(tree->right, tree->n, max));
}

/**
 * check_right - checks the right subtree
 * @tree: right subtree to check
 * @min: minimum value root node must be greater than
 * @max: maximum value root node must be less than
 *
 * Return: 1 if successful, 0 if failed
 */

int check_right(binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);
	if (tree->n <= min || tree->n >= max)
		return (0);
	return (check_left(tree->left, min, tree->n) &&
			check_right(tree->right, tree->n, max));
}

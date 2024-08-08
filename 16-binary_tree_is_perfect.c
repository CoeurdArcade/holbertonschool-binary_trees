#include "binary_trees.h"

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree
 *
 * Return: 1 if perfect, or 0 if NULL or not perfect
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_perfect_height(tree));
}

/**
 * is_perfect_height - checks if a binary tree is perfect using height
 * @tree: pointer to the root node of the tree
 *
 * Return: 1 if perfect, or 0 if not perfect
 */

int is_perfect_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (1);

	left_height = height_helper(tree->left);
	right_height = height_helper(tree->right);

	if (left_height != right_height)
		return (0);

	return (is_perfect_height(tree->left) && is_perfect_height(tree->right));
}

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
 * height_helper - the heavy lifter
 * @tree: tree to measure
 * * Return: height, root inclusive
 */

size_t height_helper(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL)
		return (0);

	left = height_helper(tree->left);
	right = height_helper(tree->right);

	return ((left > right ? left : right) + 1);
}

/**
 * binary_tree_is_leaf - checks if the given node is a leaf (no children)
 * @node: pointer to the binary tree node to check if leaf
 *
 * Return: 1 if node is a leaf, 0 if not
 */

int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	if (node->right || node->left)
		return (0);
	return (1);
}

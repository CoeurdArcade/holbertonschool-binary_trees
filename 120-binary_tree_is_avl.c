#include "binary_trees.h"
#include <limits.h>

size_t height(const binary_tree_t *tree);
int is_avl_helper(const binary_tree_t *tree, int lo, int hi);
int binary_tree_is_avl(const binary_tree_t *tree);

/**
 * height - A function that Measures the height of a binary tree.
 * @tree: is pointer to the root node of the tree to measure the height.
 * Return: If tree is NULL, your function must return 0, else return height.
 */

size_t height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	size_t l = height(tree->left);
	size_t r = height(tree->right);
	return ((l > r) ? l + 1 : r + 1);
}

/**
 * is_avl_helper - A function that Checks if a binary tree
 *                 is a valid AVL tree.
 * @tree: is a pointer to the root node of the tree to check.
 * @lo: The value of the smallest node visited thus far.
 * @hi: The value of the largest node visited this far.
 * Return: If the tree is a valid AVL tree, 1, otherwise, 0.
 */

int is_avl_helper(const binary_tree_t *tree, int lo, int hi)
{
	if (tree == NULL)
		return (1);
	if (tree->n < lo || tree->n > hi)
		return (0);
	size_t lhgt = height(tree->left);
	size_t rhgt = height(tree->right);
	size_t diff = lhgt > rhgt ? lhgt - rhgt : rhgt - lhgt;
	if (diff > 1)
		return (0);
	return (is_avl_helper(tree->left, lo, tree->n - 1) &&
		is_avl_helper(tree->right, tree->n + 1, hi));
}

/**
 * binary_tree_is_avl - A function that Checks if
 *                      a binary tree is a valid AVL tree.
 * @tree: is a pointer to the root node of the tree to check.
 * Return: 1 if tree is a valid AVL tree, and 0 otherwise
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_avl_helper(tree, INT_MIN, INT_MAX));
}

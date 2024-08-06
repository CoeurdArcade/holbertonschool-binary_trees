#include "binary_trees.h"

/**
 * binary_tree_leaves - counts number of leaves in a binary tree
 * @tree: pointer to the root node of the tree
 *
 * Return: number of leaves, or 0 if NULL
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (binary_tree_is_leaf(tree))
		return (1);
	return (binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right));
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
	return (!(node->right) && !(node->left));
}


#include "binary_trees.h"

/**
 * binary_tree_nodes - counts nodes with at least 1 child
 * @tree: pointer to the root node of the tree
 *
 * Return: number of leaves, or 0 if NULL
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree == NULL || binary_tree_is_leaf(tree))
		return (0);

	return (1 + binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right));
}

/**
 * binary_tree_is_leaf - checks if the given node is a leaf (no children)
 * @node: pointer to the binary tree node to check if leaf
 *
 * Return: 1 if node is a leaf, 0 if not
 */

int binary_tree_is_leaf(const binary_tree_t *node)
{
	return (node != NULL && node->right == NULL && node->left == NULL);
}


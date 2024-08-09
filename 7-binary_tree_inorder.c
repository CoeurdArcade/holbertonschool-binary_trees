#include "binary_trees.h"

/**
 * binary_tree_inorder - print tree in-order traversal
 * @tree: tree to print
 * @func: function to print
 *
 * Return: void
 */

void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree != NULL)
	{
		if (func != NULL)
		{
			binary_tree_inorder(tree->left, func);
			func(tree->n);
			binary_tree_inorder(tree->right, func);
		}
	}
}

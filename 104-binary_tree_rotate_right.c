#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 * @tree: pointer to the root node of the tree
 *
 * Return: pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_root, *temp;

	if (tree == NULL || tree->left == NULL)
		return (tree);

	new_root = tree->left;
	temp = new_root->right;

	new_root->parent = tree->parent;
	new_root->right = tree;
	tree->parent = new_root;
	tree->left = temp;

	if (temp != NULL)
		temp->parent = tree;

	return (new_root);
}

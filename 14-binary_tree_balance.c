#include "binary_trees.h"

/**
 * binary_tree_balance - factor de balance
 * @tree: arbol
 *
 * Return: Factor de balance, la resta de la altira izquierda con la derecha
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree != NULL)
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));

	return (0);
}

/**
 * binary_tree_height - measures the height of a tree
 * @tree: pointer to the root node
 * Return: if tree null 0, else the height
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (max_height(tree->left, tree->right));
}

/**
 * max_height - returns the maximum height of two subtrees
 * @left: pointer to the left subtree
 * @right: pointer to the right subtree
 * Return: maximum height of the two subtrees
 */

size_t max_height(const binary_tree_t *left, const binary_tree_t *right)
{
	size_t left_height = left ? 1 + binary_tree_height(left) : 0;
	size_t right_height = right ? 1 + binary_tree_height(right) : 0;

	return (left_height > right_height ? left_height : right_height);
}

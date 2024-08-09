#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a tree
 * @tree: pointer to the root node
 * Return: if tree null 0, else the height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	size_t left_height = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	size_t right_height = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	return (left_height > right_height ? left_height : right_height);
}

/**
 * binary_tree_size - measures the size of a tree
 * @tree: pointer to the root node of the tree
 * Return: 0 if null, else the measure of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node
 * Return: 1 if the tree is perfect, else 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height = binary_tree_height(tree);
	size_t size = binary_tree_size(tree);
	size_t expected_size = 1;

	for (size_t i = 0; i <= height; i++)
	{
		expected_size *= 2;
	}

	return (expected_size - 1 == size ? 1 : 0);
}

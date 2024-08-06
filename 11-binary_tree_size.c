#include "binary_trees.h"

/**
 * binary_tree_size - measures size of a binary tree
 * @tree: pointer to the root node of the tree
 *
 * Return: size of tree, 0 if tree is NULL
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;
	const binary_tree_t *stack[1024];
	int top = 0;

	if (tree == NULL)
		return (0);

	stack[top++] = tree;

	while (top > 0)
	{
		const binary_tree_t *current = stack[--top];

		size++;

		if (current->left != NULL)
			stack[top++] = current->left;

		if (current->right != NULL)
			stack[top++] = current->right;
	}

	return (size);
}

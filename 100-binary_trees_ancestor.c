#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds lowest common ancestor of two nodes
 * @first: pointer to the first node of the binary tree
 * @second: pointer to the second node of the binary tree
 *
 * Return: pointer to location of lowest common ancestor or NULL
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	binary_tree_t *first_mover, *second_mover;

	if (first == NULL || second == NULL)
		return (NULL);

	first_mover = (binary_tree_t *)first;
	second_mover = (binary_tree_t *)second;

	while (binary_tree_depth(first_mover) > binary_tree_depth(second_mover))
		first_mover = first_mover->parent;
	while (binary_tree_depth(second_mover) > binary_tree_depth(first_mover))
		second_mover = second_mover->parent;

	return (find_common_ancestor(first_mover, second_mover));
}

/**
 * find_common_ancestor - finds the lowest common ancestor recursively
 * @first_mover: starting position of first node, same level as second
 * @second_mover: starting position of the second node, same level as first
 *
 * Return: location of common ancestor or NULL
 */

binary_tree_t *find_common_ancestor(binary_tree_t *first_mover, binary_tree_t *second_mover)
{
	if (first_mover == second_mover)
		return (first_mover);

	first_mover = first_mover->parent;
	second_mover = second_mover->parent;

	return (find_common_ancestor(first_mover, second_mover));
}

/**
 * binary_tree_depth - measures the depth of a binary tree
 * @tree: pointer to the root node of the tree
 *
 * Return: depth of tree, 0 if tree is NULL
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth;

	if (tree == NULL)
		return (0);

	depth = depth_helper(tree);
	return (depth - 1);
}

/**
 * depth_helper - the heavy lifter
 * @tree: tree to measure
 *
 * Return: depth, root inclusive
 */

size_t depth_helper(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + depth_helper(tree->parent));
}

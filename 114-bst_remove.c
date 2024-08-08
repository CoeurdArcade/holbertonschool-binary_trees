#include "binary_trees.h"

/**
 * bst_remove - removes node from a binary search tree,
 * in-order successor replaces
 * @root: pointer to the root node
 * @value: value to remove
 *
 * Return: pointer to root node of bst
 */

bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *rm_node = NULL, *temp = NULL;

	if (root == NULL)
		return (NULL);
	rm_node = bst_search2(root, value);
	if (rm_node == NULL)
		return (NULL);

	if (rm_node->left == NULL && rm_node->right == NULL)
		return (remove_leaf(root, rm_node));
	if (rm_node->left == NULL)
		return (remove_one_child(root, rm_node, rm_node->right));
	if (rm_node->right == NULL)
		return (remove_one_child(root, rm_node, rm_node->left));

	temp = find_min(rm_node->right);
	rm_node->n = temp->n;
	return (remove_leaf(root, temp));
}

/**
 * bst_search2 - finds location of where the value should be inserted
 * @tree: tree to sort in binary search order
 * @value: value to find where should be inserted
 *
 * Return: pointer to location to insert value at
 */

bst_t *bst_search2(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);
	if (tree->n == value)
		return ((bst_t *)tree);

	if (value < tree->n)
		return (bst_search2(tree->left, value));
	return (bst_search2(tree->right, value));
}

/**
 * find_min - finds the minimum value node in a tree
 * @node: pointer to the root node of the tree
 *
 * Return: pointer to the minimum value node
 */

bst_t *find_min(bst_t *node)
{
	while (node->left != NULL)
		node = node->left;
	return (node);
}

/**
 * remove_leaf - removes a leaf node from the tree
 * @root: pointer to the root node of the tree
 * @node: pointer to the leaf node to remove
 *
 * Return: pointer to the root node of the tree
 */

bst_t *remove_leaf(bst_t *root, bst_t *node)
{
	if (node->parent == NULL)
		root = NULL;
	else if (node->parent->left == node)
		node->parent->left = NULL;
	else
		node->parent->right = NULL;
	free(node);
	return (root);
}

/**
 * remove_one_child - removes a node with one child from the tree
 * @root: pointer to the root node of the tree
 * @node: pointer to the node to remove
 * @child: pointer to the child node of the node to remove
 *
 * Return: pointer to the root node of the tree
 */

bst_t *remove_one_child(bst_t *root, bst_t *node, bst_t *child)
{
	if (node->parent == NULL)
		root = child;
	else if (node->parent->left == node)
		node->parent->left = child;
	else
		node->parent->right = child;
	child->parent = node->parent;
	free(node);
	return (root);
}

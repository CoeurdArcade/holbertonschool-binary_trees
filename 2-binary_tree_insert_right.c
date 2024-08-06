#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts new binary tree node as parent-right
 * if parent-right exists, becomes new node's right child
 * @parent: parent node of the node to create
 * @value: value to put in the new node
 *
 * Return: pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (!parent)
		return (NULL);

	new_node = malloc(sizeof(binary_tree_t));
	if (!new_node)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = parent->right;

	parent->right = new_node;

	if (new_node->right)
		new_node->right->parent = new_node;

	return (new_node);
}


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

    size_t left_height = tree->left ? 1 + binary_tree_height(tree->left) : 0;
    size_t right_height = tree->right ? 1 + binary_tree_height(tree->right) : 0;

    return (left_height > right_height ? left_height : right_height);
}

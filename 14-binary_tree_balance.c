#include "binary_trees.h"

/**
 * binary_tree_balance - Measure balance factor of tree.
 *
 * @tree: root node.
 *
 * Return: balance factor, 0 otherwise.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
    if (tree)
    {
        int left_height, right_height;
        left_height = binary_tree_height(tree->left);
        right_height = binary_tree_height(tree->right);

        return (left_height - right_height);
    }

    return (0);
}

/**
 * binary_tree_height - Measure the height of tree.
 *
 * @tree: root node.
 *
 * Return: height or 0 otherwise.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    if (tree)
    {
        size_t left_height, right_height;
        left_height = tree->left ? 1 + binary_tree_height(tree->left) : 0;
        right_height = tree->right ? 1 + binary_tree_height(tree->right) : 0;

        return ((left_height > right_height) ? left_height : right_height);
    }

    return (0);
}

#include "binary_trees.h"

/**
 * binary_tree_height - Measure height of binary tree.
 *
 * @tree: root node.
 *
 * Return: height or 0 otherwise.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    if (tree)
    {
        size_t left_height = 0, right_height = 0;
        left_height = (tree->left) ? 1 + binary_tree_height(tree->left) : 0;
        right_height = (tree->right) ? 1 + binary_tree_height(tree->right) : 0;

        return ((left_height > right_height) ? left_height : right_height);
    }

    return (0);
}

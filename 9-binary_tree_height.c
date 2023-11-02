#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 *
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, your function must return 0, else return the height.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    /** Check if the tree is not NULL */
    if (tree)
    {
        size_t left_height = 0, right_height = 0;

        /** Calculate the height of the left subtree, if it exists */
        left_height = (tree->left) ? 1 + binary_tree_height(tree->left) : 0;

        /** Calculate the height of the right subtree, if it exists */
        right_height = (tree->right) ? 1 + binary_tree_height(tree->right) : 0;

        /** Return the maximum of left and right subtree heights */
        return ((left_height > right_height) ? left_height : right_height);
    }

    /** If the tree is NULL, return 0 */
    return (0);
}

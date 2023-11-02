#include "binary_trees.h"

/**
 * binary_tree_balance - Measures the balance factor of a binary tree.
 *
 * @tree: A pointer to the root node of the tree to measure the balance factor.
 *
 * Return: If tree is NULL, return 0, else return the balance factor.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
    if (tree)
    {
        int left_height, right_height;

        /** Calculate the height of the left subtree */
        left_height = binary_tree_height(tree->left);

        /** Calculate the height of the right subtree */
        right_height = binary_tree_height(tree->right);

        /** Return the balance factor by subtracting right height from left height */
        return (left_height - right_height);
    }

    /** If the tree is NULL, return 0 */
    return (0);
}

/**
 * binary_tree_height - Measures the height of a binary tree.
 *
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, your function must return 0, else return the height.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    if (tree)
    {
        size_t left_height, right_height;

        /** Calculate the height of the left subtree */
        left_height = tree->left ? 1 + binary_tree_height(tree->left) : 0;

        /** Calculate the height of the right subtree */
        right_height = tree->right ? 1 + binary_tree_height(tree->right) : 0;

        /** Return the maximum of left and right subtree heights */
        return ((left_height > right_height) ? left_height : right_height);
    }

    /** If the tree is NULL, return 0 */
    return (0);
}

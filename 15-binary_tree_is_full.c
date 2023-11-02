#include "binary_trees.h"

/**
 * is_full_recursive - Checks if a binary tree is full recursively.
 *
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: If tree is not full, 0. Otherwise, 1.
 */
int is_full_recursive(const binary_tree_t *tree)
{
    if (tree != NULL)
    {
        /** Check if either the left or the right child is missing */
        if ((tree->left != NULL && tree->right == NULL) ||
            (tree->left == NULL && tree->right != NULL) ||
            is_full_recursive(tree->left) == 0 ||
            is_full_recursive(tree->right) == 0)
        {
            return (0); /** The tree is not full */
        }
    }

    return (1); /** The tree is full */
}

/**
 * binary_tree_is_full - Checks if a binary tree is full.
 *
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: If tree is NULL or is not full - 0. Otherwise - 1.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
    if (tree == NULL)
    {
        return (0); /** The tree is NULL, so it's not full */
    }

    return (is_full_recursive(tree)); /** Check if the tree is full recursively */
}

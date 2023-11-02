#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the leaves in a binary tree.
 *
 * @tree: A pointer to the root node of the tree to count the leaves of.
 *
 * Return: The number of leaves in the tree.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
    size_t leaves = 0;

    /** Check if the tree is not NULL */
    if (tree)
    {
        /** Increment leaves if the current node is a leaf (has no children) */
        leaves += (!tree->left && !tree->right) ? 1 : 0;

        /** Recursively count leaves in the left subtree */
        leaves += binary_tree_leaves(tree->left);

        /** Recursively count leaves in the right subtree */
        leaves += binary_tree_leaves(tree->right);
    }

    return (leaves);
}

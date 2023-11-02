#include "binary_trees.h"

/**
 * binary_tree_postorder - Traverses a binary tree using post-order traversal.
 *
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node's value.
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
    /** Check if both tree and func are not NULL */
    if (tree && func)
    {
        /** Recursively traverse the left subtree in post-order */
        binary_tree_postorder(tree->left, func);

        /** Recursively traverse the right subtree in post-order */
        binary_tree_postorder(tree->right, func);

        /** Call the function for the current node's value */
        func(tree->n);
    }
}

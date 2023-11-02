#include "binary_trees.h"

/**
 * binary_tree_preorder - Traverses a binary tree using pre-order traversal.
 *
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node's value.
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
    /** Check if both tree and func are not NULL */
    if (tree && func)
    {
        /** Call the function for the current node's value */
        func(tree->n);

        /** Recursively traverse the left subtree in pre-order */
        binary_tree_preorder(tree->left, func);

        /** Recursively traverse the right subtree in pre-order */
        binary_tree_preorder(tree->right, func);
    }
}

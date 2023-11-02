#include "binary_trees.h"

/**
 * binary_tree_is_root - Checks if a node is the root of a binary tree.
 *
 * @node: A pointer to the node to check.
 *
 * Return: If the node is the root - 1.
 *         Otherwise - 0.
 */
int binary_tree_is_root(const binary_tree_t *node)
{
    /** Check if the node is NULL or has a parent */
    if (node == NULL || node->parent != NULL) {
        /** Node is not a root */
        return (0);
    }

    /** Node is the root */
    return (1);
}

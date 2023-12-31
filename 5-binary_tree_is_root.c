#include "binary_trees.h"

/**
 * binary_tree_is_root - Checks if node is root.
 *
 * @node: node to check.
 *
 * Return: 1 if leaf, 0 otherwise.
 */
int binary_tree_is_root(const binary_tree_t *node)
{
    if (node == NULL || node->parent != NULL) {
        return (0);
    }

    return (1);
}

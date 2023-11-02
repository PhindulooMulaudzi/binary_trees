#include "binary_trees.h"

/**
 * binary_tree_depth - Measure depth of node in a tree.
 *
 * @tree: root node.
 *
 * Return: depth or 0 otherwise.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
    return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}

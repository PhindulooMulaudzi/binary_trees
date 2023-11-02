#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node in a binary tree.
 *
 * @node: A pointer to the node to find the uncle of.
 *
 * Return: If node is NULL or has no uncle, NULL.
 *         Otherwise, a pointer to the uncle node.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
    if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
    {
        return (NULL); /** Node is NULL, has no parent, or has no grandparent, so no uncle. */
    }

    if (node->parent->parent->left == node->parent)
    {
        return (node->parent->parent->right); /** Node's parent is a left child, return right uncle. */
    }

    return (node->parent->parent->left); /** Node's parent is a right child, return left uncle. */
}

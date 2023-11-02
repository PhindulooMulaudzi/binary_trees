#include "binary_trees.h"

/**
 * is_leaf - Check if node is leaf of a tree.
 *
 * @node: node.
 *
 * Return: 1 if leaf, 0 otherwise.
 */
unsigned char is_leaf(const binary_tree_t *node)
{
    return ((node->left == NULL && node->right == NULL) ? 1 : 0);
}

/**
 * depth - Get depth of given node.
 *
 * @tree: root node.
 *
 * Return: depth of the node.
 */
size_t depth(const binary_tree_t *tree)
{
    return (tree->parent != NULL ? 1 + depth(tree->parent) : 0);
}

/**
 * get_leaf - Get leaf of a binary tree.
 *
 * @tree: root node.
 *
 * Return: first encountered leaf.
 */
const binary_tree_t *get_leaf(const binary_tree_t *tree)
{
    if (is_leaf(tree) == 1)
        return (tree);
    return (tree->left ? get_leaf(tree->left) : get_leaf(tree->right));
}

/**
 * is_perfect_recursive - Check if tree is perfect.
 *
 * @tree: root node.
 * @leaf_depth: depth of leaf in the tree.
 * @level: Level of current node.
 *
 * Return: 1 if perfect, 0 otherwise.
 */
int is_perfect_recursive(const binary_tree_t *tree,
        size_t leaf_depth, size_t level)
{
    if (is_leaf(tree))
        return (level == leaf_depth ? 1 : 0);
    if (tree->left == NULL || tree->right == NULL)
        return (0);
    return (is_perfect_recursive(tree->left, leaf_depth, level + 1) &&
            is_perfect_recursive(tree->right, leaf_depth, level + 1));
}

/**
 * binary_tree_is_perfect - Checks if tree is perfect.
 *
 * @tree: root node.
 *
 * Return: 1 if perfect, 0 otherwise.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);
    return (is_perfect_recursive(tree, depth(get_leaf(tree)), 0));
}

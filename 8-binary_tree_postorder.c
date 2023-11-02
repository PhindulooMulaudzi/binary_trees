#include "binary_trees.h"

/**
 * binary_tree_postorder - Traverse tree using post-order traversal.
 *
 * @tree: root node.
 * @func: functor to node's value.
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
    if (tree && func)
    {
        binary_tree_postorder(tree->left, func);
        binary_tree_postorder(tree->right, func);
        func(tree->n);
    }
}

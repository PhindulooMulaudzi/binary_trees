#include "binary_trees.h"

/**
 * binary_tree_delete - Delete binary tree including nodes.
 *
 * @tree: root node to delete.
 */
void binary_tree_delete(binary_tree_t *tree)
{
    if (tree != NULL)
    {
        binary_tree_delete(tree->left);
        binary_tree_delete(tree->right);
        free(tree);
    }
}

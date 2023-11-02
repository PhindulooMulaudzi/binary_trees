#include "binary_trees.h"

/**
 * binary_tree_delete - Deletes a binary tree and its nodes.
 *
 * @tree: A pointer to the root node of the tree to delete.
 */
void binary_tree_delete(binary_tree_t *tree)
{
    /** Check if the tree is not NULL */
    if (tree != NULL)
    {
        /** Recursively delete the left subtree */
        binary_tree_delete(tree->left);

        /** Recursively delete the right subtree */
        binary_tree_delete(tree->right);

        /** Free the current node */
        free(tree);
    }
}

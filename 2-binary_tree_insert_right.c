#include "binary_trees.h"

/**
 * binary_tree_insert_right - Insert a node as the right child of another node
 *                          in a binary tree.
 *
 * @parent: A pointer to the node to insert the right child.
 * @value: The value to store in the new node.
 *
 * Return: If parent is NULL or memory allocation fails - NULL.
 *         Otherwise - a pointer to the new node.
 *
 * Description: If the parent already has a right child, the new node
 *              takes its place, and the old right child becomes the right
 *              child of the new node.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
    /** Create a new binary tree node */
    binary_tree_t *new_node;

    if (parent == NULL) {
        /** Return NULL if parent is NULL */
        return (NULL);
    }

    /** Create a new node with the specified value */
    new_node = binary_tree_node(parent, value);

    if (new_node == NULL) {
        /** Return NULL if memory allocation fails */
        return (NULL);
    }

    if (parent->right != NULL) {
        /** If parent already has a right child, adjust pointers */
        new_node->right = parent->right;
        parent->right->parent = new_node;
    }

    /** Set the new node as the right child of the parent */
    parent->right = new_node;

    return (new_node);
}

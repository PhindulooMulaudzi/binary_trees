#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Left-rotates a binary tree.
 * @tree: A pointer to the root node of the tree to rotate.
 *
 * Return: A pointer to the new root node after rotation.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *pivot, *tmp;

	if (tree == NULL || tree->right == NULL)
	{
		/* Invalid input or no right child; no rotation needed */
		return (NULL);
	}

	/* Perform left rotation */
	pivot = tree->right;
	tmp = pivot->left;
	pivot->left = tree;
	tree->right = tmp;

	/* Update parent pointers */
	if (tmp != NULL)
		tmp->parent = tree;
	tmp = tree->parent;
	tree->parent = pivot;
	pivot->parent = tmp;

	if (tmp != NULL)
	{
		/* Update parent's child pointer to the new root */
		if (tmp->left == tree)
			tmp->left = pivot;
		else
			tmp->right = pivot;
	}

	return (pivot);
}

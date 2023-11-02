#include "binary_trees.h"

/** Structure for the binary tree level order queue node **/
typedef struct levelorder_queue_s
{
	binary_tree_t *node;
	struct levelorder_queue_s *next;
} levelorder_queue_t;

/**
 * create_node - Creates a new levelorder_queue_t node.
 * @node: The binary tree node for the new node to contain.
 *
 * Return: If an error occurs, NULL.
 *         Otherwise, a pointer to the new node.
 */
levelorder_queue_t *create_node(binary_tree_t *node)
{
	levelorder_queue_t *new_node = malloc(sizeof(levelorder_queue_t));
	if (new_node == NULL)
	{
		/* Handle memory allocation error */
		return NULL;
	}

	new_node->node = node;
	new_node->next = NULL;

	return new_node;
}

/**
 * free_queue - Frees a levelorder_queue_t queue.
 * @head: A pointer to the head of the queue.
 */
void free_queue(levelorder_queue_t *head)
{
	levelorder_queue_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

/**
 * push - Pushes a node to the back of a levelorder_queue_t queue.
 * @node: The binary tree node to push.
 * @queue: A pointer to the head of the queue.
 * @tailNode: A pointer to the tail of the queue.
 *
 * Description: Handles memory allocation failure gracefully.
 */
void push(binary_tree_t *node, levelorder_queue_t **queue, levelorder_queue_t **tailNode)
{
	levelorder_queue_t *new_node = create_node(node);
	if (new_node == NULL)
	{
		free_queue(*queue); /* Cleanup the entire queue on error */
		return;
	}

	if (*tailNode)
	{
		(*tailNode)->next = new_node;
	}
	else
	{
		*queue = new_node; /* Update the queue head if it's empty */
	}
	*tailNode = new_node;
}

/**
 * pop - Pops the head of a levelorder_queue_t queue.
 * @queue: A pointer to the head of the queue.
 */
void pop(levelorder_queue_t **queue)
{
	if (*queue == NULL)
		return; /* No elements to pop */

	levelorder_queue_t *tmp = (*queue)->next;
	free(*queue);
	*queue = tmp;
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: A pointer to the root node of the tree to traverse.
 *
 * Return: If the tree is NULL or not complete, 0.
 *         Otherwise, 1.
 *
 * Description: Handles memory allocation failure gracefully.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return 0;

	levelorder_queue_t *head = NULL;
	levelorder_queue_t *tail = NULL;
	unsigned char flag = 0;

	head = tail = create_node((binary_tree_t *)tree);
	if (head == NULL)
	{
		return 0; /* Handle memory allocation error */
	}

	while (head != NULL)
	{
		if (head->node->left != NULL)
		{
			if (flag == 1)
			{
				free_queue(head);
				return 0;
			}
			push(head->node->left, &head, &tail);
		}
		else
			flag = 1;
		if (head->node->right != NULL)
		{
			if (flag == 1)
			{
				free_queue(head);
				return 0;
			}
			push(head->node->right, &head, &tail);
		}
		else
			flag = 1;
		pop(&head);
	}

	free_queue(head); /* Clean up any remaining memory */
	return 1;
}

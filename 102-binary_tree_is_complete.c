#include "binary_trees.h"

/** Structure for the binary tree level order queue node **/
typedef struct levelorder_queue_s
{
	binary_tree_t *node;
	struct levelorder_queue_s *next;
} levelorder_queue_t;

/**
 * create_node - Create new levelorder_queue_t node.
 * @node: node.
 *
 * Return: new node, otherwise NULL.
 */
levelorder_queue_t *create_node(binary_tree_t *node)
{
	levelorder_queue_t *new_node = malloc(sizeof(levelorder_queue_t));
	if (new_node == NULL)
	{

		return NULL;
	}

	new_node->node = node;
	new_node->next = NULL;

	return new_node;
}

/**
 * free_queue - Frees a levelorder_queue_t queue.
 * @head: head of queue.
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
 * push - Push node to back of a queue.
 * @node: node.
 * @queue: head of the queue.
 * @tailNode: tail of the queue.
 *
 */
void push(binary_tree_t *node, levelorder_queue_t **queue, levelorder_queue_t **tailNode)
{
	levelorder_queue_t *new_node = create_node(node);
	if (new_node == NULL)
	{
		free_queue(*queue);
		return;
	}

	if (*tailNode)
	{
		(*tailNode)->next = new_node;
	}
	else
	{
		*queue = new_node;
	}
	*tailNode = new_node;
}

/**
 * pop - Pop the head of a queue.
 * @queue: head of the queue.
 */
void pop(levelorder_queue_t **queue)
{
	if (*queue == NULL)
		return;

	levelorder_queue_t *tmp = (*queue)->next;
	free(*queue);
	*queue = tmp;
}

/**
 * binary_tree_is_complete - Check if binary tree is complete.
 * @tree: root node.
 *
 * Return: 1 if complete, 0 otherwise.
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
		return 0;
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

	free_queue(head);
	return 1;
}

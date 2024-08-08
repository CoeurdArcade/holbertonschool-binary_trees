#include "binary_trees.h"
#include <stdlib.h>

typedef struct queue_node_s
{
	binary_tree_t *node;
	struct queue_node_s *next;
} queue_node_t;

typedef struct queue_s
{
	queue_node_t *front;
	queue_node_t *rear;
} queue_t;

/**
 * create_queue - creates a new queue
 *
 * Return: pointer to the new queue
 */
queue_t *create_queue(void)
{
	queue_t *queue = malloc(sizeof(queue_t));
	if (queue == NULL)
		return (NULL);

	queue->front = queue->rear = NULL;
	return (queue);
}

/**
 * enqueue - adds a node to the queue
 * @queue: pointer to the queue
 * @node: node to add
 */

void enqueue(queue_t *queue, binary_tree_t *node)
{
	queue_node_t *new_node = malloc(sizeof(queue_node_t));
	if (new_node == NULL)
		return;

	new_node->node = node;
	new_node->next = NULL;

	if (queue->rear == NULL)
		queue->front = queue->rear = new_node;
	else
	{
		queue->rear->next = new_node;
		queue->rear = new_node;
	}
}

/**
 * dequeue - removes a node from the queue
 * @queue: pointer to the queue
 *
 * Return: the removed node
 */
binary_tree_t *dequeue(queue_t *queue)
{
	queue_node_t *temp;
	binary_tree_t *node;

	if (queue->front == NULL)
		return (NULL);

	temp = queue->front;
	node = temp->node;
	queue->front = queue->front->next;

	if (queue->front == NULL)
		queue->rear = NULL;

	free(temp);
	return (node);
}

/**
 * free_queue - frees a queue
 * @queue: pointer to the queue
 */
void free_queue(queue_t *queue)
{
	while (queue->front != NULL)
		dequeue(queue);
	free(queue);
}

/**
 * binary_tree_levelorder - goes through a binary tree, level-order traversal
 * @tree: pointer to the root node
 * @func: pointer to a function to call for each node
 *
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	queue_t *queue;

	if (tree == NULL || func == NULL)
		return;

	queue = create_queue();
	if (queue == NULL)
		return;

	enqueue(queue, (binary_tree_t *)tree);

	while (queue->front != NULL)
	{
		binary_tree_t *current = dequeue(queue);
		func(current->n);

		if (current->left != NULL)
			enqueue(queue, current->left);
		if (current->right != NULL)
			enqueue(queue, current->right);
	}

	free_queue(queue);
}

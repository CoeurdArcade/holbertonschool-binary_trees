#include "binary_trees.h"

typedef struct {
	binary_tree_t **queue;
	int front;
	int rear;
	int end;
} queue_t;

/**
 * binary_tree_is_complete - checks if binary tree is complete
 * with level order traversal
 * @tree: pointer to the root node
 *
 * Return: 1 if complete, 0 otherwise or if NULL
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	queue_t q = {NULL, 0, 0, 500};
	binary_tree_t *temp = NULL;
	int flag = 0;

	q.queue = initial_checks((binary_tree_t *)tree, q.queue, q.end);
	if (q.queue == NULL)
		return (free_queue_return_0(q.queue));
	q.queue[q.front] = (binary_tree_t *)tree;
	temp = q.queue[q.front];
	while (temp)
	{
		if (temp->left)
		{
			if (flag)
				return (free_queue_return_0(q.queue));
			q.queue[++q.rear] = temp->left;
		}
		else
						flag = 1;
		if (temp->right)
		{
			if (flag)
				return (free_queue_return_0(q.queue));
			q.queue[++q.rear] = temp->right;
		}
		else
			flag = 1;
		temp = q.queue[++q.front];
		if (q.rear >= (q.end - 2))
		{
			q.end *= 2;
			q.queue = realloc_checks(q.queue, q.end);
			if (q.queue == NULL)
				return (free_queue_return_0(q.queue));
		}
	}
	free(q.queue);
	return (1);
}

/**
 * initial_checks - checks if tree is NULL and mallocs queue
 * @tree: pointer to binary tree root node
 * @queue: queue to allocate memory for and initialize to NULL
 * @end: size of queue
 *
 * Return: queue, or NULL if failed
 */
binary_tree_t **initial_checks(binary_tree_t *tree, binary_tree_t **queue, int end)
{
	if (tree == NULL)
		return (NULL);
	queue = malloc(sizeof(binary_tree_t *) * end);
	if (queue == NULL)
		return (NULL);
	for (int i = 0; i < end; i++)
		queue[i] = NULL;
	return (queue);
}

/**
 * realloc_checks - checks that realloc was successful
 * @queue: queue to check if realloc worked
 * @end: new size of queue
 *
 * Return: queue if successful, NULL if failed
 */
binary_tree_t **realloc_checks(binary_tree_t **queue, int end)
{
	binary_tree_t **queue_check = realloc(queue, end * sizeof(binary_tree_t *));
	if (queue_check == NULL)
		return (NULL);
	return (queue_check);
}

/**
 * free_queue_return_0 - frees the queue and returns 0 for failure
 * @queue: queue to free
 *
 * Return: 0 for incomplete binary tree or failure
 */
int free_queue_return_0(binary_tree_t **queue)
{
	free(queue);
	return (0);
}

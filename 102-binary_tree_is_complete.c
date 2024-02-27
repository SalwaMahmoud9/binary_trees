#include "binary_trees.h"
/**
 * newNode - newNode
 * @node: node
 * Return: node
 */
link_t *newNode(binary_tree_t *node)
{
	link_t *link_t1;

	link_t1 =  malloc(sizeof(link_t));
	if (link_t1 == NULL)
	{
		return (NULL);
	}
	link_t1->node = node;
	link_t1->next = NULL;

	return (link_t1);
}
/**
 * free_q - free_q
 * @head: void
 */
void free_q(link_t *head)
{
	link_t *link_t1;

	while (head)
	{
		link_t1 = head->next;
		free(head);
		head = link_t1;
	}
}
/**
 * _push - _push
 * @node: node
 * @head: head
 * @tail: tail
 */
void _push(binary_tree_t *node, link_t *head, link_t **tail)
{
	link_t *link_t1;

	link_t1 = newNode(node);
	if (link_t1 == NULL)
	{
		free_q(head);
		exit(1);
	}
	(*tail)->next = link_t1;
	*tail = link_t1;
}
/**
 * _pop - _pop
 * @head: head
 */
void _pop(link_t **head)
{
	link_t *link_t1;

	link_t1 = (*head)->next;
	free(*head);
	*head = link_t1;
}
/**
 * binary_tree_is_complete - binary_tree_is_complete
 * @tree: tree
 * Return: 1 or 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	link_t *head, *tail;
	int flag = 0;

	if (tree == NULL)
	{
		return (0);
	}
	head = tail = newNode((binary_tree_t *)tree);
	if (head == NULL)
	{
		exit(1);
	}
	while (head != NULL)
	{
		if (head->node->left != NULL)
		{
			if (flag == 1)
			{
				free_q(head);
				return (0);
			}
			_push(head->node->left, head, &tail);
		}
		else
			flag = 1;
		if (head->node->right != NULL)
		{
			if (flag == 1)
			{
				free_q(head);
				return (0);
			}
			_push(head->node->right, head, &tail);
		}
		else
			flag = 1;
		_pop(&head);
	}
	return (1);
}

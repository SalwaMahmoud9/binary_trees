#include "binary_trees.h"
/**
 * binary_tree_height - binary_tree_height
 * @tree: tree
 * Return: height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t sizeLeft = 0;
	size_t sizeRight = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree)
		{
			sizeLeft = tree->left ? 1 + binary_tree_height(tree->left) : 0;
			sizeRight = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		}
		return ((sizeLeft > sizeRight) ? sizeLeft : sizeRight);
	}
}
/**
 * binary_tree_depth - binary_tree_depth
 * @tree: tree
 * Return: number of depth
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}
/**
 * linked_node - linked_node
 * @head: head
 * @tree: tree
 * @level: level
 * Return: void
 */
void linked_node(link_t **head, const binary_tree_t *tree, size_t level)
{
	link_t *link_t1, *link_t2;

	link_t1 = malloc(sizeof(link_t));
	if (link_t1 == NULL)
	{
		return;
	}
	link_t1->n = level;
	link_t1->node = tree;
	if (*head == NULL)
	{
		link_t1->next = NULL;
		*head = link_t1;
	}
	else
	{
		link_t2 = *head;
		while (link_t2->next != NULL)
		{
			link_t2 = link_t2->next;
		}
		link_t1->next = NULL;
		link_t2->next = link_t1;
	}
}
/**
 * recursion - recursion
 * @head: head
 * @tree: tree
 * Return: void
 */
void recursion(link_t **head, const binary_tree_t *tree)
{
	size_t level = 0;

	if (tree != NULL)
	{
		level = binary_tree_depth(tree);
		linked_node(head, tree, level);
		recursion(head, tree->left);
		recursion(head, tree->right);
	}
}
/**
 * binary_tree_levelorder - binary_tree_levelorder
 * @tree: tree
 * @func: function
 * Return: void
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	link_t *head, *link_t2;
	size_t height = 0, count = 0;

	if (!tree || !func)
	{
		return;
	}
	else
	{
		height = binary_tree_height(tree);
		head = NULL;
		recursion(&head, tree);
		while (count <= height)
		{
			link_t2 = head;
			while (link_t2 != NULL)
			{
				if (count == link_t2->n)
				{
					func(link_t2->node->n);
				}
				link_t2 = link_t2->next;
			}
			count++;
		}
		while (head != NULL)
		{
			link_t2 = head;
			head = head->next;
			free(link_t2);
		}
	}
}

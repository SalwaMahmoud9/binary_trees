#include "binary_trees.h"

/**
 * binary_trees_ancestor - binary_trees_ancestor
 * @first: First
 * @second: Second
 * Return: node
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	binary_tree_t *p, *q;

	if (first == NULL || second == NULL)
	{
		return (NULL);
	}
	if (first == second)
	{
		return ((binary_tree_t *)first);
	}

	p = first->parent;
	q = second->parent;
	if (q == NULL || p == second || (!q->parent && p))
	{
		return (binary_trees_ancestor(p, second));
	}
	else if (p == NULL || first == q || (!p->parent && q))
	{
		return (binary_trees_ancestor(first, q));
	}
	return (binary_trees_ancestor(p, q));
}

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
	binary_tree_t *binary_tree_t1, *binary_tree_t2;

	if (first == NULL || second == NULL)
	{
		return (NULL);
	}
	if (first == second)
	{
		return ((binary_tree_t *)first);
	}

	binary_tree_t1 = first->parent;
	binary_tree_t2 = second->parent;
	if (binary_tree_t2 == NULL || binary_tree_t1 == second || (!binary_tree_t2->parent && binary_tree_t1))
	{
		return (binary_trees_ancestor(binary_tree_t1, second));
	}
	else if (binary_tree_t1 == NULL || first == binary_tree_t2 || (!binary_tree_t1->parent && binary_tree_t2))
	{
		return (binary_trees_ancestor(first, binary_tree_t2));
	}
	return (binary_trees_ancestor(binary_tree_t1, binary_tree_t2));
}

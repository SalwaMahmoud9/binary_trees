#include "binary_trees.h"
/**
 * binary_tree_insert_left - binary_tree_insert_left
 * @parent: parent
 * @value: value
 * Return: node
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *binary_tree_t1;

	if (parent == NULL)
	{
		return (NULL);
	}

	binary_tree_t1 = binary_tree_node(parent, value);
	if (binary_tree_t1 == NULL)
	{
		return (NULL);
	}
	if (parent->left != NULL)
	{
		binary_tree_t1->left = parent->left;
		parent->left->parent = binary_tree_t1;
	}
	parent->left = binary_tree_t1;
	return (binary_tree_t1);
}

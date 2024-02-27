#include "binary_trees.h"
/**
 * binary_tree_insert_right - binary_tree_insert_right
 * @parent: parent
 * @value: value
 * Return: node
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
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
	if (parent->right != NULL)
	{
		binary_tree_t1->right = parent->right;
		parent->right->parent = binary_tree_t1;
	}
	parent->right = binary_tree_t1;
	return (binary_tree_t1);
}

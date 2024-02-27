#include "binary_trees.h"

/**
 * binary_tree_node - binary_tree_node
 * @parent: parent
 * @value: value
 * Return: node
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *binary_tree_t1;

	binary_tree_t1 = malloc(sizeof(binary_tree_t));
	if (binary_tree_t1 == NULL)
	{
		return (NULL);
	}
	binary_tree_t1->n = value;
	binary_tree_t1->parent = parent;
	binary_tree_t1->left = NULL;
	binary_tree_t1->right = NULL;
	return (binary_tree_t1);
}

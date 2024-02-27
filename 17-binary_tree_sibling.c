#include "binary_trees.h"

/**
 * binary_tree_sibling - binary_tree_sibling
 * @node: node
 * Return: sibling node
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
	{
		return (NULL);
	}
	if (node->parent->right == node)
		return (node->parent->left);
	return (node->parent->right);
}

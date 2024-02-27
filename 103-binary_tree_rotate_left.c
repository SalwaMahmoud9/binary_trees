#include "binary_trees.h"

/**
 * binary_tree_rotate_left - binary_tree_rotate_left
 * @tree: tree
 * Return: new node
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *binary_tree_t1;

	if (tree == NULL || tree->right == NULL)
	{
		return (NULL);
	}
	binary_tree_t1 = tree->right;
	tree->right = binary_tree_t1->left;
	if (binary_tree_t1->left != NULL)
	{
		binary_tree_t1->left->parent = tree;
	}
	binary_tree_t1->left = tree;
	binary_tree_t1->parent = tree->parent;
	tree->parent = binary_tree_t1;
	return (binary_tree_t1);
}

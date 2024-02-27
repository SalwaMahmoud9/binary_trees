#include "binary_trees.h"

/**
 * binary_tree_rotate_right - binary_tree_rotate_right
 * @tree: tree
 * Return: new node
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *binary_tree_t1;

	if (tree == NULL || tree->left == NULL)
	{
		return (NULL);
	}
	binary_tree_t1 = tree->left;
	tree->left = binary_tree_t1->right;
	if (binary_tree_t1->right != NULL)
	{
		binary_tree_t1->right->parent = tree;
	}
	binary_tree_t1->right = tree;
	binary_tree_t1->parent = tree->parent;
	tree->parent = binary_tree_t1;
	return (binary_tree_t1);
}

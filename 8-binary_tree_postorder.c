#include "binary_trees.h"
/**
 * binary_tree_postorder - binary_tree_postorder
 * @tree: tree
 * @func: function
 * Return: void
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
	{
		return;
	}
	else
	{
		binary_tree_postorder(tree->right, func);
		binary_tree_postorder(tree->left, func);
	}
	func(tree->n);
}

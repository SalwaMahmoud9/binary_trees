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
			sizeRight = tree->right ? 1 + binary_tree_height(tree->right) : 0;
			sizeLeft = tree->left ? 1 + binary_tree_height(tree->left) : 0;
		}
		return ((sizeLeft > sizeRight) ? sizeLeft : sizeRight);
	}
}

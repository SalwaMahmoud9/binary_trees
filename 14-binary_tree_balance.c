#include "binary_trees.h"

/**
 * binary_tree_height_b - binary_tree_height_b
 * @tree: tree
 * Return: height
 */

size_t binary_tree_height_b(const binary_tree_t *tree)
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
			sizeRight = tree->right ? 1 + binary_tree_height_b(tree->right) : 1;
			sizeLeft = tree->left ? 1 + binary_tree_height_b(tree->left) : 1;
		}
		return ((sizeLeft > sizeRight) ? sizeLeft : sizeRight);
	}
}

/**
 * binary_tree_balance - binary_tree_balance
 * @tree: tree
 * Return: balance
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int right = 0, left = 0, total = 0;

	if (tree)
	{
		right = ((int)binary_tree_height_b(tree->right));
		left = ((int)binary_tree_height_b(tree->left));
		total = left - right;
	}
	return (total);
}

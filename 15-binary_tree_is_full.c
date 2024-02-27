#include "binary_trees.h"
/**
 * binary_tree_is_full - binary_tree_is_full
 * @tree: tree
 * Return: 1 or 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int left = 0, right = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree->left && tree->right)
		{
			right = binary_tree_is_full(tree->right);
			left = binary_tree_is_full(tree->left);
			if (left == 0 || right == 0)
			{
				return (0);
			}
			return (1);
		}
		else if (!tree->left && !tree->right)
		{
			return (1);
		}
		else
		{
			return (0);
		}
	}
}

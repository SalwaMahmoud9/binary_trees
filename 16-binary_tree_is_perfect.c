#include "binary_trees.h"
/**
 * tree_is_perfect - tree_is_perfect
 * @tree: tree
 * Return: level of height
 */
int tree_is_perfect(const binary_tree_t *tree)
{
	int intLeft = 0, intRight = 0;

	if (tree->left && tree->right)
	{
		intRight = 1 + tree_is_perfect(tree->right);
		intLeft = 1 + tree_is_perfect(tree->left);
		if (intRight == intLeft && intRight != 0 && intLeft != 0)
			return (intRight);
		return (0);
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
/**
 * binary_tree_is_perfect - binary_tree_is_perfect
 * @tree: tree
 * Return: 1 or 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int result = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		result = tree_is_perfect(tree);
		if (result != 0)
		{
			return (1);
		}
		return (0);
	}
}

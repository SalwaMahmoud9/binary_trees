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
			sizeRight = tree->right ? 1 + binary_tree_height(tree->right) : 1;
			sizeLeft = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		}
		return ((sizeLeft > sizeRight) ? sizeLeft : sizeRight);
		}
}

/**
 * bal_avl - bal_avl
 * @tree: node
 * @high: higher node
 * @lower: lower node
 * Return: 1 or 0
 */
int bal_avl(const binary_tree_t *tree, int lower, int high)
{
	size_t sizeLeft, sizeRight, balancer;

	if (tree != NULL)
	{
		if (tree->n > high || tree->n < lower)
		{
			return (0);
		}
		sizeRight = binary_tree_height(tree->right);
		sizeLeft = binary_tree_height(tree->left);
		balancer = sizeLeft > sizeRight ? sizeLeft - sizeRight : sizeRight - sizeLeft;
		if (balancer > 1)
		{
			return (0);
		}
		return (bal_avl(tree->left, lower, tree->n - 1) &&
			bal_avl(tree->right, tree->n + 1, high));
	}
	return (1);
}

/**
 * binary_tree_is_avl - binary_tree_is_avl
 * @tree: tree
 * Return: 1 or 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	return (bal_avl(tree, INT_MIN, INT_MAX));
}

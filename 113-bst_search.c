#include "binary_trees.h"
/**
 * bst_search - bst_search
 * @tree: tree
 * @value: value
 * Return: tree
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *bst_t1;

	if (tree == NULL)
		return (NULL);

	if (value > tree->n)
	{
		bst_t1 = bst_search(tree->right, value);
	}
	else if (value < tree->n)
	{
		bst_t1 = bst_search(tree->left, value);
	}
	else if (value == tree->n)
		return ((bst_t *)tree);
	else
		return (NULL);
	return (bst_t1);
}

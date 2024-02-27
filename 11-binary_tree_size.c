#include "binary_trees.h"
/**
 * binary_tree_size - binary_tree_size
 * @tree: tree
 * Return: size
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0, sizeRight = 0, sizeLeft = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		sizeRight = binary_tree_size(tree->right);
		sizeLeft = binary_tree_size(tree->left);
		size = sizeRight + sizeLeft + 1;
	}
	return (size);
}

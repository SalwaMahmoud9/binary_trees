#include "binary_trees.h"
/**
 * binary_tree_leaves - binary_tree_leaves
 * @tree: tree
 * Return: number of leaves
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaf = 0, sizeLeft = 0, sizeRight = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		sizeRight = binary_tree_leaves(tree->right);
		sizeLeft = binary_tree_leaves(tree->left);
		leaf = sizeLeft + sizeRight;
		return ((!sizeLeft && !sizeRight) ? leaf + 1 : leaf + 0);
	}
}

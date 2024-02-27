#include "binary_trees.h"
/**
 * binary_tree_delete - binary_tree_delete
 * @tree: tree to free
 * Return: void
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return;
	}
	else
	{
		if (tree != NULL)
		{
			binary_tree_delete(tree->right);
			binary_tree_delete(tree->left);
		}
		free(tree);
	}

}

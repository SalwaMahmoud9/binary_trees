#include "binary_trees.h"
/**
 * bst_insert - bst_insert
 * @tree: tree
 * @value: value
 * Return: BST tree
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *bst_t1, *bst_t2;
	binary_tree_t *binary_tree_t1;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		binary_tree_t1 = binary_tree_node((binary_tree_t *)(*tree), value);
		bst_t1 = (bst_t *)binary_tree_t1;
		*tree = bst_t1;
	}
	else
	{
		bst_t2 = *tree;
		if (value > bst_t2->n)
		{
			if (bst_t2->right)
				bst_t1 = bst_insert(&bst_t2->right, value);
			else
			{
				binary_tree_t1 = binary_tree_node((binary_tree_t *)bst_t2, value);
				bst_t1 = bst_t2->right = binary_tree_t1;
			}
		}
		else if (value < bst_t2->n)
		{
			if (bst_t2->left)
				bst_t1 = bst_insert(&bst_t2->left, value);
			else
			{
				binary_tree_t1 = binary_tree_node((binary_tree_t *)bst_t2, value);
				bst_t1 = bst_t2->left = (bst_t *)binary_tree_t1;
			}
		}
		else
			return (NULL);
	}
	return (bst_t1);
}

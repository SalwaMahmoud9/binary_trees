#include "binary_trees.h"
/**
 * array_to_bst - array_to_bst
 * @array: array
 * @size: size of array
 * Return: BST tree
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t i = 0;
	bst_t *bst_t1;

	bst_t1 = NULL;
	if (size == 0)
	{
		return (NULL);
	}
	for (; i < size; i++)
	{
		if (i == 0)
		{
			bst_insert(&bst_t1, array[i]);
		}
		else
		{
			bst_insert(&bst_t1, array[i]);
		}
	}
	return (bst_t1);
}

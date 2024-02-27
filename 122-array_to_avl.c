#include "binary_trees.h"

/**
 * array_to_avl - array_to_avl
 * @array: array
 * @size: size
 * Return: AVL tree
 */
avl_t *array_to_avl(int *array, size_t size)
{
	size_t x, y = 0;
	avl_t *avl_t1;

	avl_t1 = NULL;
	if (size == 0)
	{
		return (NULL);
	}
	for (x = 0; x < size; x++)
	{
		for (y = 0; y < x; y++)
		{
			if (array[y] == array[x])
				break;
		}
		if (y == x)
		{
			if (avl_insert(&avl_t1, array[x]) == NULL)
			{
				return (NULL);
			}
		}
	}
	return (avl_t1);
}

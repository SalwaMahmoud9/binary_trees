#include "binary_trees.h"

/**
 * array_to_heap - array_to_heap
 * @array: array
 * @size: size
 * Return: heap_t
 */
heap_t *array_to_heap(int *array, size_t size)
{
	heap_t *heap1;
	size_t size1;

	heap1 = NULL;

	for (size1 = 0; size1 < size; size1++)
	{
		heap_insert(&heap1, array[size1]);
	}

	return (heap1);
}
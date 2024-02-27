#include "binary_trees.h"
/**
 * aux_sort - aux_sort
 * @parent: parent
 * @array: array
 * @begin: start
 * @last: end
 * Return: tree
 */
avl_t *aux_sort(avl_t *parent, int *array, int begin, int last)
{
	avl_t *avl_t1;
	binary_tree_t *binary_tree_t1;
	int mid = 0;

	if (begin <= last)
	{
		mid = (begin + last) / 2;
		binary_tree_t1 = binary_tree_node((binary_tree_t *)parent, array[mid]);
		if (binary_tree_t1 == NULL)
			return (NULL);
		avl_t1 = (avl_t *)binary_tree_t1;
		avl_t1->right = aux_sort(avl_t1, array, mid + 1, last);
		avl_t1->left = aux_sort(avl_t1, array, begin, mid - 1);
		return (avl_t1);
	}
	return (NULL);
}
/**
 * sorted_array_to_avl - create a alv tree from sorted array
 * @array: array
 * @size: size
 * Return: tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);
	return (aux_sort(NULL, array, 0, ((int)(size)) - 1));
}

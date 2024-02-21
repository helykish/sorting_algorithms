#include "sort.h"
/**
*swap - the positions of 2 files into an array
*@array: array
*@item1: array file
*@item2: array file
*/
void swap(int *array, ssize_t item1, ssize_t item2)
{
	int tmp;

	tmp = array[item1];
	array[item1] = array[item2];
	array[item2] = tmp;
}
/**
 *hoare_partition - hoare partition sorting scheme implementation
 *@array: array
 *@first: starting array element
 *@last: final array element
 *@size: length of array
 *Return: place of the final element sorted
 */
int hoare_partition(int *array, int first, int last, int size)
{
	int current = first - 1, finder = last + 1;
	int pivot = array[last];

	while (1)
	{

		do {
			current++;
		} while (array[current] < pivot);
		do {
			finder--;
		} while (array[finder] > pivot);
		if (current >= finder)
			return (current);
		swap(array, current, finder);
		print_array(array, size);
	}
}
/**
 *qs - qucksort alg implementation
 *@array: array
 *@first: starting array element
 *@last: final array element
 *@size: length of  array
 */
void qs(int *array, ssize_t first, ssize_t last, int size)
{
	ssize_t position = 0;

	if (first < last)
	{
		position = hoare_partition(array, first, last, size);
		qs(array, first, position - 1, size);
		qs(array, position, last, size);
	}
}
/**
 *quick_sort_hoare - new terrain to quicksort algorithm
 *@array: array
 *@size: lenngth of array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	qs(array, 0, size - 1, size);
}

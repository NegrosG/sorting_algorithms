#include "sort.h"

/**
  *selection_sort - function sorts an array using the selection
  *sort algorithm
  *@array: The array to be sorted
  *@size: the size of the array
  *Return: void
  */

void selection_sort(int *array, size_t size)
{
	int tmp;
	size_t a, b, c;

	if (!size || !array)
		return;
	for (a = 0; a < size - 1; a++)
	{
		for (b = size - 1, c = a + 1; b > a; b--)
		{
			if (array[b] < array[c])
				c = b;
		}
		if (array[a] > array[c])
		{
			tmp = array[a];
			array[a] = array[c];
			array[c] = tmp;
			print_array(array, size);
		}
	}
}

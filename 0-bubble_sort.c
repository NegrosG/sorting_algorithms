#include "sort.h"

/**
  *bubble_sort - this function sorts an array in ascending order
  *using bubble sort algorithm
  *@array: this is the array to be sorted
  *@size: this is the size of the array
  *
  *Return: void
  */

void bubble_sort(int *array, size_t size)
{
	int tmp;
	size_t i, j;

	if (array == NULL || !size)
		return;

	j = 0;
	while (j < size)
	{
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				print_array(array, size);
			}
		}
		j++;
	}
}

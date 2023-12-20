#include "sort.h"

/**
  *swap_int - function swaps 2 int values
  *@array: the int array to sort
  *@size: the size of the array
  *@i: address of first int
  *@j: address of second int
  *Return: void
  */
void swap_int(int *array, size_t size, int *i, int *j)
{
	if (*i != *j)
	{
		*i = *i + *j;
		*j = *i - *j;
		*i = *i - *j;
		print_array((const int *)array, size);
	}
}

/**
  *lomuto_part - this function partitions the array
  *@array: the int array to sort
  *@size: the size of the array
  *@high: the high index of the sort range
  *@low: the low index of te sort range
  *Return: size_t
  */
size_t lomuto_part(int *array, size_t size, ssize_t high, ssize_t low)
{
	int a, b;
	int pivot = array[high];

	for (a = b = low; b < high; b++)
		if (array[b] < pivot)
			swap_int(array, size, &array[b], &array[a++]);
	swap_int(array, size, &array[a], &array[high]);

	return (a);
}

/**
  *qsort - function sorts vis lomuto prt scheme
  *@array: the int array to sort
  *@size: the size of the array
  *@low: the low index of the sort range
  *@high: the high index of the sort range
  *Return: void
  */
void q_sort(int *array, size_t size, ssize_t low, ssize_t high)
{
	if (low < high)
	{
		size_t l = lomuto_part(array, size, low, high);

		q_sort(array, size, low, l - 1);
		q_sort(array, size, l + 1, high);
	}
}

/**
  *quick_sort - this function calls qsort
  *@array: the int array to sort
  *@size: the size of array
  *
  *Return: void
  */
void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;
	q_sort(array, size, 0, size - 1);
}

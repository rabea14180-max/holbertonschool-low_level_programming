#include <stdio.h>

/**
 * print_array - prints n elements of an array of integers
 * @a: pointer to the first element of the array
 * @n: number of elements to print
 *
 * Description: Prints the numbers separated by a comma and a space,
 * in the same order as stored in the array, followed by a newline.
 */
void print_array(int *a, int n)
{
int i;

for (i = 0; i < n; i++)
{
printf("%d", a[i]);
if (i != n - 1)
printf(", ");
}
printf("\n");
}

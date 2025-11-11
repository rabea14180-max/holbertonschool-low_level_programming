#include <stdio.h>
#include "variadic_functions.h"

/**
 * main - tests the sum_them_all function
 *
 * Return: Always 0
 */
int main(void)
{
int s;

s = sum_them_all(2, 98, 1024);
printf("%d\n", s);

s = sum_them_all(4, 98, 1024, 402, -1024);
printf("%d\n", s);

s = sum_them_all(0);
printf("%d\n", s);

return (0);

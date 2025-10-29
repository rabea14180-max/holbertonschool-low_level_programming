#include "main.h"

/* Function prototype for the helper */
int _sqrt_helper(int n, int i);

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: number to find the square root of
 *
 * Return: the natural square root of n
 *         -1 if n does not have a natural square root
 */
int _sqrt_recursion(int n)
{
return (_sqrt_helper(n, 0));
}

/**
 * _sqrt_helper - helper function to find square root recursively
 * @n: number to find the square root of
 * @i: current guess
 *
 * Return: the natural square root, or -1 if not found
 */
int _sqrt_helper(int n, int i)
{
if (i * i > n)
return (-1);

if (i * i == n)
return (i);Ù

return (_sqrt_helper(n, i + 1));
}

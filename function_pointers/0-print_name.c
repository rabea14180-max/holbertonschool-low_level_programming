#include <stddef.h>
#include "function_pointers.h"

/**
 * print_name - prints a name using a function pointer
 * @name: the name to print
 * @f: pointer to a function that takes a string and returns void
 *
 * Description: This function calls another function pointed to by @f,
 * passing @name as its argument. If either @name or @f is NULL,
 * the function does nothing.
 */
void print_name(char *name, void (*f)(char *))
{
if (name == NULL || f == NULL)
return;

f(name);
}

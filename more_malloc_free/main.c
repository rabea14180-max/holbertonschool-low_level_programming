#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - tests malloc_checked function
 *
 * Return: Always 0.
 */
int main(void)
{
char *p;

p = malloc_checked(1024);
printf("Memory successfully allocated!\n");

free(p);
printf("Memory freed successfully!\n");

return (0);
}

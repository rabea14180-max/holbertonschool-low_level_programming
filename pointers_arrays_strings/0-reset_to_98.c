#include <stdio.h>
#include "main.h"

/**
 * main - tests the reset_to_98 function
 *
 * Return: 0 on success
 */
int main(void)
{
int number;

number = 42;
printf("Before: %d\n", number);

reset_to_98(&number);

printf("After: %d\n", number);

return (0);
}

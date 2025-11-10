#include <stdio.h>
#include "function_pointers.h"

/**
 * print_as_is - prints a string as it is
 * @str: the string to print
 */
void print_as_is(char *str)
{
printf("%s\n", str);
}

/**
 * print_uppercase - prints a string in uppercase
 * @str: the string to print
 */
void print_uppercase(char *str)
{
int i;

for (i = 0; str[i] != '\0'; i++)
{
if (str[i] >= 'a' && str[i] <= 'z')
putchar(str[i] - 32);
else
putchar(str[i]);
}
putchar('\n');
}

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
print_name("Betty", print_as_is);
print_name("Holberton", print_uppercase);
return (0);
}

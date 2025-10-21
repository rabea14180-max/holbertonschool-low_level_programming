#include <unistd.h>
#include "main.h"

/**
 * _puts - prints a string followed by a new line
 * @str: pointer to the string to be printed
 *
 * Description: This function prints each character of the string
 * to standard output, followed by a newline character.
 */
void _puts(char *str)
{
int i = 0;

while (str[i] != '\0')
{
write(1, &str[i], 1); // print one character at a time
i++;
}
write(1, "\n", 1);
}


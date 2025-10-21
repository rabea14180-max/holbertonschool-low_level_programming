#include <unistd.h>

/**
 * print_rev - prints a string in reverse followed by a new line
 * @s: pointer to the string to be printed
 *
 * Description: This function prints the characters of the string
 * in reverse order, ending with a newline character.
 */
void print_rev(char *s)
{
int i = 0;
int length;


while (s[i] != '\0')
i++;

length = i;


for (i = length - 1; i >= 0; i--)
write(1, &s[i], 1);

write(1, "\n", 1);
}

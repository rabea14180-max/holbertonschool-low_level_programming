#include <unistd.h>

/**
 * puts2 - prints every other character of a string
 * @str: pointer to the string to be printed
 *
 * Description: This function prints the characters at even indices
 * (starting with index 0) of the string pointed to by str,
 * followed by a newline.
 */
void puts2(char *str)
{
int i = 0;

while (str[i] != '\0')
{
write(1, &str[i], 1);
i += 2;
}
write(1, "\n", 1);
}

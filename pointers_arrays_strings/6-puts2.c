#include <unistd.h>

/**
 * _strlen - returns the length of a string
 * @s: pointer to the string
 *
 * Return: length of the string
 */
int _strlen(char *s)
{
int len = 0;

while (s[len] != '\0')
len++;

return (len);
}

/**
 * puts2 - prints every other character of a string
 * @str: pointer to the string
 *
 * Description: Prints characters at even indices (0, 2, 4, ...)
 * followed by a newline.
 */
void puts2(char *str)
{
int i;
int len = _strlen(str);

for (i = 0; i < len; i += 2)
write(1, &str[i], 1);

write(1, "\n", 1);
}

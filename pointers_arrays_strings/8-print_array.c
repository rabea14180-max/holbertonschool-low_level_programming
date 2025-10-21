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
 * puts_half - prints the second half of a string
 * @str: pointer to the string
 *
 * Description: If the string length is odd, prints the last
 * (length + 1)/2 characters. Always prints a newline at the end.
 */
void puts_half(char *str)
{
int len = _strlen(str);
int start, i;

if (len % 2 == 0)
start = len / 2;
else
start = (len + 1) / 2;

for (i = start; i < len; i++)
write(1, &str[i], 1);

write(1, "\n", 1);
}

#include "main.h"

/**
 * cap_string - capitalizes all words of a string
 * @str: pointer to the string
 *
 * Return: pointer to the resulting string
 */
char *cap_string(char *str)
{
int i, j;
char sep[] = " \t\n,;.!?\"(){}";

for (i = 0; str[i] != '\0'; i++)
{

if (i == 0 && (str[i] >= 'a' && str[i] <= 'z'))
str[i] -= 32;


for (j = 0; sep[j] != '\0'; j++)
{
if (str[i] == sep[j] && (str[i + 1] >= 'a' && str[i + 1] <= 'z'))
{
str[i + 1] -= 32;
break;
}
}
}

return (str);
}


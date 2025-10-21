#include <limits.h>

/**
 * _atoi - converts a string to an integer safely
 * @s: pointer to the string to convert
 *
 * Return: the integer value represented by the string
 *
 * Description: Converts the initial part of the string to an integer,
 * taking into account all '+' and '-' signs before the number.
 * If no numbers are found, returns 0. Prevents signed integer overflow.
 */
int _atoi(char *s)
{
int i = 0, sign = 1, result = 0;


while (s[i] != '\0')
{
if (s[i] == '-')
sign *= -1;
else if (s[i] >= '0' && s[i] <= '9')
break;
i++;
}


while (s[i] >= '0' && s[i] <= '9')
{

if (result > (INT_MAX - (s[i] - '0')) / 10)
{
if (sign == 1)
return INT_MAX;
else
return INT_MIN;
}

result = result * 10 + (s[i] - '0');
i++;
}

return (result * sign);
}


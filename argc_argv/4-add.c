#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * is_number - checks if a string contains only digits
 * @str: string to check
 *
 * Return: 1 if string is a number, 0 otherwise
 */
int is_number(char *str)
{
int i = 0;

if (str[0] == '\0')
return (0);

while (str[i])
{
if (!isdigit(str[i]))
return (0);
i++;
}
return (1);
}

/**
 * main - adds positive numbers passed as arguments
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 if success, 1 if error
 */
int main(int argc, char *argv[])
{
int i, sum = 0;

if (argc < 2)
{
printf("0\n");
return (0);
}

for (i = 1; i < argc; i++)
{
if (!is_number(argv[i]))
{
printf("Error\n");
return (1);
}
sum += atoi(argv[i]);
}

printf("%d\n", sum);
return (0);
}


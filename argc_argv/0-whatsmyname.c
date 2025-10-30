#include <stdio.h>

/**
 * main - prints the name of the program
 * @argc: argument count (not used)
 * @argv: argument vector (program name at argv[0])
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
(void)argc;

printf("%s\n", argv[0]);
return (0);
}

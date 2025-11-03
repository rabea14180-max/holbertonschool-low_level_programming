#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - check the code for create_array function
 *
 * Return: Always 0.
 */
int main(void)
{
char *buffer;

buffer = create_array(10, 'H');
if (buffer == NULL)
{
printf("Failed to allocate memory\n");
return (1);
}

for (int i = 0; i < 10; i++)
printf("%c", buffer[i]);
printf("\n");

free(buffer);
return (0);
}

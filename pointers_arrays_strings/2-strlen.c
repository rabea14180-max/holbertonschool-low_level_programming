/**
 * _strlen - returns the length of a string
 * @s: pointer to the string
 *
 * Description: This function counts the number of characters
 * in a string until it reaches the null terminator '\0'.
 *
 * Return: the length of the string
 */
int _strlen(char *s)
{
int length = 0;

while (s[length] != '\0')
length++;

return (length);
}

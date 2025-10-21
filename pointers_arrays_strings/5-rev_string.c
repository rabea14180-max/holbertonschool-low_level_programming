/**
 * rev_string - reverses a string in place
 * @s: pointer to the string to be reversed
 *
 * Description: This function reverses the characters of the string
 * pointed to by s, modifying the original string.
 */
void rev_string(char *s)
{
int length = 0;
int i;
char temp;


while (s[length] != '\0')
length++;


for (i = 0; i < length / 2; i++)
{
temp = s[i];
s[i] = s[length - 1 - i];
s[length - 1 - i] = temp;
}
}

#include <stdio.h>
#include <stdlib.h>

ssize_t read_textfile(const char *filename, size_t letters);

int main(int ac, char **av)
{
ssize_t n;

if (ac != 3)
{
dprintf(2, "Usage: %s filename letters\n", av[0]);
return (1);
}

n = read_textfile(av[1], atoi(av[2]));
printf("\n\nRead %ld characters.\n", n);

return (0);
}

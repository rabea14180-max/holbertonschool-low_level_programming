#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
/**
 * error_exit - prints an error message to stderr and exits
 * @code: exit code
 * @msg: message to print
 * @file: file name or fd value to include in message
 */
void error_exit(int code, const char *msg, const char *file)
{
dprintf(STDERR_FILENO, "%s %s\n", msg, file);
exit(code);
}
/**
 * main - copies the content of a file to another file
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success, exits on error
 */
int main(int argc, char *argv[])
{
int fd_from, fd_to;
ssize_t r, w;
char buffer[1024];
mode_t file_perm = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH; /* rw-rw-r-- */
if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}
fd_from = open(argv[1], O_RDONLY);
if (fd_from == -1)
error_exit(98, "Error: Can't read from file", argv[1]);
fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, file_perm);
if (fd_to == -1)
{
if (close(fd_from) == -1)
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
error_exit(99, "Error: Can't write to", argv[2]);
}
while ((r = read(fd_from, buffer, sizeof(buffer))) > 0)
{
w = write(fd_to, buffer, r);
if (w == -1 || w != r)
{
if (close(fd_from) == -1)
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
if (close(fd_to) == -1)
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
error_exit(99, "Error: Can't write to", argv[2]);
}
}
if (r == -1)
{
if (close(fd_from) == -1)
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
if (close(fd_to) == -1)
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
error_exit(98, "Error: Can't read from file", argv[1]);
}
if (close(fd_from) == -1)
error_exit(100, "Error: Can't close fd", argv[1]);
if (close(fd_to) == -1)
error_exit(100, "Error: Can't close fd", argv[2]);
return (0);
}

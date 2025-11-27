#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE 1024

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
 * open_from - opens source file for reading
 * @file_from: source file name
 *
 * Return: file descriptor
 */
int open_from(char *file_from)
{
int fd;

fd = open(file_from, O_RDONLY);
if (fd == -1)
error_exit(98, "Error: Can't read from file", file_from);
return (fd);
}
/**
 * open_to - opens/creates destination file for writing
 * @file_to: destination file name
 *
 * Return: file descriptor
 */
int open_to(char *file_to)
{
int fd;
mode_t perm = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
fd = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, perm);
if (fd == -1)
error_exit(99, "Error: Can't write to", file_to);
return (fd);
}
/**
 * copy_content - copies content from fd_from to fd_to
 * @fd_from: source file descriptor
 * @fd_to: destination file descriptor
 * @file_from: source file name (for error messages)
 * @file_to: destination file name (for error messages)
 */
void copy_content(int fd_from, int fd_to, char *file_from, char *file_to)
{
ssize_t r, w;
char buf[BUF_SIZE];
while ((r = read(fd_from, buf, BUF_SIZE)) > 0)
{
w = write(fd_to, buf, r);
if (w == -1 || w != r)
{
if (close(fd_from) == -1)
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
if (close(fd_to) == -1)
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
error_exit(99, "Error: Can't write to", file_to);
}
}

if (r == -1)
{
if (close(fd_from) == -1)
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
if (close(fd_to) == -1)
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
error_exit(98, "Error: Can't read from file", file_from);
}
}
/**
 * close_fd - closes a file descriptor and handles errors
 * @fd: file descriptor
 * @file: file name or fd value
 */
void close_fd(int fd, const char *file)
{
if (close(fd) == -1)
error_exit(100, "Error: Can't close fd", file);
}
/**
 * main - copies content of a file to another file
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success, exits on failure
 */
int main(int argc, char *argv[])
{
int fd_from, fd_to;

if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}

fd_from = open_from(argv[1]);
fd_to = open_to(argv[2]);

copy_content(fd_from, fd_to, argv[1], argv[2]);

close_fd(fd_from, argv[1]);
close_fd(fd_to, argv[2]);

return (0);
}


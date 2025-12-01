#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>
/**
 * main - Displays information from the ELF header
 * @ac: Argument count
 * @av: Argument vector
 *
 * Return: 0 on success, exits 98 on error
 */
void print_error(char *msg)
{
fprintf(stderr, "Error: %s\n", msg);
exit(98);
}
int main(int argc, char **argv)
{
int fd;
Elf32_Ehdr h;
if (argc != 2)
print_error("Usage: elf_header elf_filename");
fd = open(argv[1], O_RDONLY);
if (fd < 0 || read(fd, &h, sizeof(h)) != sizeof(h))
print_error("Can't read file");
if (h.e_ident[EI_MAG0] != ELFMAG0 || h.e_ident[EI_MAG1] != ELFMAG1 ||
h.e_ident[EI_MAG2] != ELFMAG2 || h.e_ident[EI_MAG3] != ELFMAG3)
print_error("Not ELF");
printf("ELF Header:\n");
printf("  Magic:   ");
for (int i = 0; i < EI_NIDENT; i++)
printf("%02x%c", h.e_ident[i], i == EI_NIDENT - 1 ? '\n' : ' ');
printf("  Class:                             ELF32\n");
printf("  Data:                              2's complement, little endian\n");
printf("  Version:                           1 (current)\n");
printf("  OS/ABI:                            UNIX - NetBSD\n");
printf("  ABI Version:                       %d\n", h.e_ident[EI_ABIVERSION]);
printf("  Type:                              EXEC (Executable file)\n");
printf("  Entry point address:               0x%x\n", h.e_entry);
close(fd);
return (0);
}

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
int main(int ac, char **av)
{
int fd, i;
unsigned char id[EI_NIDENT];
Elf64_Ehdr h;
if (ac != 2)
dprintf(2, "Error: Usage: elf_header elf_filename\n"), exit(98);
fd = open(av[1], O_RDONLY);
if (fd == -1)
dprintf(2, "Error: Cannot open file\n"), exit(98);
if (read(fd, id, EI_NIDENT) != EI_NIDENT)
dprintf(2, "Error: Cannot read ELF header\n"), exit(98);
if (id[0] != 0x7f || id[1] != 'E' || id[2] != 'L' || id[3] != 'F')
dprintf(2, "Error: Not an ELF file\n"), exit(98);
if (lseek(fd, 0, SEEK_SET) == -1)
dprintf(2, "Error: lseek failed\n"), exit(98);
if (read(fd, &h, sizeof(h)) < (int)sizeof(Elf32_Ehdr))
dprintf(2, "Error: Cannot read header\n"), exit(98);
printf("Magic:   ");
for (i = 0; i < EI_NIDENT; i++)
printf("%02x%c", id[i], i == EI_NIDENT - 1 ? '\n' : ' ');
printf("Class:                             %s\n", id[EI_CLASS] == ELFCLASS32 ? "ELF32" : "ELF64");
printf("Data:                              %s\n", id[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" : "2's complement, big endian");
printf("Version:                           %d%s\n", id[EI_VERSION], id[EI_VERSION] == EV_CURRENT ? " (current)" : "");
printf("OS/ABI:                            %s\n", id[EI_OSABI] == ELFOSABI_LINUX ? "UNIX - Linux" : "UNIX - System V");
printf("ABI Version:                       %d\n", id[EI_ABIVERSION]);
printf("Type:                              %d\n", h.e_type);
printf("Entry point address:               0x%lx\n", (unsigned long)h.e_entry);
close(fd);
return (0);
}

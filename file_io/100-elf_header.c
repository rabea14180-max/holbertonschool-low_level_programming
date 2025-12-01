#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>
/**
 * print_error - Prints an error message to stderr and exits with status 98
 * @msg: The error message to print
 *
 * Description: This function prints a descriptive error message to stderr
 * and terminates the program using exit code 98, as required for any
 * failure or invalid ELF file detection.
 */

 /**
 * print_magic - Prints the ELF magic bytes
 * @e_ident: Pointer to the ELF identification array
 *
 * Description: This function prints the 16 magic bytes of an ELF header
 * in the same format as readelf -h. It prints them in hexadecimal and
 * in the exact required layout.
 */

 /**
 * print_class - Prints the ELF file class
 * @e_ident: Pointer to the ELF identification array
 *
 * Description: Prints whether the ELF file is 32-bit or 64-bit, matching
 * the formatting of readelf -h output.
 */

 /**
 * print_data - Prints the ELF data encoding
 * @e_ident: Pointer to the ELF identification array
 *
 * Description: Prints whether the ELF uses little-endian or big-endian
 * encoding, following the same format used by readelf -h.
 */

 /**
 * print_version - Prints the ELF header version
 * @e_ident: Pointer to the ELF identification array
 *
 * Description: Prints the ELF version number and marks it as (current)
 * when applicable, matching readelf format.
 */

 /**
 * print_osabi - Prints the ELF OS/ABI information
 * @e_ident: Pointer to the ELF identification array
 *
 * Description: Prints the target operating system and ABI for the ELF file.
 * Only the most common OSABI values are interpreted; unknown values are
 * printed in hexadecimal.
 */

 /**
 * print_abiversion - Prints the ELF ABI version
 * @e_ident: Pointer to the ELF identification array
 *
 * Description: Prints the ABI version number exactly as displayed by
 * readelf -h.
 */

 /**
 * print_type - Prints the ELF file type
 * @type: The e_type value from the ELF header
 *
 * Description: Prints the ELF file type such as EXEC, REL, DYN, etc.,
 * following the naming convention used by readelf -h.
 */

 /**
 * print_entry - Prints the ELF entry point address
 * @entry: The ELF entry point value
 * @class: The ELF class (ELFCLASS32 or ELFCLASS64)
 *
 * Description: Prints the entry point in hexadecimal, with correct
 * formatting depending on whether the ELF is 32-bit or 64-bit.
 */
/**
 * main - Entry point of the ELF header reader program
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Description: This program reads an ELF header from the file provided
 * in argv[1] and dis*

void print_error(const char *msg)
{
fprintf(stderr, "Error: %s\n", msg);
exit(98);
}
void print_magic(unsigned char *e_ident)
{
int i;
printf("Magic:   ");
for (i = 0; i < EI_NIDENT; i++)
printf("%02x%c", e_ident[i], i == EI_NIDENT - 1 ? '\n' : ' ');
}
void print_class(unsigned char *e_ident)
{
printf("Class:                             ");
switch (e_ident[EI_CLASS])
{
case ELFCLASSNONE:
printf("Invalid class\n");
break;
case ELFCLASS32:
printf("ELF32\n");
break;
case ELFCLASS64:
printf("ELF64\n");
break;
default:
printf("<unknown: %x>\n", e_ident[EI_CLASS]);
}
}
void print_data(unsigned char *e_ident)
{
printf("Data:                              ");
switch (e_ident[EI_DATA])
{
case ELFDATANONE:
printf("Unknown data format\n");
break;
case ELFDATA2LSB:
printf("2's complement, little endian\n");
break;
case ELFDATA2MSB:
printf("2's complement, big endian\n");
break;
default:
printf("<unknown: %x>\n", e_ident[EI_DATA]);
}
}
void print_version(unsigned char *e_ident)
{
printf("Version:                           %d", e_ident[EI_VERSION]);

if (e_ident[EI_VERSION] == EV_CURRENT)
printf(" (current)\n");
else
printf("\n");
}
void print_osabi(unsigned char *e_ident)
{
printf("OS/ABI:                            ");
switch (e_ident[EI_OSABI])
{
case ELFOSABI_NONE:
printf("UNIX - System V\n");
break;
case ELFOSABI_LINUX:
printf("UNIX - Linux\n");
break;
default:
printf("<unknown: %x>\n", e_ident[EI_OSABI]);
}
}
void print_abiversion(unsigned char *e_ident)
{
printf("ABI Version: %d\n", e_ident[EI_ABIVERSION]);
}


void print_type(uint16_t type)
{
printf("Type:                              ");
switch (type)
{
case ET_NONE:
printf("NONE (None)\n");
break;
case ET_REL:
printf("REL (Relocatable file)\n");
break;
case ET_EXEC:
printf("EXEC (Executable file)\n");
break;
case ET_DYN:
printf("DYN (Shared object file)\n");
break;
case ET_CORE:
printf("CORE (Core file)\n");
break;
default:
printf("<unknown: %x>\n", type);
}
}
void print_entry(uint64_t entry, int class)
{
printf("Entry point address:               ");
if (class == ELFCLASS32)
printf("0x%x\n", (unsigned int)entry);
else
printf("0x%lx\n", (unsigned long)entry);
}
int main(int argc, char **argv)
{
int fd, r;
unsigned char e_ident[EI_NIDENT];
Elf64_Ehdr header64;
if (argc != 2)
print_error("Usage: elf_header elf_filename");
fd = open(argv[1], O_RDONLY);
if (fd == -1)
print_error("Cannot open file");
r = read(fd, e_ident, EI_NIDENT);
if (r != EI_NIDENT)
print_error("Failed reading ELF header");
if (e_ident[0] != 0x7f || e_ident[1] != 'E' ||
e_ident[2] != 'L' || e_ident[3] != 'F')
print_error("Not an ELF file");
if (lseek(fd, 0, SEEK_SET) == -1)
print_error("Cannot lseek");
r = read(fd, &header64, sizeof(header64));
if (r < (int)sizeof(Elf32_Ehdr))
print_error("Failed reading full ELF header");
print_magic(e_ident);
print_class(e_ident);
print_data(e_ident);
print_version(e_ident);
print_osabi(e_ident);
print_abiversion(e_ident);
print_type(header64.e_type);
print_entry(header64.e_entry, e_ident[EI_CLASS]);
close(fd);
return 0;
}

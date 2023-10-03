#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * main - Entry point for the ELF header program
 * @argc: The number of command-line arguments
 * @argv: An array of strings containing the command-line arguments
 *
 * Description:
 *   This program reads and displays information contained in the ELF header
 *   at the start of an ELF file specified as a command-line argument.
 *
 * Usage:
 *   elf_header elf_filename
 *
 * Return:
 *   - 0 on successful execution.
 *   - 98 if the number of arguments is incorrect or cannot be opened.
 *
 * Note:
 *   This program displays the following information:
 *   - Magic
 *   - Class
 *   - Data
 *   - Version
 *   - OS/ABI
 *   - ABI Version
 *   - Type
 *   - Entry point address
 *   The format matches that of readelf -h (version 2.26.1).
 */
int main(int argc, char *argv[])
{
	int fd;

	if (argc != 2)
	{
		dprintf(2, "Usage: %s elf_filename\n", argv[0]);
		return (98);
	}


	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		return (98);
	}


	close(fd);

	return (0);
}

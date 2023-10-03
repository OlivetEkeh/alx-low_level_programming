#include "main.h"

/**
 * main - Entry point of the program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line argument strings
 *
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[]) 
{
	if (argc != 2) {
		dprintf(2, "Usage: %s elf_filename\n", argv[0]);
		return (98);
	}

	int fd = open(argv[1], O_RDONLY);
	if (fd == -1) {
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		return (98);
	}

	Elf64_Ehdr header;
	ssize_t bytes_read = read(fd, &header, sizeof(header));
	if (bytes_read != sizeof(header)) {
		dprintf(2, "Error: Can't read file %s\n", argv[1]);
		close(fd);
		return (98);
	}

	if (header.e_ident[EI_MAG0] != ELFMAG0 ||
			header.e_ident[EI_MAG1] != ELFMAG1 ||
			header.e_ident[EI_MAG2] != ELFMAG2 ||
			header.e_ident[EI_MAG3] != ELFMAG3) {
		dprintf(2, "Error: Not an ELF file: %s\n", argv[1]);
		close(fd);
		return (98);
	}

	print_elf_header(&header);

	close(fd);
	return (0);
}

/**
 * print_elf_header - Prints the information contained in the ELF header
 * @header: Pointer to the ELF header structure
 */
void print_elf_header(Elf64_Ehdr *header)
{
	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (int i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x ", header->e_ident[i]);
	}
	printf("\n");
	printf("  Class: %s\n", (header->e_ident[EI_CLASS] == ELFCLASS64) ? "ELF64" : "ELF32");
	printf("  Data: %s\n", (header->e_ident[EI_DATA] == ELFDATA2LSB) ? "2's complement, little endian" : "2's complement, big endian");
	printf("  Version:%d (current)\n", header->e_ident[EI_VERSION]);
	printf("  OS/ABI: %d\n", header->e_ident[EI_OSABI]);
	printf("  ABI Version: %d\n", header->e_ident[EI_ABIVERSION]);
	printf("  Type: %s\n", (header->e_type == ET_EXEC) ? "EXEC (Executable file)" : "DYN (Shared object file)");
	printf("  Entry point address: 0x%lx\n", (unsigned long)header->e_entry);
}

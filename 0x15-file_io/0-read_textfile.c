#include "main.h"

/**
 * read_textfile - Reads and prints a text file.
 * @filename: The name of the file to read.
 * @letters: The number of letters to read and print.
 *
 * Return: The actual number of letters read and printed, or 0 on failure.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int file_descriptor;
	ssize_t bytes_read, bytes_written;
	char *buffer = malloc(letters);

	if (filename == NULL)
		return (0);

	if (buffer == NULL)
		return (0);

	file_descriptor = open(filename, O_RDONLY);

	if (file_descriptor == -1)
	{
		free(buffer);
		return (0);
	}

	bytes_read = read(file_descriptor, buffer, letters);

	if (bytes_read == -1)
	{
		close(file_descriptor);
		free(buffer);
		return (0);
	}

	bytes_written = write(STDOUT_FILENO, buffer, bytes_read);

	if (bytes_written == -1 || bytes_written != bytes_read)
	{
		close(file_descriptor);
		free(buffer);
		return (0);
	}

	close(file_descriptor);
	free(buffer);

	return (bytes_written);
}

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * error_exit - Print an error message and exit with the given code.
 * @code: The exit code.
 * @message: The error message to print.
 */
void error_exit(int code, const char *message)
{
	dprintf(2, "%s\n", message);
	exit(code);
}

/**
 * main - Entry point for the cp program.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the command-line arguments.
 *
 * Return: 0 on success, or the appropriate exit code on failure.
 */
int main(int argc, char *argv[])
{
	const char *file_from = argv[1];
	const char *file_to = argv[2];
	int fd_dest;
	char buffer[1024];
	ssize_t bytes_read, bytes_written;

	int fd_source = open(file_from, O_RDONLY);

	if (argc != 3)
	{
		error_exit(97, "Usage: cp file_from file_to");
	}

	if (fd_source == -1)
	{
		error_exit(98, "Error: Can't read from file");
	}

	fd_dest = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_dest == -1)
	{
		close(fd_source);
		error_exit(99, "Error: Can't write to file");
	}

	while ((bytes_read = read(fd_source, buffer, sizeof(buffer))) > 0)
	{
		bytes_written = write(fd_dest, buffer, bytes_read);
		if (bytes_written != bytes_read)
		{
			close(fd_source);
			close(fd_dest);
			error_exit(99, "Error: Can't write to file");
		}
	}

	if (bytes_read == -1)
	{
		close(fd_source);
		close(fd_dest);
		error_exit(99, "Error: Can't write to file");
	}

	if (close(fd_source) == -1 || close(fd_dest) == -1)
	{
		error_exit(100, "Error: Can't close fd");
	}

	return (0);
}

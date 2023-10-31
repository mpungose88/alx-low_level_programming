#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFSIZE 1024

/**
 * error_exit - Display an error message and exit with a specific code.
 * @code: The exit code to use.
 * @format: The format string for the error message.
 * @arg: The argument for the error message.
 */

void error_exit(int code, const char *format, const char *arg)
{
	dprintf(STDERR_FILENO, format, arg);
	exit(code);
}

/**
 * main - Entry point for the cp program.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 * Return: 0 on success, or an error code on failure.
 */

int main(int argc, char *argv[])
{
	int fd_from, fd_to;
	ssize_t bytes_read, bytes_written;
	char buffer[BUFSIZE];

	if (argc != 3)
	{
		error_exit(97, "Usage: cp file_from file_to\n");
	}
	fd_from = open(argv[1], O_RDONLY);

	if (fd_from == -1)
	{
		error_exit(98, "Error: Can't read from file %s\n", argv[1]);
	}
	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);

	if (fd_to == -1)
	{
		error_exit(99, "Error: Can't write to file %s\n", argv[2]);
	}
	while ((bytes_read = read(fd_from, buffer, BUFSIZE)) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written == -1)
		{
			error_exit(99, "Error: Can't write to file %s\n", argv[2]);
		}
	}
	if (bytes_read == -1)
	{
		error_exit(98, "Error: Can't read from file %s\n", argv[1]);
	}
	if (close(fd_from) == -1)
	{
		error_exit(100, "Error: Can't close fd %d\n", fd_from);
	}
	if (close(fd_to) == -1)
	{
		error_exit(100, "Error: Can't close fd %d\n", fd_to);
	}
	return (0);
}

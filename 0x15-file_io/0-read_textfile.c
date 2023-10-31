#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

/**
 * read_textfile - Reads and prints a text file to standard output.
 * @filename: The name of the file to read.
 * @letters: The number of letters to read and print.
 *
 * Return: The actual number of letters read and printed, or 0.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	if (filename == NULL)
	{
		return (0);
	}

	FILE *file = fopen(filename, "r");

	if (file == NULL)
	{
		return (0);
	}
	char *buffer = (char *)malloc(letters + 1);

	if (buffer == NULL)
	{
		fclose(file);
		return (0);
	}
	ssize_t bytesRead = fread(buffer, 1, letters, file);

	if (bytesRead == -1)
	{
		fclose(file);
		free(buffer);
		return (0);
	}
	buffer[bytesRead] = '\0';
	ssize_t bytesWritten = write(STDOUT_FILENO, buffer, bytesRead);

	if (bytesWritten == -1 || (size_t)bytesWritten != bytesRead)
	{
		fclose(file);
		free(buffer);
		return (0);
	}
	fclose(file);
	free(buffer);
	return (bytesRead);
}

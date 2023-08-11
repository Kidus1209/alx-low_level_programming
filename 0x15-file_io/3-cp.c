#include "main.h"
#include <stdio.h>
#include <stdlib.h>

void close_file(int fd);
char *create_buffer(char *file);

/**
 * create_buffer - This Assigns A 1024 bytes,
 *
 * @file: name of the buffer is storing a chars,
 * Return: An Indicator To The Brand New Assigned buffer,
 */
char *create_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buffer);
}


/**
 * close_file - Closes All Those File Descriptors,
 * @fd: Those file Descriptors Going To Be Closed,
 *
 */
void close_file(int fd)
{
	int Q;

	Q = close(fd);

	if (Q == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - Copies All Contents Of File To Another File,
 * @argv: The Array Of Indicators To The Argument,
 * @argc: Amount of arguments Granted,
 *
 * Return: IfIts Success It Is 0,
 *
 * Description: If the Count is incorrect, exit code is 97
 * If file_to cannot be created or written, exit code 99
 * If file_to or file_from cannot be closed, exit code 100
 * If file_from does not exist, exit code 98
 *
 */
int main(int argc, char *argv[])
{
	int from, to, r, p;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	r = read(from, buffer, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || r == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		p = write(to, buffer, r);
		if (to == -1 || p == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		r = read(from, buffer, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);

	} while (r > 0);

	free(buffer);
	close_file(from);
	close_file(to);

	return (0);
}

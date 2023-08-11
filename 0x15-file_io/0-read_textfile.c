#include <stdlib.h>
#include "main.h"

/**
 * read_textfile- It Reads Text Files To Be Printed To Stdout
 * @filename: The text file is being read
 * Return: w- The Exact Amount Of Bytes
 * It Becomes zero If Filename Is NulL
 * @letters: The Amount Of Letters To Be Readen
 *
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t fd;
	ssize_t y;
	ssize_t z;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	z = read(fd, buf, letters);
	y = write(STDOUT_FILENO, buf, z);

	free(buf);
	close(fd);
	return (y);
}

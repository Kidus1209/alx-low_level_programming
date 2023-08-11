#include "main.h"

/**
 * append_text_to_file - attaches the text at end of all files,
 * @filename: An Indicator Of Name Of File,
 *
 * @text_content: String To Be Added In The End Of File,
 * Return: Function Failure Then Its -1,
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int s, d, n = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (n = 0; text_content[n];)
			n++;
	}

	s = open(filename, O_WRONLY | O_APPEND);
	d = write(s, text_content, n);

	if (s == -1 || d == -1)
		return (-1);

	close(s);

	return (1);
}

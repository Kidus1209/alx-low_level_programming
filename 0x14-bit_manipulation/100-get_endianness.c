#include "main.h"

/**
 * get_endianness - checks an endianess
 *
 * Return: 0 if it is large and 1 if it is small.
 */
int get_endianness(void)
{
	unsigned int i = 1;
	char *c = (char *) &i;

	return (*c);
}

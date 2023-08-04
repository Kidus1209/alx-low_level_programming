#include "main.h"

/**
 * get_endianness - checks an endianess
 *
 * Return: 0 if it is large and 1 if it is small.
 */
 int get_endianness(void)
{
	unsigned long int n = 1;

	return (*(char *)&n);
}

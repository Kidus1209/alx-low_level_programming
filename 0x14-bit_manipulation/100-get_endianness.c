#include "main.h"

/**
 * Return: 0 if it is large and 1 if it is small..
 *
 * get_endianness - checks an endian
 *
 */
int get_endianness(void)
{
	unsigned long int n = 1;

	return (*(char *)&n);
}

#include "main.h"

/**
 * clear_bit - changes the value of bit into zero
 * @n: The amount to pointer index
 * @index: To explicit the bit
 *
 * Return: 1 if its right, -1 if it becomes an ERROR
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(n) * 8)
		return (-1);

	if (*n & 1L << index)
		*n ^= 1L << index;
	return (1);
}

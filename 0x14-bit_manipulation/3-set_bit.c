#include "main.h"

/**
 * set_bit _ sets bit at index
 * @n: amount for index.
 * @index: Bit to be set
 *
 * Return: 1 if its Correct, -1 if its an ERror
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(n) * 8)
		return (-1);

	return (!!(*n |= 1L << index));
}

#include "main.h"

/**
 * flip_bits - replaces amount of Bits that have to be changed.
 * @m: subordinate Number
 *
 * @n: Initial Number.
 * Return: The amount of Bits to swap.
 *
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int p, count = 0;
	unsigned long int current;
	unsigned long int exclusive = n ^ m;

	for (p = 63; p >= 0; p--)
	{
		current = exclusive >> p;
		if (current & 1)
			count++;
	}

	return (count);
}

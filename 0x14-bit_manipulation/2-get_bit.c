#include "main.h"

/**
 * get_bit - finds at the index
 * @n: The amount needed to index
 * @index: Bit to find
 *
 * Return: State of the bit
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int valueof_Bit;

	if (index > 63)
		return (-1);

	valueof_Bit = (n >> index) & 1;

	return (valueof_Bit);
}

#include "main.h"

/**
 * print_binary - prints numbers as a binary string
 * @n: the number to be printed
 */
void print_binary(unsigned long int n)
{
	int p, count = 0;
	unsigned long int current;

	for (p = 63; p >= 0; p--)
	{
		current = n >> p;

		if (current & 1)
		{
			_putchar('1');
			count++;
		}
		else if (count)
			_putchar('0');
	}
	if (!count)
		_putchar('0');
}

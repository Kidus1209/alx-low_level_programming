#include "main.h"
#include <unistd.h>

/**
 * @c: Despositon or char which will be printed.
 * _putchar - Moves the C disposition (char) to Stdout.
 *
 * Return - on availability
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

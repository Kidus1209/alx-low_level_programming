#include <stdio.h>
/**
 * main - my main function
 * Return: zero
 * Description - printing sizes
 *
 */
int main (void)
{

        printf("size of a char: %zu byte(s)\n", sizeof(char));
	printf("size of an int: %zu byte(s)\n", sizeof(int));
	printf("size of a long int: %zu byte(s)\n", sizeof(long int));
	printf("size of a long long int: %zu byte(s)\n", sizeof(long long int));
	printf("size of  float: %zu byte(s)\n", sizeof(float));
        return (0);
}

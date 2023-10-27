#include <stdio.h>
#include "main.h"

/**
 * print_binary - Prints the binary representation of an unsigned long integer.
 * @n: The number to be printed in binary.
 */

void print_binary(unsigned long int n)
{
	int shift = sizeof(unsigned long int) * 8 - 1;
	int flag = 0;

	if (n == 0)
	{
		putchar('0');

		return;
	}
	while (shift >= 0)
	{
		unsigned long int bit = (n >> shift) & 1;

		if (bit)
			flag = 1;
		if (flag)
			putchar(bit ? '1' : '0');
		shift--;
	}
}

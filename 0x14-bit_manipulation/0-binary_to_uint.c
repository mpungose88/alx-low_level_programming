#include <stdio.h>
#include "main.h"

/**
 * binary_to_uint - Converts a binary number to an unsigned int.
 * @b: A string containing 0 and 1 characters.
 *
 * Return: The converted number, or 0 if there are non-0/1 characters
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;

	if (b == NULL)
		return (0);
	while (*b)
	{
		if (*b == '0' || *b == '1')
		{
			result = (result << 1) + (*b - '0');
		}
		else
		{
			return (0);
		}
		b++;
	}
	return (result);
}

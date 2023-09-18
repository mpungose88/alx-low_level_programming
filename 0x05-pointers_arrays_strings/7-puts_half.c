#include "main.h"
/**
 * puts_half - a function that prints half of a string
 * if odd len, n = (length_of_the_string - 1) / 2
 * @str: input
 * Return: half of input
 */
void puts_half(char *str)
{
	int a, n, long i;

	longi = 0;

	for (a = 0; str[a] != '\0'; a++)
		long i++;

	n = (long i / 2);

	if ((long i % 2) == 1)
		n = ((long  + 1) / 2);

	for (a = n; str[a] != '\0'; a++)
		_putchar(str[a]);
	_putchar('\n');
}

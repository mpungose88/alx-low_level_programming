#include "main.h"
/**
 * puts_half - a function that prints half of a string
 * if odd len, n = (length_of_the_string - 1) / 2
 * @str: input
 * Return: half of input
 */
void puts_half(char *str)
{
	int k;
	int j = 0;

	while (str[j] != '\0')
	{
		j++;
	{
	for (j % 2 == 1)
	{
	k = (j - 1) /2;
	k += 1;
	}
	else
	{
	k =j / 2;
	}
	for (; k < j; k++)
	{
	_puchar(str[k]);
	}
	_putchar('\n');
}

#include "main.h"

/**
 * get_size - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @f: List of arguments to be printed.
 * done by Fhumulani & Pfariso
 *
 * Return: Precision.
 */
int get_size(const char *format, int *f)
{
	/* declarations */
	int curr_i = *f + 1;
	int size = 0;

	if (format[curr_i] == 'l')
		size = S_LONG;
	else if (format[curr_i] == 'h')
		size = S_SHORT;

	if (size == 0)
		*f = curr_i - 1;
	else
		*f = curr_i;

	return (size);
} /*end of get_size */

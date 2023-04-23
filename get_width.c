#include "main.h"

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @f: List of arguments to be printed.
 * done by Fhumulani & Pfariso
 * @list: list of arguments.
 *
 * Return: width.
 */
int get_width(const char *format, int *f, va_list list)
{
	/* declarations*/
	int curr_i;
	int width = 0;

	for (curr_i = *f + 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			width *= 10;
			width += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*f = curr_i - 1;

	return (width);
} /* declarations*/

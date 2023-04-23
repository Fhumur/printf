#include "main.h"

/**
 * get_precision - Calculates for printing
 * @format: Formatted string in which to print the arguments
 * @f: List of arguments to be printed.
 * @list: list of arguments.
 * @precision: arg.
 * done by Fhumulani & Pfariso
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *f, va_list list)
{
	/* declarations */
	int curr_i = *f + 1;
	int precision = -1;

	if (format[curr_i] != '.')
		return (precision);

	precision = 0;

	for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			precision *= 10;
			precision += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*f = curr_i - 1;

	return (precision);
} /* end of get_precision fucntion */

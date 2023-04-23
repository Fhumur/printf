#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 * done by Fhumulani & Pfariso
 */
int _printf(const char *format, ...)
{
	/* declarations and intializations */
	int f;
	int prints = 0;
	int output_chars = 0;
	int flags;
	int width;
	int precision;
	int size;
	int buff_ind = 0;
	va_list vlist;

	char buffer[BUFF_SIZE]; /*end of declarations */

	if (format == NULL) /* if input is not a char */
		return (-1); /*exit function */

	va_start(vlist, format); /* function va_start begings */

	for (f = 0; format && format[f] != '\0'; f++) /* for loop */
	{
		if (format[f] != '%') /* if input is not a special character */
		{
			buffer[buff_ind++] = format[f];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[f], 1);*/
			printed_chars++;
		}
		else /* else statement */
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &f);
			width = get_width(format, &f, vlist);
			precision = get_precision(format, &f, vlist);
			size = get_size(format, &f);
			++f;
			printed = handle_print(format, &f, vlist, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind); /* print_buffer functions call */

	va_end(vlist); /*close va_list*/

	return (printed_chars); /* return value after function runs */
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 * done by Fhumulani & Pfariso
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0) /* if index is more than zero*/
		write(1, &buffer[0], *buff_ind); /*output*/

	*buff_ind = 0; /*reset buff_ind */
}

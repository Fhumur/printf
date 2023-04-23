#include "main.h"

/* PRINT UNSIGNED NUMBER FUNCTION */

/**
 * print_unsigned - Prints an unsigned number
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 * done by Fhumulani & Pfariso
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	/* declarations and initializations */
	int f = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size); /* end of declarations*/

	if (num == 0)
		buffer[f--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0) /* while loop */
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	} /* end of while */

	f++;

	return (write_unsgnd(0, f, buffer, flags, width, precision, size));
} /* end of print unsigned numebr functino */

/*PRINT UNSIGNED NUMBER IN OCTAL FUNCTION */

/**
 * print_octal - Prints an unsigned number in octal number system
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 * done by Fhumulani & Pfariso
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	/* declarations and initializations */
	int f = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);
	/* end of declarations and initializations */

	if (num == 0)
		buffer[f--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[f--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[f--] = '0';

	f++;

	return (write_unsgnd(0, f, buffer, flags, width, precision, size));
} /* end of print unsigned numbers in octal number system */

/*PRINT UNSIGNED NUMBER IN HEXADECIMAL FUNCTION */

/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 * done by Fhumulani & Pfariso
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size)); /* return values */
} /* end of print in hex function */

/* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL */

/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 * done by Fhumulani & Pfariso
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
} /* end of print usigned numbers in upper hex */

/* PRINT HEXX NUM IN LOWER OR UPPER */

/**
 * print_hexa - Prints a hexadecimal number in lower or upper
 * @types: Lista of arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @flag_ch: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * @size: Size specification
 * Return: Number of chars printed
 * done by Fhumulani & Pfariso
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	/* declarations and intializations */
	int f = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size); /* end of declarations */

	if (num == 0)
		buffer[f--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[f--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[f--] = flag_ch;
		buffer[f--] = '0';
	}

	f++;

	return (write_unsgnd(0, f, buffer, flags, width, precision, size));
} /* end of print hex in lower or upper */

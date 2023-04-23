#include "main.h"

/* PRINT POINTER FUNCTION*/
/**
 * print_pointer - Prints the value of a pointer variable
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 * done by Fhumulani & Pfariso
 */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	/* Declarations and initializations*/
	char extra_c = 0;
	char padd = ' ';
	int ind = BUFF_SIZE - 2;
	int length = 2;
	int padd_start = 1;
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size); /* end of declarations and initializations*/

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0) /* while loop */
	{
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_c = '+', length++;
	else if (flags & F_SPACE)
		extra_c = ' ', length++;

	ind++;

	/*return (write(1, &buffer[f], BUFF_SIZE - f - 1));*/
	return (write_pointer(buffer, ind, length,
		width, flags, padd, extra_c, padd_start));
} /*end of print pointer function*/

/* PRINT NON PRINTABLE FUNCTIONS */

/**
 * print_non_printable - Prints ascii codes in hexa of non printable chars
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 * done by Fhumulani & Pfariso
 */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	/* declarations and initializations */
	int f = 0;
	int offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size); /* end of declarations and initializations */

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[f] != '\0') /* while loop*/
	{
		if (is_printable(str[i]))
			buffer[f + offset] = str[i];
		else
			offset += append_hexa_code(str[f], buffer, f + offset);

		f++;
	} /*end of loop */

	buffer[f + offset] = '\0';

	return (write(1, buffer, f + offset));
} /*end of function */

/* PRINT REVERSE FUNCTION*/

/**
 * print_reverse - Prints reverse string.
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 * done by Fhumulani & Pfariso
 */

int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	/* Declarations and initializations*/
	char *str;
	int f;
	int count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size); /* end of declarations*/

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (f = 0; str[f]; f++)
		;

	for (f = f - 1; f >= 0; f--)
	{
		char z = str[f];

		write(1, &z, 1);
		count++;
	}
	return (count);
} /* end of print in reverse function */


/* PRINT A STRING IN ROT13 FUNCTION*/
/**
 * print_rot13string - Print a string in rot13.
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 * done by Fhumulani & Pfariso
 */
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	/* declarations and initializations */
	char x;
	char *str;
	unsigned int f, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size); /*end o declarations */

	if (str == NULL)
		str = "(AHYY)";
	for (f = 0; str[f]; f++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[f])
			{
				x = out[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			x = str[f];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
} /* end of Print in rot13 function */

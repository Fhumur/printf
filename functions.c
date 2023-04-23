#include "main.h"

/* PRINT INT FUNCTION */

/**
 * print_int - Prints intigers
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 * done by Fhumulani & Pfariso
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	/* declarations and initializations */
	int f = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size); /*end of declarations and initializations */

	if (n == 0)
		buffer[f--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0) /* while loop */
	{
		buffer[f--] = (num % 10) + '0';
		num /= 10;
	}

	f++;

	return (write_number(is_negative, f, buffer, flags, width, precision, size));
} /* end of print intiger function */

/* PRINT BINARY FUNCTION */

/**
 * print_binary - Prints an unsigned number
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of char printed.
 * done by Fhumulani & Pfariso
 */
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	/* declarations and intializations */
	unsigned int n;
	unsigned int m;
	unsigned int f;
	unsigned int sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m; /* end of declarations and initializations */

	for (f = 1; f < 32; f++) /* for loop */
	{
		m /= 2;
		a[f] = (n / m) % 2; /* modulus function to get 0 or 1 */
	} /* end of for loop */
	for (f = 0, sum = 0, count = 0; f < 32; f++) /* for loop */
	{
		sum += a[f]; /* sum formular */
		if (sum || f == 31)
		{
			char z = '0' + a[f];

			write(1, &z, 1);
			count++; /* incremental */
		}
	}
	return (count); /* return value */
} /* end of print binary function */

/* PRINT CHAR FUNCTION */

/**
 * print_char - Prints a char
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 * done by Fhumulani & Pfariso
 */
int print_char(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
	char c = va_arg(types, int); /*declaration */

	return (handle_write_char(c, buffer, flags, width, precision, size));
} /* end of print char function */

/* PRINT A STRING FUNCTION */

/**
 * print_string - Prints a string
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 * done by Fhumulani & Pfariso
 */
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int f, count = 0; /*declarations and initializations */
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size); /*end of declarations */

	if (str == NULL) /* if string is invalid */
	{
		str = "(null)";
		if (precision >= 6)
			str = "      "; /* string is blank */
	}

	while (str[count] != '\0') /* while loop */
		count++;

	if (precision >= 0 && precision < count)
		count = precision;

	if (width > count)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], count);
			for (f = width - count; f > 0; f--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (f = width - count; f > 0; f--)
				write(1, " ", 1);
			write(1, &str[0], count);
			return (width);
		}
	} /* end of while loop */
	return (write(1, str, count)); /* return values after function runs */
} /* end of print string function */

/* PRINT PERCENT SIGN FUNCTION*/

/**
 * print_percent - Prints a percent sign
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 * done by Fhumulani & Pfariso
 */
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	/* declarations */
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size); /* end of declaration */
	return (write(1, "%%", 1)); /* return values after function runs */
} /* end of print percent function */

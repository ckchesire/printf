#include "main.h"

/**
 * print_unsigned - Prints an unsigned number
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Get width
 * @precision: Precision specification
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int index = BUFF_SIZE - 2;
	unsigned long int value = va_arg(types, unsigned long int);

	value = convert_size_unsgnd(value, size);

	if (value == 0)
		buffer[index--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (value > 0)
	{
		buffer[index--] = (value % 10) + '0';
		value /= 10;
	}

	index++;

	return (write_unsgnd(0, index, buffer, flags, width, precision, size));
}

/**
 * print_octal - Prints an unsigned number in octal notation
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Get width
 * @precision: Precision specification
 * @size: Size specifier
 *
 * Return: Number of chars printed
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int index = BUFF_SIZE - 2;
	unsigned long int value = va_arg(types, unsigned long int);
	unsigned long int initial_value = value;

	UNUSED(width);

	value = convert_size_unsgnd(value, size);

	if (value == 0)
		buffer[index--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (value > 0)
	{
		buffer[index--] = (value % 8) + '0';
		value /= 8;
	}

	if (flags & F_HASH && initial_value != 0)
		buffer[index--] = '0';

	index++;

	return (write_unsgnd(0, index, buffer, flags, width, precision, size));
}

/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Get width
 * @precision: Precision specification
 * @size: Size specifier
 *
 * Return: Number of chars printed
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Get width
 * @precision: Precision specification
 * @size: Size specifier
 *
 * Return: Number of chars printed
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/**
 * print_hexa - Prints a hexadecimal number in lower or upper
 * @types: List of arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @flag_ch: Calculates active flags
 * @width: Get width
 * @precision: Precision specification
 * @size: Size specifier
 *
 * Return: Number of chars printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int index = BUFF_SIZE - 2;
	unsigned long int value = va_arg(types, unsigned long int);
	unsigned long int initial_value = value;

	UNUSED(width);

	value = convert_size_unsgnd(value, size);

	if (value == 0)
		buffer[index--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (value > 0)
	{
		buffer[index--] = map_to[value % 16];
		value /= 16;
	}

	if (flags & F_HASH && initial_value != 0)
	{
		buffer[index--] = flag_ch;
		buffer[index--] = '0';
	}

	index++;

	return (write_unsgnd(0, index, buffer, flags, width, precision, size));
}

#include "main.h"

/**
 * print_pointer - Prints the value of a pointer variable
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Get width
 * @precision: Precision specification
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char padding_char = ' ', extra_char = 0;
	int index = BUFF_SIZE - 2, len = 2, padding_start = 1;
	unsigned long addr_num;
	char hex_map[] = "0123456789abcdef";
	void *addr = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (addr == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	addr_num = (unsigned long)addr;

	while (addr_num > 0)
	{
		buffer[index--] = hex_map[addr_num % 16];
		addr_num /= 16;
		len++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padding_char = '0';
	if (flags & F_PLUS)
		extra_char = '+', len++;
	else if (flags & F_SPACE)
		extra_char = ' ', len++;

	index++;

	return (write_pointer(buffer, index, len,
		width, flags, padding_char, extra_char, padding_start));
}

/**
 * print_non_printable - Prints ascii codes in hexa of non printable chars
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Get width
 * @precision: Precision specification
 * @size: Size specifier
 *
 * Return: Number of chars printed
 */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = 0, offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			buffer[i + offset] = str[i];
		else
			offset += append_hexa_code(str[i], buffer, i + offset);

		i++;
	}

	buffer[i + offset] = '\0';

	return (write(1, buffer, i + offset));
}

/**
 * print_reverse - Prints reverse string
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Get width
 * @precision: Precision specification
 * @size: Size specifier
 *
 * Return: Numbers of chars printed
 */
int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int i, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = "(null)";
	}
	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		count++;
	}
	return (count);
}

/**
 * print_rot13string - Print a string in rot13
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Get width
 * @precision: Precision specification
 * @size: Size specifier
 *
 * Return: Numbers of chars printed
 */
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char transformed_char;
	char *input_str;
	unsigned int i, j;
	int char_count = 0;
	char input_set[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char output_set[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	input_str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (input_str == NULL)
		input_str = "(AHYY)";
	for (i = 0; input_str[i]; i++)
	{
		for (j = 0; input_set[j]; j++)
		{
			if (input_set[j] == input_str[i])
			{
				transformed_char = output_set[j];
				write(1, &transformed_char, 1);
				char_count++;
				break;
			}
		}
		if (!input_set[j])
		{
			transformed_char = input_str[i];
			write(1, &transformed_char, 1);
			char_count++;
		}
	}
	return (char_count);
}

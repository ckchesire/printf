#include "main.h"

/**
 * print_char - Outputs a single character
 * @arg_list: List of arguments
 * @output_buffer: Buffer array to handle print
 * @formatting_flags: Active formatting flags
 * @field_width: Minimum field Width
 * @precision: Precision for decimal numbers
 * @size: Length modifier for data types
 * Return: Number of chars printed
 */
int print_char(va_list arg_list, char output_buffer[],
	int formatting_flags, int field_width, int precision, int size)
{
	char output_char = va_arg(arg_list, int);

	return (handle_write_char(output_char, output_buffer, formatting_flags,
				field_width, precision, size));
}

/**
 * print_string - Outputs a string
 * @arg_list: List a of arguments
 * @output_buffer: Buffer array to handle output
 * @formatting_flags:  Calculates active flags
 * @field_width: get width.
 * @precision: Precision specification
 * @size: Length modifier for data types
 * Return: Number of chars printed
 */
int print_string(va_list arg_list, char output_buffer[],
	int formatting_flags, int field_width, int precision, int size)
{
	int str_length = 0, index;
	char *output_str = va_arg(arg_list, char *);

	UNUSED(output_buffer);
	UNUSED(formatting_flags);
	UNUSED(field_width);
	UNUSED(precision);
	UNUSED(size);
	if (output_str == NULL)
	{
		output_str = "(null)";
		if (precision >= 6)
			output_str = "      ";
	}

	while (output_str[str_length] != '\0')
		str_length++;

	if (precision >= 0 && precision < str_length)
		str_length = precision;

	if (field_width > str_length)
	{
		if (formatting_flags & F_MINUS)
		{
			write(1, &output_str[0], str_length);
			for (index = field_width - str_length; index > 0; index--)
				write(1, " ", 1);
			return (field_width);
		}
		else
		{
			for (index = field_width - str_length; index > 0; index--)
				write(1, " ", 1);
			write(1, &output_str[0], str_length);
			return (field_width);
		}
	}

	return (write(1, output_str, str_length));
}

/**
 * print_percent - Prints a percent sign
 * @arg_list: List of arguments
 * @output_buffer: Buffer array to handle output
 * @formatting_flags:  Calculates active flags
 * @field_width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_percent(va_list arg_list, char output_buffer[],
	int formatting_flags, int field_width, int precision, int size)
{
	UNUSED(arg_list);
	UNUSED(output_buffer);
	UNUSED(formatting_flags);
	UNUSED(field_width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/**
 * print_int - Outputs an integer
 * @arg_list: List of arguments
 * @output_buffer: Buffer array to handle print
 * @formatting_flags:  Calculates active flags
 * @field_width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_int(va_list arg_list, char output_buffer[],
	int formatting_flags, int field_width, int precision, int size)
{
	int buffer_index = BUFF_SIZE - 2;
	int is_negative = 0;
	long int input_num = va_arg(arg_list, long int);
	unsigned long int absolute_num;

	input_num = convert_size_number(input_num, size);

	if (input_num == 0)
		output_buffer[buffer_index--] = '0';

	output_buffer[BUFF_SIZE - 1] = '\0';
	absolute_num = (unsigned long int)input_num;

	if (input_num < 0)
	{
		absolute_num = (unsigned long int)((-1) * input_num);
		is_negative = 1;
	}

	while (absolute_num > 0)
	{
		output_buffer[buffer_index--] = (absolute_num % 10) + '0';
		absolute_num /= 10;
	}

	buffer_index++;

	return (write_number(is_negative, buffer_index, output_buffer,
				formatting_flags, field_width, precision, size));
}

/*
 * print_binary - Outputs an unsigned number in binary format
 * @arg_list: Variable argument list
 * @output_buffer: Buffer for handling output
 * @formatting_flags: Active formatting flags
 * @field_width: Minimum field width
 * @decimal_precision: Precision for decimal numbers
 * @length_modifier: Length modifier for data types
 * Return: Count of characters output
 */
int print_binary(va_list arg_list, char output_buffer[], int formatting_flags,
		int field_width, int decimal_precision, int length_modifier)
{
	unsigned int input_num, bit_mask, bit_index, b_sum;
	unsigned int binary_digits[32];
	int output_count;

	UNUSED(output_buffer);
	UNUSED(formatting_flags);
	UNUSED(field_width);
	UNUSED(decimal_precision);
	UNUSED(length_modifier);

	input_num = va_arg(arg_list, unsigned int);
	bit_mask = 2147483648; /* (2 ^ 31) */
	binary_digits[0] = input_num / bit_mask;

	for (bit_index = 1; bit_index < 32; bit_index++)
	{
		bit_mask /= 2;
		binary_digits[bit_index] = (input_num / bit_mask) % 2;
	}

	for (bit_index = 0, b_sum = 0, output_count = 0; bit_index < 32; bit_index++)
	{
		b_sum += binary_digits[bit_index];
		if (b_sum || bit_index == 31)
		{
			char output_digit = '0' + binary_digits[bit_index];

			write(1, &output_digit, 1);
			output_count++;
		}
	}
	return (output_count);
}

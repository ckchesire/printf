#include "main.h"

/**
 * get_precision - Determines the precision for printing
 * @format: Formatted string containing the precision specifier
 * @index: Pointer to current position in format string
 * @args: List of arguments for variable precision
 *
 * Return: Calculated precision value
 */
int get_precision(const char *format, int *index, va_list args)
{
	int current_pos = *index + 1;
	int precision_value = -1;

	if (format[current_pos] != '.')
		return (precision_value);

	precision_value = 0;

	for (current_pos += 1; format[current_pos] != '\0'; current_pos++)
	{
		if (is_digit(format[current_pos]))
		{
			precision_value *= 10;
			precision_value += format[current_pos] - '0';
		}
		else if (format[current_pos] == '*')
		{
			current_pos++;
			precision_value = va_arg(args, int);
			break;
		}
		else
			break;
	}

	*index = current_pos - 1;

	return (precision_value);
}

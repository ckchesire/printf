#include "main.h"

/**
 * get_width - Determines the width for printing
 * @format: Formatted string containing the width specifier
 * @pos: Pointer to current position in format string
 * @args: Variable argument list for dynamic width
 *
 * Return: Calculated width value
 */
int get_width(const char *format, int *pos, va_list args)
{
	int current_index;
	int field_width = 0;

	for (current_index = *pos + 1; format[current_index] != '\0'; current_index++)
	{
		if (is_digit(format[current_index]))
		{
			field_width *= 10;
			field_width += format[current_index] - '0';
		}
		else if (format[current_index] == '*')
		{
			current_index++;
			field_width = va_arg(args, int);
			break;
		}
		else
			break;
	}

	*pos = current_index - 1;

	return (field_width);
}

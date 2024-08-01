#include "main.h"

void flush_buffer(char buffer[], int *buffer_index);

/**
 * _printf - Custom printf function
 * @format: format, input
 * Return: Printed characters
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buffer_index = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buffer_index++] = format[i];
			if (buffer_index == BUFF_SIZE)
				flush_buffer(buffer, &buffer_index);
			printed_chars++;
		}
		else
		{
			flush_buffer(buffer, &buffer_index);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
			{
				va_end(list);
				return (-1);
			}
			printed_chars += printed;
		}
	}

	flush_buffer(buffer, &buffer_index);

	va_end(list);

	return (printed_chars);
}

/**
 * flush_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buffer_index: Index at which to add next char, represents the length.
 */
void flush_buffer(char buffer[], int *buffer_index)
{
	if (*buffer_index > 0)
		write(1, &buffer[0], *buffer_index);

	*buffer_index = 0;
}

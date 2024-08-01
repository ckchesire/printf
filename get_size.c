#include "main.h"

/**
 * get_size - Determines the size modifier for casting the argument
 * @format: Formatted string containing the size specifier
 * @index: Pointer to current position in format string
 *
 * Return: Size modifier value
 */
int get_size(const char *format, int *index)
{
	int next_pos = *index + 1;
	int size_modifier = 0;

	if (format[next_pos] == 'l')
		size_modifier = S_LONG;
	else if (format[next_pos] == 'h')
		size_modifier = S_SHORT;

	if (size_modifier == 0)
		*index = next_pos - 1;
	else
		*index = next_pos;

	return (size_modifier);
}

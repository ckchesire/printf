#include "main.h"

/**
 * get_flags - Determines active flags for formatting
 * @format: String containing format specifiers
 * @index: Pointer to current position in format string
 *
 * Return: Calculated flags
 */
int get_flags(const char *format, int *index)
{
	/* Flag characters: - + 0 # ' ' */
	/* Corresponding bit values: 1 2 4 8 16 */
	int flag_index, current_pos;
	int active_flags = 0;
	const char FLAG_CHARS[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAG_VALUES[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (current_pos = *index + 1; format[current_pos] != '\0'; current_pos++)
	{
		for (flag_index = 0; FLAG_CHARS[flag_index] != '\0'; flag_index++)
		{
			if (format[current_pos] == FLAG_CHARS[flag_index])
			{
				active_flags |= FLAG_VALUES[flag_index];
				break;
			}
		}

		if (FLAG_CHARS[flag_index] == 0)
			break;
	}

	*index = current_pos - 1;

	return (active_flags);
}

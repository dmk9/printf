#include "main.h"

/**
 * _printf - prints a formatted string
 * @format: character string for desired output
 * Return: the number of characters printed
 * (excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
	int c = 0;
	size_t i = 0;

	va_list a;

	va_start(a, format);

	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			switch (format[i])
			{
				case 'c':
					c += _putchar(va_arg(a, int));
					break;
				case 's': {
					const char *s = va_arg(a, const char *);
					while (*s)
						c += _putchar(*s++);
					break;
				}
				case '%':
					c += _putchar('%');
					break;
				default:
					c += _putchar('%'), c += _putchar(format[i]);
					break;
			}
		}
		else
			c += _putchar(format[i]);
	}
	va_end(a);
	return (c);
}

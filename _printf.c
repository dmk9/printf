#include "main.h"

/**
 * _printf - prints a formatted string
 * @format: character string for desired output
 * Return: the number of characters printed (excluding the null byte used to end output to strings)
 */

int _printf(const char *format, ...)
{
    int count = 0; // To keep track of the number of characters printed
    va_list args;
    va_start(args, format);

    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++; // Move past the '%'

            // Handle conversion specifiers
            switch (*format)
            {
            case 'c':
                // Print a character
                _putchar(va_arg(args, int));
                count++;
                break;
            case 's':
                // Print a string
                {
                    char *str = va_arg(args, char *);
                    while (*str != '\0')
                    {
                        _putchar(*str);
                        str++;
                        count++;
                    }
                }
                break;
            case '%':
                // Print a literal '%' character
                _putchar('%');
                count++;
                break;
            default:
                // Unsupported specifier, just print as is
                _putchar('%');
                _putchar(*format);
                count += 2;
                break;
            }
        }
        else
        {
            // Normal character, print as is
            _putchar(*format);
            count++;
        }

        format++; // Move to the next character in the format string
    }

    va_end(args);

    return count;
}
/*
int main()
{
    _printf("Hello, %s! The answer is %d%%.\n", "world", 42);
    return 0;
}*/

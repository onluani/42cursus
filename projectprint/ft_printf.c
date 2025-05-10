#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		length;
	va_list	agruments;

	length = 0;
	va_start(agruments, format);
	length = parse_input(format, agruments, length);
	va_end(agruments);
	return (length);
}

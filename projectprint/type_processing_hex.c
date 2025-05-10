#include "ft_printf.h"

void	x_type(va_list arguments, int *length, char *str)
{
	unsigned int	nb;

	nb = va_arg(arguments, unsigned int);
	ft_puthex(nb, length, str);
}

void	p_type(va_list arguments, int *length, char *str)
{
	unsigned long	adr;

	adr = va_arg(arguments, unsigned long long);
	ft_putchar('0', length);
	ft_putchar('x', length);
	ft_puthex(adr, length, str);
}

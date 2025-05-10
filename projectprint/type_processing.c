#include "ft_printf.h"

void	c_type(va_list arguments, int *length)
{
	char	c;

	c = va_arg(arguments, int);
	ft_putchar(c, length);
}

void	s_type(va_list arguments, int *length)
{
	char	*s;

	s = va_arg(arguments, char *);
	if (!s)
		s = "(null)";
	while (*s)
		ft_putchar(*s++, length);
}

void	d_i_type(va_list arguments, int *length)
{
	int	nb;

	nb = va_arg(arguments, int);
	ft_putnbr(nb, length);
}

void	u_type(va_list arguments, int *length)
{
	unsigned int	nb;

	nb = va_arg(arguments, unsigned int);
	ft_putuns(nb, length);
}

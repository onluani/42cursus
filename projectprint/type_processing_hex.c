/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_processing_hex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antsitsk <antsitsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:25:23 by antsitsk          #+#    #+#             */
/*   Updated: 2025/05/27 15:41:09 by antsitsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	x_type(va_list arguments, int *length, char *str)
{
	unsigned int	nb;

	nb = va_arg(arguments, unsigned int);
	ft_puthex(nb, length, str);
}

void	p_type(va_list arguments, int *length, char *str)
{
	void			*ptr;
	unsigned long	adr;

	ptr = va_arg(arguments, void *);
	if (!ptr)
	{
		ft_putstr("(nil)", length);
	}
	else
	{
		adr = (unsigned long)ptr;
		ft_putchar('0', length);
		ft_putchar('x', length);
		ft_puthex(adr, length, str);
	}
}

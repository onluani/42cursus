/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antsitsk <antsitsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:52:58 by antsitsk          #+#    #+#             */
/*   Updated: 2025/05/27 13:53:59 by antsitsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_conversions(char *str, int *length, va_list arguments)
{
	if (*str == 'c')
		c_type(arguments, length);
	else if (*str == 's')
		s_type(arguments, length);
	else if (*str == 'd' || *str == 'i')
		d_i_type(arguments, length);
	else if (*str == 'u')
		u_type(arguments, length);
	else if (*str == 'x' || *str == 'X')
		x_type(arguments, length, str);
	else if (*str == 'p')
		p_type(arguments, length, str);
	else
		ft_putchar(*str, length);
}

int	parse_input(const char *str, va_list arguments, int length)
{
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			parse_conversions((char *)str, &length, arguments);
			str++;
		}
		else
			ft_putchar(*str++, &length);
	}
	return (length);
}

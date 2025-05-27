/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antsitsk <antsitsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:24:01 by antsitsk          #+#    #+#             */
/*   Updated: 2025/05/27 15:43:18 by antsitsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
void	parse_conversions(char *str, int *length, va_list arguments);
int		parse_input(const char *str, va_list arguments, int length);
void	ft_putstr(const char *s, int *length);
int		ft_putchar(char c, int *length);
void	ft_putnbr(int nb, int *length);
void	ft_putuns(unsigned int nb, int *length);
void	ft_puthex(unsigned long long nb, int *length, char *str);
void	c_type(va_list arguments, int *length);
void	s_type(va_list arguments, int *length);
void	d_i_type(va_list arguments, int *length);
void	u_type(va_list arguments, int *length);
void	x_type(va_list arguments, int *length, char *str);
void	p_type(va_list arguments, int *length, char *str);

#endif

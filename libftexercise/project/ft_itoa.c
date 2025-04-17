/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antsitsk <antsitsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:00:51 by antsitsk          #+#    #+#             */
/*   Updated: 2025/04/17 14:10:38 by antsitsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	len_int(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	len;
	long	nl;

	nl = n;
	len = len_int(nl);
	str = (char *)malloc(sizeof(char) * (len +1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nl < 0)
	{
		str[0] = '-';
		nl *= -1;
	}
	while (len > 0 && str[len -1] != '-')
	{
		str[--len] = (nl % 10) + '0';
		nl /= 10;
	}
	return (str);
}

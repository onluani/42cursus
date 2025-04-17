/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antsitsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:15:02 by antsitsk          #+#    #+#             */
/*   Updated: 2025/03/07 13:09:09 by antsitsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_base(char *base)
{
	int	i;
	int	j;

	if (!base || base[0] == '\0' || base[1] == '\0')
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || \
				base[i] == ' ' || (base[i] >= 9 \
					&& base[i] <= 13))
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int	index_of_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

void	skip_whitespace_and_sign(char **str, int *sign)
{
	while (**str == ' ' || (**str >= 9 && **str <= 13))
		(*str)++;
	while (**str == '+' || **str == '-')
	{
		if (**str == '-')
			*sign *= -1;
		(*str)++;
	}
}

int	ft_atoi_base(char *str, char *base)
{
	int	base_len;
	int	num;
	int	sign;
	int	digit;

	base_len = check_base(base);
	if (!base_len)
		return (0);
	sign = 1;
	skip_whitespace_and_sign(&str, &sign);
	num = 0;
	while (*str)
	{
		digit = index_of_base(*str, base);
		if (digit == -1)
			return (0);
		num = (num * base_len) + digit;
		str++;
	}
	return (num * sign);
}

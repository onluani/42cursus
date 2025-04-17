/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antsitsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 12:44:14 by antsitsk          #+#    #+#             */
/*   Updated: 2025/02/28 13:02:25 by antsitsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	is_uppercase(char c)
{
	return (c >= 'A' && c <= 'Z');
}

char	is_lowercase(char c)
{
	return (c >= 'a' && c <= 'z');
}

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (is_uppercase(str[i]) || is_lowercase(str[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

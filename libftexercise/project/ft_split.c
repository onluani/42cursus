/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antsitsk <antsitsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:50:40 by antsitsk          #+#    #+#             */
/*   Updated: 2025/04/17 13:41:31 by antsitsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_count(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s != '\0')
	{
		if (*s == c)
			s++;
		else
		{
			count++;
			while (*s != '\0' && *s != c)
				s++;
		}
	}
	return (count);
}

char	**free_machine(char **s, size_t idx)
{
	while (idx > 0)
	{
		free(s[--idx]);
	}
	free(s);
	return (NULL);
}

static char	*get_word(char const *s, size_t *len, char c)
{
	char	*word;
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	*len = i;
	word = ft_substr(s, 0, *len);
	return (word);
}

static void	skip_delimiters(char const **s, char c)
{
	while (**s == c)
		(*s)++;
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	len;
	size_t	word_count;
	char	**words;

	i = 0;
	if (!s)
		return (NULL);
	word_count = get_count(s, c);
	words = malloc(sizeof(char *) * (word_count + 1));
	if (!words)
		return (NULL);
	while (*s)
	{
		skip_delimiters(&s, c);
		if (*s == '\0')
			break ;
		len = 0;
		words[i] = get_word(s, &len, c);
		if (!(words[i++]))
			return (free_machine(words, i));
		s += len;
	}
	words[i] = NULL;
	return (words);
}

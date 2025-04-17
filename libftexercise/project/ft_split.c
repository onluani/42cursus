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
		if (*s == c)
			s++;
		else
		{
			len = 0;
			while (s[len] && s[len] != c)
				len++;
			if (!(words[i++] = ft_substr(s, 0, len)))
				return (free_machine(words, i));
			s += len;
		}
	}
	words[i] = NULL;
	return (words);
}

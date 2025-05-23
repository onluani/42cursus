/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antsitsk <antsitsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:04:51 by antsitsk          #+#    #+#             */
/*   Updated: 2025/05/20 12:04:51 by antsitsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_before_newline(int fd, char *leftover)
{
	char	*buff;
	ssize_t	read_bytes;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(leftover, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[read_bytes] = '\0';
		leftover = ft_strjoin(leftover, buff);
	}
	free(buff);
	return (leftover);
}

char	*ft_line_from_leftover(char *leftover)
{
	int		i;
	char	*line;

	i = 0;
	if (!leftover[i])
		return (NULL);
	while (leftover[i] && leftover[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (leftover[i] && leftover[i] != '\n')
	{
		line[i] = leftover[i];
		i++;
	}
	if (leftover[i] == '\n')
	{
		line[i] = leftover[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_trim_leftover(char *leftover)
{
	int		i;
	int		j;
	char	*new_leftover;

	i = 0;
	while (leftover[i] && leftover[i] != '\n')
		i++;
	if (!leftover[i])
	{
		free(leftover);
		return (NULL);
	}
	new_leftover = (char *)malloc(sizeof(char) * (ft_strlen(leftover) - i + 1));
	if (!new_leftover)
		return (NULL);
	i++;
	j = 0;
	while (leftover[i])
		new_leftover[j++] = leftover[i++];
	new_leftover[j] = '\0';
	free(leftover);
	return (new_leftover);
}

char	*get_next_line(int fd)
{
	static char	*leftover;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	leftover = ft_read_before_newline(fd, leftover);
	if (!leftover)
		return (NULL);
	line = ft_line_from_leftover(leftover);
	leftover = ft_trim_leftover(leftover);
	return (line);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggonza <anggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:11:36 by anggonza          #+#    #+#             */
/*   Updated: 2021/11/09 18:06:08 by anggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 42

static char	*ft_strndup(char *s, int n)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(sizeof(char) * n + 2);
	if (!str)
		return (NULL);
	while (i <= n)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

void	ft_fill_rest(char *line, char *rest)
{
	if (rest)
		ft_strjoin(rest, line);
	free(rest);
}

char	*return_line(char *line, char *buffer, char *rest, int i)
{
	if (ft_strlen(line) < BUFFER_SIZE * i)
	{
		rest = ft_strndup((buffer + i))
	}
}
char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*rest;
	char		*line;
	int			count;
	int			i;

	line = NULL;
	i = 0;
	if (read(fd, buffer, BUFFER_SIZE) < 0 || fd < 0)
	{
		free(buffer);
		if (rest)
			free(rest);
		return (NULL);
	}
	ft_fill_rest(line, rest);
	while (ft_strchr(buffer, '\n') < 0 && count > 0)
	{
		ft_strjoin(line, ft_strndup(buffer, ft_strchr(buffer, '\n')));
		count = read(fd, buffer, BUFFER_SIZE);
		i += 1;
	}
	return (return_line(line, buffer, rest, i));
}

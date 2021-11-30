/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggonza <anggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:11:36 by anggonza          #+#    #+#             */
/*   Updated: 2021/11/30 12:00:55 by anggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
//#define BUFFER_SIZE 1

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

void	ft_fill_rest(char **line, char *rest)
{
	if (rest != '\0')
	{
		*line = ft_strjoin(*line, rest, 0);
		if (!line)
			return ;
		rest = NULL;
		free(rest);
	}
	if (rest == '\0')
		free(rest);
	return ;
}

char	*return_line(char *line, char **buffer, char **rest)
{
	if (*buffer)
	{
		*rest = NULL;
		*rest = ft_strjoin(*rest, *buffer, 0);
		if (!rest)
			free(rest);
		free(*buffer);
		*buffer = NULL;
	}
	if (ft_strlen(line) == 0)
		return (NULL);
	return (line);
}

static char	*ft_fill_temp(int fd, char *buffer, t_vars *v)
{
	int		count;
	char	*tmp;

	count = read(fd, buffer, BUFFER_SIZE);
	if (count == 0)
	{
		free(buffer);
		buffer = NULL;
		return (0);
	}
	while (ft_strchr(buffer, '\n') < 0 && count > 0)
	{
		v->temp = ft_strjoin(v->temp, buffer, &v->i);
		count = read(fd, buffer, BUFFER_SIZE);
	}
	tmp = ft_strndup(buffer, ft_strchr(buffer, '\n') - 1);
	if (!tmp)
		return (NULL);
	v->temp = ft_strjoin(v->temp, tmp, &v->i);
	buffer = ft_substr(buffer, ft_strchr(buffer, '\n'), ft_strlen(buffer));
	if (!buffer)
	{
		free(buffer);
		buffer = NULL;
	}
	free(tmp);
	return (buffer);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*rest = NULL;
	t_vars		v;

	v.line = NULL;
	v.temp = NULL;
	v.i = 0;
	buffer = malloc(BUFFER_SIZE + 1);
	if (read(fd, buffer, 0) < 0 || fd < 0)
	{
		if (rest)
			free(rest);
		free(buffer);
		return (NULL);
	}
	ft_fill_rest(&v.line, rest);
	buffer = ft_fill_temp(fd, buffer, &v);
	if (buffer == 0)
		return (return_line(v.line, &buffer, &rest));
	v.line = ft_strjoin(v.line, v.temp, 0);
	free(v.temp);
	v.temp = NULL;
	return (return_line(v.line, &buffer, &rest));
}
/*
int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}
*/

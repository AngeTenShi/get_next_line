/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggonza <anggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 14:02:38 by anggonza          #+#    #+#             */
/*   Updated: 2021/11/30 11:51:50 by anggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strchr(char *s, int c)
{
	int	i;

	if ((char)c == '\0')
		return (ft_strlen(s));
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i + 1);
		i++;
	}
	return (-1);
}

char	*ft_strjoin(char *s1, char *s2, int *sizefinal)
{
	char	*str;
	size_t	i;
	size_t	size;

	size = ft_strlen(s1) + ft_strlen(s2);
	if (sizefinal)
		*sizefinal = size;
	i = 0;
	str = malloc(size + 1);
	if (!str)
	{
		free(str);
		return (NULL);
	}
	while (i <= size)
	{
		if (i < size - ft_strlen(s2))
		{
			str[i] = s1[i];
		}
		else
		{
			str[i] = *s2++;
		}
		i++;
	}
	str[i] = 0;
	free(s1);
	return (str);
}

char	*ft_substr(char *s, int start, int len)
{
	int		i;
	int		j;
	char	*sub;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if ((int)start > ft_strlen(s))
	{
		free(s);
		return (ft_strjoin(""," ",0));
	}
	if ((int)len > ft_strlen((s + start)))
		len = ft_strlen((s + start));
	sub = (char *)malloc(sizeof(char) * len + 1);
	if (!sub)
	{
		free(s);
		return (NULL);
	}
	while (s[i])
	{
		if (i >= start && j < len)
			sub[j++] = s[i];
		i++;
	}
	sub[j] = '\0';
	free(s);
	return (sub);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggonza <anggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 14:30:22 by anggonza          #+#    #+#             */
/*   Updated: 2021/11/15 15:48:10 by anggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_v
{
	int		i;
	int		pass;
	char	*temp;
	char	*line;
}	t_vars;

int		ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2, int *sizefinal);
int		ft_strchr(char *s, int c);
char	*get_next_line(int fd);
void	ft_fill_line(char *line, char *buffer, int *count);
void	ft_fill_rest(char **line, char *rest);
char	*ft_substr(char *s, unsigned int start, size_t len);

#endif

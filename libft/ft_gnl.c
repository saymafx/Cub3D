/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ma1iik <ma1iik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 21:44:30 by ma1iik            #+#    #+#             */
/*   Updated: 2023/01/20 15:46:51 by ma1iik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_gnl(char **join, int *size_read, char buffer[1], int fd)
{
	char	*tmp;

	*size_read = 1;
	if (*join == 0)
		*join = ft_calloc(sizeof(char), 1);
	while (ft_strchr(*join, '\n') == 0 && *size_read > 0)
	{
		*size_read = read(fd, buffer, 1);
		buffer[*size_read] = 0;
		tmp = ft_strjoin(*join, buffer);
		free(*join);
		*join = tmp;
	}
}

int	get_next_line(int fd, char **line)
{
	int			size_read;
	char		buffer[1 + 1];
	static char	*join = 0;
	char		*tmp;

	ft_gnl(&join, &size_read, buffer, fd);
	if (size_read == 0)
	{
		*line = ft_strdup(join);
		free(join);
		join = 0;
		return (0);
	}
	if (size_read > 0)
	{
		*line = ft_substr(join, 0, (ft_strchr(join, '\n') - join));
		tmp = ft_strdup(join + ft_strlen(*line) + 1);
		free(join);
		join = tmp;
		return (1);
	}
	if (fd == -1 && 1 > 0)
		free(join);
	return (-1);
}

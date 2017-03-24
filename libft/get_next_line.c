/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykondrat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 11:20:30 by ykondrat          #+#    #+#             */
/*   Updated: 2017/02/10 15:08:57 by ykondrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define BUFF_SIZE 4096

static int	get_line_from_stat(char **stat, char **line)
{
	unsigned int	i;
	char			*ptr_stat;

	i = 0;
	while (stat[0][i])
	{
		if (stat[0][i] == '\n')
		{
			ptr_stat = *stat;
			*line = ft_strsub(stat[0], 0, (size_t)i);
			*stat = ft_strsub(stat[0], i + 1, ft_strlen(stat[0]) - (size_t)i);
			free(ptr_stat);
			return (1);
		}
		i++;
	}
	return (0);
}

static int	get_return_value(char **stat, char **line)
{
	if (*stat == NULL)
		return (0);
	if (get_line_from_stat(&*stat, &*line))
		return (1);
	else
	{
		if (ft_strchr(*stat, '\n'))
		{
			if (!(*line = ft_strsub(*stat, 0, ft_strlen(*stat) - 1)))
				return (0);
		}
		else if (!(*line = ft_strsub(*stat, 0, ft_strlen(*stat))))
			return (0);
		ft_strdel(&*stat);
		if (**line != '\0')
			return (1);
	}
	return (0);
}

static int	get_lines(int fd, char *stat[fd], char **line)
{
	char	*ptr_stat;
	char	*buff;
	int		ret;

	if (!(buff = ft_strnew(BUFF_SIZE)))
		return (0);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		ptr_stat = stat[fd];
		if (ret < 0)
			return (-1);
		if (!stat[fd])
		{
			if (!(stat[fd] = ft_strdup(buff)))
				return (0);
		}
		else if (!(stat[fd] = ft_strjoin(stat[fd], buff)))
			return (0);
		free(ptr_stat);
	}
	free(buff);
	return (get_return_value(&stat[fd], &*line));
}

int			get_next_line(const int fd, char **line)
{
	static char	*stat[4096];

	if (fd > 4096 || fd < 0 || !line || read(fd, 0, 0) || BUFF_SIZE < 1)
		return (-1);
	*line = NULL;
	return (get_lines(fd, &stat[fd], &*line));
}

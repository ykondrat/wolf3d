/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_get_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykondrat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 17:30:25 by ykondrat          #+#    #+#             */
/*   Updated: 2017/10/27 12:42:30 by ykondrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf_header.h"

static void		wolf_map_validation(char *line, int x)
{
	int		i;

	i = 0;
	if (line[0] <= '0' || line[ft_strlen(line) - 1] <= '0')
		wolf_file_error();
	if (x == 0 || x == 39)
		while (line[i])
			if (line[i++] == '0' || line[i++] == '7')
				wolf_file_error();
	while (line[i])
	{
		if (line[i] < '0' || line[i] > '7')
			wolf_file_error();
		i++;
	}
	if (i != 40)
		wolf_file_error();
}

void			wolf_get_map(char map[MX][MY], char *file)
{
	t_int	i;
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	wolf_error_fd(fd);
	i.x = 0;
	while (get_next_line(fd, &line) == 1)
	{
		i.y = 0;
		wolf_map_validation(line, i.x);
		while (line[i.y])
		{
			map[i.x][i.y] = line[i.y];
			i.y++;
		}
		free(line);
		i.x++;
	}
	free(line);
	if (close(fd) == -1)
		wolf_close_error();
}

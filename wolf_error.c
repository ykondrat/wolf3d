/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykondrat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 17:26:37 by ykondrat          #+#    #+#             */
/*   Updated: 2017/03/14 17:29:19 by ykondrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf_header.h"

void	wolf_error_argc(int argc)
{
	if (argc != 2)
	{
		ft_putendl("\033[31;01musage: ./wolf3d [file_name]");
		ft_putstr("\033[31;01m\t~[file_name]");
		ft_putendl(" is a file with map for wolfenstein game");
		ft_putendl("\033[31;01m\t~choose only one file");
		exit(0);
	}
}

void	wolf_error(char *str)
{
	ft_putstr("\033[31;01merror with: ");
	ft_putendl(str);
	exit(0);
}

void	wolf_error_fd(int fd)
{
	if (fd < 0)
	{
		ft_putstr("\033[31;01mopen() ");
		ft_putendl("error with map (check file and direction of it)");
		exit(0);
	}
}

void	wolf_file_error(void)
{
	ft_putendl("\033[31;01merror: file not valid");
	ft_putendl("\033[31;01m\tcheck that your map 40x40 size");
	ft_putendl("\033[31;01m\tall of the borders != 0");
	ft_putendl("\033[31;01m\tand texture >= 0 || texture <= 6");
	exit(0);
}

void	wolf_close_error(void)
{
	ft_putendl("\033[31;01mclose() error with map");
	exit(0);
}

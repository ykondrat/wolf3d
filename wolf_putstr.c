/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_putstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykondrat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 17:29:40 by ykondrat          #+#    #+#             */
/*   Updated: 2017/03/14 17:29:45 by ykondrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf_header.h"

void	wolf_putstr(void)
{
	ft_putchar('\n');
	ft_putendl("\033[32;01m**********Wolfenstein 3D**********");
	ft_putchar('\n');
	ft_putstr("\033[31;01m\t1 ~");
	ft_putendl("\033[32;01m move forward \033[33;01m\tW\n");
	ft_putstr("\033[31;01m\t2 ~");
	ft_putendl("\033[32;01m move back \033[33;01m\t\tS\n");
	ft_putstr("\033[31;01m\t3 ~");
	ft_putendl("\033[32;01m rotate left \033[33;01m\tA\n");
	ft_putstr("\033[31;01m\t4 ~");
	ft_putendl("\033[32;01m rotate right \033[33;01m\tD\n");
	ft_putstr("\033[31;01m\t5 ~");
	ft_putendl("\033[32;01m open door \033[33;01m\t\tE\n");
	ft_putchar('\n');
	ft_putendl("\033[32;01m**********************************");
	ft_putchar('\n');
}

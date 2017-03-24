/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykondrat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 17:34:16 by ykondrat          #+#    #+#             */
/*   Updated: 2017/03/14 17:57:32 by ykondrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf_header.h"

static void	wolf_open_door(t_mlx *mlx)
{
	t_flt	i;

	i.x = mlx->x0 + cos(mlx->a) * 0.9;
	i.y = mlx->y0 + sin(mlx->a) * 0.9;
	if ((int)i.x > 0 && (int)i.x < MX - 1 && (int)i.y > 0 && (int)i.y < MY - 1
		&& mlx->map[(int)i.x][(int)i.y] == '7')
	{
		mlx->map[(int)i.x][(int)i.y] = '0';
		wolf_start_draw(mlx);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->screen.img, 0, 0);
	}
}

static void	wolf_moove(t_mlx *mlx, int f)
{
	t_flt	i;

	i.x = mlx->x0 + f * cos(mlx->a) * 0.15;
	i.y = mlx->y0 + f * sin(mlx->a) * 0.15;
	if (mlx->map[(int)i.x][(int)i.y] != '0')
	{
		if (mlx->map[(int)mlx->x0][(int)i.y] == '0')
			mlx->y0 = i.y;
		else if (mlx->map[(int)i.x][(int)mlx->y0] == '0')
			mlx->x0 = i.x;
	}
	else
	{
		mlx->x0 = i.x;
		mlx->y0 = i.y;
	}
}

int			wolf_exit_x(void *params)
{
	params = NULL;
	exit(1);
	return (0);
}

int			wolf_key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
		exit(1);
	if (keycode == 14)
		wolf_open_door(mlx);
	if (keycode == 13)
		wolf_moove(mlx, 1);
	if (keycode == 1)
		wolf_moove(mlx, -1);
	if (keycode == 0)
		mlx->a += (mlx->a + 0.1 > 2 * M_PI ? -2 * M_PI + 0.1 : 0.1);
	if (keycode == 2)
		mlx->a += (mlx->a - 0.1 < -2 * M_PI ? 2 * M_PI - 0.1 : -0.1);
	wolf_start_draw(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->screen.img, 0, 0);
	return (0);
}

int			wolf_expose(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->screen.img, 0, 0);
	return (0);
}

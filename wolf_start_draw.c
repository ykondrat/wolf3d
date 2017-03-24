/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_start_draw.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykondrat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 17:35:05 by ykondrat          #+#    #+#             */
/*   Updated: 2017/03/15 11:23:00 by ykondrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf_header.h"

static float	wolf_set_zx(t_mlx *mlx, t_flt vec)
{
	t_int	i;
	t_flt	z;

	z.x = WIDTH * 4 + HEIGHT * 4;
	i.x = 0;
	while (i.x < MX)
	{
		if (vec.x < 0)
			i.z = -1;
		else
			i.z = 0;
		z.y = (i.x - mlx->x0) / vec.x;
		i.y = mlx->y0 + z.y * vec.y;
		if (z.y >= 0 && i.y >= 0 && i.y < MY
				&& mlx->map[i.x + i.z][i.y] != '0' && z.y < z.x)
			z.x = z.y;
		i.x++;
	}
	return (z.x);
}

static float	wolf_set_zy(t_mlx *mlx, t_flt vec)
{
	t_int	i;
	t_flt	z;

	z.y = WIDTH * 4 + HEIGHT * 4;
	i.y = 0;
	while (i.y < MY)
	{
		if (vec.y < 0)
			i.z = -1;
		else
			i.z = 0;
		z.x = (i.y - mlx->y0) / vec.y;
		i.x = mlx->x0 + z.x * vec.x;
		if (z.x >= 0 && i.x >= 0 && i.x < MX
				&& mlx->map[i.x][i.y + i.z] != '0' && z.x < z.y)
			z.y = z.x;
		i.y++;
	}
	return (z.y);
}

static void		wolf_set_pos(int xs, t_flt vec, t_int *a)
{
	if (xs == 1 && vec.x < 0)
		a->x = -1;
	else
		a->x = 0;
	if (xs == 0 && vec.y < 0)
		a->y = -1;
	else
		a->y = 0;
}

static void		wolf_search_side_z(t_mlx *mlx, int x, t_flt vec)
{
	int		xs;
	t_flt	pos;
	t_flt	z;
	t_int	a;

	mlx->z = wolf_set_zx(mlx, vec);
	if (mlx->z > (z.y = wolf_set_zy(mlx, vec)))
	{
		mlx->z = z.y;
		xs = 0;
	}
	else
		xs = 1;
	wolf_set_pos(xs, vec, &a);
	pos.x = mlx->x0 + mlx->z * vec.x - (int)(mlx->x0 + mlx->z * vec.x);
	pos.y = mlx->y0 + mlx->z * vec.y - (int)(mlx->y0 + mlx->z * vec.y);
	mlx->current = mlx->wall[
		mlx->map[(int)(mlx->x0 + mlx->z * vec.x + a.x)]
		[(int)(mlx->y0 + mlx->z * vec.y + a.y)] - '1'];
	if (xs)
		wolf_set_texture(mlx, x, HEIGHT / (2 * mlx->z), pos.y);
	else
		wolf_set_texture(mlx, x, HEIGHT / (2 * mlx->z), pos.x);
}

void			wolf_start_draw(t_mlx *mlx)
{
	int		x;
	t_flt	a;
	t_flt	vec;

	x = 0;
	while (x < WIDTH)
	{
		a.y = 1.0 * (WIDTH / 2 - x) / WIDTH;
		a.x = 0.5 * cos(mlx->a) - a.y * sin(mlx->a) + mlx->x0;
		a.y = 0.5 * sin(mlx->a) + a.y * cos(mlx->a) + mlx->y0;
		vec.x = a.x - mlx->x0;
		vec.y = a.y - mlx->y0;
		wolf_search_side_z(mlx, x, vec);
		x++;
	}
}

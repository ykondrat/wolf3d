/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_set_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykondrat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 17:32:08 by ykondrat          #+#    #+#             */
/*   Updated: 2017/03/15 17:32:35 by ykondrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf_header.h"

static void	wolf_pixel_put(t_mlx *mlx, int x, int y, int f)
{
	int	i;
	int	dest;

	dest = y * mlx->screen.size + x * mlx->screen.bpp;
	i = 0;
	while (i < mlx->screen.bpp)
	{
		if (f)
			mlx->screen.data[dest + i] = (char)ft_atoi_base("222222", 16);
		else
			mlx->screen.data[dest + i] = (char)ft_atoi_base("000000", 16);
		i++;
	}
}

static void	wolf_put_texture(t_mlx *mlx, t_img *img, t_int pos, t_int wall)
{
	int	i;
	int	src;
	int	dest;

	src = wall.y * img->size + wall.x * img->bpp;
	dest = pos.y * mlx->screen.size + pos.x * mlx->screen.bpp;
	i = 0;
	while (i < img->bpp)
	{
		mlx->screen.data[dest + i] = img->data[src + i];
		i++;
	}
}

void		wolf_set_texture(t_mlx *mlx, int x, int ws, float posx)
{
	t_int	pos;
	t_int	wall;
	float	min;
	float	max;

	pos.x = x;
	pos.y = 0;
	min = HEIGHT / 2.0 - ws;
	max = HEIGHT / 2.0 + ws;
	while (pos.y < HEIGHT)
	{
		wall.x = posx * mlx->current.x;
		wall.y = ((float)(pos.y - min) / (max - min)) * mlx->current.y;
		if (pos.y < min)
			wolf_pixel_put(mlx, pos.x, pos.y, 0);
		else if (pos.y < max)
			wolf_put_texture(mlx, &mlx->current, pos, wall);
		else
			wolf_pixel_put(mlx, pos.x, pos.y, 1);
		pos.y++;
	}
}

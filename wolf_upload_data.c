/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_upload_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykondrat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 17:36:38 by ykondrat          #+#    #+#             */
/*   Updated: 2017/10/27 12:21:03 by ykondrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf_header.h"

static void	wolf_get_img(t_mlx *mlx, t_img *img, char *path)
{
	img->img = mlx_xpm_file_to_image(mlx->mlx, path, &img->x, &img->y);
	img->data = mlx_get_data_addr(img->img, &img->bpp, &img->size,
			&img->endian);
	img->bpp = img->bpp >> 3;
}

static void	wolf_load_wall(t_mlx *mlx)
{
	wolf_get_img(mlx, &mlx->wall[0], "img/redbrick.xpm");
	wolf_get_img(mlx, &mlx->wall[1], "img/greystone.xpm");
	wolf_get_img(mlx, &mlx->wall[2], "img/colorstone.xpm");
	wolf_get_img(mlx, &mlx->wall[3], "img/eagle.xpm");
	wolf_get_img(mlx, &mlx->wall[4], "img/mossy.xpm");
	wolf_get_img(mlx, &mlx->wall[5], "img/bluestone.xpm");
	wolf_get_img(mlx, &mlx->wall[6], "img/door.xpm");
}

void		wolf_upload_data(t_mlx *mlx, char *file)
{
	mlx->x0 = 35;
	mlx->y0 = 3;
	mlx->a = 0;
	mlx->screen.img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	mlx->screen.data = mlx_get_data_addr(mlx->screen.img, &mlx->screen.bpp,
			&mlx->screen.size, &mlx->screen.endian);
	mlx->screen.bpp = mlx->screen.bpp >> 3;
	wolf_load_wall(mlx);
	wolf_get_map(mlx->map, file);
}

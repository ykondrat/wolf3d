/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykondrat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 17:29:57 by ykondrat          #+#    #+#             */
/*   Updated: 2017/03/14 17:38:49 by ykondrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf_header.h"

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	wolf_error_argc(argc);
	if (!(mlx.mlx = mlx_init()))
		wolf_error("mlx_init.");
	if (!(mlx.win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, "Wolfenstein 3D")))
		wolf_error("mlx_new_window.");
	wolf_upload_data(&mlx, argv[argc - 1]);
	wolf_putstr();
	wolf_start_draw(&mlx);
	mlx_expose_hook(mlx.win, &wolf_expose, &mlx);
	mlx_hook(mlx.win, 2, 1, &wolf_key_hook, &mlx);
	mlx_hook(mlx.win, 17, 1L << 17, wolf_exit_x, NULL);
	mlx_loop(mlx.mlx);
	return (0);
}

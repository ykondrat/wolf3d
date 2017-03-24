/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_header.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykondrat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 17:30:40 by ykondrat          #+#    #+#             */
/*   Updated: 2017/03/15 17:32:53 by ykondrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_HEADER_H
# define WOLF_HEADER_H
# define WIDTH 1024
# define HEIGHT 768
# define MX 40
# define MY 40
# include <mlx.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <unistd.h>

typedef struct		s_flt
{
	float			x;
	float			y;
	float			z;
}					t_flt;
typedef struct		s_int
{
	int				x;
	int				y;
	int				z;
}					t_int;
typedef struct		s_img
{
	void			*img;
	char			*data;
	int				x;
	int				y;
	int				bpp;
	int				size;
	int				endian;
}					t_img;
typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	char			map[MX][MY];
	t_img			screen;
	t_img			wall[8];
	t_img			current;
	float			a;
	float			x0;
	float			y0;
	float			z;
}					t_mlx;
void				wolf_error_argc(int argc);
void				wolf_error_fd(int fd);
void				wolf_error(char *str);
void				wolf_file_error(void);
void				wolf_close_error(void);
void				wolf_upload_data(t_mlx *mlx, char *file);
void				wolf_putstr(void);
void				wolf_get_map(char map[MX][MY], char *file);
void				wolf_start_draw(t_mlx *mlx);
void				wolf_set_texture(t_mlx *mlx, int x, int ws, float posx);
int					wolf_key_hook(int keycode, t_mlx *mlx);
int					wolf_expose(t_mlx *mlx);
int					wolf_exit_x(void *params);

#endif

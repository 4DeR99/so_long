/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_open_window.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 19:02:27 by moulmado          #+#    #+#             */
/*   Updated: 2022/01/12 18:15:43 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	key_hook(int keycode, t_vars *mlx)
{
	if (keycode == 53)
		exit(1);
	if (keycode == 2)
		mlx_loop_hook(mlx->mlx, running_right, mlx);
	if (keycode == 0)
		mlx_loop_hook(mlx->mlx, running_left, mlx);
	printf("%d\n", keycode);
	return (0);
}

static int	standing(int keycode, t_vars *mlx)
{
	if (keycode == 2)
		mlx_loop_hook(mlx->mlx, standing_right, mlx);
	if (keycode == 0)
		mlx_loop_hook(mlx->mlx, standing_left, mlx);
	return (0);
}

static void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	open_window(void)
{
	t_vars	mlx;
	t_data	img;
	int		i;
	int		j;

	mlx.player_x = 0;
	mlx.player_y = 0;
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 640, 480, "So_long");
	img.img = mlx_new_image(mlx.mlx, 640, 480);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	i = 0;
	while (i < 480)
	{
		j = 0;
		while (j < 640)
			my_mlx_pixel_put(&img, j++, i, 0x0d1017);
		i++;
	}
	mlx_put_image_to_window(mlx.mlx, mlx.win, img.img, 0, 0);
	mlx_hook(mlx.win, 2, 0, key_hook, &mlx);
	mlx_hook(mlx.win, 3, 0, standing, &mlx);
	mlx_loop_hook(mlx.mlx, standing_right, &mlx);
	mlx_loop(mlx.mlx);
}

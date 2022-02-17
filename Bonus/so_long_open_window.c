/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_open_window.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 19:02:27 by moulmado          #+#    #+#             */
/*   Updated: 2022/02/16 16:30:35 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	key_hook(int keycode, t_vars *mlx)
{
	static int	count;

	if (keycode == 53)
		ft_exit(mlx);
	if (keycode == 2)
		mlx_loop_hook(mlx->mlx, running_right, mlx);
	if (keycode == 0)
		mlx_loop_hook(mlx->mlx, running_left, mlx);
	if (keycode == 13)
		mlx_loop_hook(mlx->mlx, running_up, mlx);
	if (keycode == 1)
		mlx_loop_hook(mlx->mlx, running_down, mlx);
	write(1, "moves : ", 8);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->frames.wall0.img, 70, 0);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->frames.wall0.img, 140, 0);
	mlx_string_put(mlx->mlx, mlx->win, 77, 2, 0xeff2f6, ft_itoa(count));
	ft_putnbr(count++);
	write(1, "\n", 1);
	return (0);
}

static int	standing(int keycode, t_vars *mlx)
{
	if (keycode == 2)
		mlx_loop_hook(mlx->mlx, standing_right, mlx);
	if (keycode == 0)
		mlx_loop_hook(mlx->mlx, standing_left, mlx);
	if (keycode == 13)
		mlx_loop_hook(mlx->mlx, standing_back, mlx);
	if (keycode == 1)
		mlx_loop_hook(mlx->mlx, standing_front, mlx);
	return (0);
}

static void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	put_background(t_vars *mlx)
{
	t_data	img;
	int		i;
	int		j;

	img.img = mlx_new_image(mlx->mlx, mlx->win_width, mlx->win_height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	i = 0;
	while (i < mlx->win_height)
	{
		j = 0;
		while (j < mlx->win_width)
			my_mlx_pixel_put(&img, j++, i, 0x161b26);
		i++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, img.img, 0, 0);
}

void	open_window(t_vars *mlx)
{
	get_info(mlx);
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, mlx->win_width,
			mlx->win_height, "So_long");
	get_imgs(mlx);
	put_background(mlx);
	put_elements(mlx);
	mlx_string_put(mlx->mlx, mlx->win, 2, 2, 0xeff2f6, "moves: ");
	mlx_string_put(mlx->mlx, mlx->win, 77, 2, 0xeff2f6, "0");
	put_exit(mlx);
	mlx_hook(mlx->win, 2, 0, key_hook, mlx);
	mlx_hook(mlx->win, 3, 0, standing, mlx);
	mlx_hook(mlx->win, 17, 0, ft_exit, mlx);
	mlx_loop_hook(mlx->mlx, standing_right, mlx);
	mlx_loop(mlx->mlx);
}

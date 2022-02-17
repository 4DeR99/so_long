/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_put_walls.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 00:59:07 by moulmado          #+#    #+#             */
/*   Updated: 2022/02/15 21:06:56 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	put_horizontal_walls(t_vars *mlx, char path, int height)
{
	int		i;
	t_img	img;

	if (path == '0')
		img = mlx->frames.wall0;
	if (path == '1')
		img = mlx->frames.wall1;
	i = (mlx->win_width / 70);
	while (i > 0)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win, img.img, i * 70, height);
		i--;
	}
}

static void	put_vertical_walls(t_vars *mlx, char path, int width)
{
	int		i;
	t_img	img;

	if (path == '2')
		img = mlx->frames.wall2;
	if (path == '3')
		img = mlx->frames.wall3;
	i = (mlx->win_height / 70);
	while (i > 0)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win, img.img, width, i * 70);
		i--;
	}
}

static void	put_corners(t_vars *mlx, char path, int width, int height)
{
	t_img	img;

	if (path == '0')
		img = mlx->frames.corner0;
	if (path == '1')
		img = mlx->frames.corner1;
	if (path == '2')
		img = mlx->frames.corner2;
	if (path == '3')
		img = mlx->frames.corner3;
	mlx_put_image_to_window(mlx->mlx, mlx->win, img.img, width, height);
}

void	put_walls(t_vars *mlx)
{
	put_horizontal_walls(mlx, '0', 0);
	put_horizontal_walls(mlx, '1',
		mlx->win_height - 70);
	put_vertical_walls(mlx, '2', 0);
	put_vertical_walls(mlx, '3', mlx->win_width - 70);
	put_corners(mlx, '0', 0, 0);
	put_corners(mlx, '1', mlx->win_width - 70, 0);
	put_corners(mlx, '2', 0, mlx->win_height - 70);
	put_corners(mlx, '3',
		mlx->win_width - 70, mlx->win_height - 70);
}

void	put_mid_wall(t_vars *mlx)
{
	int		i;

	i = 0;
	while (mlx->w_position[i])
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->frames.mid_wall_1.img,
			mlx->w_position[i][0], mlx->w_position[i][1]);
		i++;
	}
}

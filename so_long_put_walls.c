/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_put_walls.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 00:59:07 by moulmado          #+#    #+#             */
/*   Updated: 2022/01/17 16:38:25 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_horizontal_walls(t_vars *mlx, char *path, int height)
{
	int		i;
	t_img	img;

	img.img = mlx_xpm_file_to_image(mlx->mlx, path,
			&img.img_width, &img.img_height);
	i = (mlx->win_width / 70);
	while (i > 0)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win, img.img, i * 70, height);
		i--;
	}
}

static void	put_vertical_walls(t_vars *mlx, char *path, int width)
{
	int		i;
	t_img	img;

	img.img = mlx_xpm_file_to_image(mlx->mlx, path,
			&img.img_width, &img.img_height);
	i = (mlx->win_height / 70);
	while (i > 0)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win, img.img, width, i * 70);
		i--;
	}
}

static void	put_corners(t_vars *mlx, char *path, int width, int height)
{
	t_img	img;

	img.img = mlx_xpm_file_to_image(mlx->mlx, path,
			&img.img_width, &img.img_height);
	mlx_put_image_to_window(mlx->mlx, mlx->win, img.img, width, height);
}

void	put_walls(t_vars *mlx)
{
	put_horizontal_walls(mlx, "xpm files/walls/wall0.xpm", 0);
	put_horizontal_walls(mlx, "xpm files/walls/wall1.xpm",
		mlx->win_height - 70);
	put_vertical_walls(mlx, "xpm files/walls/wall2.xpm", 0);
	put_vertical_walls(mlx, "xpm files/walls/wall3.xpm", mlx->win_width - 70);
	put_corners(mlx, "xpm files/corners/corner0.xpm", 0, 0);
	put_corners(mlx, "xpm files/corners/corner1.xpm", mlx->win_width - 70, 0);
	put_corners(mlx, "xpm files/corners/corner2.xpm", 0, mlx->win_height - 70);
	put_corners(mlx, "xpm files/corners/corner3.xpm",
		mlx->win_width - 70, mlx->win_height - 70);
}

void	put_mid_wall(t_vars *mlx)
{
	int		i;
	t_img	img;

	i = 0;
	img.img = mlx_xpm_file_to_image(mlx->mlx, "xpm files/mid_wall_1.xpm",
			&img.img_width, &img.img_width);
	while (mlx->w_position[i])
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win, img.img,
			mlx->w_position[i][0], mlx->w_position[i][1]);
		i++;
	}
}

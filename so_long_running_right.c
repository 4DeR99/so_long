/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_running_right.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:13:02 by moulmado          #+#    #+#             */
/*   Updated: 2022/01/12 18:14:12 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	running_right(t_vars *mlx)
{
	static int	i;
	static int	j;
	t_img	img;

	mlx->player_x += 3;
	if (i == 6)
	{
		i = 0;
		j = 0;
	}
	if (j == 5)
	{
		i++;
		j = 0;
	}
	if (i == 0)
		img.img = mlx_xpm_file_to_image(mlx->mlx, "xpm files/running_right/running_right0.xpm", &img.img_width, &img.img_height);
	if (i == 1)
		img.img = mlx_xpm_file_to_image(mlx->mlx, "xpm files/running_right/running_right1.xpm", &img.img_width, &img.img_height);
	if (i == 2)
		img.img = mlx_xpm_file_to_image(mlx->mlx, "xpm files/running_right/running_right2.xpm", &img.img_width, &img.img_height);
	if (i == 3)
		img.img = mlx_xpm_file_to_image(mlx->mlx, "xpm files/running_right/running_right3.xpm", &img.img_width, &img.img_height);
	if (i == 4)
		img.img = mlx_xpm_file_to_image(mlx->mlx, "xpm files/running_right/running_right4.xpm", &img.img_width, &img.img_height);
	if (i == 5)
		img.img = mlx_xpm_file_to_image(mlx->mlx, "xpm files/running_right/running_right5.xpm", &img.img_width, &img.img_height);
	mlx_put_image_to_window(mlx->mlx, mlx->win, img.img, mlx->player_x, mlx->player_y);
	j++;
	return (0);
}
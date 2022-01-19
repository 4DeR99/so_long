/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_standing_right.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:37:52 by moulmado          #+#    #+#             */
/*   Updated: 2022/01/19 21:01:58 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	util(t_vars *mlx, t_img *img, int *i)
{
	if (*i == 0)
		img->img = mlx_xpm_file_to_image(mlx->mlx,
				"xpm files/standing_right/standing_right0.xpm",
				&img->img_width, &img->img_height);
	if (*i == 1)
		img->img = mlx_xpm_file_to_image(mlx->mlx,
				"xpm files/standing_right/standing_right1.xpm",
				&img->img_width, &img->img_height);
	if (*i == 2)
		img->img = mlx_xpm_file_to_image(mlx->mlx,
				"xpm files/standing_right/standing_right2.xpm",
				&img->img_width, &img->img_height);
	if (*i == 3)
		img->img = mlx_xpm_file_to_image(mlx->mlx,
				"xpm files/standing_right/standing_right3.xpm",
				&img->img_width, &img->img_height);
}

int	standing_right(t_vars *mlx)
{
	static int	i;
	static int	j;
	t_img		img;

	if (i == 6)
	{
		i = 0;
		j = 0;
	}
	if (j == 15)
	{
		i++;
		j = 0;
	}
	util(mlx, &img, &i);
	mlx_put_image_to_window(mlx->mlx, mlx->win, img.img,
		mlx->player_x, mlx->player_y);
	j++;
	return (0);
}

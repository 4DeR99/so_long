/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_running_up.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 15:51:10 by moulmado          #+#    #+#             */
/*   Updated: 2022/01/19 21:01:48 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	util(t_vars *mlx, t_img *img, int *i)
{
	if (*i == 0)
		img->img = mlx_xpm_file_to_image(mlx->mlx,
				"xpm files/running_up/running_up0.xpm",
				&img->img_width, &img->img_height);
	if (*i == 1)
		img->img = mlx_xpm_file_to_image(mlx->mlx,
				"xpm files/running_up/running_up1.xpm",
				&img->img_width, &img->img_height);
	if (*i == 2)
		img->img = mlx_xpm_file_to_image(mlx->mlx,
				"xpm files/running_up/running_up2.xpm",
				&img->img_width, &img->img_height);
	if (*i == 3)
		img->img = mlx_xpm_file_to_image(mlx->mlx,
				"xpm files/running_up/running_up3.xpm",
				&img->img_width, &img->img_height);
}

int	running_up(t_vars *mlx)
{
	static int	i;
	static int	j;
	static int	c;
	t_img		img;

	if (check_next_position_v(mlx, mlx->player_y - 2, 'U'))
		mlx->player_y -= 2;
	if (i == 4)
	{
		i = 0;
		j = 0;
	}
	if (j == 10)
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

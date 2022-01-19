/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_put_collectibles.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:51:16 by moulmado          #+#    #+#             */
/*   Updated: 2022/01/19 20:44:54 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	util(t_vars *mlx, t_img *img, int *i)
{
	if (*i == 0)
		img->img = mlx_xpm_file_to_image(mlx->mlx,
				"xpm files/meat/meat0.xpm",
				&img->img_width, &img->img_height);
	if (*i == 1)
		img->img = mlx_xpm_file_to_image(mlx->mlx,
				"xpm files/meat/meat1.xpm",
				&img->img_width, &img->img_height);
	if (*i == 2)
		img->img = mlx_xpm_file_to_image(mlx->mlx,
				"xpm files/meat/meat2.xpm",
				&img->img_width, &img->img_height);
}

int	collectibles(t_vars *mlx)
{
	static int	i;
	static int	j;
	int			c;
	t_img		img;

	c = 0;
	if (i == 2)
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
	while (mlx->c_position[c])
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win, img.img,
			mlx->c_position[c][0], mlx->c_position[c][1]);
			c++;
	}
	j++;
	return (0);
}

// void	put_collectibles(t_vars *mlx)
// {
// 	mlx_loop_hook(mlx->mlx, collectibles, mlx);
// }

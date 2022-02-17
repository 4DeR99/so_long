/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_put_collectibles.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:51:16 by moulmado          #+#    #+#             */
/*   Updated: 2022/02/15 20:54:56 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	remove_collectible(t_vars *mlx, int c)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->frames.background.img,
		mlx->c_position[c][0], mlx->c_position[c][1]);
}

static void	util(t_vars *mlx, t_img *img, int *i)
{
	int	c;

	c = 0;
	if (*i == 0)
		*img = mlx->frames.meat0;
	if (*i == 1)
		*img = mlx->frames.meat1;
	if (*i == 2)
		*img = mlx->frames.meat2;
	while (mlx->c_position[c])
	{
		if (mlx->c_position[c][2] != 'X')
			mlx_put_image_to_window(mlx->mlx, mlx->win, img->img,
				mlx->c_position[c][0], mlx->c_position[c][1]);
		else
			remove_collectible(mlx, c);
		c++;
	}
}

int	collectibles(t_vars *mlx)
{
	static int	i;
	static int	j;
	t_img		img;

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
	j++;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_standing_right.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:37:52 by moulmado          #+#    #+#             */
/*   Updated: 2022/02/16 14:04:40 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	util(t_vars *mlx, t_img *img, int *i)
{
	if (*i == 0)
		*img = mlx->frames.standing_right0;
	if (*i == 1)
		*img = mlx->frames.standing_right1;
	if (*i == 2)
		*img = mlx->frames.standing_right2;
	if (*i == 3)
		*img = mlx->frames.standing_right3;
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
	collectibles(mlx);
	enemy(mlx);
	util(mlx, &img, &i);
	mlx_put_image_to_window(mlx->mlx, mlx->win, img.img,
		mlx->player_x, mlx->player_y);
	j++;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_running_right.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:13:02 by moulmado          #+#    #+#             */
/*   Updated: 2022/02/15 20:54:56 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	util(t_vars *mlx, t_img *img, int *i)
{
	if (*i == 0)
		*img = mlx->frames.running_right0;
	if (*i == 1)
		*img = mlx->frames.running_right1;
	if (*i == 2)
		*img = mlx->frames.running_right2;
	if (*i == 3)
		*img = mlx->frames.running_right3;
	if (*i == 4)
		*img = mlx->frames.running_right4;
	if (*i == 5)
		*img = mlx->frames.running_right5;
}

int	running_right(t_vars *mlx)
{
	static int	i;
	static int	j;
	t_img		img;

	if (check_next_position_h(mlx, (mlx->player_x + 2 + 50), 'R')
		&& check_next_position_4exit_h(mlx, (mlx->player_x + 2 + 50), 'R'))
		mlx->player_x += 2;
	check_next_position_4c_h(mlx, (mlx->player_x + 2 + 50), 'R');
	if (i == 6)
	{
		i = 0;
		j = 0;
	}
	if (j == 6)
	{
		i++;
		j = 0;
	}
	util(mlx, &img, &i);
	collectibles(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, img.img,
		mlx->player_x, mlx->player_y);
	j++;
	return (0);
}

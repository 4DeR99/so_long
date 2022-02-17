/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_running_left.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:59:10 by moulmado          #+#    #+#             */
/*   Updated: 2022/02/15 21:06:56 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	util(t_vars *mlx, t_img *img, int *i)
{
	wasted_h(mlx, mlx->player_x - 2, 'L');
	if (*i == 0)
		*img = mlx->frames.running_left0;
	if (*i == 1)
		*img = mlx->frames.running_left1;
	if (*i == 2)
		*img = mlx->frames.running_left2;
	if (*i == 3)
		*img = mlx->frames.running_left3;
	if (*i == 4)
		*img = mlx->frames.running_left4;
	if (*i == 5)
		*img = mlx->frames.running_left5;
}

int	running_left(t_vars *mlx)
{
	static int	i;
	static int	j;
	t_img		img;

	if (check_next_position_h(mlx, mlx->player_x - 2, 'L')
		&& check_next_position_4exit_h(mlx, mlx->player_x - 2, 'L'))
		mlx->player_x -= 2;
	check_next_position_4c_h(mlx, mlx->player_x - 2, 'L');
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
	enemy(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, img.img,
		mlx->player_x, mlx->player_y);
	j++;
	return (0);
}

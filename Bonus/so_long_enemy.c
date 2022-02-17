/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_enemy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 15:31:13 by moulmado          #+#    #+#             */
/*   Updated: 2022/02/15 21:06:56 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	util(t_vars *mlx, int *i)
{
	t_img	img;
	int		d ;

	if (*i == 0)
		img = mlx->frames.enemy0;
	if (*i == 1)
		img = mlx->frames.enemy1;
	if (*i == 2)
		img = mlx->frames.enemy2;
	d = 0;
	while (mlx->x_position[d])
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win, img.img,
			mlx->x_position[d][0], mlx->x_position[d][1]);
		d++;
	}
}

static void	move(t_vars *mlx, int d)
{
	static int	r[1000000];

	if (r[d] == 0 && check_next_position_e(mlx,
			(mlx->x_position[d][0] + 2 + 70), 'R', d)
			&& check_next_position_4exit_e(mlx,
			(mlx->x_position[d][0] + 2 + 70), 'R', d)
			&& check_next_position_4c_e(mlx,
			(mlx->x_position[d][0] + 2 + 70), 'R', d))
	{
		wasted_e_h(mlx, (mlx->x_position[d][0] + 2 + 70), 'R', d);
		mlx->x_position[d][0] += 2;
	}
	else
		r[d] = 1;
	if (r[d] == 1 && check_next_position_e(mlx, (mlx->x_position[d][0] - 2),
		'L', d) && check_next_position_4exit_e(mlx, (mlx->x_position[d][0] - 2),
		'L', d) && check_next_position_4c_e(mlx, (mlx->x_position[d][0] - 2),
		'L', d))
	{
		wasted_e_h(mlx, (mlx->x_position[d][0] - 2), 'L', d);
		mlx->x_position[d][0] -= 2;
	}
	else
		r[d] = 0;
}

int	enemy(t_vars *mlx)
{
	static int	i;
	static int	j;
	int			d;

	d = 0;
	while (mlx->x_position[d])
	{
		move(mlx, d);
		d++;
	}
	if (i == 3)
	{
		i = 0;
		j = 0;
	}
	if (j == 10)
	{
		i++;
		j = 0;
	}
	util(mlx, &i);
	j++;
	return (0);
}

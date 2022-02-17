/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_check_nextposition_e.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 13:26:51 by moulmado          #+#    #+#             */
/*   Updated: 2022/02/15 21:06:56 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	check_edge_wall(t_vars *mlx, int next_position)
{
	if (next_position > 70 && next_position < mlx->win_width - 70)
		return (1);
	return (0);
}

static int	util_r(int player_x, int player_y, int **w_p)
{
	int	i;
	int	ret;

	i = 0;
	ret = 1;
	while (ret && w_p[i])
	{
		if ((player_x > w_p[i][0] && player_x < w_p[i][0] + 70)
			&& (player_y == w_p[i][1]))
			ret = 0;
		i++;
	}
	return (ret);
}

static int	util_l(int player_x, int player_y, int **w_p)
{
	int	i;
	int	ret;

	i = 0;
	ret = 1;
	while (ret && w_p[i])
	{
		if ((player_x > w_p[i][0] && player_x < w_p[i][0] + 70)
			&& (player_y == w_p[i][1]))
			ret = 0;
		i++;
	}
	return (ret);
}

static int	check_mid_wall(int **w_p, int player_x, int player_y, char movement)
{
	int	ret;

	if (movement == 'R')
		ret = util_r(player_x, player_y, w_p);
	if (movement == 'L')
		ret = util_l(player_x, player_y, w_p);
	return (ret);
}

int	check_next_position_e(t_vars *mlx, int position, char movement, int i)
{
	int	edge_wall;
	int	mid_wall;

	edge_wall = check_edge_wall(mlx, position);
	mid_wall = check_mid_wall(mlx->w_position, position,
			mlx->x_position[i][1], movement);
	if (!edge_wall || !mid_wall)
		return (0);
	return (1);
}

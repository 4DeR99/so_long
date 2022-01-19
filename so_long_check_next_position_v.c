/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_check_next_position_v.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 10:18:39 by moulmado          #+#    #+#             */
/*   Updated: 2022/01/17 16:36:17 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_edge_wall(t_vars *mlx, int next_position)
{
	if (next_position > 70 && next_position < mlx->win_height - 120)
		return (1);
	return (0);
}

static int	util_u(int player_x, int player_y, int **w_p)
{
	int	i;
	int	ret;

	ret = 1;
	i = 0;
	while (ret && w_p[i])
	{
		if ((((player_y > w_p[i][1] && player_y < w_p[i][1] + 70)
			&& (player_x > w_p[i][0] && player_x < w_p[i][0] + 70))
		|| ((player_y > w_p[i][1] && player_y < w_p[i][1] + 70)
		&& (player_x + 50 > w_p[i][0] && player_x + 50 < w_p[i][0] + 70))))
			ret = 0;
		i++;
	}
	return (ret);
}

static int	util_d(int player_x, int player_y, int **w_p)
{
	int	i;
	int	ret;

	i = 0;
	ret = 1;
	while (ret && w_p[i])
	{
		if ((((player_y + 50 > w_p[i][1] && player_y + 50 < w_p[i][1] + 70)
			&& (player_x > w_p[i][0] && player_x < w_p[i][0] + 70))
		|| ((player_y + 50 > w_p[i][1] && player_y + 50 < w_p[i][1] + 70)
		&& (player_x + 50 > w_p[i][0] && player_x + 50 < w_p[i][0] + 70))))
			ret = 0;
		i++;
	}
	return (ret);
}

static int	check_mid_wall(int **w_p, int player_x, int player_y, char movement)
{
	int	ret;

	if (movement == 'U')
		ret = util_u(player_x, player_y, w_p);
	if (movement == 'D')
		ret = util_d(player_x, player_y, w_p);
	return (ret);
}

int	check_next_position_v(t_vars *mlx, int next_position, char movement)
{
	int	edge_wall;
	int	mid_wall;

	edge_wall = check_edge_wall(mlx, next_position);
	mid_wall = check_mid_wall(mlx->w_position, mlx->player_x,
			next_position, movement);
	if (!edge_wall || !mid_wall)
		return (0);
	return (1);
}

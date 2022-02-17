/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_check_nextposition_4c_e.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 15:13:22 by moulmado          #+#    #+#             */
/*   Updated: 2022/02/15 21:06:56 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	util_r(int player_x, int player_y, int **c_p)
{
	int	i;
	int	ret;

	i = 0;
	ret = 1;
	while (ret && c_p[i])
	{
		if ((player_x > c_p[i][0] && player_x < c_p[i][0] + 70)
			&& player_y == c_p[i][1] && c_p[i][2] != 'X')
			ret = 0;
		i++;
	}
	return (ret);
}

static int	util_l(int player_x, int player_y, int **c_p)
{
	int	i;
	int	ret;

	i = 0;
	ret = 1;
	while (ret && c_p[i])
	{
		if ((player_x > c_p[i][0] && player_x < c_p[i][0] + 70)
			&& player_y == c_p[i][1] && c_p[i][2] != 'X')
			ret = 0;
		i++;
	}
	return (ret);
}

static int	check_4c(t_vars *mlx, int player_x, int player_y, char movement)
{
	int	ret;

	if (movement == 'R')
		ret = util_r(player_x, player_y, mlx->c_position);
	if (movement == 'L')
		ret = util_l(player_x, player_y, mlx->c_position);
	return (ret);
}

int	check_next_position_4c_e(t_vars *mlx, int next, char movement, int i)
{
	if (!check_4c(mlx, next,
			mlx->x_position[i][1], movement))
		return (0);
	return (1);
}

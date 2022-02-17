/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_check_nextposition_4exit_e.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 14:57:52 by moulmado          #+#    #+#             */
/*   Updated: 2022/02/16 12:38:42 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	util_r(int player_x, int player_y, int **e_p)
{
	int	i;
	int	ret;

	i = 0;
	ret = 1;
	while (ret && e_p[i])
	{
		if ((player_x > e_p[i][0] && player_x < e_p[i][0] + 70)
			&& (player_y == e_p[i][1]))
			ret = 0;
		i++;
	}
	return (ret);
}

static int	util_l(int player_x, int player_y, int **e_p)
{
	int	i;
	int	ret;

	i = 0;
	ret = 1;
	while (ret && e_p[i])
	{
		if ((player_x > e_p[i][0] && player_x < e_p[i][0] + 70)
			&& (player_y == e_p[i][1]))
			ret = 0;
		i++;
	}
	return (ret);
}

static int	check_4exit(t_vars *mlx, int player_x, int player_y, char movement)
{
	int	ret;

	if (movement == 'R')
		ret = util_r(player_x, player_y, mlx->e_position);
	if (movement == 'L')
		ret = util_l(player_x, player_y, mlx->e_position);
	return (ret);
}

int	check_next_position_4exit_e(t_vars *mlx, int next, char movement, int i)
{
	int	exit_wall;

	exit_wall = check_4exit(mlx, next,
			mlx->x_position[i][1], movement);
	if (!exit_wall)
		return (0);
	return (1);
}

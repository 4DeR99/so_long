/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_check_next_exit_h.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:23:59 by moulmado          #+#    #+#             */
/*   Updated: 2022/02/07 17:27:52 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	util_r(int player_x, int player_y, int **e_p, t_vars *mlx)
{
	int	i;
	int	ret;

	i = 0;
	ret = 1;
	while (ret && e_p[i])
	{
		if ((((player_x > e_p[i][0] && player_x < e_p[i][0] + 70)
			&& (player_y > e_p[i][1] && player_y < e_p[i][1] + 70))
		|| ((player_x == e_p[i][0] && player_x < e_p[i][0] + 70)
		&& (player_y + 50 > e_p[i][1] && player_y + 50 < e_p[i][1] + 70))))
		{
			if (!mlx->c_count)
			{
				write(1, "YOU WON\n", 8);
				free_all(mlx);
				exit(0);
			}
			else
				ret = 0;
		}
		i++;
	}
	return (ret);
}

static int	util_l(int player_x, int player_y, int **e_p, t_vars *mlx)
{
	int	i;
	int	ret;

	i = 0;
	ret = 1;
	while (ret && e_p[i])
	{
		if ((((player_x > e_p[i][0] && player_x < e_p[i][0] + 70)
			&& (player_y > e_p[i][1] && player_y < e_p[i][1] + 70))
		|| ((player_x > e_p[i][0] && player_x < e_p[i][0] + 70)
		&& (player_y + 50 > e_p[i][1] && player_y + 50 < e_p[i][1] + 70))))
		{
			if (!mlx->c_count)
			{
				write(1, "YOU WON\n", 8);
				free_all(mlx);
				exit(0);
			}
			else
				ret = 0;
		}
		i++;
	}
	return (ret);
}

static int	check_4exit(t_vars *mlx, int player_x, int player_y, char movement)
{
	int	ret;

	if (movement == 'R')
		ret = util_r(player_x, player_y, mlx->e_position, mlx);
	if (movement == 'L')
		ret = util_l(player_x, player_y, mlx->e_position, mlx);
	return (ret);
}

int	check_next_position_4exit_h(t_vars *mlx, int next, char movement)
{
	int	exit_wall;

	exit_wall = check_4exit(mlx, next,
			mlx->player_y, movement);
	if (!exit_wall)
		return (0);
	return (1);
}

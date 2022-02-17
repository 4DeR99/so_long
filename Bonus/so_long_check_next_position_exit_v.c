/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_check_next_position_exit_v.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:08:28 by moulmado          #+#    #+#             */
/*   Updated: 2022/02/17 18:23:27 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	util_u(int player_x, int player_y, int **e_p, t_vars *mlx)
{
	int	i;
	int	ret;

	ret = 1;
	i = 0;
	while (ret && e_p[i])
	{
		if ((((player_y > e_p[i][1] && player_y < e_p[i][1] + 70)
			&& (player_x > e_p[i][0] && player_x < e_p[i][0] + 70))
		|| ((player_y > e_p[i][1] && player_y < e_p[i][1] + 70)
		&& (player_x + 50 > e_p[i][0] && player_x + 50 < e_p[i][0] + 70))))
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

static int	util_d(int player_x, int player_y, int **e_p, t_vars *mlx)
{
	int	i;
	int	ret;

	i = 0;
	ret = 1;
	while (ret && e_p[i])
	{
		if ((((player_y + 50 > e_p[i][1] && player_y + 50 < e_p[i][1] + 70)
			&& (player_x > e_p[i][0] && player_x < e_p[i][0] + 70))
		|| ((player_y + 50 > e_p[i][1] && player_y + 50 < e_p[i][1] + 70)
		&& (player_x + 50 > e_p[i][0] && player_x + 50 < e_p[i][0] + 70))))
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

	if (movement == 'U')
		ret = util_u(player_x, player_y, mlx->e_position, mlx);
	if (movement == 'D')
		ret = util_d(player_x, player_y, mlx->e_position, mlx);
	return (ret);
}

int	check_next_position_4exit_v(t_vars *mlx, int next, char movement)
{
	int	exit_wall;

	exit_wall = check_4exit(mlx, mlx->player_x,
			next, movement);
	if (!exit_wall)
		return (0);
	return (1);
}

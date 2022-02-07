/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_check_next_position_4c_v.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:28:26 by moulmado          #+#    #+#             */
/*   Updated: 2022/02/06 13:05:49 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	util_u(int player_x, int player_y, t_vars *mlx)
{
	int	i;
	int	**c_p;

	c_p = mlx->c_position;
	i = 0;
	while (c_p[i])
	{
		if (c_p[i][2] != 'X')
		{
			if ((((player_y > c_p[i][1] && player_y < c_p[i][1] + 70)
				&& (player_x > c_p[i][0] && player_x < c_p[i][0] + 70))
			|| ((player_y > c_p[i][1] && player_y < c_p[i][1] + 70)
			&& (player_x + 50 > c_p[i][0] && player_x + 50 < c_p[i][0] + 70))))
			{
				c_p[i][2] = 'X';
				mlx->c_count--;
			}
		}
		i++;
	}
}

static void	util_d(int player_x, int player_y, t_vars *mlx)
{
	int	i;
	int	**c_p;

	i = 0;
	c_p = mlx->c_position;
	while (c_p[i])
	{
		if (c_p[i][2] != 'X')
		{
			if ((((player_y + 50 > c_p[i][1] && player_y + 50 < c_p[i][1] + 70)
				&& (player_x > c_p[i][0] && player_x < c_p[i][0] + 70))
			|| ((player_y + 50 > c_p[i][1] && player_y + 50 < c_p[i][1] + 70)
			&& (player_x + 50 > c_p[i][0] && player_x + 50 < c_p[i][0] + 70))))
			{
				c_p[i][2] = 'X';
				mlx->c_count--;
			}
		}
		i++;
	}
}

static void	check_4c(t_vars *mlx, int player_x, int player_y, char movement)
{
	if (movement == 'U')
		util_u(player_x, player_y, mlx);
	if (movement == 'D')
		util_d(player_x, player_y, mlx);
}

void	check_next_position_4c_v(t_vars *mlx, int next_position, char movement)
{
	check_4c(mlx, mlx->player_x,
		next_position, movement);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_wasted_v.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:54:11 by moulmado          #+#    #+#             */
/*   Updated: 2022/02/15 22:01:40 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	util_u(int player_x, int player_y, int **x_p, t_vars *mlx)
{
	int	i;

	i = 0;
	while (x_p[i])
	{
		if ((((player_y > x_p[i][1] && player_y < x_p[i][1] + 70)
			&& (player_x > x_p[i][0] && player_x < x_p[i][0] + 70))
		|| ((player_y > x_p[i][1] && player_y < x_p[i][1] + 70)
		&& (player_x + 50 > x_p[i][0] && player_x + 50 < x_p[i][0] + 70))))
		{
			free_all(mlx);
			write(1, "WASTED\n", 7);
			exit(0);
		}
		i++;
	}
}

static void	util_d(int player_x, int player_y, int **x_p, t_vars *mlx)
{
	int	i;

	i = 0;
	while (x_p[i])
	{
		if (x_p[i][2] != 'X')
		{
			if ((((player_y + 50 > x_p[i][1] && player_y + 50 < x_p[i][1] + 70)
				&& (player_x > x_p[i][0] && player_x < x_p[i][0] + 70))
			|| ((player_y + 50 > x_p[i][1] && player_y + 50 < x_p[i][1] + 70)
			&& (player_x + 50 > x_p[i][0] && player_x + 50 < x_p[i][0] + 70))))
			{
				free_all(mlx);
				write(1, "WASTED\n", 7);
				exit(0);
			}
		}
		i++;
	}
}

static void	check_4c(t_vars *mlx, int player_x, int player_y, char movement)
{
	if (movement == 'U')
		util_u(player_x, player_y, mlx->x_position, mlx);
	if (movement == 'D')
		util_d(player_x, player_y, mlx->x_position, mlx);
}

void	wasted_v(t_vars *mlx, int next_position, char movement)
{
	check_4c(mlx, mlx->player_x,
		next_position, movement);
}

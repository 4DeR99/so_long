/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_wasted_h.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:22:09 by moulmado          #+#    #+#             */
/*   Updated: 2022/02/16 12:43:02 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	util_r(int player_x, int player_y, int **x_p, t_vars *mlx)
{
	int	i;

	i = 0;
	while (x_p[i])
	{
		if ((((player_x > x_p[i][0] && player_x < x_p[i][0] + 70)
			&& (player_y > x_p[i][1] && player_y < x_p[i][1] + 70))
		|| ((player_x > x_p[i][0] && player_x < x_p[i][0] + 70)
		&& (player_y + 50 > x_p[i][1] && player_y + 50 < x_p[i][1] + 70))))
		{
			free_all(mlx);
			write(1, "WASTED\n", 7);
			exit(0);
		}
		i++;
	}
}

static void	util_l(int player_x, int player_y, int **x_p, t_vars *mlx)
{
	int	i;

	i = 0;
	while (x_p[i])
	{
		if ((((player_x > x_p[i][0] && player_x < x_p[i][0] + 70)
			&& (player_y > x_p[i][1] && player_y < x_p[i][1] + 70))
		|| ((player_x > x_p[i][0] && player_x < x_p[i][0] + 70)
		&& (player_y + 50 > x_p[i][1] && player_y + 50 < x_p[i][1] + 70))))
		{
			free_all(mlx);
			write(1, "WASTED\n", 7);
			exit(0);
		}
		i++;
	}
}

static void	check_4c(t_vars *mlx, int player_x, int player_y, char movement)
{
	if (movement == 'R')
		util_r(player_x, player_y, mlx->x_position, mlx);
	if (movement == 'L')
		util_l(player_x, player_y, mlx->x_position, mlx);
}

void	wasted_h(t_vars *mlx, int next_position, char movement)
{
	check_4c(mlx, next_position,
		mlx->player_y, movement);
}

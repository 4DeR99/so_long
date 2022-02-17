/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_wasted_e.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:57:42 by moulmado          #+#    #+#             */
/*   Updated: 2022/02/16 12:42:49 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	util_r(int player_x, int player_y, t_vars *mlx)
{
	if ((((player_x > mlx->player_x && player_x < mlx->player_x + 50)
				&& (player_y > mlx->player_y
					&& player_y < mlx->player_y + 50))
			|| ((player_x > mlx->player_x && player_x < mlx->player_x + 50)
				&& (player_y + 70 > mlx->player_y
					&& player_y + 70 < mlx->player_y + 50))
			|| ((player_x > mlx->player_x && player_x < mlx->player_x + 50)
				&& (player_y + 35 > mlx->player_y
					&& player_y + 35 < mlx->player_y + 50))))
	{
		free_all(mlx);
		write(1, "WASTED\n", 7);
		exit(0);
	}
}

static void	util_l(int player_x, int player_y, t_vars *mlx)
{
	if ((((player_x > mlx->player_x && player_x < mlx->player_x + 50)
				&& (player_y > mlx->player_y
					&& player_y < mlx->player_y + 50))
			|| ((player_x > mlx->player_x && player_x < mlx->player_x + 50)
				&& (player_y + 70 > mlx->player_y
					&& player_y + 70 < mlx->player_y + 50))
			|| ((player_x > mlx->player_x && player_x < mlx->player_x + 50)
				&& (player_y + 35 > mlx->player_y
					&& player_y + 35 < mlx->player_y + 50))))
	{
		free_all(mlx);
		write(1, "WASTED\n", 7);
		exit(0);
	}
}

static void	check_4p(t_vars *mlx, int player_x, int player_y, char movement)
{
	if (movement == 'R')
		util_r(player_x, player_y, mlx);
	if (movement == 'L')
		util_l(player_x, player_y, mlx);
}

void	wasted_e_h(t_vars *mlx, int next, char movement, int i)
{
	check_4p(mlx, next,
		mlx->x_position[i][1], movement);
}

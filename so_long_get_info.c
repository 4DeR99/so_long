/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_get_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:13:42 by moulmado          #+#    #+#             */
/*   Updated: 2022/01/19 20:37:57 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	win_res(t_vars *mlx, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{	
		j = 0;
		while (map[i][j])
			j++;
		i++;
	}
	mlx->win_width = j * SIZE_OF_BOCK;
	mlx->win_height = i * SIZE_OF_BOCK;
}

static void	player_cords(t_vars *mlx, char **map)
{
	int	i;
	int	j;
	int	stop;

	stop = 0;
	i = 0;
	while (!stop && map[i])
	{	
		j = 0;
		while (!stop && map[i][j])
		{
			if (map[i][j] == 'P')
			{
				mlx->player_x = j * SIZE_OF_BOCK + 10;
				mlx->player_y = i * SIZE_OF_BOCK + 10;
				stop = 1;
			}
			j++;
		}
		i++;
	}
}

void	get_info(t_vars *mlx, char **map)
{
	static int	i;

	player_cords(mlx, map);
	win_res(mlx, map);
	walls_position(mlx, map);
	collectibles_position(mlx, map);
}

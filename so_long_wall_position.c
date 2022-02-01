/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_wall_position.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 23:46:57 by moulmado          #+#    #+#             */
/*   Updated: 2022/02/01 15:50:40 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_walls(char **map)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 1;
	while (map[i + 1])
	{
		j = 1;
		while (map[i][j + 1])
		{
			if (map[i][j] == '1')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

static void	ft_allocate(t_vars *mlx, char **map)
{
	int	i;
	int	tabs;

	tabs = count_walls(map);
	mlx->w_position = (int **)malloc((tabs + 1) * sizeof(int *));
	mlx->w_position[tabs] = NULL;
	i = 0;
	while (i < tabs)
	{
		mlx->w_position[i] = (int *)malloc(2 * sizeof(int));
		i++;
	}
}

void	walls_position(t_vars *mlx, char **map)
{
	int			i;
	int			j;
	int			w_i;

	ft_allocate(mlx, map);
	w_i = 0;
	i = 1;
	while (map[i + 1])
	{
		j = 1;
		while (map[i][j + 1])
		{
			if (map[i][j] == '1')
			{
				mlx->w_position[w_i][0] = j * SIZE_OF_BOCK;
				mlx->w_position[w_i][1] = i * SIZE_OF_BOCK;
				w_i++;
			}
			j++;
		}
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_collectibles_position.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 19:05:31 by moulmado          #+#    #+#             */
/*   Updated: 2022/02/01 15:50:40 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_collectibles(char **map)
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
			if (map[i][j] == 'C')
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

	tabs = count_collectibles(map);
	mlx->c_position = (int **)malloc((tabs + 1) * sizeof(int *));
	mlx->c_position[tabs] = NULL;
	i = 0;
	while (i < tabs)
	{
		mlx->c_position[i] = (int *)malloc(2 * sizeof(int));
		i++;
	}
}

void	collectibles_position(t_vars *mlx, char **map)
{
	int			i;
	int			j;
	int			c_i;

	ft_allocate(mlx, map);
	c_i = 0;
	i = 1;
	while (map[i + 1])
	{
		j = 1;
		while (map[i][j + 1])
		{
			if (map[i][j] == 'C')
			{
				mlx->c_position[c_i][0] = j * SIZE_OF_BOCK;
				mlx->c_position[c_i][1] = i * SIZE_OF_BOCK;
				c_i++;
			}
			j++;
		}
		i++;
	}
}

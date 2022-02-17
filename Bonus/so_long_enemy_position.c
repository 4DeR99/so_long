/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_enemy_position.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 15:25:39 by moulmado          #+#    #+#             */
/*   Updated: 2022/02/17 18:10:37 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	count_enemy(t_vars *mlx)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 1;
	while (mlx->map[i + 1])
	{
		j = 1;
		while (mlx->map[i][j + 1])
		{
			if (mlx->map[i][j] == 'X')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

static void	ft_allocate(t_vars *mlx)
{
	int	i;
	int	tabs;

	tabs = count_enemy(mlx);
	mlx->x_position = (int **)malloc((tabs + 1) * sizeof(int *));
	if (!mlx->x_position)
		exit(0);
	mlx->x_position[tabs] = NULL;
	i = 0;
	while (i < tabs)
	{
		mlx->x_position[i] = (int *)malloc(2 * sizeof(int));
		if (!mlx->x_position[i])
			exit(0);
		i++;
	}
}

void	enemy_position(t_vars *mlx)
{
	int			i;
	int			j;
	int			c_i;

	ft_allocate(mlx);
	c_i = 0;
	i = 1;
	while (mlx->map[i + 1])
	{
		j = 1;
		while (mlx->map[i][j + 1])
		{
			if (mlx->map[i][j] == 'X')
			{
				mlx->x_position[c_i][0] = j * SIZE_OF_BOCK;
				mlx->x_position[c_i][1] = i * SIZE_OF_BOCK;
				c_i++;
			}
			j++;
		}
		i++;
	}
}

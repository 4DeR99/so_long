/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_wall_position.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 23:46:57 by moulmado          #+#    #+#             */
/*   Updated: 2022/02/17 18:13:25 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_walls(t_vars *mlx)
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
			if (mlx->map[i][j] == '1')
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

	tabs = count_walls(mlx);
	mlx->w_position = (int **)malloc((tabs + 1) * sizeof(int *));
	if (!mlx->w_position)
		exit(0);
	mlx->w_position[tabs] = NULL;
	i = 0;
	while (i < tabs)
	{
		mlx->w_position[i] = (int *)malloc(2 * sizeof(int));
		if (!mlx->w_position[i])
			exit(0);
		i++;
	}
}

void	walls_position(t_vars *mlx)
{
	int			i;
	int			j;
	int			w_i;

	ft_allocate(mlx);
	w_i = 0;
	i = 1;
	while (mlx->map[i + 1])
	{
		j = 1;
		while (mlx->map[i][j + 1])
		{
			if (mlx->map[i][j] == '1')
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

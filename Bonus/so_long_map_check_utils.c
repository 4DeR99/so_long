/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map_check_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 19:12:53 by moulmado          #+#    #+#             */
/*   Updated: 2022/02/15 21:48:01 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_intruder(t_vars *mlx)
{
	int	i;
	int	j;
	int	intruder;

	i = 0;
	intruder = 0;
	while (!intruder && mlx->map[i])
	{
		j = 0;
		while (!intruder && mlx->map[i][j])
		{
			if (mlx->map[i][j] != '1' && mlx->map[i][j] != '0'
				&& mlx->map[i][j] != 'C' && mlx->map[i][j] != 'X'
			&& mlx->map[i][j] != 'E' && mlx->map[i][j] != 'P')
				intruder = 1;
			j++;
		}
		i++;
	}
	if (intruder)
	{
		ft_free(mlx->map);
		invalid_map();
		exit(1);
	}
}

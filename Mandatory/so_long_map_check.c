/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 18:59:36 by moulmado          #+#    #+#             */
/*   Updated: 2022/02/16 18:22:40 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_border_util(char *s, int *border)
{
	int	i;

	i = 0;
	while (*border == 1 && s[i])
	{
		if (s[i] != '1')
			*border = 0;
		i++;
	}
}

static int	check_border(t_vars *mlx)
{
	int	border;
	int	i;
	int	j;

	border = 1;
	i = 0;
	j = 0;
	check_border_util(mlx->map[j], &border);
	j++;
	while (border == 1 && mlx->map[j + 1])
	{
		i = 0;
		if (mlx->map[j][i] != '1')
			border = 0;
		while (border == 1 && mlx->map[j][i + 1])
			i++;
		if (border == 1 && mlx->map[j][i] != '1')
			border = 0;
		j++;
	}
	check_border_util(mlx->map[j], &border);
	return (border);
}

/* every tab's len should be same as the first one */
static int	check_shape(t_vars *mlx)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = 0;
	while (mlx->map[0][i++])
		len++;
	i = 1;
	while (mlx->map[i])
	{
		j = 0;
		while (mlx->map[i][j])
			j++;
		if (j != len)
			return (0);
		i++;
	}
	return (1);
}

static void	check_elements(t_vars *mlx, int *player, int *collectible, int *ext)
{
	int	i;
	int	j;

	*player = 0;
	*collectible = 0;
	*ext = 0;
	i = 0;
	while (mlx->map[i])
	{
		j = 0;
		while (mlx->map[i][j])
		{
			if (mlx->map[i][j] == 'P')
				*player += 1;
			if (mlx->map[i][j] == 'C')
				*collectible += 1;
			if (mlx->map[i][j] == 'E')
				*ext += 1;
			j++;
		}
		i++;
	}
}

void	check_map(t_vars *mlx)
{
	int	border;
	int	player;
	int	collectible;
	int	shape;
	int	ext;

	border = 0;
	shape = 0;
	shape = check_shape(mlx);
	border = check_border(mlx);
	check_elements(mlx, &player, &collectible, &ext);
	if (border != 1 || player != 1
		|| shape != 1 || collectible == 0 || ext == 0)
	{
		invalid_map();
		ft_free(mlx->map);
		exit(0);
	}
	check_intruder(mlx);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 18:59:36 by moulmado          #+#    #+#             */
/*   Updated: 2022/02/01 15:50:30 by moulmado         ###   ########.fr       */
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

static int	check_border(char **map)
{
	int	border;
	int	i;
	int	j;

	border = 1;
	i = 0;
	j = 0;
	check_border_util(map[j], &border);
	j++;
	while (border == 1 && map[j + 1])
	{
		i = 0;
		if (map[j][i] != '1')
			border = 0;
		while (border == 1 && map[j][i + 1])
			i++;
		if (border == 1 && map[j][i] != '1')
			border = 0;
		j++;
	}
	check_border_util(map[j], &border);
	return (border);
}

/* every tab's len should be same as the first one */
static int	check_shape(char **map)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = 0;
	while (map[0][i++])
		len++;
	i = 1;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (j != len)
			return (0);
		i++;
	}
	return (1);
}

static void	check_elements(char **map, int *player, int *collectible, int *ext)
{
	int	i;
	int	j;

	*player = 0;
	*collectible = 0;
	*ext = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				*player += 1;
			if (map[i][j] == 'C')
				*collectible += 1;
			if (map[i][j] == 'E')
				*ext += 1;
			j++;
		}
		i++;
	}
}

void	check_map(char **map)
{
	int	border;
	int	player;
	int	collectible;
	int	shape;
	int	ext;

	border = 0;
	shape = 0;
	shape = check_shape(map);
	border = check_border(map);
	check_elements(map, &player, &collectible, &ext);
	if (border != 1 || player != 1
		|| shape != 1 || collectible == 0 || ext == 0)
	{
		printf("Error\n");
		printf("Invalid map\n");
		exit(1);
	}
	check_intruder(map);
}

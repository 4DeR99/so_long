/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_check_map_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 19:12:53 by moulmado          #+#    #+#             */
/*   Updated: 2022/01/08 17:10:02 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_intruder(char **map)
{
	int	i;
	int	j;
	int	intruder;

	i = 0;
	intruder = 0;
	while (!intruder && map[i])
	{
		j = 0;
		while (!intruder && map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'C'
				&& map[i][j] != 'E' && map[i][j] != 'P')
				intruder = 1;
			j++;
		}
		i++;
	}
	if (intruder)
	{
		printf("Error\n");
		printf("Invalid map\n");
		exit(1);
	}
}
